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

	// Get NetDriverPort. Needed to send it to GameLift.
	int32 GetNetDriverPort();

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

	// Event that is triggered when a player controller disconnects from the server.
	virtual void Logout(AController* Exiting) override;

	// Begin Play
	virtual void BeginPlay() override;
	
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
