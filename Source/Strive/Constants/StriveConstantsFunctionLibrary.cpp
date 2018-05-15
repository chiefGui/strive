// Fill out your copyright notice in the Description page of Project Settings.

#include "StriveConstantsFunctionLibrary.h"
#include "Engine.h"

UStriveConstantsFunctionLibrary::UStriveConstantsFunctionLibrary(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UStriveConstants* UStriveConstantsFunctionLibrary::GetStriveConstants(bool& IsValid)
{
	IsValid = false;
	UStriveConstants* ConstantsInstance = Cast<UStriveConstants>(GEngine->GameSingleton);

	if (!ConstantsInstance) return NULL;
	if (!ConstantsInstance->IsValidLowLevel()) return NULL;

	IsValid = true;

	return ConstantsInstance;
}

