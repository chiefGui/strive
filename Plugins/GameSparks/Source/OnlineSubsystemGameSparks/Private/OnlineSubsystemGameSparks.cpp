#include "OnlineSubsystemGameSparks.h"
#include "OnlineSubsystemGameSparksPrivatePCH.h"
#include "./Interfaces/OnlineIdentityInterfaceGameSparks.h"
#include "./Interfaces/OnlineUserInterfaceGameSparks.h"
#include "./Interfaces/OnlineFriendsInterfaceGameSparks.h"

#include "GameSparksModule.h"


// FOnlineSubsystemGameSparks

IOnlineSessionPtr FOnlineSubsystemGameSparks::GetSessionInterface() const
{
	return nullptr;
}

IOnlineFriendsPtr FOnlineSubsystemGameSparks::GetFriendsInterface() const
{
	return FriendsInterface;
}

IOnlinePartyPtr FOnlineSubsystemGameSparks::GetPartyInterface() const
{
	return nullptr;
}

IOnlineGroupsPtr FOnlineSubsystemGameSparks::GetGroupsInterface() const
{
	return nullptr;
}

IOnlineSharedCloudPtr FOnlineSubsystemGameSparks::GetSharedCloudInterface() const
{
	return nullptr;
}

IOnlineUserCloudPtr FOnlineSubsystemGameSparks::GetUserCloudInterface() const
{
	return nullptr;
}

IOnlineLeaderboardsPtr FOnlineSubsystemGameSparks::GetLeaderboardsInterface() const
{
	return nullptr;
}

IOnlineVoicePtr FOnlineSubsystemGameSparks::GetVoiceInterface() const
{
	return nullptr;
}

IOnlineExternalUIPtr FOnlineSubsystemGameSparks::GetExternalUIInterface() const	
{
	return nullptr;
}

IOnlineTimePtr FOnlineSubsystemGameSparks::GetTimeInterface() const
{
	return nullptr;
}

IOnlineIdentityPtr FOnlineSubsystemGameSparks::GetIdentityInterface() const
{
	return IdentityInterface;
}

IOnlineTitleFilePtr FOnlineSubsystemGameSparks::GetTitleFileInterface() const
{
	return nullptr;
}

IOnlineEntitlementsPtr FOnlineSubsystemGameSparks::GetEntitlementsInterface() const
{
	return nullptr;
}

IOnlineStorePtr FOnlineSubsystemGameSparks::GetStoreInterface() const
{
	return nullptr;
}

IOnlineEventsPtr FOnlineSubsystemGameSparks::GetEventsInterface() const
{
	return nullptr;
}

IOnlineAchievementsPtr FOnlineSubsystemGameSparks::GetAchievementsInterface() const
{
	return nullptr;
}

IOnlineSharingPtr FOnlineSubsystemGameSparks::GetSharingInterface() const
{
	return nullptr;
}

IOnlineUserPtr FOnlineSubsystemGameSparks::GetUserInterface() const
{
	return UserInterface;
}

IOnlineMessagePtr FOnlineSubsystemGameSparks::GetMessageInterface() const
{
	return nullptr;
}

IOnlinePresencePtr FOnlineSubsystemGameSparks::GetPresenceInterface() const
{
	return nullptr;
}

IOnlineChatPtr FOnlineSubsystemGameSparks::GetChatInterface() const
{
	return nullptr;
}

IOnlineTurnBasedPtr FOnlineSubsystemGameSparks::GetTurnBasedInterface() const
{
    return nullptr;
}

bool FOnlineSubsystemGameSparks::Tick(float DeltaTime)
{
	if (!FOnlineSubsystemImpl::Tick(DeltaTime))
	{
		return false;
	}

    // wait for the GS module to be loaded and initialize it
    if(UGameSparksModule::GetModulePtr() && !UGameSparksModule::GetModulePtr()->IsInitialized())
    {
        FString ApiKey;
        if(!GConfig->GetString(TEXT("OnlineSubsystemGameSparks"), TEXT("ApiKey"), ApiKey, GEngineIni))
        {
            UE_LOG(LogOnline, Display, TEXT("OnlineSubsystemGameSparks: ApiKey not configured in Engine.ini - please add in the [OnlineSubsystemGameSparks] section."));
            return false;
        }

        FString ApiSecret;
        if(!GConfig->GetString(TEXT("OnlineSubsystemGameSparks"), TEXT("ApiSecret"), ApiSecret, GEngineIni))
        {
            UE_LOG(LogOnline, Display, TEXT("OnlineSubsystemGameSparks: ApiSecret not configured in Engine.ini - please add in the [OnlineSubsystemGameSparks] section."));
            return false;
        }

        bool usePreviewServer = false;
        GConfig->GetBool(TEXT("OnlineSubsystemGameSparks"), TEXT("bUsePreviewServer"), usePreviewServer, GEngineIni);

        #if UE_BUILD_SHIPPING
        if(usePreviewServer)
        {
            UE_LOG(LogOnline, Display, TEXT("OnlineSubsystemGameSparks: WARNING: bUsePreviewServer is True in a shipping build. Overriding your setting"));
            usePreviewServer = false;
        }
        #endif

        OnGameSparksAvailableDelegateHandle = UGameSparksModule::GetModulePtr()->AddOnGameSparksAvailableDelegate_Handle(OnGameSparksAvailableDelegate);
        UGameSparksModule::GetModulePtr()->Initialize(ApiKey, ApiSecret, usePreviewServer, false);
    }
	return true;
}


void FOnlineSubsystemGameSparks::OnGameSparksAvailable(bool available)
{
    auto currentConnectionStatus = available?EOnlineServerConnectionStatus::Type::Connected:EOnlineServerConnectionStatus::Type::NotConnected;
    TriggerOnConnectionStatusChangedDelegates(lastConnectionStatus, currentConnectionStatus);
    lastConnectionStatus = currentConnectionStatus;
}


bool FOnlineSubsystemGameSparks::Init()
{
    IdentityInterface = MakeShareable(new FOnlineIdentityInterfaceGameSparks());
	UserInterface = MakeShareable(new FOnlineUserInterfaceGameSparks());
    FriendsInterface = MakeShareable(new FOnlineFriendsInterfaceGameSparks());

	return true;
}

bool FOnlineSubsystemGameSparks::Shutdown()
{
	UE_LOG(LogOnline, Display, TEXT("FOnlineSubsystemGameSparks::Shutdown()"));
	FOnlineSubsystemImpl::Shutdown();
	return true;
}

FString FOnlineSubsystemGameSparks::GetAppId() const
{
	return TEXT("GameSparks");
}

bool FOnlineSubsystemGameSparks::Exec(UWorld* InWorld, const TCHAR* Cmd, FOutputDevice& Ar) 
{
	#if GS_UE_VERSION > 41000
	if (FOnlineSubsystemImpl::Exec(InWorld, Cmd, Ar))
	{
		return true;
	}
    #endif

	return false;
}

#if ENGINE_MAJOR_VERSION >= 4 && ENGINE_MINOR_VERSION >= 19
bool FOnlineSubsystemGameSparks::IsEnabled() const
#else
bool FOnlineSubsystemGameSparks::IsEnabled()
#endif
{
	// Check the ini for disabling GameSparks
	bool bEnableGameSparks = false;
	GConfig->GetBool(TEXT("OnlineSubsystemGameSparks"), TEXT("bEnabled"), bEnableGameSparks, GEngineIni);

#if !UE_BUILD_SHIPPING
	// Check the commandline for disabling GameSparks
	bEnableGameSparks = bEnableGameSparks && !FParse::Param(FCommandLine::Get(),TEXT("NOGameSparks"));
#endif

	return bEnableGameSparks;
}


FOnlineSubsystemGameSparks::FOnlineSubsystemGameSparks() 
{
    OnGameSparksAvailableDelegate = FOnGameSparksAvailableDelegate::CreateLambda([=](bool available){
        this->OnGameSparksAvailable(available);
    });
}


FOnlineSubsystemGameSparks::~FOnlineSubsystemGameSparks()
{
    if(OnGameSparksAvailableDelegateHandle.IsValid() && UGameSparksModule::GetModulePtr())
    {
        UGameSparksModule::GetModulePtr()->ClearOnGameSparksAvailableDelegate_Handle(OnGameSparksAvailableDelegateHandle);
    }
}
