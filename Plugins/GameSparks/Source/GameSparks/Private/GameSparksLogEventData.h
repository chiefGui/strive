#pragma once
#include "GameSparksPrivatePCH.h"
#include "Engine.h"
#include "GameSparksClasses.h"

#include "GameSparks/generated/GSRequests.h"
#include "GameSparksModule.h"
#include "GameSparksLogEventData.generated.h"

UCLASS(BlueprintType, Blueprintable)
class GAMESPARKS_API UGameSparksLogEventData : public UObject
{
	GENERATED_BODY()

public:
    
    /* Create a new Log Event Data object. */
    UFUNCTION(BlueprintPure, meta = (DisplayName = "Create Log Event Attributes", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"), Category = "GameSparks|Data")
    static UGameSparksLogEventData* CreateGameSparksLogEventAttributes(UObject* WorldContextObject);

    UFUNCTION(BlueprintPure, Category = "GameSparks|Data")
    UGameSparksLogEventData* SetString(const FString& name, const FString& value);
    
    UFUNCTION(BlueprintPure, Category = "GameSparks|Data")
    UGameSparksLogEventData* SetNumber(const FString& name, const int32 value);
    
    UFUNCTION(BlueprintPure, Category = "GameSparks|Data")
    UGameSparksLogEventData* SetObject(const FString& name, UGameSparksScriptData* value);
    
    void AddToLogEvent(GameSparks::Api::Requests::LogEventRequest* event){

        UE_LOG(UGameSparksModuleLog, Warning, TEXT("%s"), TEXT("UGameSparksLogEventData::AddToLogEvent_LogEventRequest"));
        for (const auto& Entry : m_strings)
        {
            UE_LOG(UGameSparksModuleLog, Warning, TEXT("%s"), TEXT("UGameSparksLogEventData::AddToLogEvent_LogEventRequest_SetString"));
            event->SetEventAttribute(TCHAR_TO_UTF8(*Entry.Key), TCHAR_TO_UTF8(*Entry.Value));
        }
        for (const auto& Entry : m_numbers)
        {
            event->SetEventAttribute(TCHAR_TO_UTF8(*Entry.Key), Entry.Value);
        }
        for (const auto& Entry : m_objects)
        {
            event->SetEventAttribute(TCHAR_TO_UTF8(*Entry.Key), Entry.Value->ToRequestData());
        }

    }
    
    void AddToLogEvent(GameSparks::Api::Requests::LogChallengeEventRequest* event){

        UE_LOG(UGameSparksModuleLog, Warning, TEXT("%s"), TEXT("UGameSparksLogEventData::AddToLogEvent_LogChallengeEventRequest"));
        for (const auto& Entry : m_strings)
        {
            UE_LOG(UGameSparksModuleLog, Warning, TEXT("%s"), TEXT("UGameSparksLogEventData::AddToLogEvent_LogChallengeEventRequest_SetString"));
            event->SetEventAttribute(TCHAR_TO_ANSI(*Entry.Key), TCHAR_TO_ANSI(*Entry.Value));
        }
        for (const auto& Entry : m_numbers)
        {
            event->SetEventAttribute(TCHAR_TO_ANSI(*Entry.Key), Entry.Value);
        }
        for (const auto& Entry : m_objects)
        {
            event->SetEventAttribute(TCHAR_TO_ANSI(*Entry.Key), Entry.Value->ToRequestData());
        }
        
    }

protected:
    UPROPERTY()
    TMap<FString, FString> m_strings;
    
    UPROPERTY()
    TMap<FString, int32> m_numbers;

    UPROPERTY()
    TMap<FString,UGameSparksScriptData*> m_objects;

};
