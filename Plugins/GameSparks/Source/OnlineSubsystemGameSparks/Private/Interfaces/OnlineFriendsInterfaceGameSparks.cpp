#include "OnlineFriendsInterfaceGameSparks.h"
#include "../OnlineSubsystemGameSparksPrivatePCH.h"
#include "../Types/OnlineFriendGameSparks.h"


FOnlineFriendsInterfaceGameSparks::FOnlineFriendsInterfaceGameSparks()
{

}


FOnlineFriendsInterfaceGameSparks::~FOnlineFriendsInterfaceGameSparks()
{

}


GameSparks::Core::GS& FOnlineFriendsInterfaceGameSparks::GetGSInstance(int32 LocalUserNum)
{
    if(LocalUserNum != 0)
    {
        UE_LOG(GSOSSLog, Error, TEXT("OnlineSubsystemGameSparks currently only supports one logged in user, make sure to pass 0 as LocalUserNum."));
    }
    return  UGameSparksModule::GetModulePtr()->GetGSInstance();
}


bool FOnlineFriendsInterfaceGameSparks::ReadFriendsList(int32 LocalUserNum, const FString &ListName, const FOnReadFriendsListComplete &Delegate) {
    if(!ListName.IsEmpty())
    {
        UE_LOG(GSOSSLog, Warning, TEXT("ReadFriendsList does not support named friend lists."));
    }

    auto& gs = GetGSInstance(LocalUserNum);

    if(!gs.GetAvailable())
        return false;

    GameSparks::Api::Requests::ListGameFriendsRequest request(gs);
    request.Send([=](GameSparks::Core::GS&, const GameSparks::Api::Responses::ListGameFriendsResponse& response){
        if(response.GetHasErrors())
        {
            Delegate.ExecuteIfBound(LocalUserNum, false, ListName, response.GetErrors().GetValue().GetJSON().c_str());
        }
        else
        {
            for(const auto& player : response.GetFriends())
            {
                TSharedRef<FOnlineFriend> user = MakeShareable(new FOnlineFriendGameSparks(player));
                cache.Add(FUniqueNetIdString(player.GetId().GetValue().c_str()), user);
            }

            Delegate.ExecuteIfBound(LocalUserNum, true, ListName, TEXT(""));
        }
    });

    return true;
}

bool FOnlineFriendsInterfaceGameSparks::DeleteFriendsList(int32 LocalUserNum, const FString &ListName, const FOnDeleteFriendsListComplete &Delegate) {
    return false; // not supported
}

bool FOnlineFriendsInterfaceGameSparks::SendInvite(int32 LocalUserNum, const FUniqueNetId &FriendId, const FString &ListName, const FOnSendInviteComplete &Delegate) {
    return false; // not supported
}

bool FOnlineFriendsInterfaceGameSparks::AcceptInvite(int32 LocalUserNum, const FUniqueNetId &FriendId, const FString &ListName, const FOnAcceptInviteComplete &Delegate) {
    return false; // not supported
}

bool FOnlineFriendsInterfaceGameSparks::RejectInvite(int32 LocalUserNum, const FUniqueNetId &FriendId, const FString &ListName) {
    return false; // not supported
}

bool FOnlineFriendsInterfaceGameSparks::DeleteFriend(int32 LocalUserNum, const FUniqueNetId &FriendId, const FString &ListName) {
    return false; // not supported
}

bool FOnlineFriendsInterfaceGameSparks::GetFriendsList(int32 LocalUserNum, const FString &ListName, TArray<TSharedRef<FOnlineFriend> > &OutFriends) {
    cache.GenerateValueArray(OutFriends);
    return true;//cache.Num() > 0;
}

TSharedPtr<FOnlineFriend> FOnlineFriendsInterfaceGameSparks::GetFriend(int32 LocalUserNum, const FUniqueNetId &FriendId, const FString &ListName) {
    if(auto found = cache.Find(FUniqueNetIdString(FriendId)))
    {
        return *found;
    }
    return {};
}

bool FOnlineFriendsInterfaceGameSparks::IsFriend(int32 LocalUserNum, const FUniqueNetId &FriendId, const FString &ListName) {
    return cache.Contains(FUniqueNetIdString(FriendId));
}

bool FOnlineFriendsInterfaceGameSparks::QueryRecentPlayers(const FUniqueNetId &UserId, const FString &Namespace) {
    return false; // not supported
}

bool FOnlineFriendsInterfaceGameSparks::GetRecentPlayers(const FUniqueNetId &UserId, const FString &Namespace, TArray<TSharedRef<FOnlineRecentPlayer> > &OutRecentPlayers) {
    return false; // not supported
}


#if GS_UE_VERSION >= GS_MAKE_VERSION(4,11)
bool FOnlineFriendsInterfaceGameSparks::BlockPlayer(int32 LocalUserNum, const FUniqueNetId &PlayerId) {
    return false;
}

bool FOnlineFriendsInterfaceGameSparks::UnblockPlayer(int32 LocalUserNum, const FUniqueNetId &PlayerId) {
    return false;
}

bool FOnlineFriendsInterfaceGameSparks::QueryBlockedPlayers(const FUniqueNetId &UserId) {
    return false;
}


bool FOnlineFriendsInterfaceGameSparks::GetBlockedPlayers(const FUniqueNetId &UserId, TArray<TSharedRef<FOnlineBlockedPlayer> > &OutBlockedPlayers) {
    return false;
}
#endif


#if GS_UE_VERSION >= GS_MAKE_VERSION(4,12)
void FOnlineFriendsInterfaceGameSparks::DumpBlockedPlayers() const {

}
#endif
