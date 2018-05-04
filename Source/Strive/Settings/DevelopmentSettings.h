// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "DevelopmentSettings.generated.h"

/**
 * 
 */
UCLASS(config = Game, defaultconfig, meta=(DisplayName="Strive Development"))
class STRIVE_API UDevelopmentSettings : public UDeveloperSettings
{
	GENERATED_BODY()
	
public:
	UDevelopmentSettings();

	UPROPERTY(VisibleAnywhere, Category = "Online", meta = (DisplayName = "Skip GameSparks Authentication?"))
		bool bSkipGameSparks;

	UPROPERTY(VisibleAnywhere, Category = "Online", meta = (DisplayName = "Skip Steam Authentication?"))
		bool bSkipSteamAuthentication;
};
