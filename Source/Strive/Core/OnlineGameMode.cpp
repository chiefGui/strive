// Fill out your copyright notice in the Description page of Project Settings.

#include "OnlineGameMode.h"
#include "GameLiftServerSDK.h"
#include "Engine/World.h"
#include <CommandLine.h>
#include "IPAddress.h"
#include "IpNetDriver.h"

DEFINE_LOG_CATEGORY(LogGameLift);

AOnlineGameMode::AOnlineGameMode()
	: Super()
{

}

void AOnlineGameMode::BeginPlay()
{
	Super::BeginPlay();

	// Only communicates with GameLift when the world is ready.
	if (GetWorld())
	{
		SetGameLiftServerSDK(&FModuleManager::LoadModuleChecked<FGameLiftServerSDKModule>(FName("GameLiftServerSDK")));

		//InitSDK establishes a local connection with GameLift's agent to enable further communication.
		GetGameLiftServerSDK()->InitSDK();
		UE_LOG(LogGameLift, Display, TEXT("SDK successfully initiated."));

		if (GetWorld()->NetDriver)
		{
			StartGameLiftProcess(
				GetGameLiftServerSDK()
				, GetGameLiftProcessParameters(GetGameLiftServerSDK())
			);
		}
	}
}

void AOnlineGameMode::StartGameLiftProcess(FGameLiftServerSDKModule* GameLiftServerSDK, FProcessParameters* GameLiftProcessParameters)
{
	UE_LOG(
		LogGameLift
		, Display
		, TEXT("GameLift started a new game process.")
	);

	FGameLiftGenericOutcome GameProcess = GameLiftServerSDK->ProcessReady(*GameLiftProcessParameters);

	if (GameProcess.IsSuccess()) {
		UE_LOG(
			LogGameLift
			, Display
			, TEXT("The game process is listening on port %d")
			, GameLiftProcessParameters->port
		);
	}
	else
	{
		UE_LOG(
			LogGameLift
			, Display
			, TEXT("The game process failed on port %d with message: %s")
			, GameLiftProcessParameters->port
			, *GameProcess.GetError().m_errorMessage
		);
	}
}

FProcessParameters* AOnlineGameMode::GetGameLiftProcessParameters(FGameLiftServerSDKModule* GameLiftServerSDK)
{
	//When a game session is created, GameLift sends an activation request to the game server and passes along the game session object containing game properties and other settings.
	//Here is where a game server should take action based on the game session object.
	//Once the game server is ready to receive incoming player connections, it should invoke GameLiftServerAPI.ActivateGameSession()
	auto StartGameSession = [=](Aws::GameLift::Server::Model::GameSession gameSession)
	{
		GameLiftServerSDK->ActivateGameSession();
	};

	FProcessParameters* GameLiftProcessParameters = new FProcessParameters();
	GameLiftProcessParameters->OnStartGameSession.BindLambda(StartGameSession);

	//OnProcessTerminate callback. GameLift invokes this callback before shutting down an instance hosting this game server.
	//It gives this game server a chance to save its state, communicate with services, etc., before being shut down.
	//In this case, we simply tell GameLift we are indeed going to shut down.
	GameLiftProcessParameters->OnTerminate.BindLambda([=]() {
		GameLiftServerSDK->ProcessEnding();
	});

	//This is the HealthCheck callback.
	//GameLift invokes this callback every 60 seconds or so.
	//Here, a game server might want to check the health of dependencies and such.
	//Simply return true if healthy, false otherwise.
	//The game server has 60 seconds to respond with its health status. GameLift defaults to 'false' if the game server doesn't respond in time.
	//In this case, we're always healthy!
	GameLiftProcessParameters->OnHealthCheck.BindLambda([]() {
		return true;
	});

	//This game server tells GameLift that it listens on port XXXX for incoming player connections.
	GameLiftProcessParameters->port = GetNetDriverPort();

	return GameLiftProcessParameters;
}

void AOnlineGameMode::Logout(AController* Exiting)
{
	int NewNumberOfConnectedPlayers = this->GetNumPlayers() - 1;

	if (NewNumberOfConnectedPlayers == 0)
	{
		OnAllPlayersDisconnected();
	}
}

void AOnlineGameMode::OnAllPlayersDisconnected()
{
	UE_LOG(LogGameLift, Display, TEXT("All players have disconnected. The Game Session will be terminated."));

	GetGameLiftServerSDK()->TerminateGameSession();
	GetGameLiftServerSDK()->ProcessEnding();
}

int32 AOnlineGameMode::GetNetDriverPort()
{
	UIpNetDriver* NetDriver = Cast<UIpNetDriver>(GetWorld()->NetDriver);

	return NetDriver->LocalAddr->GetPort();
}