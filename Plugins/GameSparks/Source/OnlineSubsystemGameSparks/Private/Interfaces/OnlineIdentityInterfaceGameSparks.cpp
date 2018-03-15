#include "OnlineIdentityInterfaceGameSparks.h"
#include "../OnlineSubsystemGameSparksPrivatePCH.h"
#include "GameSparksModule.h"
#include <GameSparks/generated/GSRequests.h>
#include "OnlineError.h"

// FOnlineIdentityInterfaceGameSparks

/**
 * Sets the needed configuration properties
 */
FOnlineIdentityInterfaceGameSparks::FOnlineIdentityInterfaceGameSparks()
	: bHasLoginOutstanding(false)
	, LocalUserNumPendingLogin(0)
    , bHasLogoutOutstanding(false)
    , LocalUserNumPendingLogout(0)
{}


/**
 * Obtain online account info for a user that has been registered
 *
 * @param UserId user to search for
 *
 * @return info about the user if found, NULL otherwise
 */
TSharedPtr<FUserOnlineAccount> FOnlineIdentityInterfaceGameSparks::GetUserAccount(const FUniqueNetId& UserId) const
{
	TSharedPtr<FUserOnlineAccount> Result;

	const TSharedRef<FUserOnlineAccountGameSparks>* FoundUserAccount = UserAccounts.Find(UserId.ToString());
	if (FoundUserAccount != NULL)
	{
		Result = *FoundUserAccount;
	}

	return Result;
}

/**
 * Obtain list of all known/registered user accounts
 *
 * @param UserId user to search for
 *
 * @return info about the user if found, NULL otherwise
 */
TArray<TSharedPtr<FUserOnlineAccount> > FOnlineIdentityInterfaceGameSparks::GetAllUserAccounts() const
{
	TArray<TSharedPtr<FUserOnlineAccount> > Result;
	
	for (FUserOnlineAccountGameSparksMap::TConstIterator It(UserAccounts); It; ++It)
	{
		Result.Add(It.Value());
	}

	return Result;
}


TSharedPtr<const FUniqueNetId> FOnlineIdentityInterfaceGameSparks::GetUniquePlayerId(int32 LocalUserNum) const
{
	const TSharedPtr<const FUniqueNetId>* FoundId = UserIds.Find(LocalUserNum);
	if (FoundId != NULL)
	{
		return *FoundId;
	}
	return NULL;
}


bool FOnlineIdentityInterfaceGameSparks::Login(int32 LocalUserNum, const FOnlineAccountCredentials& AccountCredentials)
{
	if (bHasLoginOutstanding)
	{
		const auto ErrorStr = FString::Printf(TEXT("Login() failed: already pending for user %d"), LocalUserNumPendingLogin);
        UE_LOG(LogOnline, Error, TEXT("Login() failed: %s"),  *ErrorStr);
        TriggerOnLoginCompleteDelegates(LocalUserNum, false, FUniqueNetIdString(TEXT("")), ErrorStr);
        return false;
	}

    if(UserIds.Num() > 0)
    {
        const FString ErrorStr = TEXT("GameSparks Identity Interface supports one logged in user only, please log-out any existing users before Loging in a new one.");
        UE_LOG(LogOnline, Error, TEXT("Login() failed: %s"),  *ErrorStr);
        TriggerOnLoginCompleteDelegates(LocalUserNum, false, FUniqueNetIdString(TEXT("")), ErrorStr);
        return false;
    }

    // keep track of local user requesting registration
    LocalUserNumPendingLogin = LocalUserNum;
    bHasLoginOutstanding = true;

    auto AuthenticationRequest_Response = [=](GameSparks::Core::GS& gs, const GameSparks::Api::Responses::AuthenticationResponse& authResponse)
    {
        bHasLoginOutstanding = false;

        if(authResponse.GetHasErrors())
        {
            TriggerOnLoginCompleteDelegates(LocalUserNum, false, FUniqueNetIdString(TEXT("")), authResponse.GetErrors().GetValue().GetJSON().c_str());
        }
        else
        {
            TSharedRef<FUserOnlineAccountGameSparks> UserRef(new FUserOnlineAccountGameSparks(authResponse));
			UserIds.Add(LocalUserNum, UserRef->UserIdPtr);
            UserAccounts.Add(UserRef->response.GetUserId().GetValue().c_str(), UserRef);
            TriggerOnLoginCompleteDelegates(LocalUserNum, true, FUniqueNetIdString(authResponse.GetAuthToken().GetValue().c_str()), TEXT(""));
        }
    };

    GameSparks::Core::GS& gs = UGameSparksModule::GetModulePtr()->GetGSInstance();

    if(AccountCredentials.Type == "GSDevice")
    {
        GameSparks::Api::Requests::DeviceAuthenticationRequest authRequest(gs);
        authRequest.SetDeviceOS(gs.GetDeviceOS());
        authRequest.SetDeviceId(gs.GetDeviceId()); // generate a random device id (for easy testing)
        authRequest.Send(AuthenticationRequest_Response);
    }
    else if(AccountCredentials.Type == "GSCredentials")
    {
        GameSparks::Api::Requests::AuthenticationRequest authRequest(gs);
        authRequest.SetUserName(TCHAR_TO_UTF8(*AccountCredentials.Id));
        authRequest.SetPassword(TCHAR_TO_UTF8(*AccountCredentials.Token));
        authRequest.Send(AuthenticationRequest_Response);
    }
    else if(AccountCredentials.Type == "GSAmazon")
    {
        GameSparks::Api::Requests::AmazonConnectRequest authRequest(gs);
        authRequest.SetAccessToken(TCHAR_TO_UTF8(*AccountCredentials.Token));
        authRequest.Send(AuthenticationRequest_Response);
    }
    else if(AccountCredentials.Type == "GSFacebook")
    {
        GameSparks::Api::Requests::FacebookConnectRequest authRequest(gs);
        authRequest.SetAccessToken(TCHAR_TO_UTF8(*AccountCredentials.Token));
        authRequest.Send(AuthenticationRequest_Response);
    }
    else if(AccountCredentials.Type == "GSGameCenter")
    {
        GameSparks::Api::Requests::GameCenterConnectRequest authRequest(gs);
        authRequest.Send(AuthenticationRequest_Response);
    }
    else if(AccountCredentials.Type == "GSGooglePlay")
    {
        GameSparks::Api::Requests::GooglePlayConnectRequest authRequest(gs);
        authRequest.SetAccessToken(TCHAR_TO_UTF8(*AccountCredentials.Token));
        authRequest.Send(AuthenticationRequest_Response);
    }
    else if(AccountCredentials.Type == "GSGooglePlus")
    {
        GameSparks::Api::Requests::GooglePlusConnectRequest authRequest(gs);
        authRequest.SetAccessToken(TCHAR_TO_UTF8(*AccountCredentials.Token));
        authRequest.Send(AuthenticationRequest_Response);
    }
    else if(AccountCredentials.Type == "GSKongregate")
    {
        GameSparks::Api::Requests::KongregateConnectRequest authRequest(gs);
        authRequest.Send(AuthenticationRequest_Response);
    }
    else if(AccountCredentials.Type == "GSPSN")
    {
        GameSparks::Api::Requests::PSNConnectRequest authRequest(gs);
        authRequest.SetAuthorizationCode(TCHAR_TO_UTF8(*AccountCredentials.Token));
        authRequest.Send(AuthenticationRequest_Response);
    }
    else if(AccountCredentials.Type == "GSQQ")
    {
        GameSparks::Api::Requests::QQConnectRequest authRequest(gs);
        authRequest.SetAccessToken(TCHAR_TO_UTF8(*AccountCredentials.Token));
        authRequest.Send(AuthenticationRequest_Response);
    }
    else if(AccountCredentials.Type == "GSSteam")
    {
        GameSparks::Api::Requests::SteamConnectRequest authRequest(gs);
        authRequest.Send(AuthenticationRequest_Response);
    }
    else if(AccountCredentials.Type == "GSTwitch")
    {
        GameSparks::Api::Requests::TwitchConnectRequest authRequest(gs);
        authRequest.SetAccessToken(TCHAR_TO_UTF8(*AccountCredentials.Token));
        authRequest.Send(AuthenticationRequest_Response);
    }
    else if(AccountCredentials.Type == "GSTwitter")
    {
        GameSparks::Api::Requests::TwitterConnectRequest authRequest(gs);
        authRequest.SetAccessToken(TCHAR_TO_UTF8(*AccountCredentials.Id));
        authRequest.SetAccessSecret(TCHAR_TO_UTF8(*AccountCredentials.Token));
        authRequest.Send(AuthenticationRequest_Response);
    }
    else if(AccountCredentials.Type == "GSViber")
    {
        GameSparks::Api::Requests::ViberConnectRequest authRequest(gs);
        authRequest.SetAccessToken(TCHAR_TO_UTF8(*AccountCredentials.Token));
        authRequest.Send(AuthenticationRequest_Response);
    }
    else if(AccountCredentials.Type == "GSWeChat")
    {
        GameSparks::Api::Requests::WeChatConnectRequest authRequest(gs);
        authRequest.SetAccessToken(TCHAR_TO_UTF8(*AccountCredentials.Token));
        authRequest.Send(AuthenticationRequest_Response);
    }
    else if(AccountCredentials.Type == "GSXBOXLive")
    {
        GameSparks::Api::Requests::XBOXLiveConnectRequest authRequest(gs);
        authRequest.Send(AuthenticationRequest_Response);
    }
    else
    {
        UE_LOG(LogOnline, Error, TEXT("OnlineSubsystem GameSparks: AccountCredentials.Type must be one of [GSAmazon, GSCredentials, GSDevice, GSFacebook, GSGameCenter, GSGooglePlay, GSGooglePlus, GSKongregate, GSPSN, GSQQ, GSRegis, GSSteam, GSTwitch, GSTwitter, GSViber, GSWeChat, GSXBOXLive]."));
        return false;
    }

	return true;
}


TSharedPtr<const FUniqueNetId> FOnlineIdentityInterfaceGameSparks::CreateUniquePlayerId(uint8* Bytes, int32 Size)
{
	if (Bytes != NULL && Size > 0)
	{
		FString StrId(Size, (TCHAR*)Bytes);
		return MakeShareable(new FUniqueNetIdString(StrId));
	}
	return NULL;
}


TSharedPtr<const FUniqueNetId> FOnlineIdentityInterfaceGameSparks::CreateUniquePlayerId(const FString& Str)
{
	return MakeShareable(new FUniqueNetIdString(Str));
}

bool FOnlineIdentityInterfaceGameSparks::Logout(int32 LocalUserNum)
{
    if (bHasLogoutOutstanding)
    {
        const auto ErrorStr = FString::Printf(TEXT("Logout already pending for user %d"),  LocalUserNumPendingLogout);
        UE_LOG(LogOnline, Error, TEXT("Logout() failed: %s"), *ErrorStr);
        TriggerOnLogoutCompleteDelegates(LocalUserNum, false);
        return false;
    }
    else
    {
        // keep track of local user requesting registration
        LocalUserNumPendingLogout = LocalUserNum;
        bHasLogoutOutstanding = true;
    }

	TSharedPtr<const FUniqueNetId> UserId = GetUniquePlayerId(LocalUserNum);
	if (UserId.IsValid())
	{
        TSharedPtr<FUserOnlineAccount> UserAccount = GetUserAccount(*UserId.Get());
        GameSparks::Core::GS& gs = UGameSparksModule::GetModulePtr()->GetGSInstance();
        GameSparks::Api::Requests::EndSessionRequest request(gs);
        request.Send([=](GameSparks::Core::GS& gs2, const GameSparks::Api::Responses::EndSessionResponse& response)
        {
            bHasLogoutOutstanding = false;

            if(response.GetHasErrors())
            {
                TriggerOnLogoutCompleteDelegates(LocalUserNum, false);
            }
            else
            {
                // remove cached user account
                UserAccounts.Remove(UserId->ToString());
                // remove cached user id
                UserIds.Remove(LocalUserNum);

                // reset GS-Instance, so that session-id, auth-toke, etc. are cleared
                gs2.Reset();

                TriggerOnLogoutCompleteDelegates(LocalUserNum, true);
            }
        });

		return true;
	}
	else
	{
		UE_LOG(LogOnline, Warning, TEXT("No logged in user found for LocalUserNum=%d."), LocalUserNum);
		TriggerOnLogoutCompleteDelegates(LocalUserNum, false);
	}
	return false;
}


bool FOnlineIdentityInterfaceGameSparks::AutoLogin(int32 LocalUserNum)
{
	return false;
}


ELoginStatus::Type FOnlineIdentityInterfaceGameSparks::GetLoginStatus(int32 LocalUserNum) const
{
	TSharedPtr<const FUniqueNetId> UserId = GetUniquePlayerId(LocalUserNum);
	if (UserId.IsValid())
	{
		return GetLoginStatus(*UserId);
	}
	return ELoginStatus::NotLoggedIn;
}


ELoginStatus::Type FOnlineIdentityInterfaceGameSparks::GetLoginStatus(const FUniqueNetId& UserId) const
{
	TSharedPtr<FUserOnlineAccount> UserAccount = GetUserAccount(UserId);
	if (UserAccount.IsValid() &&
		UserAccount->GetUserId()->IsValid() &&
		!UserAccount->GetAccessToken().IsEmpty())
	{
		return ELoginStatus::LoggedIn;
	}
	return ELoginStatus::NotLoggedIn;
}


FString FOnlineIdentityInterfaceGameSparks::GetPlayerNickname(int32 LocalUserNum) const
{
	TSharedPtr<const FUniqueNetId> UserId = GetUniquePlayerId(LocalUserNum);
	if (UserId.IsValid())
	{
		return  GetPlayerNickname(*UserId);
	}
	return TEXT("");
}


FString FOnlineIdentityInterfaceGameSparks::GetPlayerNickname(const FUniqueNetId& UserId) const
{
	const TSharedRef<FUserOnlineAccountGameSparks>* FoundUserAccount = UserAccounts.Find(UserId.ToString());
	if (FoundUserAccount != NULL)
	{
		const TSharedRef<FUserOnlineAccountGameSparks>& UserAccount = *FoundUserAccount;
		return UserAccount->GetDisplayName();
	}
	return TEXT("");
}


FString FOnlineIdentityInterfaceGameSparks::GetAuthToken(int32 LocalUserNum) const
{
	TSharedPtr<const FUniqueNetId> UserId = GetUniquePlayerId(LocalUserNum);
	if (UserId.IsValid())
	{
		TSharedPtr<FUserOnlineAccount> UserAccount = GetUserAccount(*UserId);
		if (UserAccount.IsValid())
		{
			return UserAccount->GetAccessToken();
		}
	}
	return FString();
}


void FOnlineIdentityInterfaceGameSparks::GetUserPrivilege(const FUniqueNetId& UserId, EUserPrivileges::Type Privilege, const FOnGetUserPrivilegeCompleteDelegate& Delegate)
{
	Delegate.ExecuteIfBound(UserId, Privilege, (uint32)EPrivilegeResults::NoFailures);
}


#if GS_UE_VERSION >= GS_MAKE_VERSION(4,18) // const was added in 4.18
FPlatformUserId FOnlineIdentityInterfaceGameSparks::GetPlatformUserIdFromUniqueNetId(const FUniqueNetId& UniqueNetId) const
#else
FPlatformUserId FOnlineIdentityInterfaceGameSparks::GetPlatformUserIdFromUniqueNetId(const FUniqueNetId& UniqueNetId)
#endif
{
	for (int i = 0; i < MAX_LOCAL_PLAYERS; ++i)
	{
		auto CurrentUniqueId = GetUniquePlayerId(i);
		if (CurrentUniqueId.IsValid() && (*CurrentUniqueId == UniqueNetId))
		{
			return i;
		}
	}

	return PLATFORMUSERID_NONE;
}

#if GS_UE_VERSION >= GS_MAKE_VERSION(4,18) // API changed in 4.18
void FOnlineIdentityInterfaceGameSparks::RevokeAuthToken(const FUniqueNetId& UserId, const FOnRevokeAuthTokenCompleteDelegate& Delegate)
{
    // Not Implemented
    Delegate.ExecuteIfBound(UserId, FOnlineError("RevokeAuthToken Not Implemented"));
}
#endif

#if GS_UE_VERSION > GS_MAKE_VERSION(4,10)
FString FOnlineIdentityInterfaceGameSparks::GetAuthType() const
{
	return TEXT("");
}
#endif
