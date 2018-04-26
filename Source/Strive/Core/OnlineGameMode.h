// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GameLiftServerSDK.h"
#include "OnlineGameMode.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogGameLift, Log, All);

/**
 * 
 */
UCLASS()
class STRIVE_API AOnlineGameMode : public AGameModeBase
{
	GENERATED_BODY()

		AOnlineGameMode();

public:
	// The method called when all players have disconnected.
	void OnAllPlayersDisconnected();

	// Attempts to get current server port. First it looks up for a given port set through -port=something.
	// Case nothing is found, continue looking up for a port defined through the World context.
	// If both cases are invalid, returns 0.
	FORCEINLINE int GetPort()
	{
		if (IsPortValid(GetPortFromCommandLine()))
		{
			return GetPortFromCommandLine();
		}

		if (GetWorld())
		{
			return GetWorld()->URL.Port;
		}

		return 0;
	}

	// The GameLiftServerSDK module property.
	FGameLiftServerSDKModule* GameLiftServerSDK;

	// Get the GameLiftServerSDk. It must be set first in order to work properly.
	FGameLiftServerSDKModule* GetGameLiftServerSDK()
	{
		return GameLiftServerSDK;
	}

	FProcessParameters* GetGameLiftProcessParameters(FGameLiftServerSDKModule* GameLiftSDKModule);


private:
	FGameLiftServerSDKModule* GameLiftSDKModule;

	// Get port from command line. Returns 0 if no port is found.
	static uint32 GetPortFromCommandLine();

	// Check if port is valid. Ports greater than 0 are considered valid.
	static bool IsPortValid(uint32 PortNumber);

	// Event that is triggered when a player controller disconnects from the server.
	virtual void Logout(AController* Exiting) override;
	
	// Set the GameLiftServerSDK. It's required to GetGameLiftServerSDK.
	void SetGameLiftServerSDK(FGameLiftServerSDKModule* NewGameLiftServerSDK)
	{
		GameLiftServerSDK = NewGameLiftServerSDK;
	}

	// Starts a game server process with GameLift.
	void StartGameLiftProcess(
		FGameLiftServerSDKModule* GameLiftServerSDK,
		FProcessParameters* GameLiftProcessParameters
	);
};
