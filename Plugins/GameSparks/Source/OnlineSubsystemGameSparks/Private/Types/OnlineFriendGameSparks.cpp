#include "OnlineFriendGameSparks.h"
#include "../OnlineSubsystemGameSparksPrivatePCH.h"

FOnlineFriendGameSparks::FOnlineFriendGameSparks(const GameSparks::Api::Types::Player& player_)
:player(player_)
,id(MakeShareable( new FUniqueNetIdString(player_.GetId().GetValue().c_str())))
{ }

FOnlineFriendGameSparks::~FOnlineFriendGameSparks() { }

TSharedRef<const FUniqueNetId> FOnlineFriendGameSparks::GetUserId() const
{
    return id;
}

FString FOnlineFriendGameSparks::GetRealName() const
{
    return GetDisplayName();
}

#if GS_UE_VERSION >= GS_MAKE_VERSION(4,12)
FString FOnlineFriendGameSparks::GetDisplayName(const FString& Platform) const
#else
FString FOnlineFriendGameSparks::GetDisplayName() const
#endif
{
    return player.GetDisplayName().GetValue().c_str();
}

bool FOnlineFriendGameSparks::GetUserAttribute(const FString &AttrName, FString &OutAttrValue) const
{
    return false;
}

EInviteStatus::Type FOnlineFriendGameSparks::GetInviteStatus() const
{
    return EInviteStatus::Unknown;
}

const FOnlineUserPresence& FOnlineFriendGameSparks::GetPresence() const
{
    return presence;
}
