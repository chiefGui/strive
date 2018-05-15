// Strive Copyright 2018

#pragma once

#include "StriveConstants.generated.h"

UCLASS(Blueprintable, BlueprintType)
class UStriveConstants : public UObject
{
	GENERATED_BODY()

public:
	UStriveConstants(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Strive Constants", meta = (DisplayName = "Can Craft Without Ingredients?"))
		bool bCanCraftWithoutIngredients;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Strive Constants", meta = (DisplayName = "Skip GameSparks?"))
		bool bSkipGameSparks;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Strive Constants", meta = (DisplayName = "Skip Steam?"))
		bool bSkipSteam;
};
