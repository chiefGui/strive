#include "GameSparksObject.h"
#include "GameSparksPrivatePCH.h"
#include "Engine.h"
#include "GameSparksClasses.h"
#include "GameSparksModule.h"

// Sets default values for this component's properties
UGameSparksObject::UGameSparksObject(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
    //bWantsInitializeComponent = true;
    //PrimaryComponentTick.bCanEverTick = false;
}

void UGameSparksObject::Connect(FString apikey, FString secret, bool previewServer, bool clearCachedAuthentication)
{
    if (UGameSparksModule::GetModulePtr() != nullptr){
		UGameSparksModule::GetModulePtr()->Initialize(apikey, secret, previewServer, clearCachedAuthentication);
    }
}

void UGameSparksObject::Disconnect()
{
    if (UGameSparksModule::GetModulePtr() != nullptr){
        UGameSparksModule::GetModulePtr()->Shutdown();
    }
		
}

void UGameSparksObject::Logout()
{
    if (UGameSparksModule::GetModulePtr() != nullptr){
        UGameSparksModule::GetModulePtr()->Logout();
    }
}


bool UGameSparksObject::IsAuthenticated(){
    return
        UGameSparksModule::GetModulePtr() != nullptr &&
        UGameSparksModule::GetModulePtr()->GetGSInstance().GetAuthenticated();
}

bool UGameSparksObject::IsAvailable(){
    return
        UGameSparksModule::GetModulePtr() != nullptr &&
        UGameSparksModule::GetModulePtr()->GetGSInstance().GetAvailable();
}


void UGameSparksObject::SetApiCredential(FString credential)
{
    if (UGameSparksModule::GetModulePtr() != nullptr){
		UGameSparksModule::GetModulePtr()->SetApiCredential(credential);
    }
}

void UGameSparksObject::SetApiStage(FString stage)
{
    if (UGameSparksModule::GetModulePtr() != nullptr){
        UGameSparksModule::GetModulePtr()->SetApiStage(stage);
    }
}

void UGameSparksObject::SetApiDomain(FString domain)
{
    if (UGameSparksModule::GetModulePtr() != nullptr){
        UGameSparksModule::GetModulePtr()->SetApiDomain(domain);
    }
}

class UWorld* UGameSparksObject::GetWorld() const
{
    return GetOuter()->GetWorld();
}
