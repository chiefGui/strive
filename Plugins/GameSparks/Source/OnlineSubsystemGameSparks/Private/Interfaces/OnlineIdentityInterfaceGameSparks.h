#pragma once

#include "../OnlineSubsystemGameSparksPrivatePCH.h"
#include "OnlineIdentityInterface.h"
#include "OnlineSubsystemGameSparksPackage.h"
#include "../Types/UserOnlineAccountGameSparks.h"

/**
 * GameSparks service implementation of the online identity interface
 */
class FOnlineIdentityInterfaceGameSparks :
	public IOnlineIdentity
{
	/** Users that have been registered/authenticated */
	FUserOnlineAccountGameSparksMap UserAccounts;
	/** Ids mapped to locally registered users */
	TMap<int32, TSharedPtr<const FUniqueNetId> > UserIds;

	/** Whether we have a registration in flight or not */
	bool bHasLoginOutstanding;
	/** index of local user being registered */
	int32 LocalUserNumPendingLogin;

	/** Whether we have a logout in flight or not */
	bool bHasLogoutOutstanding;
	/** index of local user being logged out */
	int32 LocalUserNumPendingLogout;


public:
	FOnlineIdentityInterfaceGameSparks();
	virtual ~FOnlineIdentityInterfaceGameSparks() {}

	virtual bool Login(int32 LocalUserNum, const FOnlineAccountCredentials& AccountCredentials) override;
	virtual bool Logout(int32 LocalUserNum) override;
	virtual bool AutoLogin(int32 LocalUserNum) override;
	virtual TSharedPtr<FUserOnlineAccount> GetUserAccount(const FUniqueNetId& UserId) const override;
	virtual TArray<TSharedPtr<FUserOnlineAccount> > GetAllUserAccounts() const override;
	virtual TSharedPtr<const FUniqueNetId> GetUniquePlayerId(int32 LocalUserNum) const override;
	virtual TSharedPtr<const FUniqueNetId> CreateUniquePlayerId(uint8* Bytes, int32 Size) override;
	virtual TSharedPtr<const FUniqueNetId> CreateUniquePlayerId(const FString& Str) override;
	virtual ELoginStatus::Type GetLoginStatus(int32 LocalUserNum) const override;
	virtual ELoginStatus::Type GetLoginStatus(const FUniqueNetId& UserId) const override;
	virtual FString GetPlayerNickname(int32 LocalUserNum) const override;
	virtual FString GetPlayerNickname(const FUniqueNetId& UserId) const override;
	virtual FString GetAuthToken(int32 LocalUserNum) const override;
	virtual void GetUserPrivilege(const FUniqueNetId& UserId, EUserPrivileges::Type Privilege, const FOnGetUserPrivilegeCompleteDelegate& Delegate) override;
    
    #if GS_UE_VERSION >= GS_MAKE_VERSION(4,18) // const was added in 4.18
	virtual FPlatformUserId GetPlatformUserIdFromUniqueNetId(const FUniqueNetId& UniqueNetId) const override;
    #else
    virtual FPlatformUserId GetPlatformUserIdFromUniqueNetId(const FUniqueNetId& UniqueNetId) override;
    #endif
    
    #if GS_UE_VERSION >= GS_MAKE_VERSION(4,18) // API changed in 4.18
    virtual void RevokeAuthToken(const FUniqueNetId& UserId, const FOnRevokeAuthTokenCompleteDelegate& Delegate) override;
    #endif

	#if GS_UE_VERSION > GS_MAKE_VERSION(4,10) // API changed from 4.10 to 4.11
	virtual FString GetAuthType() const override;
    #endif
private:
};

typedef TSharedPtr<FOnlineIdentityInterfaceGameSparks, ESPMode::ThreadSafe> FOnlineIdentityGameSparksPtr;
