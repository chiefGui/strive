#include "OnlineUserInterfaceGameSparks.h"
#include "../OnlineSubsystemGameSparksPrivatePCH.h"
#include "../Types/OnlineUserGameSparks.h"


FOnlineUserInterfaceGameSparks::FOnlineUserInterfaceGameSparks()
{

}

FOnlineUserInterfaceGameSparks::~FOnlineUserInterfaceGameSparks()
{

}

GameSparks::Core::GS& FOnlineUserInterfaceGameSparks::GetGSInstance(int32 LocalUserNum)
{
    if(LocalUserNum != 0)
    {
        UE_LOG(GSOSSLog, Error, TEXT("OnlineSubsystemGameSparks currently only supports one logged in user, make sure to pass 0 as LocalUserNum."));
    }
    return  UGameSparksModule::GetModulePtr()->GetGSInstance();
}


bool FOnlineUserInterfaceGameSparks::QueryUserInfo(int32 LocalUserNum, const TArray<TSharedRef<const FUniqueNetId> >& UserIds)
{
    auto& gs = GetGSInstance(LocalUserNum);
    GameSparks::Api::Requests::ListGameFriendsRequest request(gs);

    request.Send([=](GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::ListGameFriendsResponse& response){
        if(response.GetHasErrors())
        {
            TriggerOnQueryUserInfoCompleteDelegates(LocalUserNum, false, {}, response.GetErrors().GetValue().GetJSON().c_str());
        }
        else
        {
            TArray<TSharedRef<const FUniqueNetId> > FriendIds;

            // insert into cache
            for (const auto& player : response.GetFriends())
            {
                TSharedRef<FOnlineUser> user = MakeShareable(new FOnlineUserGameSparks(player));
                cache.Add(FUniqueNetIdString(player.GetId().GetValue().c_str()), user);

                // we have retrieved all friends, but we're only added those which where requested to the list passed to the delegate
                if(UserIds.Contains(user->GetUserId()))
                {
                    FriendIds.Add(user->GetUserId());
                }
            }

            // trigger delegate
            TriggerOnQueryUserInfoCompleteDelegates(LocalUserNum, true, FriendIds, TEXT(""));
        }
    });

    return true;
}

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
bool FOnlineUserInterfaceGameSparks::GetAllUserInfo(int32 LocalUserNum, TArray< TSharedRef<class FOnlineUser> >& OutUsers)
{
    cache.GenerateValueArray(OutUsers);
    return true;//cache.Num() > 0;
}

/**
 * Get the cached user entry for a specific user id if found
 *
 * @param LocalUserNum the local user that queried for online user data
 * @param UserId id to use for finding the cached online user
 *
 * @return user info or null ptr if not found
 */
TSharedPtr<FOnlineUser> FOnlineUserInterfaceGameSparks::GetUserInfo(int32 LocalUserNum, const class FUniqueNetId& UserId)
{
    if(auto found = cache.Find(FUniqueNetIdString(UserId)))
    {
        return *found;
    }
    return {};
}

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
bool FOnlineUserInterfaceGameSparks::QueryUserIdMapping(const FUniqueNetId& UserId, const FString& DisplayNameOrEmail, const FOnQueryUserMappingComplete& Delegate)
{
    return false;
}



#if GS_UE_VERSION == GS_MAKE_VERSION(4,11)
bool FOnlineUserInterfaceGameSparks::QueryExternalIdMappings(const FUniqueNetId &UserId, const FString &AuthType, const TArray<FString> &ExternalIds, const IOnlineUser::FOnQueryExternalIdMappingsComplete &Delegate) {
    return false;
}

void FOnlineUserInterfaceGameSparks::GetExternalIdMappings(const FString &AuthType, const TArray<FString> &ExternalIds, TArray<TSharedPtr<const FUniqueNetId>> &OutIds) {

}

TSharedPtr<const FUniqueNetId> FOnlineUserInterfaceGameSparks::GetExternalIdMapping(const FString &AuthType, const FString &ExternalId) {
    return {};
}
#endif


#if GS_UE_VERSION >= GS_MAKE_VERSION(4,12)
bool FOnlineUserInterfaceGameSparks::QueryExternalIdMappings(const FUniqueNetId &UserId, const FExternalIdQueryOptions &QueryOptions, const TArray<FString> &ExternalIds, const IOnlineUser::FOnQueryExternalIdMappingsComplete &Delegate) {
    return false;
}

void FOnlineUserInterfaceGameSparks::GetExternalIdMappings(const FExternalIdQueryOptions &QueryOptions, const TArray<FString> &ExternalIds, TArray<TSharedPtr<const FUniqueNetId>> &OutIds) {

}

TSharedPtr<const FUniqueNetId> FOnlineUserInterfaceGameSparks::GetExternalIdMapping(const FExternalIdQueryOptions &QueryOptions, const FString &ExternalId) {
    return {};
}
#endif