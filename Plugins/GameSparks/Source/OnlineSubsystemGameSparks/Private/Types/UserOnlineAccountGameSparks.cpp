#include "UserOnlineAccountGameSparks.h"
#include "../OnlineSubsystemGameSparksPrivatePCH.h"


// FUserOnlineAccountGameSparks
//

TSharedRef<const FUniqueNetId> FUserOnlineAccountGameSparks::GetUserId() const
{
    return UserIdPtr;
}

FString FUserOnlineAccountGameSparks::GetRealName() const
{
    return FString();
}

#if GS_UE_VERSION >= GS_MAKE_VERSION(4,12)
FString FUserOnlineAccountGameSparks::GetDisplayName(const FString& Platform) const
#else
FString FUserOnlineAccountGameSparks::GetDisplayName() const
#endif
{
    if(response.GetDisplayName().GetValue().empty())
        return "Anonymous"; // might be empty, for example if device authenticated
    else
        return response.GetDisplayName().GetValue().c_str();
}

#if GS_UE_VERSION >= GS_MAKE_VERSION(4,11)
bool FUserOnlineAccountGameSparks::SetUserAttribute(const FString& AttrName, const FString& AttrValue)
{
    return false;
}
#endif

bool FUserOnlineAccountGameSparks::GetUserAttribute(const FString& AttrName, FString& OutAttrValue) const
{
    // TODO: query ScriptData
    return false;
}


FString FUserOnlineAccountGameSparks::GetAccessToken() const
{
    return response.GetAuthToken().GetValue().c_str();
}

bool FUserOnlineAccountGameSparks::GetAuthAttribute(const FString& AttrName, FString& OutAttrValue) const
{
    return false;
}
