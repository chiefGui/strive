// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
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

private:
	// Get port from command line. Returns 0 if no port is found.
	static uint32 GetPortFromCommandLine();

	// Check if port is valid. Ports greater than 0 are considered valid.
	static bool IsPortValid(uint32 PortNumber);
};
