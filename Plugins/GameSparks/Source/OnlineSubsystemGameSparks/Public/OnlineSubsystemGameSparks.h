#pragma once

#include "OnlineSubsystem.h"
#include "OnlineSubsystemImpl.h"
#include "OnlineSubsystemGameSparksPackage.h"
#include "GameSparksModule.h"
#include "Runtime/Launch/Resources/Version.h"

/** Forward declarations of all interface classes */
typedef TSharedPtr<class FOnlineIdentityInterfaceGameSparks, ESPMode::ThreadSafe> FOnlineIdentityGameSparksPtr;
typedef TSharedPtr<class FOnlineUserInterfaceGameSparks, ESPMode::ThreadSafe> FOnlineUserGameSparksPtr;
typedef TSharedPtr<class FOnlineFriendsInterfaceGameSparks, ESPMode::ThreadSafe> FOnlineFriendsInterfaceGameSparksPtr;

/**
 *	OnlineSubsystemGameSparks - Implementation of the online subsystem for GameSparks services
 */
class ONLINESUBSYSTEMGAMESPARKS_API FOnlineSubsystemGameSparks : public FOnlineSubsystemImpl
{
public:

	// IOnlineSubsystem Interface
	virtual IOnlineSessionPtr GetSessionInterface() const override;
	virtual IOnlineFriendsPtr GetFriendsInterface() const override;
	virtual IOnlinePartyPtr GetPartyInterface() const override;
	virtual IOnlineGroupsPtr GetGroupsInterface() const override;
	virtual IOnlineSharedCloudPtr GetSharedCloudInterface() const override;
	virtual IOnlineUserCloudPtr GetUserCloudInterface() const override;
	virtual IOnlineLeaderboardsPtr GetLeaderboardsInterface() const override;
	virtual IOnlineVoicePtr GetVoiceInterface() const override;
	virtual IOnlineExternalUIPtr GetExternalUIInterface() const override;
	virtual IOnlineTimePtr GetTimeInterface() const override;
	virtual IOnlineIdentityPtr GetIdentityInterface() const override;
	virtual IOnlineTitleFilePtr GetTitleFileInterface() const override;
	virtual IOnlineEntitlementsPtr GetEntitlementsInterface() const override;
	virtual IOnlineStorePtr GetStoreInterface() const override;

    // only available in UE 4.11+ (not in 4.10)
    #if ENGINE_MAJOR_VERSION >= 4 && ENGINE_MINOR_VERSION >= 11
	virtual IOnlineStoreV2Ptr GetStoreV2Interface() const override { return nullptr; }
	virtual IOnlinePurchasePtr GetPurchaseInterface() const override { return nullptr; }
    #endif

	virtual IOnlineEventsPtr GetEventsInterface() const override;
	virtual IOnlineAchievementsPtr GetAchievementsInterface() const override;
	virtual IOnlineSharingPtr GetSharingInterface() const override;
	virtual IOnlineUserPtr GetUserInterface() const override;
	virtual IOnlineMessagePtr GetMessageInterface() const override;
	virtual IOnlinePresencePtr GetPresenceInterface() const override;
	virtual IOnlineChatPtr GetChatInterface() const override;
    virtual IOnlineTurnBasedPtr GetTurnBasedInterface() const override;
	virtual bool Init() override;
	virtual bool Shutdown() override;
	virtual FString GetAppId() const override;
	virtual bool Exec(class UWorld* InWorld, const TCHAR* Cmd, FOutputDevice& Ar) override;

	// FTickerBaseObject

	virtual bool Tick(float DeltaTime) override;

	// FOnlineSubsystemGameSparks

	/**
	 * Destructor
	 */
	virtual ~FOnlineSubsystemGameSparks();

	/**
	 * Is GameSparks available for use
	 * @return true if GameSparks functionality is available, false otherwise
	 */
	#if ENGINE_MAJOR_VERSION >= 4 && ENGINE_MINOR_VERSION >= 19
    bool IsEnabled() const override;
    #else
    bool IsEnabled();
    #endif

	#if ENGINE_MAJOR_VERSION >= 4 && ENGINE_MINOR_VERSION >= 17
	virtual FText GetOnlineServiceName() const override
	{
		#define LOCTEXT_NAMESPACE "GameSparks"
		return LOCTEXT("GameSparks", "GameSparks");
		#undef LOCTEXT_NAMESPACE
	}
	#endif

PACKAGE_SCOPE:

	/** Only the factory makes instances */
	FOnlineSubsystemGameSparks();

private:
    FOnGameSparksAvailableDelegate OnGameSparksAvailableDelegate;
    FDelegateHandle OnGameSparksAvailableDelegateHandle;
    EOnlineServerConnectionStatus::Type lastConnectionStatus = EOnlineServerConnectionStatus::Type::NotConnected;

    virtual void OnGameSparksAvailable(bool available);

	/** GameSparks implementation of identity interface */
	FOnlineIdentityGameSparksPtr IdentityInterface;
	FOnlineUserGameSparksPtr UserInterface;
    FOnlineFriendsInterfaceGameSparksPtr FriendsInterface;
};

typedef TSharedPtr<FOnlineSubsystemGameSparks, ESPMode::ThreadSafe> FOnlineSubsystemGameSparksPtr;
