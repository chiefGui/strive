#pragma once

#include "../OnlineSubsystemGameSparksPrivatePCH.h"
#include "OnlineFriendsInterface.h"


class FOnlineFriendsInterfaceGameSparks : public IOnlineFriends
{
    public:
        FOnlineFriendsInterfaceGameSparks();
        virtual ~FOnlineFriendsInterfaceGameSparks() override;

        virtual bool ReadFriendsList(int32 LocalUserNum, const FString &ListName, const FOnReadFriendsListComplete &Delegate) override;

        virtual bool DeleteFriendsList(int32 LocalUserNum, const FString &ListName, const FOnDeleteFriendsListComplete &Delegate) override;

        virtual bool SendInvite(int32 LocalUserNum, const FUniqueNetId &FriendId, const FString &ListName, const FOnSendInviteComplete &Delegate) override;

        virtual bool AcceptInvite(int32 LocalUserNum, const FUniqueNetId &FriendId, const FString &ListName, const FOnAcceptInviteComplete &Delegate) override;

        virtual bool RejectInvite(int32 LocalUserNum, const FUniqueNetId &FriendId, const FString &ListName) override;

        virtual bool DeleteFriend(int32 LocalUserNum, const FUniqueNetId &FriendId, const FString &ListName) override;

        virtual bool GetFriendsList(int32 LocalUserNum, const FString &ListName, TArray<TSharedRef<FOnlineFriend> > &OutFriends) override;

        virtual TSharedPtr<FOnlineFriend> GetFriend(int32 LocalUserNum, const FUniqueNetId &FriendId, const FString &ListName) override;

        virtual bool IsFriend(int32 LocalUserNum, const FUniqueNetId &FriendId, const FString &ListName) override;

        virtual bool QueryRecentPlayers(const FUniqueNetId &UserId, const FString &Namespace) override;

        virtual bool GetRecentPlayers(const FUniqueNetId &UserId, const FString &Namespace, TArray<TSharedRef<FOnlineRecentPlayer> > &OutRecentPlayers) override;

        #if GS_UE_VERSION >= GS_MAKE_VERSION(4,11)
            virtual bool BlockPlayer(int32 LocalUserNum, const FUniqueNetId &PlayerId) override;
            virtual bool UnblockPlayer(int32 LocalUserNum, const FUniqueNetId &PlayerId) override;
            virtual bool QueryBlockedPlayers(const FUniqueNetId &UserId) override;
            virtual bool GetBlockedPlayers(const FUniqueNetId &UserId, TArray<TSharedRef<FOnlineBlockedPlayer> > &OutBlockedPlayers) override;
        #endif

        #if GS_UE_VERSION >= GS_MAKE_VERSION(4,12)
            virtual void DumpBlockedPlayers() const override;
        #endif
    private:
        GameSparks::Core::GS& GetGSInstance(int32 LocalUserNum);

        typedef TMap<FUniqueNetIdString, TSharedRef<FOnlineFriend> > Cache;
        Cache cache;
};

typedef TSharedPtr<FOnlineFriendsInterfaceGameSparks, ESPMode::ThreadSafe> FOnlineFriendsInterfaceGameSparksPtr;
