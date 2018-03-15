#include "GameSparksLogEventData.h"
#include "GameSparksPrivatePCH.h"
#include "Engine.h"
#include "GameSparksClasses.h"

UGameSparksLogEventData* UGameSparksLogEventData::CreateGameSparksLogEventAttributes(UObject* WorldContextObject){
    UGameSparksLogEventData* proxy = NewObject<UGameSparksLogEventData>();
    return proxy;
};

UGameSparksLogEventData* UGameSparksLogEventData::SetString(const FString& name, const FString& value)
{
    m_strings.Add(name, value);
    return this;
}

UGameSparksLogEventData* UGameSparksLogEventData::SetNumber(const FString& name, const int32 value)
{
    m_numbers.Add(name, value);
    return this;
}

UGameSparksLogEventData* UGameSparksLogEventData::SetObject(const FString& name, UGameSparksScriptData* value)
{
    m_objects.Add(name, value);
    return this;
}

