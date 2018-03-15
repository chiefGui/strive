#pragma once

#include "../OnlineSubsystemGameSparksPrivatePCH.h"
#include "OnlineIdentityInterface.h"
#include "OnlineSubsystemGameSparksPackage.h"
#include "OnlineJsonSerializer.h"
#include "OnlineUserInterface.h"
#include <GameSparks/generated/GSResponses.h>

/**
 *	Interface class for obtaining online User info
 *
 *	Note: confusingly there is FOnlineUser which represents a user and
 *	IOnlineUser which represents the interface to query users. To make the
 *	confusion complete the method to retrieve the interface is called
 *	GetUserInterface() - which of course has nothing to do with UIs or GUIs.
 */
class FOnlineUserInterfaceGameSparks : public IOnlineUser
{

public:
    FOnlineUserInterfaceGameSparks();
    virtual ~FOnlineUserInterfaceGameSparks();

    /**
     * Starts an async task that queries/reads the info for a list of users
     *
     * @param LocalUserNum the user requesting the query
     * @param UserIds list of users to read info about
     *
     * @return true if the read request was started successfully, false otherwise
     */
    virtual bool QueryUserInfo(int32 LocalUserNum, const TArray<TSharedRef<const FUniqueNetId> >& UserIds) override;

    /**
     * Delegate used when the user query request has completed
     *
     * @param LocalUserNum the controller number of the associated user that made the request
     * @param bWasSuccessful true if the async action completed without error, false if there was an error
     * @param UserIds list of user ids that were queried
     * @param ErrorStr string representing the error condition
     */
     //DEFINE_ONLINE_PLAYER_DELEGATE_THREE_PARAM(MAX_LOCAL_PLAYERS, OnQueryUserInfoComplete, bool, const TArray< TSharedRef<const FUniqueNetId> >&, const FString&);

    /**
     * Obtains the cached list of online user info
     *
     * @param LocalUserNum the local user that queried for online user data
     * @param OutUsers [out] array that receives the copied data
     *
     * @return true if user info was found
     */
    virtual bool GetAllUserInfo(int32 LocalUserNum, TArray< TSharedRef<class FOnlineUser> >& OutUsers) override;

    /**
     * Get the cached user entry for a specific user id if found
     *
     * @param LocalUserNum the local user that queried for online user data
     * @param UserId id to use for finding the cached online user
     *
     * @return user info or null ptr if not found
     */
    virtual TSharedPtr<FOnlineUser> GetUserInfo(int32 LocalUserNum, const class FUniqueNetId& UserId) override;

    /**
     * Called when done querying for a UserId mapping from a requested display name
     *
     * @param bWasSuccessful true if server was contacted and a valid result received
     * @param UserId user id initiating the request
     * @param DisplayNameOrEmail the name string that was being queried
     * @param FoundUserId the user id matched for the passed name string
     * @param Error string representing the error condition
     */
     //DECLARE_DELEGATE_FiveParams(FOnQueryUserMappingComplete, bool /*bWasSuccessful*/, const FUniqueNetId& /*UserId*/, const FString& /*DisplayNameOrEmail*/, const FUniqueNetId& /*FoundUserId*/, const FString& /*Error*/);

    /**
     * Contacts server to obtain a user id from an arbitrary user-entered name string, eg. display name
     *
     * @param UserId id of the user that is requesting the name string lookup
     * @param DisplayNameOrEmail a string of a display name or email to attempt to map to a user id
     *
     * @return true if the operation was started successfully
     */
    virtual bool QueryUserIdMapping(const FUniqueNetId& UserId, const FString& DisplayNameOrEmail, const FOnQueryUserMappingComplete& Delegate = FOnQueryUserMappingComplete()) override;

    #if GS_UE_VERSION == GS_MAKE_VERSION(4,11)
    virtual bool QueryExternalIdMappings(const FUniqueNetId &UserId, const FString &AuthType, const TArray<FString> &ExternalIds, const IOnlineUser::FOnQueryExternalIdMappingsComplete &Delegate) override;
    virtual void GetExternalIdMappings(const FString &AuthType, const TArray<FString> &ExternalIds, TArray<TSharedPtr<const FUniqueNetId>> &OutIds) override;
    virtual TSharedPtr<const FUniqueNetId> GetExternalIdMapping(const FString &AuthType, const FString &ExternalId) override;
    #endif

    #if GS_UE_VERSION >= GS_MAKE_VERSION(4,12)
    virtual bool QueryExternalIdMappings(const FUniqueNetId &UserId, const FExternalIdQueryOptions &QueryOptions, const TArray<FString> &ExternalIds, const IOnlineUser::FOnQueryExternalIdMappingsComplete &Delegate) override;
    virtual void GetExternalIdMappings(const FExternalIdQueryOptions &QueryOptions, const TArray<FString> &ExternalIds, TArray<TSharedPtr<const FUniqueNetId>> &OutIds) override;
    virtual TSharedPtr<const FUniqueNetId> GetExternalIdMapping(const FExternalIdQueryOptions &QueryOptions, const FString &ExternalId) override;
    #endif

private:
    GameSparks::Core::GS& GetGSInstance(int32 LocalUserNum);

    typedef TMap<FUniqueNetIdString, TSharedRef<FOnlineUser> > Cache;
    Cache cache;
};
