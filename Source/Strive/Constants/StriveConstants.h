// Strive Copyright 2018

#pragma once

#include "StriveConstants.generated.h"

UCLASS(Blueprintable, BlueprintType)
class UStriveConstants : public UObject
{
	GENERATED_BODY()

public:
	UStriveConstants(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Timers", meta = (DisplayName = "Character Selection Timeout"))
		float CharacterSelectionTimeout;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Timers", meta = (DisplayName = "Character Post Match Timeout"))
		float CharacterPostMatchTimeout;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Development", meta = (DisplayName = "Can Craft Without Ingredients?"))
		bool bCanCraftWithoutIngredients;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Development", meta = (DisplayName = "Skip GameSparks?"))
		bool bSkipGameSparks;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Development", meta = (DisplayName = "Skip Steam?"))
		bool bSkipSteam;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Development", meta = (DisplayName = "Simulate Authenticated Player?"))
		bool bSimulateAuthenticatedPlayer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Development", meta = (DisplayName = "Character Start At Max Level?"))
		bool bCharacterStartAtMaxLevel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Development", meta = (DisplayName = "Enable Characters Hit Kill?"))
		bool bEnableCharactersHitKill;
};
