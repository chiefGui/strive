// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include <UserWidget.h>
#include "StriveGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class STRIVE_API UStriveGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UUserWidget * LoadingScreenWidget;

	virtual void Init() override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Loading Screen")
	TSubclassOf<class UUserWidget> DefaultLoadingScreenWidget;

	UFUNCTION()
		virtual void BeginLoadingScreen(const FString& MapName);

	UFUNCTION()
		virtual void EndLoadingScreen(UWorld* InLoadedWorld);
};
