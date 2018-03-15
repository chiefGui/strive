#pragma once
#include "../OnlineSubsystemGameSparksPrivatePCH.h"
#include "OnlineSubsystemTypes.h"
#include <GameSparks/generated/GSTypes.h>
#include "OnlinePresenceInterface.h"

class FOnlineFriendGameSparks : public FOnlineFriend
{
public:
    FOnlineFriendGameSparks(const GameSparks::Api::Types::Player& player);
    virtual ~FOnlineFriendGameSparks() override;


    virtual TSharedRef<const FUniqueNetId> GetUserId() const override;

    virtual FString GetRealName() const override;

    #if GS_UE_VERSION >= GS_MAKE_VERSION(4,12)
        virtual FString GetDisplayName(const FString& Platform = FString()) const override;
    #else
        virtual FString GetDisplayName() const override;
    #endif

    virtual bool GetUserAttribute(const FString &AttrName, FString &OutAttrValue) const override;

    virtual EInviteStatus::Type GetInviteStatus() const override;

    virtual const class FOnlineUserPresence &GetPresence() const override;

private:
    GameSparks::Api::Types::Player player;
    TSharedRef<FUniqueNetIdString> id;
    FOnlineUserPresence presence;
};
