#include "GameSparksModule.h"
#include "GameSparksPrivatePCH.h"

#include "Engine.h"
#include "Engine/EngineTypes.h"
#include "GameSparksClasses.h"

#include "GameSparksObject.h"
#include "GSMessageListeners.h"
#include "GameSparksComponent.h"
#include "ModuleManager.h"
#include "Runtime/Core/Public/Features/IModularFeatures.h"
#include "Runtime/Core/Public/Stats/Stats2.h"

#include "GameSparksComponent.h"

#include "GameSparks/generated/GSMessages.h"
#include "GameSparksUnrealPlatform.h"
#include "GSMessageListeners.h"
#include <functional>

using namespace GameSparks::Core;
using namespace GameSparks::UnrealEngineSDK;


//DEFINE_LOG_CATEGORY(FGameSparks);
//
IMPLEMENT_MODULE(UGameSparksModule, GameSparks);
#define LOCTEXT_NAMESPACE "GameSparksPlugin"

DEFINE_LOG_CATEGORY(UGameSparksModuleLog);

void GameSparksAvailable_Static(GameSparks::Core::GS& gsInstance, bool available)
{
    UE_LOG(UGameSparksModuleLog, Warning, TEXT("%s"), TEXT("GameSparks::GameSparksAvailable_Static"));
    UGameSparksModule::GetModulePtr()->SendGameSparksAvailableToComponents(available);
    UGameSparksModule::GetModulePtr()->TriggerOnGameSparksAvailableDelegates(available);
}

void UGameSparksModule::StartupModule()
{
    UE_LOG(UGameSparksModuleLog, Warning, TEXT("%s"), TEXT("GameSparks::StartupModule"));
    GS.GameSparksAvailable = GameSparksAvailable_Static;
    UGSMessageListeners::RegisterListeners(GS);
}

void UGameSparksModule::ShutdownModule()
{
    GS.ShutDown();
    delete this->platform;
    this->platform = nullptr;
    isInitialised = false;
}

bool UGameSparksModule::IsTickableWhenPaused() const
{
    return true;
}

bool UGameSparksModule::IsTickableInEditor() const
{
    return false;
}

void UGameSparksModule::Tick(float DeltaTime)
{
    GS.Update(DeltaTime);
}

bool UGameSparksModule::IsTickable() const
{
    return true;
}

TStatId UGameSparksModule::GetStatId() const
{
    RETURN_QUICK_DECLARE_CYCLE_STAT(UGameSparksModule, STATGROUP_Tickables);
}

void UGameSparksModule::Initialize(FString apikey, FString secret, bool previewServer, bool clearCachedAuthentication)
{
    if(!isInitialised){
        UE_LOG(UGameSparksModuleLog, Warning, TEXT("%s"), TEXT("GameSparks::Initialize"));

        if(this->platform)
        {
            delete this->platform;
        }

        this->platform = new GameSparksUnrealPlatform(TCHAR_TO_ANSI(*apikey), TCHAR_TO_ANSI(*secret), previewServer);
		
		if (!Credentials.IsEmpty()) 
		{
			this->platform->SetApiCredential(TCHAR_TO_UTF8(*this->Credentials));
		}
		
		if (!Stage.IsEmpty())
		{
			this->platform->SetApiStage(TCHAR_TO_UTF8(*this->Stage));
		}
		
		if (!Domain.IsEmpty())
		{
			this->platform->SetApiDomain(TCHAR_TO_UTF8(*this->Domain));
		}
		
		if(clearCachedAuthentication){
            platform->SetAuthToken("0");
            platform->SetUserId("");
        }
        GS.Initialise(platform);
        isInitialised = true;
    }
}

void UGameSparksModule::Shutdown()
{
    if(isInitialised){
        UE_LOG(UGameSparksModuleLog, Warning, TEXT("%s"), TEXT("GameSparks::Shutdown"));
        GS.ShutDown();
        isInitialised = false;
    }
}

void UGameSparksModule::Logout()
{
    if(isInitialised){
        UE_LOG(UGameSparksModuleLog, Warning, TEXT("%s"), TEXT("GameSparks::Logout"));
        GS.Reset();
    }
}

UGameSparksModule* UGameSparksModule::GetModulePtr()
{
    return FModuleManager::GetModulePtr<UGameSparksModule>("GameSparks");
}

void UGameSparksModule::SendGameSparksAvailableToComponents(bool available)
{
    for ( TObjectIterator<UGameSparksComponent> Itr; Itr; ++Itr )
    {
        #if GS_UE_VERSION < GS_MAKE_VERSION(4, 14) // since 4.14 auto-generated enums no longer use TEnumAsByte
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType.GetValue() == EWorldType::Game || Itr->GetWorld()->WorldType.GetValue() == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #else
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType == EWorldType::Game || Itr->GetWorld()->WorldType == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #endif
        {
            Itr->OnGameSparksAvailableDelegate.Broadcast(available);
        }
    }

    // Also notify UGameSparksObject instances
    for (TObjectIterator<UGameSparksObject> Itr; Itr; ++Itr)
    {
        #if GS_UE_VERSION < GS_MAKE_VERSION(4, 14) // since 4.14 auto-generated enums no longer use TEnumAsByte
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType.GetValue() == EWorldType::Game || Itr->GetWorld()->WorldType.GetValue() == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #else
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType == EWorldType::Game || Itr->GetWorld()->WorldType == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #endif
        {
            Itr->OnGameSparksAvailableDelegate.Broadcast(available);
        }
    }
}

void UGameSparksModule::SendDebugLogToComponents(const gsstl::string& message)
{
    FString str = FString(UTF8_TO_TCHAR(message.c_str()));
    
    UE_LOG(UGameSparksModuleLog, Log, TEXT("%s"), *str);
    
    if (GEngine != NULL)
    {
        for ( TObjectIterator<UGameSparksComponent> Itr; Itr; ++Itr )
        {
            #if GS_UE_VERSION < GS_MAKE_VERSION(4, 14) // since 4.14 auto-generated enums no longer use TEnumAsByte
            if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType.GetValue() == EWorldType::Game || Itr->GetWorld()->WorldType.GetValue() == EWorldType::PIE) && (!Itr->IsPendingKill()))
            #else
            if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType == EWorldType::Game || Itr->GetWorld()->WorldType == EWorldType::PIE) && (!Itr->IsPendingKill()))
            #endif
            {
                Itr->OnGameSparksDebugLog.Broadcast(str);
            }
        }

        // Also notify UGameSparksObject instances
        for (TObjectIterator<UGameSparksObject> Itr; Itr; ++Itr)
        {
            #if GS_UE_VERSION < GS_MAKE_VERSION(4, 14) // since 4.14 auto-generated enums no longer use TEnumAsByte
            if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType.GetValue() == EWorldType::Game || Itr->GetWorld()->WorldType.GetValue() == EWorldType::PIE) && (!Itr->IsPendingKill()))
            #else
            if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType == EWorldType::Game || Itr->GetWorld()->WorldType == EWorldType::PIE) && (!Itr->IsPendingKill()))
            #endif
            {
                Itr->OnGameSparksDebugLog.Broadcast(str);
            }
        }

    }
}

bool UGameSparksModule::IsInitialized() const
{
	return isInitialised;
}


void UGameSparksModule::SetApiCredential(FString credential)
{
	this->Credentials = credential;
}


void UGameSparksModule::SetApiStage(FString stage)
{
	this->Stage = stage;
}


void UGameSparksModule::SetApiDomain(FString domain)
{
	this->Domain = domain;
}

#if GS_USE_IN_MEMORY_PERSISTENT_STORAGE
bool UGameSparksModule::GetPersistentStorage(PersistentStorage& storageToSave)
{
	if (!platform)
		return false;

	return platform->accessPersistentStorage([&storageToSafe](const PersistentStorage& storage) {
		storageToSafe = storage;
		return true;
	});
}

bool UGameSparksModule::RestoreFromPersistentStorage(const PersistentStorage& storageToRestore)
{
	if (!platform)
		return false;

	platform->accessPersistentStorage([&storageToRestore](PersistentStorage& internalStorage) {
		internalStorage = storageToRestore;
	});

	GS.ShutDown();
	GS.Initialise(platform);

	return true;
}
#endif /* GS_USE_IN_MEMORY_PERSISTENT_STORAGE */
