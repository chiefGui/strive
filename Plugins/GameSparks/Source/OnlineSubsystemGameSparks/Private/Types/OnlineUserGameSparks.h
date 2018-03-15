#pragma once

#include "../OnlineSubsystemGameSparksPrivatePCH.h"
#include <GameSparks/generated/GSTypes.h>

class FOnlineUserGameSparks : public FOnlineUser
{
public:
    FOnlineUserGameSparks(const GameSparks::Api::Types::Player& player);

    /**
     * destructor
     */
    virtual ~FOnlineUserGameSparks();

    /**
     * @return Id associated with the user account provided by the online service during registration
     */
    virtual TSharedRef<const FUniqueNetId> GetUserId() const override;
    /**
     * @return the real name for the user if known
     */
    virtual FString GetRealName() const override;
    /**
     * @return the nickname of the user if known
     */
    #if GS_UE_VERSION >= GS_MAKE_VERSION(4,12)
    virtual FString GetDisplayName(const FString& Platform = FString()) const override;
    #else
    virtual FString GetDisplayName() const override ;
    #endif
    /**
     * @return Any additional user data associated with a registered user
     */
    virtual bool GetUserAttribute(const FString& AttrName, FString& OutAttrValue) const override;

private:
    GameSparks::Api::Types::Player player;
    TSharedRef<FUniqueNetIdString> id;
};
