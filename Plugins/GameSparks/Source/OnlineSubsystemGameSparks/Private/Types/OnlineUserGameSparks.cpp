#include "OnlineUserGameSparks.h"
#include "../OnlineSubsystemGameSparksPrivatePCH.h"


FOnlineUserGameSparks::FOnlineUserGameSparks(const GameSparks::Api::Types::Player& player_)
:player(player_)
,id(MakeShareable( new FUniqueNetIdString(player_.GetId().GetValue().c_str())))
{ }


/**
 * destructor
 */
FOnlineUserGameSparks::~FOnlineUserGameSparks() { }


/**
 * @return Id associated with the user account provided by the online service during registration
 */
TSharedRef<const FUniqueNetId> FOnlineUserGameSparks::GetUserId() const
{
    return id;
}


/**
 * @return the real name for the user if known
 */
FString FOnlineUserGameSparks::GetRealName() const
{
    return GetDisplayName();
}


/**
 * @return the nickname of the user if known
 */
#if GS_UE_VERSION >= GS_MAKE_VERSION(4,12)
FString FOnlineUserGameSparks::GetDisplayName(const FString& Platform) const
#else
FString FOnlineUserGameSparks::GetDisplayName() const
#endif
{
    return player.GetDisplayName().GetValue().c_str();
}


/**
 * @return Any additional user data associated with a registered user
 */
bool FOnlineUserGameSparks::GetUserAttribute(const FString& AttrName, FString& OutAttrValue) const
{
    return false;
}
