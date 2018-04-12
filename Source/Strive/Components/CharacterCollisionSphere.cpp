// Fill out your copyright notice in the Description page of Project Settings.

#include "CharacterCollisionSphere.h"
#include "Online/OnlineCharacter.h"
#include <Engine/Engine.h>
#include "Helpers/CharacterHelpers.h"

UCharacterCollisionSphere::UCharacterCollisionSphere()
{
	OnComponentBeginOverlap.AddDynamic(this, &UCharacterCollisionSphere::OnBeginOverlap);
}

void UCharacterCollisionSphere::OnBeginOverlap(
	UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult &SweepResult)
{
	AActor* Owner = this->GetOwner();

	if (Owner != OtherActor)
	{
		AOnlineCharacter* OverlappingCharacter = Cast<AOnlineCharacter>(OtherActor);

		if (OverlappingCharacter)
		{
			USkeletalMeshComponent* SkeletalMesh = Cast<USkeletalMeshComponent>(OtherComp);

			if (SkeletalMesh)
			{
				AOnlineCharacter* SelfCharacter = Cast<AOnlineCharacter>(Owner);

				this->OnOtherCharacterBeginOverlap.Broadcast(OverlappingCharacter);
			}
		}
	}
}