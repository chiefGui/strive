// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "GameplaySettings.generated.h"

/**
 * 
 */
UCLASS(config = Game, defaultconfig, meta = (DisplayName = "Strive Gameplay"))
class STRIVE_API UGameplaySettings : public UDeveloperSettings
{
	GENERATED_BODY()
	
public:
	/* How much time players have to wait in the character selection screen before they're allowed to spawn in the actual game? */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "General")
		float PreGameWaitingTime;
};
