// Fill out your copyright notice in the Description page of Project Settings.

#include "OnlineGameMode.h"
#include "GameLiftServerSDK.h"
#include "Engine/World.h"
#include <CommandLine.h>

DEFINE_LOG_CATEGORY(LogGameLift);

AOnlineGameMode::AOnlineGameMode()
	: Super()
{
#if WITH_GAMELIFT
	//Getting the module first.
	FGameLiftServerSDKModule* gameLiftSdkModule = &FModuleManager::LoadModuleChecked<FGameLiftServerSDKModule>(FName("GameLiftServerSDK"));

	//InitSDK establishes a local connection with GameLift's agent to enable further communication.
	FGameLiftGenericOutcome SDK = gameLiftSdkModule->InitSDK();

	//When a game session is created, GameLift sends an activation request to the game server and passes along the game session object containing game properties and other settings.
	//Here is where a game server should take action based on the game session object.
	//Once the game server is ready to receive incoming player connections, it should invoke GameLiftServerAPI.ActivateGameSession()
	auto onGameSession = [=](Aws::GameLift::Server::Model::GameSession gameSession)
	{
		gameLiftSdkModule->ActivateGameSession();
	};

	FProcessParameters* params = new FProcessParameters();
	params->OnStartGameSession.BindLambda(onGameSession);

	//OnProcessTerminate callback. GameLift invokes this callback before shutting down an instance hosting this game server.
	//It gives this game server a chance to save its state, communicate with services, etc., before being shut down.
	//In this case, we simply tell GameLift we are indeed going to shut down.
	params->OnTerminate.BindLambda([=]() {gameLiftSdkModule->ProcessEnding(); });

	//This is the HealthCheck callback.
	//GameLift invokes this callback every 60 seconds or so.
	//Here, a game server might want to check the health of dependencies and such.
	//Simply return true if healthy, false otherwise.
	//The game server has 60 seconds to respond with its health status. GameLift defaults to 'false' if the game server doesn't respond in time.
	//In this case, we're always healthy!
	params->OnHealthCheck.BindLambda([]() {return true; });

	//This game server tells GameLift that it listens on port 7777 for incoming player connections.
	UE_LOG(LogGameLift, Display, TEXT("GameLift is listening to port %d"), GetPort());
	params->port = GetPort();

	//Here, the game server tells GameLift what set of files to upload when the game session ends.
	//GameLift uploads everything specified here for the developers to fetch later.
	// TArray<FString> logfiles;
	// logfiles.Add(TEXT("aLogFile.txt"));
	// params->logParameters = logfiles;

	//Calling ProcessReady tells GameLift this game server is ready to receive incoming game sessions!
	gameLiftSdkModule->ProcessReady(*params);
#endif
}

uint32 AOnlineGameMode::GetPortFromCommandLine()
{
	FString PortWithEqualsChar;

	if (FParse::Value(FCommandLine::Get(), TEXT("port"), PortWithEqualsChar))
	{
		FString PortWithoutEqualsChar = *PortWithEqualsChar.Replace(TEXT("="), TEXT(""));
		uint32 ProcessedPort = FCString::Atoi(*PortWithoutEqualsChar);

		return ProcessedPort;
	}

	return 0;
}

bool AOnlineGameMode::IsPortValid(uint32 PortNumber)
{
	if (PortNumber > 0)
	{
		return true;
	}

	return false;
}
