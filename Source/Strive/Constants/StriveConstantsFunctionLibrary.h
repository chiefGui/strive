// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "StriveConstants.h"
#include "StriveConstantsFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class STRIVE_API UStriveConstantsFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	UStriveConstantsFunctionLibrary(const FObjectInitializer& ObjectInitializer);

	UFUNCTION(BlueprintPure, Category = "Strive Constants")
		static UStriveConstants* GetStriveConstants(bool& IsValid);
};
