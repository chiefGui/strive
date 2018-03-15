#include "GSMessageListenersObject.h"
#include "GameSparksPrivatePCH.h"
#include "GameSparks/GS.h"
#include "GameSparks/generated/GSMessages.h"
#include "GameSparksComponent.h"
#include "GameSparksModule.h"

UGSMessageListenersObject::UGSMessageListenersObject(){}

class UWorld* UGSMessageListenersObject::GetWorld() const
{
    return GetOuter()->GetWorld();
}
