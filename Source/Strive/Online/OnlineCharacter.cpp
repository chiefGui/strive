// Fill out your copyright notice in the Description page of Project Settings.

#include "OnlineCharacter.h"
#include "CoreUObject.h"


// Sets default values
AOnlineCharacter::AOnlineCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AOnlineCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AOnlineCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AOnlineCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

bool AOnlineCharacter::IsAlly(AOnlineCharacter* Character)
{
	if (this == Character)
	{
		return true;
	}

	if (this->GetOwner() == Character)
	{
		return true;
	}

	if (this->GetOwner() == Character->GetOwner())
	{
		return true;
	}

	return false;
}

UActorComponent* AOnlineCharacter::AddComponentFromClass(UClass* ActorComponentClass)
{
	UClass* baseClass = FindObject<UClass>(ANY_PACKAGE, TEXT("ActorComponent"));

	if (ActorComponentClass->IsChildOf(baseClass))
	{
		UActorComponent* NewComponent = NewObject<UActorComponent>(this, ActorComponentClass);

		if (!NewComponent)
		{
			return NULL;
		}

		NewComponent->RegisterComponent();

		return NewComponent;
	}
	else
	{
		return NULL;
	}
}
