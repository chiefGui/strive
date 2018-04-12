// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "OnlineCharacter.generated.h"

UCLASS()
class STRIVE_API AOnlineCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AOnlineCharacter();

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Is Ally?", Tooltip = "Checks if given AOnlineCharacter is ally of the caller."))
		bool IsAlly(AOnlineCharacter* Character);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
};
