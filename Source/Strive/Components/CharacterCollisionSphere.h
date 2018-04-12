// Vincae Entertainment ME, 2018. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "Online/OnlineCharacter.h"
#include "CharacterCollisionSphere.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnOtherCharacterBeginOverlapSignature, class AOnlineCharacter*, OtherCharacter);

/**
 * 
 */
UCLASS(Blueprintable, hideCategories=("Physics", "Mobile", "HLOD", "Sockets", "Navigation", "Tags", "Cooking"), meta = (DisplayName="Character Collision Sphere", BlueprintSpawnableComponent, Tooltip="A ready-to-use Collision Sphere for Characters. It primarily handles the most basic logics behind a Collision Sphere for characters."))
class STRIVE_API UCharacterCollisionSphere : public USphereComponent
{
	GENERATED_BODY()

public:
	UCharacterCollisionSphere();

	UFUNCTION()
		void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent,
			AActor* OtherActor,
			UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex,
			bool bFromSweep,
			const FHitResult &SweepResult);

	UPROPERTY(BlueprintAssignable, Category = "Collision")
		FOnOtherCharacterBeginOverlapSignature OnOtherCharacterBeginOverlap;
};
