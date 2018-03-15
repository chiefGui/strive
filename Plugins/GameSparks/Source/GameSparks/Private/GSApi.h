#pragma once
#include "GameSparksLogEventData.h"
#include "GameSparksScriptData.h"
#include "GSTypes.h"
#include "GameSparks/generated/GSRequests.h"
#include "GameSparksModule.h"
#include "OnlineBlueprintCallProxyBase.h"
#include "GameSparksRequestArray.h"
#include "GSApi.generated.h"


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAcceptChallengeRequest_Response, FGSAcceptChallengeResponse, AcceptChallengeResponse, bool, hasErrors);

UCLASS()
class GAMESPARKS_API UGSAcceptChallengeRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnAcceptChallengeRequest_Response OnResponse;
	
	/**
	Accepts a challenge that has been issued to the current player.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS AcceptChallengeRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Multiplayer")
	static UGSAcceptChallengeRequest* SendAcceptChallengeRequest(FString ChallengeInstanceId = "", FString Message = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);

	/**
	Accepts a challenge that has been issued to the current player.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS AcceptChallengeRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks Server-side|Requests|Multiplayer")
	static UGSAcceptChallengeRequest* SendAcceptChallengeRequestOnBehalfOf(const FString& PlayerId, FString ChallengeInstanceId = "", FString Message = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSAcceptChallengeRequest();

private:
	
	UPROPERTY()
	FString challengeInstanceId;
	
	UPROPERTY()
	FString message;


	UPROPERTY()
	UGameSparksScriptData* scriptData;
	
	UPROPERTY()
	bool durable;
	
	UPROPERTY()
	int32 requestTimeoutSeconds;

	UPROPERTY()
	FString playerId;
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAccountDetailsRequest_Response, FGSAccountDetailsResponse, AccountDetailsResponse, bool, hasErrors);

UCLASS()
class GAMESPARKS_API UGSAccountDetailsRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnAccountDetailsRequest_Response OnResponse;
	
	/**
	Retrieves the details of the current authenticated player.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS AccountDetailsRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Player")
	static UGSAccountDetailsRequest* SendAccountDetailsRequest( UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);

	/**
	Retrieves the details of the current authenticated player.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS AccountDetailsRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks Server-side|Requests|Player")
	static UGSAccountDetailsRequest* SendAccountDetailsRequestOnBehalfOf(const FString& PlayerId,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSAccountDetailsRequest();

private:


	UPROPERTY()
	UGameSparksScriptData* scriptData;
	
	UPROPERTY()
	bool durable;
	
	UPROPERTY()
	int32 requestTimeoutSeconds;

	UPROPERTY()
	FString playerId;
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAmazonBuyGoodsRequest_Response, FGSBuyVirtualGoodResponse, BuyVirtualGoodResponse, bool, hasErrors);

UCLASS()
class GAMESPARKS_API UGSAmazonBuyGoodsRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnAmazonBuyGoodsRequest_Response OnResponse;
	
	/**
	Processes the receipt from an Amazon in app purchase.
	The GameSparks platform will validate the amazonUserId and receiptId with Amazon using the Amazon Purchase Secret configured against the game.
	The receiptId in the data will be recorded and the request will be rejected if the receiptId has previously been processed, this prevents replay attacks.
	Once verfied, the players account will be credited with the Virtual Good, or Virtual Currency the purchase contains. The virtual good will be looked up by matching the productId in the receipt with the 'Amazon Product Id' configured against the virtual good.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS AmazonBuyGoodsRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Store")
	static UGSAmazonBuyGoodsRequest* SendAmazonBuyGoodsRequest(FString AmazonUserId = "", FString CurrencyCode = "", FString ReceiptId = "", float SubUnitPrice = 0.0f, bool UniqueTransactionByPlayer = false,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);

	/**
	Processes the receipt from an Amazon in app purchase.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	The GameSparks platform will validate the amazonUserId and receiptId with Amazon using the Amazon Purchase Secret configured against the game.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	The receiptId in the data will be recorded and the request will be rejected if the receiptId has previously been processed, this prevents replay attacks.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	Once verfied, the players account will be credited with the Virtual Good, or Virtual Currency the purchase contains. The virtual good will be looked up by matching the productId in the receipt with the 'Amazon Product Id' configured against the virtual good.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS AmazonBuyGoodsRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks Server-side|Requests|Store")
	static UGSAmazonBuyGoodsRequest* SendAmazonBuyGoodsRequestOnBehalfOf(const FString& PlayerId, FString AmazonUserId = "", FString CurrencyCode = "", FString ReceiptId = "", float SubUnitPrice = 0.0f, bool UniqueTransactionByPlayer = false,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSAmazonBuyGoodsRequest();

private:
	
	UPROPERTY()
	FString amazonUserId;
	
	UPROPERTY()
	FString currencyCode;
	
	UPROPERTY()
	FString receiptId;

	
	UPROPERTY()
	float subUnitPrice;
	
	UPROPERTY()
	bool uniqueTransactionByPlayer;

	UPROPERTY()
	UGameSparksScriptData* scriptData;
	
	UPROPERTY()
	bool durable;
	
	UPROPERTY()
	int32 requestTimeoutSeconds;

	UPROPERTY()
	FString playerId;
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAmazonConnectRequest_Response, FGSAuthenticationResponse, AuthenticationResponse, bool, hasErrors);

UCLASS()
class GAMESPARKS_API UGSAmazonConnectRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnAmazonConnectRequest_Response OnResponse;
	
	/**
	Allows an Amazon access token to be used as an authentication mechanism.
	Once authenticated the platform can determine the current players details from the Amazon platform and store them within GameSparks.
	If the Amazon user is already linked to a player, the current session will switch to the linked player.
	If the current player has previously created an account using either DeviceAuthentictionRequest or RegistrationRequest AND the Amazon user is not already registered with the game, the Amazon user will be linked to the current player.
	If the current player has not authenticated and the Amazon user is not known, a new player will be created using the Amazon details and the session will be authenticated against the new player.
	If the Amazon user is already known, the session will switch to being the previously created user.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS AmazonConnectRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Authentication")
	static UGSAmazonConnectRequest* SendAmazonConnectRequest(FString AccessToken = "", bool DoNotLinkToCurrentPlayer = false, bool ErrorOnSwitch = false, UGameSparksScriptData* Segments = nullptr, bool SwitchIfPossible = false, bool SyncDisplayName = false,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);

	/**
	Allows an Amazon access token to be used as an authentication mechanism.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	Once authenticated the platform can determine the current players details from the Amazon platform and store them within GameSparks.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	If the Amazon user is already linked to a player, the current session will switch to the linked player.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	If the current player has previously created an account using either DeviceAuthentictionRequest or RegistrationRequest AND the Amazon user is not already registered with the game, the Amazon user will be linked to the current player.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	If the current player has not authenticated and the Amazon user is not known, a new player will be created using the Amazon details and the session will be authenticated against the new player.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	If the Amazon user is already known, the session will switch to being the previously created user.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS AmazonConnectRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks Server-side|Requests|Authentication")
	static UGSAmazonConnectRequest* SendAmazonConnectRequestOnBehalfOf(const FString& PlayerId, FString AccessToken = "", bool DoNotLinkToCurrentPlayer = false, bool ErrorOnSwitch = false, UGameSparksScriptData* Segments = nullptr, bool SwitchIfPossible = false, bool SyncDisplayName = false,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSAmazonConnectRequest();

private:
	
	UPROPERTY()
	FString accessToken;
	
	UPROPERTY()
	bool doNotLinkToCurrentPlayer;
	
	UPROPERTY()
	bool errorOnSwitch;

	
	UPROPERTY()
	UGameSparksScriptData* segments;
	
	UPROPERTY()
	bool switchIfPossible;
	
	UPROPERTY()
	bool syncDisplayName;

	UPROPERTY()
	UGameSparksScriptData* scriptData;
	
	UPROPERTY()
	bool durable;
	
	UPROPERTY()
	int32 requestTimeoutSeconds;

	UPROPERTY()
	FString playerId;
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAnalyticsRequest_Response, FGSAnalyticsResponse, AnalyticsResponse, bool, hasErrors);

UCLASS()
class GAMESPARKS_API UGSAnalyticsRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnAnalyticsRequest_Response OnResponse;
	
	/**
	Records some custom analytical data.
	Simple analytics, where you just need to track the number of times something happened, just take a key parameter. We'll record the players id against the data to allow you to report on averages per user
	Timed analytics allow you to send start and end timer requests, and with this data GameSparks can track the length of time something takes.
	If an end request is sent without a matching start timer the request will fail silently and your analytics data might not contain what you expect.
	If both start and end are supplied, the request will be treated as a start timer.
	An additional data payload can be attached to the event for advanced reporting. This data can be a string, number or JSON object.
	If a second start timer is created using a key that has already had a start timer created without an end, the previous one will be marked as abandoned.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS AnalyticsRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Analytics")
	static UGSAnalyticsRequest* SendAnalyticsRequest(UGameSparksScriptData* Data = nullptr, bool End = false, FString Key = "", bool Start = false,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);

	/**
	Records some custom analytical data.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	Simple analytics, where you just need to track the number of times something happened, just take a key parameter. We'll record the players id against the data to allow you to report on averages per user

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	Timed analytics allow you to send start and end timer requests, and with this data GameSparks can track the length of time something takes.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	If an end request is sent without a matching start timer the request will fail silently and your analytics data might not contain what you expect.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	If both start and end are supplied, the request will be treated as a start timer.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	An additional data payload can be attached to the event for advanced reporting. This data can be a string, number or JSON object.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	If a second start timer is created using a key that has already had a start timer created without an end, the previous one will be marked as abandoned.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS AnalyticsRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks Server-side|Requests|Analytics")
	static UGSAnalyticsRequest* SendAnalyticsRequestOnBehalfOf(const FString& PlayerId, UGameSparksScriptData* Data = nullptr, bool End = false, FString Key = "", bool Start = false,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSAnalyticsRequest();

private:
	
	UPROPERTY()
	UGameSparksScriptData* data;
	
	UPROPERTY()
	bool end;
	
	UPROPERTY()
	FString key;

	
	UPROPERTY()
	bool start;

	UPROPERTY()
	UGameSparksScriptData* scriptData;
	
	UPROPERTY()
	bool durable;
	
	UPROPERTY()
	int32 requestTimeoutSeconds;

	UPROPERTY()
	FString playerId;
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAroundMeLeaderboardRequest_Response, FGSAroundMeLeaderboardResponse, AroundMeLeaderboardResponse, bool, hasErrors);

UCLASS()
class GAMESPARKS_API UGSAroundMeLeaderboardRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnAroundMeLeaderboardRequest_Response OnResponse;
	
	/**
	Returns leaderboard data that is adjacent to the currently signed in player's position within the given leaderboard.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS AroundMeLeaderboardRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Leaderboards")
	static UGSAroundMeLeaderboardRequest* SendAroundMeLeaderboardRequest(FString ChallengeInstanceId = "", UGameSparksScriptData* CustomIdFilter = nullptr, bool DontErrorOnNotSocial = false, int32 EntryCount = 0, UGameSparksRequestArray* FriendIds = nullptr, int32 IncludeFirst = 0, int32 IncludeLast = 0, bool InverseSocial = false, FString LeaderboardShortCode = "", bool Social = false, UGameSparksRequestArray* TeamIds = nullptr, UGameSparksRequestArray* TeamTypes = nullptr,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);

	/**
	Returns leaderboard data that is adjacent to the currently signed in player's position within the given leaderboard.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS AroundMeLeaderboardRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks Server-side|Requests|Leaderboards")
	static UGSAroundMeLeaderboardRequest* SendAroundMeLeaderboardRequestOnBehalfOf(const FString& PlayerId, FString ChallengeInstanceId = "", UGameSparksScriptData* CustomIdFilter = nullptr, bool DontErrorOnNotSocial = false, int32 EntryCount = 0, UGameSparksRequestArray* FriendIds = nullptr, int32 IncludeFirst = 0, int32 IncludeLast = 0, bool InverseSocial = false, FString LeaderboardShortCode = "", bool Social = false, UGameSparksRequestArray* TeamIds = nullptr, UGameSparksRequestArray* TeamTypes = nullptr,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSAroundMeLeaderboardRequest();

private:
	
	UPROPERTY()
	FString challengeInstanceId;
	
	UPROPERTY()
	UGameSparksScriptData* customIdFilter;
	
	UPROPERTY()
	bool dontErrorOnNotSocial;
	
	UPROPERTY()
	int32 entryCount;
	
	UPROPERTY()
	UGameSparksRequestArray* friendIds;
	
	UPROPERTY()
	int32 includeFirst;
	
	UPROPERTY()
	int32 includeLast;
	
	UPROPERTY()
	bool inverseSocial;
	
	UPROPERTY()
	FString leaderboardShortCode;

	
	UPROPERTY()
	bool social;
	
	UPROPERTY()
	UGameSparksRequestArray* teamIds;
	
	UPROPERTY()
	UGameSparksRequestArray* teamTypes;

	UPROPERTY()
	UGameSparksScriptData* scriptData;
	
	UPROPERTY()
	bool durable;
	
	UPROPERTY()
	int32 requestTimeoutSeconds;

	UPROPERTY()
	FString playerId;
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAuthenticationRequest_Response, FGSAuthenticationResponse, AuthenticationResponse, bool, hasErrors);

UCLASS()
class GAMESPARKS_API UGSAuthenticationRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnAuthenticationRequest_Response OnResponse;
	
	/**
	Provides authentication using a username/password combination.
	The username will have been previously created using a RegistrationRequest.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS AuthenticationRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Authentication")
	static UGSAuthenticationRequest* SendAuthenticationRequest(FString Password = "", FString UserName = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);

	/**
	Provides authentication using a username/password combination.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	The username will have been previously created using a RegistrationRequest.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS AuthenticationRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks Server-side|Requests|Authentication")
	static UGSAuthenticationRequest* SendAuthenticationRequestOnBehalfOf(const FString& PlayerId, FString Password = "", FString UserName = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSAuthenticationRequest();

private:
	
	UPROPERTY()
	FString password;

	
	UPROPERTY()
	FString userName;

	UPROPERTY()
	UGameSparksScriptData* scriptData;
	
	UPROPERTY()
	bool durable;
	
	UPROPERTY()
	int32 requestTimeoutSeconds;

	UPROPERTY()
	FString playerId;
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnBatchAdminRequest_Response, FGSBatchAdminResponse, BatchAdminResponse, bool, hasErrors);

UCLASS()
class GAMESPARKS_API UGSBatchAdminRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnBatchAdminRequest_Response OnResponse;
	
	/**
	Performs a request for multiple players.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS BatchAdminRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Admin")
	static UGSBatchAdminRequest* SendBatchAdminRequest(UGameSparksRequestArray* PlayerIds = nullptr, UGameSparksScriptData* Request = nullptr,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);

	/**
	Performs a request for multiple players.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS BatchAdminRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks Server-side|Requests|Admin")
	static UGSBatchAdminRequest* SendBatchAdminRequestOnBehalfOf(const FString& PlayerId, UGameSparksRequestArray* PlayerIds = nullptr, UGameSparksScriptData* Request = nullptr,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSBatchAdminRequest();

private:
	
	UPROPERTY()
	UGameSparksRequestArray* playerIds;
	
	UPROPERTY()
	UGameSparksScriptData* request;


	UPROPERTY()
	UGameSparksScriptData* scriptData;
	
	UPROPERTY()
	bool durable;
	
	UPROPERTY()
	int32 requestTimeoutSeconds;

	UPROPERTY()
	FString playerId;
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnBuyVirtualGoodsRequest_Response, FGSBuyVirtualGoodResponse, BuyVirtualGoodResponse, bool, hasErrors);

UCLASS()
class GAMESPARKS_API UGSBuyVirtualGoodsRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnBuyVirtualGoodsRequest_Response OnResponse;
	
	/**
	Purchases a virtual good with an in game currency. Once purchased the virtual good will be added to the players account.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS BuyVirtualGoodsRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Store")
	static UGSBuyVirtualGoodsRequest* SendBuyVirtualGoodsRequest(FString CurrencyShortCode = "", int32 CurrencyType = 0, int32 Quantity = 0, FString ShortCode = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);

	/**
	Purchases a virtual good with an in game currency. Once purchased the virtual good will be added to the players account.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS BuyVirtualGoodsRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks Server-side|Requests|Store")
	static UGSBuyVirtualGoodsRequest* SendBuyVirtualGoodsRequestOnBehalfOf(const FString& PlayerId, FString CurrencyShortCode = "", int32 CurrencyType = 0, int32 Quantity = 0, FString ShortCode = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSBuyVirtualGoodsRequest();

private:
	
	UPROPERTY()
	FString currencyShortCode;
	
	UPROPERTY()
	int32 currencyType;
	
	UPROPERTY()
	int32 quantity;

	
	UPROPERTY()
	FString shortCode;

	UPROPERTY()
	UGameSparksScriptData* scriptData;
	
	UPROPERTY()
	bool durable;
	
	UPROPERTY()
	int32 requestTimeoutSeconds;

	UPROPERTY()
	FString playerId;
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCancelBulkJobAdminRequest_Response, FGSCancelBulkJobAdminResponse, CancelBulkJobAdminResponse, bool, hasErrors);

UCLASS()
class GAMESPARKS_API UGSCancelBulkJobAdminRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnCancelBulkJobAdminRequest_Response OnResponse;
	
	/**
	Cancel one or more bulk jobs.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS CancelBulkJobAdminRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Admin")
	static UGSCancelBulkJobAdminRequest* SendCancelBulkJobAdminRequest(UGameSparksRequestArray* BulkJobIds = nullptr,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);

	/**
	Cancel one or more bulk jobs.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS CancelBulkJobAdminRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks Server-side|Requests|Admin")
	static UGSCancelBulkJobAdminRequest* SendCancelBulkJobAdminRequestOnBehalfOf(const FString& PlayerId, UGameSparksRequestArray* BulkJobIds = nullptr,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSCancelBulkJobAdminRequest();

private:
	
	UPROPERTY()
	UGameSparksRequestArray* bulkJobIds;


	UPROPERTY()
	UGameSparksScriptData* scriptData;
	
	UPROPERTY()
	bool durable;
	
	UPROPERTY()
	int32 requestTimeoutSeconds;

	UPROPERTY()
	FString playerId;
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnChangeUserDetailsRequest_Response, FGSChangeUserDetailsResponse, ChangeUserDetailsResponse, bool, hasErrors);

UCLASS()
class GAMESPARKS_API UGSChangeUserDetailsRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnChangeUserDetailsRequest_Response OnResponse;
	
	/**
	Change the details of the currently signed in Player.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS ChangeUserDetailsRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Player")
	static UGSChangeUserDetailsRequest* SendChangeUserDetailsRequest(FString DisplayName = "", FString Language = "", FString NewPassword = "", FString OldPassword = "", FString UserName = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);

	/**
	Change the details of the currently signed in Player.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS ChangeUserDetailsRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks Server-side|Requests|Player")
	static UGSChangeUserDetailsRequest* SendChangeUserDetailsRequestOnBehalfOf(const FString& PlayerId, FString DisplayName = "", FString Language = "", FString NewPassword = "", FString OldPassword = "", FString UserName = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSChangeUserDetailsRequest();

private:
	
	UPROPERTY()
	FString displayName;
	
	UPROPERTY()
	FString language;
	
	UPROPERTY()
	FString newPassword;
	
	UPROPERTY()
	FString oldPassword;

	
	UPROPERTY()
	FString userName;

	UPROPERTY()
	UGameSparksScriptData* scriptData;
	
	UPROPERTY()
	bool durable;
	
	UPROPERTY()
	int32 requestTimeoutSeconds;

	UPROPERTY()
	FString playerId;
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnChatOnChallengeRequest_Response, FGSChatOnChallengeResponse, ChatOnChallengeResponse, bool, hasErrors);

UCLASS()
class GAMESPARKS_API UGSChatOnChallengeRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnChatOnChallengeRequest_Response OnResponse;
	
	/**
	Sends a message to all players involved in the challenge. The current player must be involved in the challenge for the message to be sent.
	As the message is sent to all players, the current player will also see details of the message in the response. Read the section on response message aggregation for a description of this.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS ChatOnChallengeRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Multiplayer")
	static UGSChatOnChallengeRequest* SendChatOnChallengeRequest(FString ChallengeInstanceId = "", FString Message = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);

	/**
	Sends a message to all players involved in the challenge. The current player must be involved in the challenge for the message to be sent.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	As the message is sent to all players, the current player will also see details of the message in the response. Read the section on response message aggregation for a description of this.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS ChatOnChallengeRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks Server-side|Requests|Multiplayer")
	static UGSChatOnChallengeRequest* SendChatOnChallengeRequestOnBehalfOf(const FString& PlayerId, FString ChallengeInstanceId = "", FString Message = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSChatOnChallengeRequest();

private:
	
	UPROPERTY()
	FString challengeInstanceId;
	
	UPROPERTY()
	FString message;


	UPROPERTY()
	UGameSparksScriptData* scriptData;
	
	UPROPERTY()
	bool durable;
	
	UPROPERTY()
	int32 requestTimeoutSeconds;

	UPROPERTY()
	FString playerId;
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnConsumeVirtualGoodRequest_Response, FGSConsumeVirtualGoodResponse, ConsumeVirtualGoodResponse, bool, hasErrors);

UCLASS()
class GAMESPARKS_API UGSConsumeVirtualGoodRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnConsumeVirtualGoodRequest_Response OnResponse;
	
	/**
	Consumes a given amount of the specified virtual good.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS ConsumeVirtualGoodRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Store")
	static UGSConsumeVirtualGoodRequest* SendConsumeVirtualGoodRequest(int32 Quantity = 0, FString ShortCode = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);

	/**
	Consumes a given amount of the specified virtual good.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS ConsumeVirtualGoodRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks Server-side|Requests|Store")
	static UGSConsumeVirtualGoodRequest* SendConsumeVirtualGoodRequestOnBehalfOf(const FString& PlayerId, int32 Quantity = 0, FString ShortCode = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSConsumeVirtualGoodRequest();

private:
	
	UPROPERTY()
	int32 quantity;

	
	UPROPERTY()
	FString shortCode;

	UPROPERTY()
	UGameSparksScriptData* scriptData;
	
	UPROPERTY()
	bool durable;
	
	UPROPERTY()
	int32 requestTimeoutSeconds;

	UPROPERTY()
	FString playerId;
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCreateChallengeRequest_Response, FGSCreateChallengeResponse, CreateChallengeResponse, bool, hasErrors);

UCLASS()
class GAMESPARKS_API UGSCreateChallengeRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnCreateChallengeRequest_Response OnResponse;
	
	/**
	Issues a challenge to a group of players from the currently signed in player.
	The endTime field must be present unless the challenge template has an achievement set in the 'First to Achievement' field.
	The usersToChallenge field must be present for this request if the acessType is PRIVATE (which is the default).
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS CreateChallengeRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Multiplayer")
	static UGSCreateChallengeRequest* SendCreateChallengeRequest(FString AccessType = "", bool AutoStartJoinedChallengeOnMaxPlayers = false, FString ChallengeMessage = "", FString ChallengeShortCode = "", int32 Currency1Wager = 0, int32 Currency2Wager = 0, int32 Currency3Wager = 0, int32 Currency4Wager = 0, int32 Currency5Wager = 0, int32 Currency6Wager = 0, UGameSparksScriptData* CurrencyWagers = nullptr, UGameSparksScriptData* EligibilityCriteria = nullptr, FString EndTime = "", FString ExpiryTime = "", int32 MaxAttempts = 0, int32 MaxPlayers = 0, int32 MinPlayers = 0, bool Silent = false, FString StartTime = "", UGameSparksRequestArray* UsersToChallenge = nullptr,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);

	/**
	Issues a challenge to a group of players from the currently signed in player.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	The endTime field must be present unless the challenge template has an achievement set in the 'First to Achievement' field.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	The usersToChallenge field must be present for this request if the acessType is PRIVATE (which is the default).

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS CreateChallengeRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks Server-side|Requests|Multiplayer")
	static UGSCreateChallengeRequest* SendCreateChallengeRequestOnBehalfOf(const FString& PlayerId, FString AccessType = "", bool AutoStartJoinedChallengeOnMaxPlayers = false, FString ChallengeMessage = "", FString ChallengeShortCode = "", int32 Currency1Wager = 0, int32 Currency2Wager = 0, int32 Currency3Wager = 0, int32 Currency4Wager = 0, int32 Currency5Wager = 0, int32 Currency6Wager = 0, UGameSparksScriptData* CurrencyWagers = nullptr, UGameSparksScriptData* EligibilityCriteria = nullptr, FString EndTime = "", FString ExpiryTime = "", int32 MaxAttempts = 0, int32 MaxPlayers = 0, int32 MinPlayers = 0, bool Silent = false, FString StartTime = "", UGameSparksRequestArray* UsersToChallenge = nullptr,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSCreateChallengeRequest();

private:
	
	UPROPERTY()
	FString accessType;
	
	UPROPERTY()
	bool autoStartJoinedChallengeOnMaxPlayers;
	
	UPROPERTY()
	FString challengeMessage;
	
	UPROPERTY()
	FString challengeShortCode;
	
	UPROPERTY()
	int32 currency1Wager;
	
	UPROPERTY()
	int32 currency2Wager;
	
	UPROPERTY()
	int32 currency3Wager;
	
	UPROPERTY()
	int32 currency4Wager;
	
	UPROPERTY()
	int32 currency5Wager;
	
	UPROPERTY()
	int32 currency6Wager;
	
	UPROPERTY()
	UGameSparksScriptData* currencyWagers;
	
	UPROPERTY()
	UGameSparksScriptData* eligibilityCriteria;
	
	UPROPERTY()
	FString endTime;
	
	UPROPERTY()
	FString expiryTime;
	
	UPROPERTY()
	int32 maxAttempts;
	
	UPROPERTY()
	int32 maxPlayers;
	
	UPROPERTY()
	int32 minPlayers;

	
	UPROPERTY()
	bool silent;
	
	UPROPERTY()
	FString startTime;
	
	UPROPERTY()
	UGameSparksRequestArray* usersToChallenge;

	UPROPERTY()
	UGameSparksScriptData* scriptData;
	
	UPROPERTY()
	bool durable;
	
	UPROPERTY()
	int32 requestTimeoutSeconds;

	UPROPERTY()
	FString playerId;
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCreateTeamRequest_Response, FGSCreateTeamResponse, CreateTeamResponse, bool, hasErrors);

UCLASS()
class GAMESPARKS_API UGSCreateTeamRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnCreateTeamRequest_Response OnResponse;
	
	/**
	Allows a new team to be created.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS CreateTeamRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Teams")
	static UGSCreateTeamRequest* SendCreateTeamRequest(FString TeamId = "", FString TeamName = "", FString TeamType = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);

	/**
	Allows a new team to be created.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS CreateTeamRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks Server-side|Requests|Teams")
	static UGSCreateTeamRequest* SendCreateTeamRequestOnBehalfOf(const FString& PlayerId, FString TeamId = "", FString TeamName = "", FString TeamType = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSCreateTeamRequest();

private:

	
	UPROPERTY()
	FString teamId;
	
	UPROPERTY()
	FString teamName;
	
	UPROPERTY()
	FString teamType;

	UPROPERTY()
	UGameSparksScriptData* scriptData;
	
	UPROPERTY()
	bool durable;
	
	UPROPERTY()
	int32 requestTimeoutSeconds;

	UPROPERTY()
	FString playerId;
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnDeclineChallengeRequest_Response, FGSDeclineChallengeResponse, DeclineChallengeResponse, bool, hasErrors);

UCLASS()
class GAMESPARKS_API UGSDeclineChallengeRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnDeclineChallengeRequest_Response OnResponse;
	
	/**
	Declines a challenge that has been issued to the current player.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS DeclineChallengeRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Multiplayer")
	static UGSDeclineChallengeRequest* SendDeclineChallengeRequest(FString ChallengeInstanceId = "", FString Message = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);

	/**
	Declines a challenge that has been issued to the current player.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS DeclineChallengeRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks Server-side|Requests|Multiplayer")
	static UGSDeclineChallengeRequest* SendDeclineChallengeRequestOnBehalfOf(const FString& PlayerId, FString ChallengeInstanceId = "", FString Message = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSDeclineChallengeRequest();

private:
	
	UPROPERTY()
	FString challengeInstanceId;
	
	UPROPERTY()
	FString message;


	UPROPERTY()
	UGameSparksScriptData* scriptData;
	
	UPROPERTY()
	bool durable;
	
	UPROPERTY()
	int32 requestTimeoutSeconds;

	UPROPERTY()
	FString playerId;
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnDeviceAuthenticationRequest_Response, FGSAuthenticationResponse, AuthenticationResponse, bool, hasErrors);

UCLASS()
class GAMESPARKS_API UGSDeviceAuthenticationRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnDeviceAuthenticationRequest_Response OnResponse;
	
	/**
	Allows a device id to be used to create an anonymous profile in the game.
	This allows the player to be tracked and have data stored against them before using FacebookConnectRequest to create a full profile.
	DeviceAuthenticationRequest should not be used in conjunction with RegistrationRequest as the two accounts will not be merged.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS DeviceAuthenticationRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Authentication")
	static UGSDeviceAuthenticationRequest* SendDeviceAuthenticationRequest(FString DeviceId = "", FString DeviceModel = "", FString DeviceName = "", FString DeviceOS = "", FString DeviceType = "", FString DisplayName = "", FString OperatingSystem = "", UGameSparksScriptData* Segments = nullptr,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);

	/**
	Allows a device id to be used to create an anonymous profile in the game.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	This allows the player to be tracked and have data stored against them before using FacebookConnectRequest to create a full profile.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	DeviceAuthenticationRequest should not be used in conjunction with RegistrationRequest as the two accounts will not be merged.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS DeviceAuthenticationRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks Server-side|Requests|Authentication")
	static UGSDeviceAuthenticationRequest* SendDeviceAuthenticationRequestOnBehalfOf(const FString& PlayerId, FString DeviceId = "", FString DeviceModel = "", FString DeviceName = "", FString DeviceOS = "", FString DeviceType = "", FString DisplayName = "", FString OperatingSystem = "", UGameSparksScriptData* Segments = nullptr,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSDeviceAuthenticationRequest();

private:
	
	UPROPERTY()
	FString deviceId;
	
	UPROPERTY()
	FString deviceModel;
	
	UPROPERTY()
	FString deviceName;
	
	UPROPERTY()
	FString deviceOS;
	
	UPROPERTY()
	FString deviceType;
	
	UPROPERTY()
	FString displayName;
	
	UPROPERTY()
	FString operatingSystem;

	
	UPROPERTY()
	UGameSparksScriptData* segments;

	UPROPERTY()
	UGameSparksScriptData* scriptData;
	
	UPROPERTY()
	bool durable;
	
	UPROPERTY()
	int32 requestTimeoutSeconds;

	UPROPERTY()
	FString playerId;
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnDismissMessageRequest_Response, FGSDismissMessageResponse, DismissMessageResponse, bool, hasErrors);

UCLASS()
class GAMESPARKS_API UGSDismissMessageRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnDismissMessageRequest_Response OnResponse;
	
	/**
	Allows a message to be dismissed. Once dismissed the message will no longer appear in either ListMessageResponse or ListMessageSummaryResponse.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS DismissMessageRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Player")
	static UGSDismissMessageRequest* SendDismissMessageRequest(FString MessageId = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);

	/**
	Allows a message to be dismissed. Once dismissed the message will no longer appear in either ListMessageResponse or ListMessageSummaryResponse.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS DismissMessageRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks Server-side|Requests|Player")
	static UGSDismissMessageRequest* SendDismissMessageRequestOnBehalfOf(const FString& PlayerId, FString MessageId = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSDismissMessageRequest();

private:
	
	UPROPERTY()
	FString messageId;


	UPROPERTY()
	UGameSparksScriptData* scriptData;
	
	UPROPERTY()
	bool durable;
	
	UPROPERTY()
	int32 requestTimeoutSeconds;

	UPROPERTY()
	FString playerId;
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnDismissMultipleMessagesRequest_Response, FGSDismissMultipleMessagesResponse, DismissMultipleMessagesResponse, bool, hasErrors);

UCLASS()
class GAMESPARKS_API UGSDismissMultipleMessagesRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnDismissMultipleMessagesRequest_Response OnResponse;
	
	/**
	Allows multiple messages to be dismissed. Once dismissed the messages will no longer appear in either ListMessageResponse or ListMessageSummaryResponse.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS DismissMultipleMessagesRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Player")
	static UGSDismissMultipleMessagesRequest* SendDismissMultipleMessagesRequest(UGameSparksRequestArray* MessageIds = nullptr,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);

	/**
	Allows multiple messages to be dismissed. Once dismissed the messages will no longer appear in either ListMessageResponse or ListMessageSummaryResponse.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS DismissMultipleMessagesRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks Server-side|Requests|Player")
	static UGSDismissMultipleMessagesRequest* SendDismissMultipleMessagesRequestOnBehalfOf(const FString& PlayerId, UGameSparksRequestArray* MessageIds = nullptr,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSDismissMultipleMessagesRequest();

private:
	
	UPROPERTY()
	UGameSparksRequestArray* messageIds;


	UPROPERTY()
	UGameSparksScriptData* scriptData;
	
	UPROPERTY()
	bool durable;
	
	UPROPERTY()
	int32 requestTimeoutSeconds;

	UPROPERTY()
	FString playerId;
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnDropTeamRequest_Response, FGSDropTeamResponse, DropTeamResponse, bool, hasErrors);

UCLASS()
class GAMESPARKS_API UGSDropTeamRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnDropTeamRequest_Response OnResponse;
	
	/**
	Allows a player to drop a team.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS DropTeamRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Teams")
	static UGSDropTeamRequest* SendDropTeamRequest(FString OwnerId = "", FString TeamId = "", FString TeamType = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);

	/**
	Allows a player to drop a team.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS DropTeamRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks Server-side|Requests|Teams")
	static UGSDropTeamRequest* SendDropTeamRequestOnBehalfOf(const FString& PlayerId, FString OwnerId = "", FString TeamId = "", FString TeamType = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSDropTeamRequest();

private:
	
	UPROPERTY()
	FString ownerId;

	
	UPROPERTY()
	FString teamId;
	
	UPROPERTY()
	FString teamType;

	UPROPERTY()
	UGameSparksScriptData* scriptData;
	
	UPROPERTY()
	bool durable;
	
	UPROPERTY()
	int32 requestTimeoutSeconds;

	UPROPERTY()
	FString playerId;
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnEndSessionRequest_Response, FGSEndSessionResponse, EndSessionResponse, bool, hasErrors);

UCLASS()
class GAMESPARKS_API UGSEndSessionRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnEndSessionRequest_Response OnResponse;
	
	/**
	Records the end of the current player's active session.
	The SDK will automatically create a new session ID when the application is started, this method can be useful to call when the app goes into the background to allow reporting on player session length.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS EndSessionRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Analytics")
	static UGSEndSessionRequest* SendEndSessionRequest( UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);

	/**
	Records the end of the current player's active session.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	The SDK will automatically create a new session ID when the application is started, this method can be useful to call when the app goes into the background to allow reporting on player session length.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS EndSessionRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks Server-side|Requests|Analytics")
	static UGSEndSessionRequest* SendEndSessionRequestOnBehalfOf(const FString& PlayerId,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSEndSessionRequest();

private:


	UPROPERTY()
	UGameSparksScriptData* scriptData;
	
	UPROPERTY()
	bool durable;
	
	UPROPERTY()
	int32 requestTimeoutSeconds;

	UPROPERTY()
	FString playerId;
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnFacebookConnectRequest_Response, FGSAuthenticationResponse, AuthenticationResponse, bool, hasErrors);

UCLASS()
class GAMESPARKS_API UGSFacebookConnectRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnFacebookConnectRequest_Response OnResponse;
	
	/**
	Allows either a Facebook access token, or a Facebook authorization code to be used as an authentication mechanism.
	Once authenticated the platform can determine the current players details from the Facebook platform and store them within GameSparks.
	GameSparks will determine the player's friends and whether any of them are currently registered with the game.
	If the Facebook user is already linked to a player, the current session will switch to the linked player.
	If the current player has previously created an account using either DeviceAuthenticationRequest or RegistrationRequest AND the Facebook user is not already registered with the game, the Facebook user will be linked to the current player.
	If the current player has not authenticated and the Facebook user is not known, a new player will be created using the Facebook details and the session will be authenticated against the new player.
	If the Facebook user is already known, the session will switch to being the previously created user.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS FacebookConnectRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Authentication")
	static UGSFacebookConnectRequest* SendFacebookConnectRequest(FString AccessToken = "", FString Code = "", bool DoNotLinkToCurrentPlayer = false, bool ErrorOnSwitch = false, UGameSparksScriptData* Segments = nullptr, bool SwitchIfPossible = false, bool SyncDisplayName = false,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);

	/**
	Allows either a Facebook access token, or a Facebook authorization code to be used as an authentication mechanism.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	Once authenticated the platform can determine the current players details from the Facebook platform and store them within GameSparks.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	GameSparks will determine the player's friends and whether any of them are currently registered with the game.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	If the Facebook user is already linked to a player, the current session will switch to the linked player.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	If the current player has previously created an account using either DeviceAuthenticationRequest or RegistrationRequest AND the Facebook user is not already registered with the game, the Facebook user will be linked to the current player.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	If the current player has not authenticated and the Facebook user is not known, a new player will be created using the Facebook details and the session will be authenticated against the new player.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	If the Facebook user is already known, the session will switch to being the previously created user.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS FacebookConnectRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks Server-side|Requests|Authentication")
	static UGSFacebookConnectRequest* SendFacebookConnectRequestOnBehalfOf(const FString& PlayerId, FString AccessToken = "", FString Code = "", bool DoNotLinkToCurrentPlayer = false, bool ErrorOnSwitch = false, UGameSparksScriptData* Segments = nullptr, bool SwitchIfPossible = false, bool SyncDisplayName = false,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSFacebookConnectRequest();

private:
	
	UPROPERTY()
	FString accessToken;
	
	UPROPERTY()
	FString code;
	
	UPROPERTY()
	bool doNotLinkToCurrentPlayer;
	
	UPROPERTY()
	bool errorOnSwitch;

	
	UPROPERTY()
	UGameSparksScriptData* segments;
	
	UPROPERTY()
	bool switchIfPossible;
	
	UPROPERTY()
	bool syncDisplayName;

	UPROPERTY()
	UGameSparksScriptData* scriptData;
	
	UPROPERTY()
	bool durable;
	
	UPROPERTY()
	int32 requestTimeoutSeconds;

	UPROPERTY()
	FString playerId;
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnFindChallengeRequest_Response, FGSFindChallengeResponse, FindChallengeResponse, bool, hasErrors);

UCLASS()
class GAMESPARKS_API UGSFindChallengeRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnFindChallengeRequest_Response OnResponse;
	
	/**
	Allows a player to find challenges that they are eligible to join.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS FindChallengeRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Multiplayer")
	static UGSFindChallengeRequest* SendFindChallengeRequest(FString AccessType = "", int32 Count = 0, UGameSparksScriptData* Eligibility = nullptr, int32 Offset = 0, UGameSparksRequestArray* ShortCode = nullptr,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);

	/**
	Allows a player to find challenges that they are eligible to join.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS FindChallengeRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks Server-side|Requests|Multiplayer")
	static UGSFindChallengeRequest* SendFindChallengeRequestOnBehalfOf(const FString& PlayerId, FString AccessType = "", int32 Count = 0, UGameSparksScriptData* Eligibility = nullptr, int32 Offset = 0, UGameSparksRequestArray* ShortCode = nullptr,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSFindChallengeRequest();

private:
	
	UPROPERTY()
	FString accessType;
	
	UPROPERTY()
	int32 count;
	
	UPROPERTY()
	UGameSparksScriptData* eligibility;
	
	UPROPERTY()
	int32 offset;

	
	UPROPERTY()
	UGameSparksRequestArray* shortCode;

	UPROPERTY()
	UGameSparksScriptData* scriptData;
	
	UPROPERTY()
	bool durable;
	
	UPROPERTY()
	int32 requestTimeoutSeconds;

	UPROPERTY()
	FString playerId;
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnFindMatchRequest_Response, FGSFindMatchResponse, FindMatchResponse, bool, hasErrors);

UCLASS()
class GAMESPARKS_API UGSFindMatchRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnFindMatchRequest_Response OnResponse;
	
	/**
	@Deprecated. Use MatchmakingRequest instead.
	Find a match for this player, using the given skill and matchShortCode.
	Players looking for a match using the same matchShortCode will be considered for a match, based on the matchConfig.
	Each player must match the other for the match to be found.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS FindMatchRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Multiplayer")
	static UGSFindMatchRequest* SendFindMatchRequest(FString Action = "", FString MatchGroup = "", FString MatchShortCode = "", int32 Skill = 0,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);

	/**
	@Deprecated. Use MatchmakingRequest instead.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	Find a match for this player, using the given skill and matchShortCode.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	Players looking for a match using the same matchShortCode will be considered for a match, based on the matchConfig.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	Each player must match the other for the match to be found.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS FindMatchRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks Server-side|Requests|Multiplayer")
	static UGSFindMatchRequest* SendFindMatchRequestOnBehalfOf(const FString& PlayerId, FString Action = "", FString MatchGroup = "", FString MatchShortCode = "", int32 Skill = 0,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSFindMatchRequest();

private:
	
	UPROPERTY()
	FString action;
	
	UPROPERTY()
	FString matchGroup;
	
	UPROPERTY()
	FString matchShortCode;

	
	UPROPERTY()
	int32 skill;

	UPROPERTY()
	UGameSparksScriptData* scriptData;
	
	UPROPERTY()
	bool durable;
	
	UPROPERTY()
	int32 requestTimeoutSeconds;

	UPROPERTY()
	FString playerId;
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnFindPendingMatchesRequest_Response, FGSFindPendingMatchesResponse, FindPendingMatchesResponse, bool, hasErrors);

UCLASS()
class GAMESPARKS_API UGSFindPendingMatchesRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnFindPendingMatchesRequest_Response OnResponse;
	
	/**
	Find other pending matches that will match this player's previously submitted MatchmakingRequest.
	Used for manual matching of players, where you want control over which pending match should be chosen.
	Each player must match the other for the pending match to be found.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS FindPendingMatchesRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Multiplayer")
	static UGSFindPendingMatchesRequest* SendFindPendingMatchesRequest(FString MatchGroup = "", FString MatchShortCode = "", int32 MaxMatchesToFind = 0,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);

	/**
	Find other pending matches that will match this player's previously submitted MatchmakingRequest.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	Used for manual matching of players, where you want control over which pending match should be chosen.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	Each player must match the other for the pending match to be found.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS FindPendingMatchesRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks Server-side|Requests|Multiplayer")
	static UGSFindPendingMatchesRequest* SendFindPendingMatchesRequestOnBehalfOf(const FString& PlayerId, FString MatchGroup = "", FString MatchShortCode = "", int32 MaxMatchesToFind = 0,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSFindPendingMatchesRequest();

private:
	
	UPROPERTY()
	FString matchGroup;
	
	UPROPERTY()
	FString matchShortCode;
	
	UPROPERTY()
	int32 maxMatchesToFind;


	UPROPERTY()
	UGameSparksScriptData* scriptData;
	
	UPROPERTY()
	bool durable;
	
	UPROPERTY()
	int32 requestTimeoutSeconds;

	UPROPERTY()
	FString playerId;
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGameCenterConnectRequest_Response, FGSAuthenticationResponse, AuthenticationResponse, bool, hasErrors);

UCLASS()
class GAMESPARKS_API UGSGameCenterConnectRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnGameCenterConnectRequest_Response OnResponse;
	
	/**
	Allows an Apple account that has GameCenter to be used as an authentication mechanism.
	The request must supply the GameCenter user details, such as the player id and username.
	If the GameCenter user is already linked to a player, the current session will switch to the linked player.
	If the current player has previously created an account using either DeviceAuthentictionRequest or RegistrationRequest AND the GameCenter user is not already registered with the game, the GameCenter user will be linked to the current player.
	If the current player has not authenticated and the GameCenter user is not known, a new player will be created using the GameCenter details and the session will be authenticated against the new player.
	If the GameCenter user is already known, the session will switch to being the previously created user.
	This API call requires the output details from GKLocalPlayer.generateIdentityVerificationSignatureWithCompletionHandler on your iOS device
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS GameCenterConnectRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Authentication")
	static UGSGameCenterConnectRequest* SendGameCenterConnectRequest(FString DisplayName = "", bool DoNotLinkToCurrentPlayer = false, bool ErrorOnSwitch = false, FString ExternalPlayerId = "", FString PublicKeyUrl = "", FString Salt = "", UGameSparksScriptData* Segments = nullptr, FString Signature = "", bool SwitchIfPossible = false, bool SyncDisplayName = false, int32 Timestamp = 0,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);

	/**
	Allows an Apple account that has GameCenter to be used as an authentication mechanism.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	The request must supply the GameCenter user details, such as the player id and username.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	If the GameCenter user is already linked to a player, the current session will switch to the linked player.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	If the current player has previously created an account using either DeviceAuthentictionRequest or RegistrationRequest AND the GameCenter user is not already registered with the game, the GameCenter user will be linked to the current player.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	If the current player has not authenticated and the GameCenter user is not known, a new player will be created using the GameCenter details and the session will be authenticated against the new player.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	If the GameCenter user is already known, the session will switch to being the previously created user.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	This API call requires the output details from GKLocalPlayer.generateIdentityVerificationSignatureWithCompletionHandler on your iOS device

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS GameCenterConnectRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks Server-side|Requests|Authentication")
	static UGSGameCenterConnectRequest* SendGameCenterConnectRequestOnBehalfOf(const FString& PlayerId, FString DisplayName = "", bool DoNotLinkToCurrentPlayer = false, bool ErrorOnSwitch = false, FString ExternalPlayerId = "", FString PublicKeyUrl = "", FString Salt = "", UGameSparksScriptData* Segments = nullptr, FString Signature = "", bool SwitchIfPossible = false, bool SyncDisplayName = false, int32 Timestamp = 0,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSGameCenterConnectRequest();

private:
	
	UPROPERTY()
	FString displayName;
	
	UPROPERTY()
	bool doNotLinkToCurrentPlayer;
	
	UPROPERTY()
	bool errorOnSwitch;
	
	UPROPERTY()
	FString externalPlayerId;
	
	UPROPERTY()
	FString publicKeyUrl;

	
	UPROPERTY()
	FString salt;
	
	UPROPERTY()
	UGameSparksScriptData* segments;
	
	UPROPERTY()
	FString signature;
	
	UPROPERTY()
	bool switchIfPossible;
	
	UPROPERTY()
	bool syncDisplayName;
	
	UPROPERTY()
	int32 timestamp;

	UPROPERTY()
	UGameSparksScriptData* scriptData;
	
	UPROPERTY()
	bool durable;
	
	UPROPERTY()
	int32 requestTimeoutSeconds;

	UPROPERTY()
	FString playerId;
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGetChallengeRequest_Response, FGSGetChallengeResponse, GetChallengeResponse, bool, hasErrors);

UCLASS()
class GAMESPARKS_API UGSGetChallengeRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnGetChallengeRequest_Response OnResponse;
	
	/**
	Gets the details of a challenge. The current player must be involved in the challenge for the request to succeed.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS GetChallengeRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Multiplayer")
	static UGSGetChallengeRequest* SendGetChallengeRequest(FString ChallengeInstanceId = "", FString Message = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);

	/**
	Gets the details of a challenge. The current player must be involved in the challenge for the request to succeed.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS GetChallengeRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks Server-side|Requests|Multiplayer")
	static UGSGetChallengeRequest* SendGetChallengeRequestOnBehalfOf(const FString& PlayerId, FString ChallengeInstanceId = "", FString Message = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSGetChallengeRequest();

private:
	
	UPROPERTY()
	FString challengeInstanceId;
	
	UPROPERTY()
	FString message;


	UPROPERTY()
	UGameSparksScriptData* scriptData;
	
	UPROPERTY()
	bool durable;
	
	UPROPERTY()
	int32 requestTimeoutSeconds;

	UPROPERTY()
	FString playerId;
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGetDownloadableRequest_Response, FGSGetDownloadableResponse, GetDownloadableResponse, bool, hasErrors);

UCLASS()
class GAMESPARKS_API UGSGetDownloadableRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnGetDownloadableRequest_Response OnResponse;
	
	/**
	Returns a secure, time sensitive url to allow the game to download a piece of downloadable content stored in the GameSparks platform.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS GetDownloadableRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Misc")
	static UGSGetDownloadableRequest* SendGetDownloadableRequest(FString ShortCode = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);

	/**
	Returns a secure, time sensitive url to allow the game to download a piece of downloadable content stored in the GameSparks platform.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS GetDownloadableRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks Server-side|Requests|Misc")
	static UGSGetDownloadableRequest* SendGetDownloadableRequestOnBehalfOf(const FString& PlayerId, FString ShortCode = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSGetDownloadableRequest();

private:

	
	UPROPERTY()
	FString shortCode;

	UPROPERTY()
	UGameSparksScriptData* scriptData;
	
	UPROPERTY()
	bool durable;
	
	UPROPERTY()
	int32 requestTimeoutSeconds;

	UPROPERTY()
	FString playerId;
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGetLeaderboardEntriesRequest_Response, FGSGetLeaderboardEntriesResponse, GetLeaderboardEntriesResponse, bool, hasErrors);

UCLASS()
class GAMESPARKS_API UGSGetLeaderboardEntriesRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnGetLeaderboardEntriesRequest_Response OnResponse;
	
	/**
	Get the leaderboard entry data for the current player or a given player. 
	For each leaderboard it returns the hichest score the player has
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS GetLeaderboardEntriesRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Leaderboards")
	static UGSGetLeaderboardEntriesRequest* SendGetLeaderboardEntriesRequest(UGameSparksRequestArray* Challenges = nullptr, bool InverseSocial = false, UGameSparksRequestArray* Leaderboards = nullptr, FString Player = "", bool Social = false, UGameSparksRequestArray* TeamTypes = nullptr,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);

	/**
	Get the leaderboard entry data for the current player or a given player. 

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	For each leaderboard it returns the hichest score the player has

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS GetLeaderboardEntriesRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks Server-side|Requests|Leaderboards")
	static UGSGetLeaderboardEntriesRequest* SendGetLeaderboardEntriesRequestOnBehalfOf(const FString& PlayerId, UGameSparksRequestArray* Challenges = nullptr, bool InverseSocial = false, UGameSparksRequestArray* Leaderboards = nullptr, FString Player = "", bool Social = false, UGameSparksRequestArray* TeamTypes = nullptr,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSGetLeaderboardEntriesRequest();

private:
	
	UPROPERTY()
	UGameSparksRequestArray* challenges;
	
	UPROPERTY()
	bool inverseSocial;
	
	UPROPERTY()
	UGameSparksRequestArray* leaderboards;
	
	UPROPERTY()
	FString player;

	
	UPROPERTY()
	bool social;
	
	UPROPERTY()
	UGameSparksRequestArray* teamTypes;

	UPROPERTY()
	UGameSparksScriptData* scriptData;
	
	UPROPERTY()
	bool durable;
	
	UPROPERTY()
	int32 requestTimeoutSeconds;

	UPROPERTY()
	FString playerId;
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGetMessageRequest_Response, FGSGetMessageResponse, GetMessageResponse, bool, hasErrors);

UCLASS()
class GAMESPARKS_API UGSGetMessageRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnGetMessageRequest_Response OnResponse;
	
	/**
	Returns the full details of a message.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS GetMessageRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Player")
	static UGSGetMessageRequest* SendGetMessageRequest(FString MessageId = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);

	/**
	Returns the full details of a message.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS GetMessageRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks Server-side|Requests|Player")
	static UGSGetMessageRequest* SendGetMessageRequestOnBehalfOf(const FString& PlayerId, FString MessageId = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSGetMessageRequest();

private:
	
	UPROPERTY()
	FString messageId;


	UPROPERTY()
	UGameSparksScriptData* scriptData;
	
	UPROPERTY()
	bool durable;
	
	UPROPERTY()
	int32 requestTimeoutSeconds;

	UPROPERTY()
	FString playerId;
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGetMyTeamsRequest_Response, FGSGetMyTeamsResponse, GetMyTeamsResponse, bool, hasErrors);

UCLASS()
class GAMESPARKS_API UGSGetMyTeamsRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnGetMyTeamsRequest_Response OnResponse;
	
	/**
	Get the teams that the player is in. Can be filtered on team type and also on those teams that the player owns.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS GetMyTeamsRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Teams")
	static UGSGetMyTeamsRequest* SendGetMyTeamsRequest(bool OwnedOnly = false, UGameSparksRequestArray* TeamTypes = nullptr,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);

	/**
	Get the teams that the player is in. Can be filtered on team type and also on those teams that the player owns.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS GetMyTeamsRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks Server-side|Requests|Teams")
	static UGSGetMyTeamsRequest* SendGetMyTeamsRequestOnBehalfOf(const FString& PlayerId, bool OwnedOnly = false, UGameSparksRequestArray* TeamTypes = nullptr,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSGetMyTeamsRequest();

private:
	
	UPROPERTY()
	bool ownedOnly;

	
	UPROPERTY()
	UGameSparksRequestArray* teamTypes;

	UPROPERTY()
	UGameSparksScriptData* scriptData;
	
	UPROPERTY()
	bool durable;
	
	UPROPERTY()
	int32 requestTimeoutSeconds;

	UPROPERTY()
	FString playerId;
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGetPropertyRequest_Response, FGSGetPropertyResponse, GetPropertyResponse, bool, hasErrors);

UCLASS()
class GAMESPARKS_API UGSGetPropertyRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnGetPropertyRequest_Response OnResponse;
	
	/**
	Get the property for the given short Code.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS GetPropertyRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Misc")
	static UGSGetPropertyRequest* SendGetPropertyRequest(FString PropertyShortCode = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);

	/**
	Get the property for the given short Code.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS GetPropertyRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks Server-side|Requests|Misc")
	static UGSGetPropertyRequest* SendGetPropertyRequestOnBehalfOf(const FString& PlayerId, FString PropertyShortCode = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSGetPropertyRequest();

private:
	
	UPROPERTY()
	FString propertyShortCode;


	UPROPERTY()
	UGameSparksScriptData* scriptData;
	
	UPROPERTY()
	bool durable;
	
	UPROPERTY()
	int32 requestTimeoutSeconds;

	UPROPERTY()
	FString playerId;
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGetPropertySetRequest_Response, FGSGetPropertySetResponse, GetPropertySetResponse, bool, hasErrors);

UCLASS()
class GAMESPARKS_API UGSGetPropertySetRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnGetPropertySetRequest_Response OnResponse;
	
	/**
	Get the property set for the given short Code.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS GetPropertySetRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Misc")
	static UGSGetPropertySetRequest* SendGetPropertySetRequest(FString PropertySetShortCode = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);

	/**
	Get the property set for the given short Code.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS GetPropertySetRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks Server-side|Requests|Misc")
	static UGSGetPropertySetRequest* SendGetPropertySetRequestOnBehalfOf(const FString& PlayerId, FString PropertySetShortCode = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSGetPropertySetRequest();

private:
	
	UPROPERTY()
	FString propertySetShortCode;


	UPROPERTY()
	UGameSparksScriptData* scriptData;
	
	UPROPERTY()
	bool durable;
	
	UPROPERTY()
	int32 requestTimeoutSeconds;

	UPROPERTY()
	FString playerId;
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGetTeamRequest_Response, FGSGetTeamResponse, GetTeamResponse, bool, hasErrors);

UCLASS()
class GAMESPARKS_API UGSGetTeamRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnGetTeamRequest_Response OnResponse;
	
	/**
	Allows the details of a team to be retrieved.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS GetTeamRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Teams")
	static UGSGetTeamRequest* SendGetTeamRequest(FString OwnerId = "", FString TeamId = "", FString TeamType = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);

	/**
	Allows the details of a team to be retrieved.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS GetTeamRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks Server-side|Requests|Teams")
	static UGSGetTeamRequest* SendGetTeamRequestOnBehalfOf(const FString& PlayerId, FString OwnerId = "", FString TeamId = "", FString TeamType = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSGetTeamRequest();

private:
	
	UPROPERTY()
	FString ownerId;

	
	UPROPERTY()
	FString teamId;
	
	UPROPERTY()
	FString teamType;

	UPROPERTY()
	UGameSparksScriptData* scriptData;
	
	UPROPERTY()
	bool durable;
	
	UPROPERTY()
	int32 requestTimeoutSeconds;

	UPROPERTY()
	FString playerId;
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGetUploadUrlRequest_Response, FGSGetUploadUrlResponse, GetUploadUrlResponse, bool, hasErrors);

UCLASS()
class GAMESPARKS_API UGSGetUploadUrlRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnGetUploadUrlRequest_Response OnResponse;
	
	/**
	Returns a secure, time sensitive URL to allow the game to upload a piece of player content to the GameSparks platform.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS GetUploadUrlRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Misc")
	static UGSGetUploadUrlRequest* SendGetUploadUrlRequest(UGameSparksScriptData* UploadData = nullptr,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);

	/**
	Returns a secure, time sensitive URL to allow the game to upload a piece of player content to the GameSparks platform.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS GetUploadUrlRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks Server-side|Requests|Misc")
	static UGSGetUploadUrlRequest* SendGetUploadUrlRequestOnBehalfOf(const FString& PlayerId, UGameSparksScriptData* UploadData = nullptr,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSGetUploadUrlRequest();

private:

	
	UPROPERTY()
	UGameSparksScriptData* uploadData;

	UPROPERTY()
	UGameSparksScriptData* scriptData;
	
	UPROPERTY()
	bool durable;
	
	UPROPERTY()
	int32 requestTimeoutSeconds;

	UPROPERTY()
	FString playerId;
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGetUploadedRequest_Response, FGSGetUploadedResponse, GetUploadedResponse, bool, hasErrors);

UCLASS()
class GAMESPARKS_API UGSGetUploadedRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnGetUploadedRequest_Response OnResponse;
	
	/**
	Returns a secure, time sensitive URL to a piece of content that was previously uploaded to the GameSparks platform by a player.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS GetUploadedRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Misc")
	static UGSGetUploadedRequest* SendGetUploadedRequest(FString UploadId = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);

	/**
	Returns a secure, time sensitive URL to a piece of content that was previously uploaded to the GameSparks platform by a player.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS GetUploadedRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks Server-side|Requests|Misc")
	static UGSGetUploadedRequest* SendGetUploadedRequestOnBehalfOf(const FString& PlayerId, FString UploadId = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSGetUploadedRequest();

private:

	
	UPROPERTY()
	FString uploadId;

	UPROPERTY()
	UGameSparksScriptData* scriptData;
	
	UPROPERTY()
	bool durable;
	
	UPROPERTY()
	int32 requestTimeoutSeconds;

	UPROPERTY()
	FString playerId;
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGooglePlayBuyGoodsRequest_Response, FGSBuyVirtualGoodResponse, BuyVirtualGoodResponse, bool, hasErrors);

UCLASS()
class GAMESPARKS_API UGSGooglePlayBuyGoodsRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnGooglePlayBuyGoodsRequest_Response OnResponse;
	
	/**
	Processes the response from a Google Play in app purchase flow.
	The GameSparks platform will validate the signature and signed data with the Google Play Public Key configured against the game.
	The orderId in the data will be recorded and the request will be rejected if the orderId has previously been processed, this prevents replay attacks.
	Once verfied, the players account will be credited with the Virtual Good, or Virtual Currency the purchase contains. The virtual good will be looked up by matching the productId in the signed data with the 'Google Product ID' configured against the virtual good.
	It is critical that the signedData is sent exactly as it is returned form google, including any whitespace. Any modification of the signedData will cause the verification process to fail.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS GooglePlayBuyGoodsRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Store")
	static UGSGooglePlayBuyGoodsRequest* SendGooglePlayBuyGoodsRequest(FString CurrencyCode = "", FString Signature = "", FString SignedData = "", float SubUnitPrice = 0.0f, bool UniqueTransactionByPlayer = false,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);

	/**
	Processes the response from a Google Play in app purchase flow.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	The GameSparks platform will validate the signature and signed data with the Google Play Public Key configured against the game.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	The orderId in the data will be recorded and the request will be rejected if the orderId has previously been processed, this prevents replay attacks.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	Once verfied, the players account will be credited with the Virtual Good, or Virtual Currency the purchase contains. The virtual good will be looked up by matching the productId in the signed data with the 'Google Product ID' configured against the virtual good.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	It is critical that the signedData is sent exactly as it is returned form google, including any whitespace. Any modification of the signedData will cause the verification process to fail.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS GooglePlayBuyGoodsRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks Server-side|Requests|Store")
	static UGSGooglePlayBuyGoodsRequest* SendGooglePlayBuyGoodsRequestOnBehalfOf(const FString& PlayerId, FString CurrencyCode = "", FString Signature = "", FString SignedData = "", float SubUnitPrice = 0.0f, bool UniqueTransactionByPlayer = false,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSGooglePlayBuyGoodsRequest();

private:
	
	UPROPERTY()
	FString currencyCode;

	
	UPROPERTY()
	FString signature;
	
	UPROPERTY()
	FString signedData;
	
	UPROPERTY()
	float subUnitPrice;
	
	UPROPERTY()
	bool uniqueTransactionByPlayer;

	UPROPERTY()
	UGameSparksScriptData* scriptData;
	
	UPROPERTY()
	bool durable;
	
	UPROPERTY()
	int32 requestTimeoutSeconds;

	UPROPERTY()
	FString playerId;
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGooglePlayConnectRequest_Response, FGSAuthenticationResponse, AuthenticationResponse, bool, hasErrors);

UCLASS()
class GAMESPARKS_API UGSGooglePlayConnectRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnGooglePlayConnectRequest_Response OnResponse;
	
	/**
	Allows either a Google Play access code or an access token to be used as an authentication mechanism.
	The access code needs to have at least the https://www.googleapis.com/auth/games scope.
	For more details about Google OAuth 2.0 scopes refer to this: https://developers.google.com/identity/protocols/googlescopes#gamesConfigurationv1configuration
	If the Google Play user is already linked to a player, the current session will switch to the linked player.
	If the current player has previously created an account using either DeviceAuthentictionRequest or RegistrationRequest AND the Google Play user is not already registered with the game, the Google Play user will be linked to the current player.
	If the current player has not authenticated and the Google Play user is not known, a new player will be created using the Google Play details and the session will be authenticated against the new player.
	If the Google Play user is already known, the session will switch to being the previously created user.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS GooglePlayConnectRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Authentication")
	static UGSGooglePlayConnectRequest* SendGooglePlayConnectRequest(FString AccessToken = "", FString Code = "", FString DisplayName = "", bool DoNotLinkToCurrentPlayer = false, bool ErrorOnSwitch = false, bool GooglePlusScope = false, bool ProfileScope = false, FString RedirectUri = "", UGameSparksScriptData* Segments = nullptr, bool SwitchIfPossible = false, bool SyncDisplayName = false,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);

	/**
	Allows either a Google Play access code or an access token to be used as an authentication mechanism.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	The access code needs to have at least the https://www.googleapis.com/auth/games scope.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	For more details about Google OAuth 2.0 scopes refer to this: https://developers.google.com/identity/protocols/googlescopes#gamesConfigurationv1configuration

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	If the Google Play user is already linked to a player, the current session will switch to the linked player.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	If the current player has previously created an account using either DeviceAuthentictionRequest or RegistrationRequest AND the Google Play user is not already registered with the game, the Google Play user will be linked to the current player.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	If the current player has not authenticated and the Google Play user is not known, a new player will be created using the Google Play details and the session will be authenticated against the new player.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	If the Google Play user is already known, the session will switch to being the previously created user.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS GooglePlayConnectRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks Server-side|Requests|Authentication")
	static UGSGooglePlayConnectRequest* SendGooglePlayConnectRequestOnBehalfOf(const FString& PlayerId, FString AccessToken = "", FString Code = "", FString DisplayName = "", bool DoNotLinkToCurrentPlayer = false, bool ErrorOnSwitch = false, bool GooglePlusScope = false, bool ProfileScope = false, FString RedirectUri = "", UGameSparksScriptData* Segments = nullptr, bool SwitchIfPossible = false, bool SyncDisplayName = false,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSGooglePlayConnectRequest();

private:
	
	UPROPERTY()
	FString accessToken;
	
	UPROPERTY()
	FString code;
	
	UPROPERTY()
	FString displayName;
	
	UPROPERTY()
	bool doNotLinkToCurrentPlayer;
	
	UPROPERTY()
	bool errorOnSwitch;
	
	UPROPERTY()
	bool googlePlusScope;
	
	UPROPERTY()
	bool profileScope;
	
	UPROPERTY()
	FString redirectUri;

	
	UPROPERTY()
	UGameSparksScriptData* segments;
	
	UPROPERTY()
	bool switchIfPossible;
	
	UPROPERTY()
	bool syncDisplayName;

	UPROPERTY()
	UGameSparksScriptData* scriptData;
	
	UPROPERTY()
	bool durable;
	
	UPROPERTY()
	int32 requestTimeoutSeconds;

	UPROPERTY()
	FString playerId;
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGooglePlusConnectRequest_Response, FGSAuthenticationResponse, AuthenticationResponse, bool, hasErrors);

UCLASS()
class GAMESPARKS_API UGSGooglePlusConnectRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnGooglePlusConnectRequest_Response OnResponse;
	
	/**
	Allows either a Google Plus access code or an authentication token to be used as an authentication mechanism.
	Once authenticated the platform can determine the current players details from the Google Plus platform and store them within GameSparks.
	GameSparks will determine the player's friends and whether any of them are currently registered with the game.
	If the Google Plus user is already linked to a player, the current session will switch to the linked player.
	If the current player has previously created an account using either DeviceAuthentictionRequest or RegistrationRequest AND the Google Plus user is not already registered with the game, the Google Plus user will be linked to the current player.
	If the current player has not authenticated and the Google Plus user is not known, a new player will be created using the Google Plus details and the session will be authenticated against the new player.
	If the Google Plus user is already known, the session will switch to being the previously created user.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS GooglePlusConnectRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Authentication")
	static UGSGooglePlusConnectRequest* SendGooglePlusConnectRequest(FString AccessToken = "", FString Code = "", bool DoNotLinkToCurrentPlayer = false, bool ErrorOnSwitch = false, FString RedirectUri = "", UGameSparksScriptData* Segments = nullptr, bool SwitchIfPossible = false, bool SyncDisplayName = false,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);

	/**
	Allows either a Google Plus access code or an authentication token to be used as an authentication mechanism.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	Once authenticated the platform can determine the current players details from the Google Plus platform and store them within GameSparks.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	GameSparks will determine the player's friends and whether any of them are currently registered with the game.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	If the Google Plus user is already linked to a player, the current session will switch to the linked player.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	If the current player has previously created an account using either DeviceAuthentictionRequest or RegistrationRequest AND the Google Plus user is not already registered with the game, the Google Plus user will be linked to the current player.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	If the current player has not authenticated and the Google Plus user is not known, a new player will be created using the Google Plus details and the session will be authenticated against the new player.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	If the Google Plus user is already known, the session will switch to being the previously created user.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS GooglePlusConnectRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks Server-side|Requests|Authentication")
	static UGSGooglePlusConnectRequest* SendGooglePlusConnectRequestOnBehalfOf(const FString& PlayerId, FString AccessToken = "", FString Code = "", bool DoNotLinkToCurrentPlayer = false, bool ErrorOnSwitch = false, FString RedirectUri = "", UGameSparksScriptData* Segments = nullptr, bool SwitchIfPossible = false, bool SyncDisplayName = false,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSGooglePlusConnectRequest();

private:
	
	UPROPERTY()
	FString accessToken;
	
	UPROPERTY()
	FString code;
	
	UPROPERTY()
	bool doNotLinkToCurrentPlayer;
	
	UPROPERTY()
	bool errorOnSwitch;
	
	UPROPERTY()
	FString redirectUri;

	
	UPROPERTY()
	UGameSparksScriptData* segments;
	
	UPROPERTY()
	bool switchIfPossible;
	
	UPROPERTY()
	bool syncDisplayName;

	UPROPERTY()
	UGameSparksScriptData* scriptData;
	
	UPROPERTY()
	bool durable;
	
	UPROPERTY()
	int32 requestTimeoutSeconds;

	UPROPERTY()
	FString playerId;
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnIOSBuyGoodsRequest_Response, FGSBuyVirtualGoodResponse, BuyVirtualGoodResponse, bool, hasErrors);

UCLASS()
class GAMESPARKS_API UGSIOSBuyGoodsRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnIOSBuyGoodsRequest_Response OnResponse;
	
	/**
	Processes a transaction receipt from an App Store in app purchase.
	The GameSparks platform will validate the receipt with Apple and process the response. The transaction_id in the response will be recorded and the request will be rejected if the transaction_id has previously been processed, this prevents replay attacks.
	Once verified, the players account will be credited with the Virtual Good, or Virtual Currency the purchase contains. The virtual good will be looked up by matching the product_id in the response with the 'IOS Product ID' configured against the virtual good.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS IOSBuyGoodsRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Store")
	static UGSIOSBuyGoodsRequest* SendIOSBuyGoodsRequest(FString CurrencyCode = "", FString Receipt = "", bool Sandbox = false, float SubUnitPrice = 0.0f, bool UniqueTransactionByPlayer = false,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);

	/**
	Processes a transaction receipt from an App Store in app purchase.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	The GameSparks platform will validate the receipt with Apple and process the response. The transaction_id in the response will be recorded and the request will be rejected if the transaction_id has previously been processed, this prevents replay attacks.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	Once verified, the players account will be credited with the Virtual Good, or Virtual Currency the purchase contains. The virtual good will be looked up by matching the product_id in the response with the 'IOS Product ID' configured against the virtual good.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS IOSBuyGoodsRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks Server-side|Requests|Store")
	static UGSIOSBuyGoodsRequest* SendIOSBuyGoodsRequestOnBehalfOf(const FString& PlayerId, FString CurrencyCode = "", FString Receipt = "", bool Sandbox = false, float SubUnitPrice = 0.0f, bool UniqueTransactionByPlayer = false,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSIOSBuyGoodsRequest();

private:
	
	UPROPERTY()
	FString currencyCode;
	
	UPROPERTY()
	FString receipt;

	
	UPROPERTY()
	bool sandbox;
	
	UPROPERTY()
	float subUnitPrice;
	
	UPROPERTY()
	bool uniqueTransactionByPlayer;

	UPROPERTY()
	UGameSparksScriptData* scriptData;
	
	UPROPERTY()
	bool durable;
	
	UPROPERTY()
	int32 requestTimeoutSeconds;

	UPROPERTY()
	FString playerId;
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnJoinChallengeRequest_Response, FGSJoinChallengeResponse, JoinChallengeResponse, bool, hasErrors);

UCLASS()
class GAMESPARKS_API UGSJoinChallengeRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnJoinChallengeRequest_Response OnResponse;
	
	/**
	Allows a player to join an open challenge.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS JoinChallengeRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Multiplayer")
	static UGSJoinChallengeRequest* SendJoinChallengeRequest(FString ChallengeInstanceId = "", UGameSparksScriptData* Eligibility = nullptr, FString Message = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);

	/**
	Allows a player to join an open challenge.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS JoinChallengeRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks Server-side|Requests|Multiplayer")
	static UGSJoinChallengeRequest* SendJoinChallengeRequestOnBehalfOf(const FString& PlayerId, FString ChallengeInstanceId = "", UGameSparksScriptData* Eligibility = nullptr, FString Message = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSJoinChallengeRequest();

private:
	
	UPROPERTY()
	FString challengeInstanceId;
	
	UPROPERTY()
	UGameSparksScriptData* eligibility;
	
	UPROPERTY()
	FString message;


	UPROPERTY()
	UGameSparksScriptData* scriptData;
	
	UPROPERTY()
	bool durable;
	
	UPROPERTY()
	int32 requestTimeoutSeconds;

	UPROPERTY()
	FString playerId;
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnJoinPendingMatchRequest_Response, FGSJoinPendingMatchResponse, JoinPendingMatchResponse, bool, hasErrors);

UCLASS()
class GAMESPARKS_API UGSJoinPendingMatchRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnJoinPendingMatchRequest_Response OnResponse;
	
	/**
	Requests to join a pending match (found via FindPendingMatchesRequest).
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS JoinPendingMatchRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Multiplayer")
	static UGSJoinPendingMatchRequest* SendJoinPendingMatchRequest(FString MatchGroup = "", FString MatchShortCode = "", FString PendingMatchId = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);

	/**
	Requests to join a pending match (found via FindPendingMatchesRequest).

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS JoinPendingMatchRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks Server-side|Requests|Multiplayer")
	static UGSJoinPendingMatchRequest* SendJoinPendingMatchRequestOnBehalfOf(const FString& PlayerId, FString MatchGroup = "", FString MatchShortCode = "", FString PendingMatchId = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSJoinPendingMatchRequest();

private:
	
	UPROPERTY()
	FString matchGroup;
	
	UPROPERTY()
	FString matchShortCode;
	
	UPROPERTY()
	FString pendingMatchId;


	UPROPERTY()
	UGameSparksScriptData* scriptData;
	
	UPROPERTY()
	bool durable;
	
	UPROPERTY()
	int32 requestTimeoutSeconds;

	UPROPERTY()
	FString playerId;
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnJoinTeamRequest_Response, FGSJoinTeamResponse, JoinTeamResponse, bool, hasErrors);

UCLASS()
class GAMESPARKS_API UGSJoinTeamRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnJoinTeamRequest_Response OnResponse;
	
	/**
	Allows a player to join a team or a team to be retrieved.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS JoinTeamRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Teams")
	static UGSJoinTeamRequest* SendJoinTeamRequest(FString OwnerId = "", FString TeamId = "", FString TeamType = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);

	/**
	Allows a player to join a team or a team to be retrieved.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS JoinTeamRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks Server-side|Requests|Teams")
	static UGSJoinTeamRequest* SendJoinTeamRequestOnBehalfOf(const FString& PlayerId, FString OwnerId = "", FString TeamId = "", FString TeamType = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSJoinTeamRequest();

private:
	
	UPROPERTY()
	FString ownerId;

	
	UPROPERTY()
	FString teamId;
	
	UPROPERTY()
	FString teamType;

	UPROPERTY()
	UGameSparksScriptData* scriptData;
	
	UPROPERTY()
	bool durable;
	
	UPROPERTY()
	int32 requestTimeoutSeconds;

	UPROPERTY()
	FString playerId;
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnKongregateConnectRequest_Response, FGSAuthenticationResponse, AuthenticationResponse, bool, hasErrors);

UCLASS()
class GAMESPARKS_API UGSKongregateConnectRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnKongregateConnectRequest_Response OnResponse;
	
	/**
	Allows a Kongregate account to be used as an authentication mechanism.
	Once authenticated the platform can determine the current players details from the Kongregate platform and store them within GameSparks.
	If the Kongregate user is already linked to a player, the current session will switch to the linked player.
	If the current player has previously created an account using either DeviceAuthentictionRequest or RegistrationRequest AND the Kongregate user is not already registered with the game, the Kongregate user will be linked to the current player.
	If the current player has not authenticated and the Kongregate user is not known, a new player will be created using the Kongregate details and the session will be authenticated against the new player.
	If the Kongregate user is already known, the session will switch to being the previously created user.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS KongregateConnectRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Authentication")
	static UGSKongregateConnectRequest* SendKongregateConnectRequest(bool DoNotLinkToCurrentPlayer = false, bool ErrorOnSwitch = false, FString GameAuthToken = "", UGameSparksScriptData* Segments = nullptr, bool SwitchIfPossible = false, bool SyncDisplayName = false, FString UserId = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);

	/**
	Allows a Kongregate account to be used as an authentication mechanism.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	Once authenticated the platform can determine the current players details from the Kongregate platform and store them within GameSparks.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	If the Kongregate user is already linked to a player, the current session will switch to the linked player.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	If the current player has previously created an account using either DeviceAuthentictionRequest or RegistrationRequest AND the Kongregate user is not already registered with the game, the Kongregate user will be linked to the current player.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	If the current player has not authenticated and the Kongregate user is not known, a new player will be created using the Kongregate details and the session will be authenticated against the new player.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	If the Kongregate user is already known, the session will switch to being the previously created user.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS KongregateConnectRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks Server-side|Requests|Authentication")
	static UGSKongregateConnectRequest* SendKongregateConnectRequestOnBehalfOf(const FString& PlayerId, bool DoNotLinkToCurrentPlayer = false, bool ErrorOnSwitch = false, FString GameAuthToken = "", UGameSparksScriptData* Segments = nullptr, bool SwitchIfPossible = false, bool SyncDisplayName = false, FString UserId = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSKongregateConnectRequest();

private:
	
	UPROPERTY()
	bool doNotLinkToCurrentPlayer;
	
	UPROPERTY()
	bool errorOnSwitch;
	
	UPROPERTY()
	FString gameAuthToken;

	
	UPROPERTY()
	UGameSparksScriptData* segments;
	
	UPROPERTY()
	bool switchIfPossible;
	
	UPROPERTY()
	bool syncDisplayName;
	
	UPROPERTY()
	FString userId;

	UPROPERTY()
	UGameSparksScriptData* scriptData;
	
	UPROPERTY()
	bool durable;
	
	UPROPERTY()
	int32 requestTimeoutSeconds;

	UPROPERTY()
	FString playerId;
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnLeaderboardDataRequest_Response, FGSLeaderboardDataResponse, LeaderboardDataResponse, bool, hasErrors);

UCLASS()
class GAMESPARKS_API UGSLeaderboardDataRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnLeaderboardDataRequest_Response OnResponse;
	
	/**
	Returns the top data for either the specified global leaderboard or the specified challenges leaderboard. The data is sorted as defined in the rules specified in the leaderboard configuration.
	The response contains the top of the leaderboard, and returns the number of entries as defined in the entryCount parameter.
	If a shortCode is supplied, the response will contain the global leaderboard data. If a challengeInstanceId is supplied, the response will contain the leaderboard data for the challenge.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS LeaderboardDataRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Leaderboards")
	static UGSLeaderboardDataRequest* SendLeaderboardDataRequest(FString ChallengeInstanceId = "", bool DontErrorOnNotSocial = false, int32 EntryCount = 0, UGameSparksRequestArray* FriendIds = nullptr, int32 IncludeFirst = 0, int32 IncludeLast = 0, bool InverseSocial = false, FString LeaderboardShortCode = "", int32 Offset = 0, bool Social = false, UGameSparksRequestArray* TeamIds = nullptr, UGameSparksRequestArray* TeamTypes = nullptr,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);

	/**
	Returns the top data for either the specified global leaderboard or the specified challenges leaderboard. The data is sorted as defined in the rules specified in the leaderboard configuration.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	The response contains the top of the leaderboard, and returns the number of entries as defined in the entryCount parameter.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	If a shortCode is supplied, the response will contain the global leaderboard data. If a challengeInstanceId is supplied, the response will contain the leaderboard data for the challenge.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS LeaderboardDataRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks Server-side|Requests|Leaderboards")
	static UGSLeaderboardDataRequest* SendLeaderboardDataRequestOnBehalfOf(const FString& PlayerId, FString ChallengeInstanceId = "", bool DontErrorOnNotSocial = false, int32 EntryCount = 0, UGameSparksRequestArray* FriendIds = nullptr, int32 IncludeFirst = 0, int32 IncludeLast = 0, bool InverseSocial = false, FString LeaderboardShortCode = "", int32 Offset = 0, bool Social = false, UGameSparksRequestArray* TeamIds = nullptr, UGameSparksRequestArray* TeamTypes = nullptr,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSLeaderboardDataRequest();

private:
	
	UPROPERTY()
	FString challengeInstanceId;
	
	UPROPERTY()
	bool dontErrorOnNotSocial;
	
	UPROPERTY()
	int32 entryCount;
	
	UPROPERTY()
	UGameSparksRequestArray* friendIds;
	
	UPROPERTY()
	int32 includeFirst;
	
	UPROPERTY()
	int32 includeLast;
	
	UPROPERTY()
	bool inverseSocial;
	
	UPROPERTY()
	FString leaderboardShortCode;
	
	UPROPERTY()
	int32 offset;

	
	UPROPERTY()
	bool social;
	
	UPROPERTY()
	UGameSparksRequestArray* teamIds;
	
	UPROPERTY()
	UGameSparksRequestArray* teamTypes;

	UPROPERTY()
	UGameSparksScriptData* scriptData;
	
	UPROPERTY()
	bool durable;
	
	UPROPERTY()
	int32 requestTimeoutSeconds;

	UPROPERTY()
	FString playerId;
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnLeaderboardsEntriesRequest_Response, FGSLeaderboardsEntriesResponse, LeaderboardsEntriesResponse, bool, hasErrors);

UCLASS()
class GAMESPARKS_API UGSLeaderboardsEntriesRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnLeaderboardsEntriesRequest_Response OnResponse;
	
	/**
	Get the leaderboard entry data for the current player or a given player.
	For each leaderboard it returns the array of leaderboard entries that the player has.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS LeaderboardsEntriesRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Leaderboards")
	static UGSLeaderboardsEntriesRequest* SendLeaderboardsEntriesRequest(UGameSparksRequestArray* Challenges = nullptr, bool InverseSocial = false, UGameSparksRequestArray* Leaderboards = nullptr, FString Player = "", bool Social = false, UGameSparksRequestArray* TeamTypes = nullptr,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);

	/**
	Get the leaderboard entry data for the current player or a given player.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	For each leaderboard it returns the array of leaderboard entries that the player has.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS LeaderboardsEntriesRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks Server-side|Requests|Leaderboards")
	static UGSLeaderboardsEntriesRequest* SendLeaderboardsEntriesRequestOnBehalfOf(const FString& PlayerId, UGameSparksRequestArray* Challenges = nullptr, bool InverseSocial = false, UGameSparksRequestArray* Leaderboards = nullptr, FString Player = "", bool Social = false, UGameSparksRequestArray* TeamTypes = nullptr,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSLeaderboardsEntriesRequest();

private:
	
	UPROPERTY()
	UGameSparksRequestArray* challenges;
	
	UPROPERTY()
	bool inverseSocial;
	
	UPROPERTY()
	UGameSparksRequestArray* leaderboards;
	
	UPROPERTY()
	FString player;

	
	UPROPERTY()
	bool social;
	
	UPROPERTY()
	UGameSparksRequestArray* teamTypes;

	UPROPERTY()
	UGameSparksScriptData* scriptData;
	
	UPROPERTY()
	bool durable;
	
	UPROPERTY()
	int32 requestTimeoutSeconds;

	UPROPERTY()
	FString playerId;
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnLeaveTeamRequest_Response, FGSLeaveTeamResponse, LeaveTeamResponse, bool, hasErrors);

UCLASS()
class GAMESPARKS_API UGSLeaveTeamRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnLeaveTeamRequest_Response OnResponse;
	
	/**
	Allows a player to leave a team.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS LeaveTeamRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Teams")
	static UGSLeaveTeamRequest* SendLeaveTeamRequest(FString OwnerId = "", FString TeamId = "", FString TeamType = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);

	/**
	Allows a player to leave a team.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS LeaveTeamRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks Server-side|Requests|Teams")
	static UGSLeaveTeamRequest* SendLeaveTeamRequestOnBehalfOf(const FString& PlayerId, FString OwnerId = "", FString TeamId = "", FString TeamType = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSLeaveTeamRequest();

private:
	
	UPROPERTY()
	FString ownerId;

	
	UPROPERTY()
	FString teamId;
	
	UPROPERTY()
	FString teamType;

	UPROPERTY()
	UGameSparksScriptData* scriptData;
	
	UPROPERTY()
	bool durable;
	
	UPROPERTY()
	int32 requestTimeoutSeconds;

	UPROPERTY()
	FString playerId;
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnListAchievementsRequest_Response, FGSListAchievementsResponse, ListAchievementsResponse, bool, hasErrors);

UCLASS()
class GAMESPARKS_API UGSListAchievementsRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnListAchievementsRequest_Response OnResponse;
	
	/**
	Retrieves a list of the configured achievements in the game, along with whether the current player has earned the achievement.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS ListAchievementsRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Player")
	static UGSListAchievementsRequest* SendListAchievementsRequest( UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);

	/**
	Retrieves a list of the configured achievements in the game, along with whether the current player has earned the achievement.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS ListAchievementsRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks Server-side|Requests|Player")
	static UGSListAchievementsRequest* SendListAchievementsRequestOnBehalfOf(const FString& PlayerId,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSListAchievementsRequest();

private:


	UPROPERTY()
	UGameSparksScriptData* scriptData;
	
	UPROPERTY()
	bool durable;
	
	UPROPERTY()
	int32 requestTimeoutSeconds;

	UPROPERTY()
	FString playerId;
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnListBulkJobsAdminRequest_Response, FGSListBulkJobsAdminResponse, ListBulkJobsAdminResponse, bool, hasErrors);

UCLASS()
class GAMESPARKS_API UGSListBulkJobsAdminRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnListBulkJobsAdminRequest_Response OnResponse;
	
	/**
	Lists existing bulk jobs.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS ListBulkJobsAdminRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Admin")
	static UGSListBulkJobsAdminRequest* SendListBulkJobsAdminRequest(UGameSparksRequestArray* BulkJobIds = nullptr,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);

	/**
	Lists existing bulk jobs.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS ListBulkJobsAdminRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks Server-side|Requests|Admin")
	static UGSListBulkJobsAdminRequest* SendListBulkJobsAdminRequestOnBehalfOf(const FString& PlayerId, UGameSparksRequestArray* BulkJobIds = nullptr,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSListBulkJobsAdminRequest();

private:
	
	UPROPERTY()
	UGameSparksRequestArray* bulkJobIds;


	UPROPERTY()
	UGameSparksScriptData* scriptData;
	
	UPROPERTY()
	bool durable;
	
	UPROPERTY()
	int32 requestTimeoutSeconds;

	UPROPERTY()
	FString playerId;
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnListChallengeRequest_Response, FGSListChallengeResponse, ListChallengeResponse, bool, hasErrors);

UCLASS()
class GAMESPARKS_API UGSListChallengeRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnListChallengeRequest_Response OnResponse;
	
	/**
	Returns a list of challenges in the state defined in the 'state' field.
	The response can be further filtered by passing a shortCode field which will limit the returned lists to challenges of that short code.
	Valid states are:
	WAITING : The challenge has been issued and accepted and is waiting for the start date.
	RUNNING : The challenge is active.
	ISSUED : The challenge has been issued by the current player and is waiting to be accepted.
	RECEIVED : The challenge has been issued to the current player and is waiting to be accepted.
	COMPLETE : The challenge has completed.
	DECLINED : The challenge has been issued by the current player and has been declined.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS ListChallengeRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Multiplayer")
	static UGSListChallengeRequest* SendListChallengeRequest(int32 EntryCount = 0, int32 Offset = 0, FString ShortCode = "", FString State = "", UGameSparksRequestArray* States = nullptr,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);

	/**
	Returns a list of challenges in the state defined in the 'state' field.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	The response can be further filtered by passing a shortCode field which will limit the returned lists to challenges of that short code.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	Valid states are:

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	WAITING : The challenge has been issued and accepted and is waiting for the start date.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	RUNNING : The challenge is active.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	ISSUED : The challenge has been issued by the current player and is waiting to be accepted.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	RECEIVED : The challenge has been issued to the current player and is waiting to be accepted.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	COMPLETE : The challenge has completed.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	DECLINED : The challenge has been issued by the current player and has been declined.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS ListChallengeRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks Server-side|Requests|Multiplayer")
	static UGSListChallengeRequest* SendListChallengeRequestOnBehalfOf(const FString& PlayerId, int32 EntryCount = 0, int32 Offset = 0, FString ShortCode = "", FString State = "", UGameSparksRequestArray* States = nullptr,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSListChallengeRequest();

private:
	
	UPROPERTY()
	int32 entryCount;
	
	UPROPERTY()
	int32 offset;

	
	UPROPERTY()
	FString shortCode;
	
	UPROPERTY()
	FString state;
	
	UPROPERTY()
	UGameSparksRequestArray* states;

	UPROPERTY()
	UGameSparksScriptData* scriptData;
	
	UPROPERTY()
	bool durable;
	
	UPROPERTY()
	int32 requestTimeoutSeconds;

	UPROPERTY()
	FString playerId;
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnListChallengeTypeRequest_Response, FGSListChallengeTypeResponse, ListChallengeTypeResponse, bool, hasErrors);

UCLASS()
class GAMESPARKS_API UGSListChallengeTypeRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnListChallengeTypeRequest_Response OnResponse;
	
	/**
	Returns the list of configured challenge types.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS ListChallengeTypeRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Multiplayer")
	static UGSListChallengeTypeRequest* SendListChallengeTypeRequest( UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);

	/**
	Returns the list of configured challenge types.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS ListChallengeTypeRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks Server-side|Requests|Multiplayer")
	static UGSListChallengeTypeRequest* SendListChallengeTypeRequestOnBehalfOf(const FString& PlayerId,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSListChallengeTypeRequest();

private:


	UPROPERTY()
	UGameSparksScriptData* scriptData;
	
	UPROPERTY()
	bool durable;
	
	UPROPERTY()
	int32 requestTimeoutSeconds;

	UPROPERTY()
	FString playerId;
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnListGameFriendsRequest_Response, FGSListGameFriendsResponse, ListGameFriendsResponse, bool, hasErrors);

UCLASS()
class GAMESPARKS_API UGSListGameFriendsRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnListGameFriendsRequest_Response OnResponse;
	
	/**
	Returns the list of the current players game friends.
	A Game friend is someone in their social network who also plays the game.
	Against each friend, an indicator is supplied to show whether the friend is currently connected to the GameSparks service
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS ListGameFriendsRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Player")
	static UGSListGameFriendsRequest* SendListGameFriendsRequest( UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);

	/**
	Returns the list of the current players game friends.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	A Game friend is someone in their social network who also plays the game.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	Against each friend, an indicator is supplied to show whether the friend is currently connected to the GameSparks service

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS ListGameFriendsRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks Server-side|Requests|Player")
	static UGSListGameFriendsRequest* SendListGameFriendsRequestOnBehalfOf(const FString& PlayerId,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSListGameFriendsRequest();

private:


	UPROPERTY()
	UGameSparksScriptData* scriptData;
	
	UPROPERTY()
	bool durable;
	
	UPROPERTY()
	int32 requestTimeoutSeconds;

	UPROPERTY()
	FString playerId;
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnListInviteFriendsRequest_Response, FGSListInviteFriendsResponse, ListInviteFriendsResponse, bool, hasErrors);

UCLASS()
class GAMESPARKS_API UGSListInviteFriendsRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnListInviteFriendsRequest_Response OnResponse;
	
	/**
	Returns the list of the current players friends in their social network, who are not yet playing this game.
	This is dependent on the security and privacy policies of the social network.
	For example, Facebook's policies prevent this friend list being provided, whereas Twitter will supply a list of users who are not playing the game.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS ListInviteFriendsRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Player")
	static UGSListInviteFriendsRequest* SendListInviteFriendsRequest( UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);

	/**
	Returns the list of the current players friends in their social network, who are not yet playing this game.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	This is dependent on the security and privacy policies of the social network.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	For example, Facebook's policies prevent this friend list being provided, whereas Twitter will supply a list of users who are not playing the game.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS ListInviteFriendsRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks Server-side|Requests|Player")
	static UGSListInviteFriendsRequest* SendListInviteFriendsRequestOnBehalfOf(const FString& PlayerId,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSListInviteFriendsRequest();

private:


	UPROPERTY()
	UGameSparksScriptData* scriptData;
	
	UPROPERTY()
	bool durable;
	
	UPROPERTY()
	int32 requestTimeoutSeconds;

	UPROPERTY()
	FString playerId;
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnListLeaderboardsRequest_Response, FGSListLeaderboardsResponse, ListLeaderboardsResponse, bool, hasErrors);

UCLASS()
class GAMESPARKS_API UGSListLeaderboardsRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnListLeaderboardsRequest_Response OnResponse;
	
	/**
	Returns a list of all leaderboards configured in the game.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS ListLeaderboardsRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Leaderboards")
	static UGSListLeaderboardsRequest* SendListLeaderboardsRequest( UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);

	/**
	Returns a list of all leaderboards configured in the game.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS ListLeaderboardsRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks Server-side|Requests|Leaderboards")
	static UGSListLeaderboardsRequest* SendListLeaderboardsRequestOnBehalfOf(const FString& PlayerId,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSListLeaderboardsRequest();

private:


	UPROPERTY()
	UGameSparksScriptData* scriptData;
	
	UPROPERTY()
	bool durable;
	
	UPROPERTY()
	int32 requestTimeoutSeconds;

	UPROPERTY()
	FString playerId;
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnListMessageDetailRequest_Response, FGSListMessageDetailResponse, ListMessageDetailResponse, bool, hasErrors);

UCLASS()
class GAMESPARKS_API UGSListMessageDetailRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnListMessageDetailRequest_Response OnResponse;
	
	/**
	Returns the list of the current player's messages / notifications.
	The list only contains un-dismissed messages, to dismiss a message see DismissMessageRequest Read the section on Messages to see the complete list of messages and their meaning.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS ListMessageDetailRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Player")
	static UGSListMessageDetailRequest* SendListMessageDetailRequest(int32 EntryCount = 0, FString Include = "", int32 Offset = 0, FString Status = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);

	/**
	Returns the list of the current player's messages / notifications.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	The list only contains un-dismissed messages, to dismiss a message see DismissMessageRequest Read the section on Messages to see the complete list of messages and their meaning.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS ListMessageDetailRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks Server-side|Requests|Player")
	static UGSListMessageDetailRequest* SendListMessageDetailRequestOnBehalfOf(const FString& PlayerId, int32 EntryCount = 0, FString Include = "", int32 Offset = 0, FString Status = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSListMessageDetailRequest();

private:
	
	UPROPERTY()
	int32 entryCount;
	
	UPROPERTY()
	FString include;
	
	UPROPERTY()
	int32 offset;

	
	UPROPERTY()
	FString status;

	UPROPERTY()
	UGameSparksScriptData* scriptData;
	
	UPROPERTY()
	bool durable;
	
	UPROPERTY()
	int32 requestTimeoutSeconds;

	UPROPERTY()
	FString playerId;
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnListMessageRequest_Response, FGSListMessageResponse, ListMessageResponse, bool, hasErrors);

UCLASS()
class GAMESPARKS_API UGSListMessageRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnListMessageRequest_Response OnResponse;
	
	/**
	Returns the list of the current player's messages / notifications.
	The list only contains un-dismissed messages, to dismiss a message see DismissMessageRequest Read the section on Messages to see the complete list of messages and their meaning.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS ListMessageRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Player")
	static UGSListMessageRequest* SendListMessageRequest(int32 EntryCount = 0, FString Include = "", int32 Offset = 0,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);

	/**
	Returns the list of the current player's messages / notifications.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	The list only contains un-dismissed messages, to dismiss a message see DismissMessageRequest Read the section on Messages to see the complete list of messages and their meaning.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS ListMessageRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks Server-side|Requests|Player")
	static UGSListMessageRequest* SendListMessageRequestOnBehalfOf(const FString& PlayerId, int32 EntryCount = 0, FString Include = "", int32 Offset = 0,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSListMessageRequest();

private:
	
	UPROPERTY()
	int32 entryCount;
	
	UPROPERTY()
	FString include;
	
	UPROPERTY()
	int32 offset;


	UPROPERTY()
	UGameSparksScriptData* scriptData;
	
	UPROPERTY()
	bool durable;
	
	UPROPERTY()
	int32 requestTimeoutSeconds;

	UPROPERTY()
	FString playerId;
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnListMessageSummaryRequest_Response, FGSListMessageSummaryResponse, ListMessageSummaryResponse, bool, hasErrors);

UCLASS()
class GAMESPARKS_API UGSListMessageSummaryRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnListMessageSummaryRequest_Response OnResponse;
	
	/**
	Returns a summary of the list of the current players messages / notifications.
	The list only contains un-dismissed messages, to dismiss a message see DismissMessageRequest.
	The full message can be retrieved using GetMessageRequest Read the section on Messages to see the complete list of messages and their meanings.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS ListMessageSummaryRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Player")
	static UGSListMessageSummaryRequest* SendListMessageSummaryRequest(int32 EntryCount = 0, int32 Offset = 0,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);

	/**
	Returns a summary of the list of the current players messages / notifications.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	The list only contains un-dismissed messages, to dismiss a message see DismissMessageRequest.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	The full message can be retrieved using GetMessageRequest Read the section on Messages to see the complete list of messages and their meanings.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS ListMessageSummaryRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks Server-side|Requests|Player")
	static UGSListMessageSummaryRequest* SendListMessageSummaryRequestOnBehalfOf(const FString& PlayerId, int32 EntryCount = 0, int32 Offset = 0,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSListMessageSummaryRequest();

private:
	
	UPROPERTY()
	int32 entryCount;
	
	UPROPERTY()
	int32 offset;


	UPROPERTY()
	UGameSparksScriptData* scriptData;
	
	UPROPERTY()
	bool durable;
	
	UPROPERTY()
	int32 requestTimeoutSeconds;

	UPROPERTY()
	FString playerId;
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnListTeamChatRequest_Response, FGSListTeamChatResponse, ListTeamChatResponse, bool, hasErrors);

UCLASS()
class GAMESPARKS_API UGSListTeamChatRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnListTeamChatRequest_Response OnResponse;
	
	/**
	Get a list of the messages sent to the team (by players using SendTeamChatMessageRequest).
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS ListTeamChatRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Teams")
	static UGSListTeamChatRequest* SendListTeamChatRequest(int32 EntryCount = 0, int32 Offset = 0, FString OwnerId = "", FString TeamId = "", FString TeamType = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);

	/**
	Get a list of the messages sent to the team (by players using SendTeamChatMessageRequest).

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS ListTeamChatRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks Server-side|Requests|Teams")
	static UGSListTeamChatRequest* SendListTeamChatRequestOnBehalfOf(const FString& PlayerId, int32 EntryCount = 0, int32 Offset = 0, FString OwnerId = "", FString TeamId = "", FString TeamType = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSListTeamChatRequest();

private:
	
	UPROPERTY()
	int32 entryCount;
	
	UPROPERTY()
	int32 offset;
	
	UPROPERTY()
	FString ownerId;

	
	UPROPERTY()
	FString teamId;
	
	UPROPERTY()
	FString teamType;

	UPROPERTY()
	UGameSparksScriptData* scriptData;
	
	UPROPERTY()
	bool durable;
	
	UPROPERTY()
	int32 requestTimeoutSeconds;

	UPROPERTY()
	FString playerId;
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnListTeamsRequest_Response, FGSListTeamsResponse, ListTeamsResponse, bool, hasErrors);

UCLASS()
class GAMESPARKS_API UGSListTeamsRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnListTeamsRequest_Response OnResponse;
	
	/**
	Returns a list of teams. Can be filtered on team name or team type.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS ListTeamsRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Teams")
	static UGSListTeamsRequest* SendListTeamsRequest(int32 EntryCount = 0, int32 Offset = 0, FString TeamNameFilter = "", FString TeamTypeFilter = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);

	/**
	Returns a list of teams. Can be filtered on team name or team type.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS ListTeamsRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks Server-side|Requests|Teams")
	static UGSListTeamsRequest* SendListTeamsRequestOnBehalfOf(const FString& PlayerId, int32 EntryCount = 0, int32 Offset = 0, FString TeamNameFilter = "", FString TeamTypeFilter = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSListTeamsRequest();

private:
	
	UPROPERTY()
	int32 entryCount;
	
	UPROPERTY()
	int32 offset;

	
	UPROPERTY()
	FString teamNameFilter;
	
	UPROPERTY()
	FString teamTypeFilter;

	UPROPERTY()
	UGameSparksScriptData* scriptData;
	
	UPROPERTY()
	bool durable;
	
	UPROPERTY()
	int32 requestTimeoutSeconds;

	UPROPERTY()
	FString playerId;
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnListTransactionsRequest_Response, FGSListTransactionsResponse, ListTransactionsResponse, bool, hasErrors);

UCLASS()
class GAMESPARKS_API UGSListTransactionsRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnListTransactionsRequest_Response OnResponse;
	
	/**
	Returns a list of the current player's transaction history.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS ListTransactionsRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Player")
	static UGSListTransactionsRequest* SendListTransactionsRequest(FString DateFrom = "", FString DateTo = "", int32 EntryCount = 0, FString Include = "", int32 Offset = 0,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);

	/**
	Returns a list of the current player's transaction history.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS ListTransactionsRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks Server-side|Requests|Player")
	static UGSListTransactionsRequest* SendListTransactionsRequestOnBehalfOf(const FString& PlayerId, FString DateFrom = "", FString DateTo = "", int32 EntryCount = 0, FString Include = "", int32 Offset = 0,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSListTransactionsRequest();

private:
	
	UPROPERTY()
	FString dateFrom;
	
	UPROPERTY()
	FString dateTo;
	
	UPROPERTY()
	int32 entryCount;
	
	UPROPERTY()
	FString include;
	
	UPROPERTY()
	int32 offset;


	UPROPERTY()
	UGameSparksScriptData* scriptData;
	
	UPROPERTY()
	bool durable;
	
	UPROPERTY()
	int32 requestTimeoutSeconds;

	UPROPERTY()
	FString playerId;
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnListVirtualGoodsRequest_Response, FGSListVirtualGoodsResponse, ListVirtualGoodsResponse, bool, hasErrors);

UCLASS()
class GAMESPARKS_API UGSListVirtualGoodsRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnListVirtualGoodsRequest_Response OnResponse;
	
	/**
	Returns the list of configured virtual goods.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS ListVirtualGoodsRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Store")
	static UGSListVirtualGoodsRequest* SendListVirtualGoodsRequest(bool IncludeDisabled = false, UGameSparksRequestArray* Tags = nullptr,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);

	/**
	Returns the list of configured virtual goods.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS ListVirtualGoodsRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks Server-side|Requests|Store")
	static UGSListVirtualGoodsRequest* SendListVirtualGoodsRequestOnBehalfOf(const FString& PlayerId, bool IncludeDisabled = false, UGameSparksRequestArray* Tags = nullptr,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSListVirtualGoodsRequest();

private:
	
	UPROPERTY()
	bool includeDisabled;

	
	UPROPERTY()
	UGameSparksRequestArray* tags;

	UPROPERTY()
	UGameSparksScriptData* scriptData;
	
	UPROPERTY()
	bool durable;
	
	UPROPERTY()
	int32 requestTimeoutSeconds;

	UPROPERTY()
	FString playerId;
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnLogChallengeEventRequest_Response, FGSLogChallengeEventResponse, LogChallengeEventResponse, bool, hasErrors);

UCLASS()
class GAMESPARKS_API UGSLogChallengeEventRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnLogChallengeEventRequest_Response OnResponse;
	
	/**
	Allows a user defined event to be triggered. The event will be posted to the challenge specified.
	This call differs from most as it does not have a fixed format. The @class, challengeInstanceId and eventKey attributes are common, but the rest of the attributes are as defined in the Event object configured in the dev portal.
	The example below shows a request to en event with a short code of HS with 2 attributes, 'HS' & 'GL'.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS LogChallengeEventRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Multiplayer")
	static UGSLogChallengeEventRequest* SendLogChallengeEventRequest(FString ChallengeInstanceId = "", FString EventKey = "",  UGameSparksLogEventData* LogEventData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);

	/**
	Allows a user defined event to be triggered. The event will be posted to the challenge specified.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	This call differs from most as it does not have a fixed format. The @class, challengeInstanceId and eventKey attributes are common, but the rest of the attributes are as defined in the Event object configured in the dev portal.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	The example below shows a request to en event with a short code of HS with 2 attributes, 'HS' & 'GL'.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS LogChallengeEventRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks Server-side|Requests|Multiplayer")
	static UGSLogChallengeEventRequest* SendLogChallengeEventRequestOnBehalfOf(const FString& PlayerId, FString ChallengeInstanceId = "", FString EventKey = "",  UGameSparksLogEventData* LogEventData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSLogChallengeEventRequest();

private:
	
	UPROPERTY()
	FString challengeInstanceId;
	
	UPROPERTY()
	FString eventKey;

	UPROPERTY()
	UGameSparksLogEventData* logEventData;
	
	UPROPERTY()
	bool durable;
	
	UPROPERTY()
	int32 requestTimeoutSeconds;

	UPROPERTY()
	FString playerId;
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnLogEventRequest_Response, FGSLogEventResponse, LogEventResponse, bool, hasErrors);

UCLASS()
class GAMESPARKS_API UGSLogEventRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnLogEventRequest_Response OnResponse;
	
	/**
	Allows a user defined event to be triggered.
	This call differs from most as it does not have a fixed format. The @class and eventKey attributes are common, but the rest of the attributes are as defined in the Event object configured in the dev portal.
	The example below shows a request to an event with a short code of HS with 2 attributes, 'HS' & 'GL'.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS LogEventRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Player")
	static UGSLogEventRequest* SendLogEventRequest(FString EventKey = "",  UGameSparksLogEventData* LogEventData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);

	/**
	Allows a user defined event to be triggered.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	This call differs from most as it does not have a fixed format. The @class and eventKey attributes are common, but the rest of the attributes are as defined in the Event object configured in the dev portal.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	The example below shows a request to an event with a short code of HS with 2 attributes, 'HS' & 'GL'.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS LogEventRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks Server-side|Requests|Player")
	static UGSLogEventRequest* SendLogEventRequestOnBehalfOf(const FString& PlayerId, FString EventKey = "",  UGameSparksLogEventData* LogEventData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSLogEventRequest();

private:
	
	UPROPERTY()
	FString eventKey;

	UPROPERTY()
	UGameSparksLogEventData* logEventData;
	
	UPROPERTY()
	bool durable;
	
	UPROPERTY()
	int32 requestTimeoutSeconds;

	UPROPERTY()
	FString playerId;
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnMatchDetailsRequest_Response, FGSMatchDetailsResponse, MatchDetailsResponse, bool, hasErrors);

UCLASS()
class GAMESPARKS_API UGSMatchDetailsRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnMatchDetailsRequest_Response OnResponse;
	
	/**
	Find the details of an existing match this player belongs to, using the matchId
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS MatchDetailsRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Multiplayer")
	static UGSMatchDetailsRequest* SendMatchDetailsRequest(FString MatchId = "", bool RealtimeEnabled = false,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);

	/**
	Find the details of an existing match this player belongs to, using the matchId

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS MatchDetailsRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks Server-side|Requests|Multiplayer")
	static UGSMatchDetailsRequest* SendMatchDetailsRequestOnBehalfOf(const FString& PlayerId, FString MatchId = "", bool RealtimeEnabled = false,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSMatchDetailsRequest();

private:
	
	UPROPERTY()
	FString matchId;
	
	UPROPERTY()
	bool realtimeEnabled;


	UPROPERTY()
	UGameSparksScriptData* scriptData;
	
	UPROPERTY()
	bool durable;
	
	UPROPERTY()
	int32 requestTimeoutSeconds;

	UPROPERTY()
	FString playerId;
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnMatchmakingRequest_Response, FGSMatchmakingResponse, MatchmakingResponse, bool, hasErrors);

UCLASS()
class GAMESPARKS_API UGSMatchmakingRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnMatchmakingRequest_Response OnResponse;
	
	/**
	Register this player for matchmaking, using the given skill and matchShortCode.
	Players looking for a match using the same matchShortCode will be considered for a match, based on the matchConfig.
	Each player must match the other for the match to be found.
	If the matchShortCode points to a match with realtime enabled, in order to minimise latency, the location of Players and their proximity to one another takes precedence over their reciprocal skill values.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS MatchmakingRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Multiplayer")
	static UGSMatchmakingRequest* SendMatchmakingRequest(FString Action = "", UGameSparksScriptData* CustomQuery = nullptr, UGameSparksScriptData* MatchData = nullptr, FString MatchGroup = "", FString MatchShortCode = "", UGameSparksScriptData* ParticipantData = nullptr, int32 Skill = 0,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);

	/**
	Register this player for matchmaking, using the given skill and matchShortCode.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	Players looking for a match using the same matchShortCode will be considered for a match, based on the matchConfig.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	Each player must match the other for the match to be found.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	If the matchShortCode points to a match with realtime enabled, in order to minimise latency, the location of Players and their proximity to one another takes precedence over their reciprocal skill values.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS MatchmakingRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks Server-side|Requests|Multiplayer")
	static UGSMatchmakingRequest* SendMatchmakingRequestOnBehalfOf(const FString& PlayerId, FString Action = "", UGameSparksScriptData* CustomQuery = nullptr, UGameSparksScriptData* MatchData = nullptr, FString MatchGroup = "", FString MatchShortCode = "", UGameSparksScriptData* ParticipantData = nullptr, int32 Skill = 0,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSMatchmakingRequest();

private:
	
	UPROPERTY()
	FString action;
	
	UPROPERTY()
	UGameSparksScriptData* customQuery;
	
	UPROPERTY()
	UGameSparksScriptData* matchData;
	
	UPROPERTY()
	FString matchGroup;
	
	UPROPERTY()
	FString matchShortCode;
	
	UPROPERTY()
	UGameSparksScriptData* participantData;

	
	UPROPERTY()
	int32 skill;

	UPROPERTY()
	UGameSparksScriptData* scriptData;
	
	UPROPERTY()
	bool durable;
	
	UPROPERTY()
	int32 requestTimeoutSeconds;

	UPROPERTY()
	FString playerId;
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnNXConnectRequest_Response, FGSAuthenticationResponse, AuthenticationResponse, bool, hasErrors);

UCLASS()
class GAMESPARKS_API UGSNXConnectRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnNXConnectRequest_Response OnResponse;
	
	/**
	Allows an Nintendo Network Service Account (NSA) to be used as an authentication mechanism.
	Once authenticated the platform can determine the current players details from the NSA and store them within GameSparks.
	GameSparks will determine the player's friends and whether any of them are currently registered with the game.
	If the NSA is already linked to a player, the current session will switch to the linked player.
	If the current player has previously created an account using either DeviceAuthentictionRequest or RegistrationRequest AND the NSA is not already registered with the game, the NSA will be linked to the current player.
	If the current player has not authenticated and the NSA is not known, a new player will be created using the NSA details and the session will be authenticated against the new player.
	If the NSA is already known, the session will switch to being the previously created user.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS NXConnectRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Authentication")
	static UGSNXConnectRequest* SendNXConnectRequest(bool AccountPerLoginId = false, FString DisplayName = "", bool DoNotLinkToCurrentPlayer = false, bool ErrorOnSwitch = false, FString NsaIdToken = "", UGameSparksScriptData* Segments = nullptr, bool SwitchIfPossible = false, bool SyncDisplayName = false,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);

	/**
	Allows an Nintendo Network Service Account (NSA) to be used as an authentication mechanism.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	Once authenticated the platform can determine the current players details from the NSA and store them within GameSparks.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	GameSparks will determine the player's friends and whether any of them are currently registered with the game.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	If the NSA is already linked to a player, the current session will switch to the linked player.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	If the current player has previously created an account using either DeviceAuthentictionRequest or RegistrationRequest AND the NSA is not already registered with the game, the NSA will be linked to the current player.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	If the current player has not authenticated and the NSA is not known, a new player will be created using the NSA details and the session will be authenticated against the new player.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	If the NSA is already known, the session will switch to being the previously created user.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS NXConnectRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks Server-side|Requests|Authentication")
	static UGSNXConnectRequest* SendNXConnectRequestOnBehalfOf(const FString& PlayerId, bool AccountPerLoginId = false, FString DisplayName = "", bool DoNotLinkToCurrentPlayer = false, bool ErrorOnSwitch = false, FString NsaIdToken = "", UGameSparksScriptData* Segments = nullptr, bool SwitchIfPossible = false, bool SyncDisplayName = false,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSNXConnectRequest();

private:
	
	UPROPERTY()
	bool accountPerLoginId;
	
	UPROPERTY()
	FString displayName;
	
	UPROPERTY()
	bool doNotLinkToCurrentPlayer;
	
	UPROPERTY()
	bool errorOnSwitch;
	
	UPROPERTY()
	FString nsaIdToken;

	
	UPROPERTY()
	UGameSparksScriptData* segments;
	
	UPROPERTY()
	bool switchIfPossible;
	
	UPROPERTY()
	bool syncDisplayName;

	UPROPERTY()
	UGameSparksScriptData* scriptData;
	
	UPROPERTY()
	bool durable;
	
	UPROPERTY()
	int32 requestTimeoutSeconds;

	UPROPERTY()
	FString playerId;
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPSNConnectRequest_Response, FGSAuthenticationResponse, AuthenticationResponse, bool, hasErrors);

UCLASS()
class GAMESPARKS_API UGSPSNConnectRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnPSNConnectRequest_Response OnResponse;
	
	/**
	Allows a PSN account to be used as an authentication mechanism.
	Once authenticated the platform can determine the current players details from the PSN platform and store them within GameSparks.
	GameSparks will determine the player's friends and whether any of them are currently registered with the game.
	If the PSN user is already linked to a player, the current session will switch to the linked player.
	If the current player has previously created an account using either DeviceAuthentictionRequest or RegistrationRequest AND the PSN user is not already registered with the game, the PSN user will be linked to the current player.
	If the current player has not authenticated and the PSN user is not known, a new player will be created using the PSN details and the session will be authenticated against the new player.
	If the PSN user is already known, the session will switch to being the previously created user.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS PSNConnectRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Authentication")
	static UGSPSNConnectRequest* SendPSNConnectRequest(FString AuthorizationCode = "", bool DoNotLinkToCurrentPlayer = false, bool ErrorOnSwitch = false, FString RedirectUri = "", UGameSparksScriptData* Segments = nullptr, bool SwitchIfPossible = false, bool SyncDisplayName = false,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);

	/**
	Allows a PSN account to be used as an authentication mechanism.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	Once authenticated the platform can determine the current players details from the PSN platform and store them within GameSparks.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	GameSparks will determine the player's friends and whether any of them are currently registered with the game.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	If the PSN user is already linked to a player, the current session will switch to the linked player.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	If the current player has previously created an account using either DeviceAuthentictionRequest or RegistrationRequest AND the PSN user is not already registered with the game, the PSN user will be linked to the current player.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	If the current player has not authenticated and the PSN user is not known, a new player will be created using the PSN details and the session will be authenticated against the new player.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	If the PSN user is already known, the session will switch to being the previously created user.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS PSNConnectRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks Server-side|Requests|Authentication")
	static UGSPSNConnectRequest* SendPSNConnectRequestOnBehalfOf(const FString& PlayerId, FString AuthorizationCode = "", bool DoNotLinkToCurrentPlayer = false, bool ErrorOnSwitch = false, FString RedirectUri = "", UGameSparksScriptData* Segments = nullptr, bool SwitchIfPossible = false, bool SyncDisplayName = false,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSPSNConnectRequest();

private:
	
	UPROPERTY()
	FString authorizationCode;
	
	UPROPERTY()
	bool doNotLinkToCurrentPlayer;
	
	UPROPERTY()
	bool errorOnSwitch;
	
	UPROPERTY()
	FString redirectUri;

	
	UPROPERTY()
	UGameSparksScriptData* segments;
	
	UPROPERTY()
	bool switchIfPossible;
	
	UPROPERTY()
	bool syncDisplayName;

	UPROPERTY()
	UGameSparksScriptData* scriptData;
	
	UPROPERTY()
	bool durable;
	
	UPROPERTY()
	int32 requestTimeoutSeconds;

	UPROPERTY()
	FString playerId;
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPsnBuyGoodsRequest_Response, FGSBuyVirtualGoodResponse, BuyVirtualGoodResponse, bool, hasErrors);

UCLASS()
class GAMESPARKS_API UGSPsnBuyGoodsRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnPsnBuyGoodsRequest_Response OnResponse;
	
	/**
	Processes an update of entitlement in PlayStation network.
	The GameSparks platform will update the 'use_count' for an entitlement (by default 'use_count' is 1).
	The request will be rejected if entitlement 'use_limit' is 0
	GampSparks platform by default will use internally saved PSN user access token
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS PsnBuyGoodsRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Store")
	static UGSPsnBuyGoodsRequest* SendPsnBuyGoodsRequest(FString AuthorizationCode = "", FString CurrencyCode = "", FString EntitlementLabel = "", FString RedirectUri = "", float SubUnitPrice = 0.0f, bool UniqueTransactionByPlayer = false, int32 UseCount = 0,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);

	/**
	Processes an update of entitlement in PlayStation network.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	The GameSparks platform will update the 'use_count' for an entitlement (by default 'use_count' is 1).

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	The request will be rejected if entitlement 'use_limit' is 0

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	GampSparks platform by default will use internally saved PSN user access token

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS PsnBuyGoodsRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks Server-side|Requests|Store")
	static UGSPsnBuyGoodsRequest* SendPsnBuyGoodsRequestOnBehalfOf(const FString& PlayerId, FString AuthorizationCode = "", FString CurrencyCode = "", FString EntitlementLabel = "", FString RedirectUri = "", float SubUnitPrice = 0.0f, bool UniqueTransactionByPlayer = false, int32 UseCount = 0,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSPsnBuyGoodsRequest();

private:
	
	UPROPERTY()
	FString authorizationCode;
	
	UPROPERTY()
	FString currencyCode;
	
	UPROPERTY()
	FString entitlementLabel;
	
	UPROPERTY()
	FString redirectUri;

	
	UPROPERTY()
	float subUnitPrice;
	
	UPROPERTY()
	bool uniqueTransactionByPlayer;
	
	UPROPERTY()
	int32 useCount;

	UPROPERTY()
	UGameSparksScriptData* scriptData;
	
	UPROPERTY()
	bool durable;
	
	UPROPERTY()
	int32 requestTimeoutSeconds;

	UPROPERTY()
	FString playerId;
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPushRegistrationRequest_Response, FGSPushRegistrationResponse, PushRegistrationResponse, bool, hasErrors);

UCLASS()
class GAMESPARKS_API UGSPushRegistrationRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnPushRegistrationRequest_Response OnResponse;
	
	/**
	Registers the current device for push notifications. Currently GameSparks supports iOS, Android (GCM), FCM, Kindle, Viber & Microsoft Push notifications.
	Supply the device type, and the push notification identifier for the device.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS PushRegistrationRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Misc")
	static UGSPushRegistrationRequest* SendPushRegistrationRequest(FString DeviceOS = "", FString PushId = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);

	/**
	Registers the current device for push notifications. Currently GameSparks supports iOS, Android (GCM), FCM, Kindle, Viber & Microsoft Push notifications.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	Supply the device type, and the push notification identifier for the device.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS PushRegistrationRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks Server-side|Requests|Misc")
	static UGSPushRegistrationRequest* SendPushRegistrationRequestOnBehalfOf(const FString& PlayerId, FString DeviceOS = "", FString PushId = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSPushRegistrationRequest();

private:
	
	UPROPERTY()
	FString deviceOS;
	
	UPROPERTY()
	FString pushId;


	UPROPERTY()
	UGameSparksScriptData* scriptData;
	
	UPROPERTY()
	bool durable;
	
	UPROPERTY()
	int32 requestTimeoutSeconds;

	UPROPERTY()
	FString playerId;
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnQQConnectRequest_Response, FGSAuthenticationResponse, AuthenticationResponse, bool, hasErrors);

UCLASS()
class GAMESPARKS_API UGSQQConnectRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnQQConnectRequest_Response OnResponse;
	
	/**
	Allows a QQ access token to be used as an authentication mechanism.
	Once authenticated the platform can determine the current players details from the QQ platform and store them within GameSparks.
	If the QQ user is already linked to a player, the current session will switch to the linked player.
	If the current player has previously created an account using either DeviceAuthenticationRequest or RegistrationRequest AND the QQ user is not already registered with the game, the QQ user will be linked to the current player.
	If the current player has not authenticated and the QQ user is not known, a new player will be created using the QQ details and the session will be authenticated against the new player.
	If the QQ user is already known, the session will switch to being the previously created user.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS QQConnectRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Authentication")
	static UGSQQConnectRequest* SendQQConnectRequest(FString AccessToken = "", bool DoNotLinkToCurrentPlayer = false, bool ErrorOnSwitch = false, UGameSparksScriptData* Segments = nullptr, bool SwitchIfPossible = false, bool SyncDisplayName = false,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);

	/**
	Allows a QQ access token to be used as an authentication mechanism.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	Once authenticated the platform can determine the current players details from the QQ platform and store them within GameSparks.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	If the QQ user is already linked to a player, the current session will switch to the linked player.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	If the current player has previously created an account using either DeviceAuthenticationRequest or RegistrationRequest AND the QQ user is not already registered with the game, the QQ user will be linked to the current player.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	If the current player has not authenticated and the QQ user is not known, a new player will be created using the QQ details and the session will be authenticated against the new player.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	If the QQ user is already known, the session will switch to being the previously created user.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS QQConnectRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks Server-side|Requests|Authentication")
	static UGSQQConnectRequest* SendQQConnectRequestOnBehalfOf(const FString& PlayerId, FString AccessToken = "", bool DoNotLinkToCurrentPlayer = false, bool ErrorOnSwitch = false, UGameSparksScriptData* Segments = nullptr, bool SwitchIfPossible = false, bool SyncDisplayName = false,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSQQConnectRequest();

private:
	
	UPROPERTY()
	FString accessToken;
	
	UPROPERTY()
	bool doNotLinkToCurrentPlayer;
	
	UPROPERTY()
	bool errorOnSwitch;

	
	UPROPERTY()
	UGameSparksScriptData* segments;
	
	UPROPERTY()
	bool switchIfPossible;
	
	UPROPERTY()
	bool syncDisplayName;

	UPROPERTY()
	UGameSparksScriptData* scriptData;
	
	UPROPERTY()
	bool durable;
	
	UPROPERTY()
	int32 requestTimeoutSeconds;

	UPROPERTY()
	FString playerId;
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnRegistrationRequest_Response, FGSRegistrationResponse, RegistrationResponse, bool, hasErrors);

UCLASS()
class GAMESPARKS_API UGSRegistrationRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnRegistrationRequest_Response OnResponse;
	
	/**
	Allows a new player to be created using a username, password display name.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS RegistrationRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Authentication")
	static UGSRegistrationRequest* SendRegistrationRequest(FString DisplayName = "", FString Password = "", UGameSparksScriptData* Segments = nullptr, FString UserName = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);

	/**
	Allows a new player to be created using a username, password display name.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS RegistrationRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks Server-side|Requests|Authentication")
	static UGSRegistrationRequest* SendRegistrationRequestOnBehalfOf(const FString& PlayerId, FString DisplayName = "", FString Password = "", UGameSparksScriptData* Segments = nullptr, FString UserName = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSRegistrationRequest();

private:
	
	UPROPERTY()
	FString displayName;
	
	UPROPERTY()
	FString password;

	
	UPROPERTY()
	UGameSparksScriptData* segments;
	
	UPROPERTY()
	FString userName;

	UPROPERTY()
	UGameSparksScriptData* scriptData;
	
	UPROPERTY()
	bool durable;
	
	UPROPERTY()
	int32 requestTimeoutSeconds;

	UPROPERTY()
	FString playerId;
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnRevokePurchaseGoodsRequest_Response, FGSRevokePurchaseGoodsResponse, RevokePurchaseGoodsResponse, bool, hasErrors);

UCLASS()
class GAMESPARKS_API UGSRevokePurchaseGoodsRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnRevokePurchaseGoodsRequest_Response OnResponse;
	
	/**
	Revokes the purchase of a good. The items aquired will be removed from remaining items of the player.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS RevokePurchaseGoodsRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Admin")
	static UGSRevokePurchaseGoodsRequest* SendRevokePurchaseGoodsRequest(FString PlayerId = "", FString StoreType = "", UGameSparksRequestArray* TransactionIds = nullptr,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);

	/**
	Revokes the purchase of a good. The items aquired will be removed from remaining items of the player.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS RevokePurchaseGoodsRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks Server-side|Requests|Admin")
	static UGSRevokePurchaseGoodsRequest* SendRevokePurchaseGoodsRequestOnBehalfOf(const FString& PlayerId, FString StoreType = "", UGameSparksRequestArray* TransactionIds = nullptr,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSRevokePurchaseGoodsRequest();

private:


	
	UPROPERTY()
	FString storeType;
	
	UPROPERTY()
	UGameSparksRequestArray* transactionIds;

	UPROPERTY()
	UGameSparksScriptData* scriptData;
	
	UPROPERTY()
	bool durable;
	
	UPROPERTY()
	int32 requestTimeoutSeconds;

	UPROPERTY()
	FString playerId;
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnScheduleBulkJobAdminRequest_Response, FGSScheduleBulkJobAdminResponse, ScheduleBulkJobAdminResponse, bool, hasErrors);

UCLASS()
class GAMESPARKS_API UGSScheduleBulkJobAdminRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnScheduleBulkJobAdminRequest_Response OnResponse;
	
	/**
	Schedules a bulk job to be run against multiple players.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS ScheduleBulkJobAdminRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Admin")
	static UGSScheduleBulkJobAdminRequest* SendScheduleBulkJobAdminRequest(UGameSparksScriptData* Data = nullptr, FString ModuleShortCode = "", UGameSparksScriptData* PlayerQuery = nullptr, FString ScheduledTime = "", FString Script = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);

	/**
	Schedules a bulk job to be run against multiple players.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS ScheduleBulkJobAdminRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks Server-side|Requests|Admin")
	static UGSScheduleBulkJobAdminRequest* SendScheduleBulkJobAdminRequestOnBehalfOf(const FString& PlayerId, UGameSparksScriptData* Data = nullptr, FString ModuleShortCode = "", UGameSparksScriptData* PlayerQuery = nullptr, FString ScheduledTime = "", FString Script = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSScheduleBulkJobAdminRequest();

private:
	
	UPROPERTY()
	UGameSparksScriptData* data;
	
	UPROPERTY()
	FString moduleShortCode;
	
	UPROPERTY()
	UGameSparksScriptData* playerQuery;

	
	UPROPERTY()
	FString scheduledTime;
	
	UPROPERTY()
	FString script;

	UPROPERTY()
	UGameSparksScriptData* scriptData;
	
	UPROPERTY()
	bool durable;
	
	UPROPERTY()
	int32 requestTimeoutSeconds;

	UPROPERTY()
	FString playerId;
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSendFriendMessageRequest_Response, FGSSendFriendMessageResponse, SendFriendMessageResponse, bool, hasErrors);

UCLASS()
class GAMESPARKS_API UGSSendFriendMessageRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnSendFriendMessageRequest_Response OnResponse;
	
	/**
	Sends a message to one or more game friend(s). A game friend is someone in the players social network who also plays the game.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS SendFriendMessageRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Player")
	static UGSSendFriendMessageRequest* SendSendFriendMessageRequest(UGameSparksRequestArray* FriendIds = nullptr, FString Message = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);

	/**
	Sends a message to one or more game friend(s). A game friend is someone in the players social network who also plays the game.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS SendFriendMessageRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks Server-side|Requests|Player")
	static UGSSendFriendMessageRequest* SendSendFriendMessageRequestOnBehalfOf(const FString& PlayerId, UGameSparksRequestArray* FriendIds = nullptr, FString Message = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSSendFriendMessageRequest();

private:
	
	UPROPERTY()
	UGameSparksRequestArray* friendIds;
	
	UPROPERTY()
	FString message;


	UPROPERTY()
	UGameSparksScriptData* scriptData;
	
	UPROPERTY()
	bool durable;
	
	UPROPERTY()
	int32 requestTimeoutSeconds;

	UPROPERTY()
	FString playerId;
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSendTeamChatMessageRequest_Response, FGSSendTeamChatMessageResponse, SendTeamChatMessageResponse, bool, hasErrors);

UCLASS()
class GAMESPARKS_API UGSSendTeamChatMessageRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnSendTeamChatMessageRequest_Response OnResponse;
	
	/**
	Send a message to all the players who are member of the given team
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS SendTeamChatMessageRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Teams")
	static UGSSendTeamChatMessageRequest* SendSendTeamChatMessageRequest(FString Message = "", FString OwnerId = "", FString TeamId = "", FString TeamType = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);

	/**
	Send a message to all the players who are member of the given team

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS SendTeamChatMessageRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks Server-side|Requests|Teams")
	static UGSSendTeamChatMessageRequest* SendSendTeamChatMessageRequestOnBehalfOf(const FString& PlayerId, FString Message = "", FString OwnerId = "", FString TeamId = "", FString TeamType = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSSendTeamChatMessageRequest();

private:
	
	UPROPERTY()
	FString message;
	
	UPROPERTY()
	FString ownerId;

	
	UPROPERTY()
	FString teamId;
	
	UPROPERTY()
	FString teamType;

	UPROPERTY()
	UGameSparksScriptData* scriptData;
	
	UPROPERTY()
	bool durable;
	
	UPROPERTY()
	int32 requestTimeoutSeconds;

	UPROPERTY()
	FString playerId;
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSocialDisconnectRequest_Response, FGSSocialDisconnectResponse, SocialDisconnectResponse, bool, hasErrors);

UCLASS()
class GAMESPARKS_API UGSSocialDisconnectRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnSocialDisconnectRequest_Response OnResponse;
	
	/**
	Allows a player's internal profile to be disconnected from an external system to which it is linked.  Any friends linked as result of this connection will be removed.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS SocialDisconnectRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Player")
	static UGSSocialDisconnectRequest* SendSocialDisconnectRequest(FString SystemId = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);

	/**
	Allows a player's internal profile to be disconnected from an external system to which it is linked.  Any friends linked as result of this connection will be removed.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS SocialDisconnectRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks Server-side|Requests|Player")
	static UGSSocialDisconnectRequest* SendSocialDisconnectRequestOnBehalfOf(const FString& PlayerId, FString SystemId = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSSocialDisconnectRequest();

private:

	
	UPROPERTY()
	FString systemId;

	UPROPERTY()
	UGameSparksScriptData* scriptData;
	
	UPROPERTY()
	bool durable;
	
	UPROPERTY()
	int32 requestTimeoutSeconds;

	UPROPERTY()
	FString playerId;
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSocialLeaderboardDataRequest_Response, FGSLeaderboardDataResponse, LeaderboardDataResponse, bool, hasErrors);

UCLASS()
class GAMESPARKS_API UGSSocialLeaderboardDataRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnSocialLeaderboardDataRequest_Response OnResponse;
	
	/**
	Returns leaderboard data that only contains entries of players that are game friends with the current player.
	The GameSparks platform will attempt to return players both ahead and behind the current player, where data is available.
	The entry count defines how many player should be returned both ahead and behind. The numer of results may vary if there are not enough friends either ahead or behind.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS SocialLeaderboardDataRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Leaderboards")
	static UGSSocialLeaderboardDataRequest* SendSocialLeaderboardDataRequest(FString ChallengeInstanceId = "", bool DontErrorOnNotSocial = false, int32 EntryCount = 0, UGameSparksRequestArray* FriendIds = nullptr, int32 IncludeFirst = 0, int32 IncludeLast = 0, bool InverseSocial = false, FString LeaderboardShortCode = "", int32 Offset = 0, bool Social = false, UGameSparksRequestArray* TeamIds = nullptr, UGameSparksRequestArray* TeamTypes = nullptr,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);

	/**
	Returns leaderboard data that only contains entries of players that are game friends with the current player.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	The GameSparks platform will attempt to return players both ahead and behind the current player, where data is available.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	The entry count defines how many player should be returned both ahead and behind. The numer of results may vary if there are not enough friends either ahead or behind.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS SocialLeaderboardDataRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks Server-side|Requests|Leaderboards")
	static UGSSocialLeaderboardDataRequest* SendSocialLeaderboardDataRequestOnBehalfOf(const FString& PlayerId, FString ChallengeInstanceId = "", bool DontErrorOnNotSocial = false, int32 EntryCount = 0, UGameSparksRequestArray* FriendIds = nullptr, int32 IncludeFirst = 0, int32 IncludeLast = 0, bool InverseSocial = false, FString LeaderboardShortCode = "", int32 Offset = 0, bool Social = false, UGameSparksRequestArray* TeamIds = nullptr, UGameSparksRequestArray* TeamTypes = nullptr,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSSocialLeaderboardDataRequest();

private:
	
	UPROPERTY()
	FString challengeInstanceId;
	
	UPROPERTY()
	bool dontErrorOnNotSocial;
	
	UPROPERTY()
	int32 entryCount;
	
	UPROPERTY()
	UGameSparksRequestArray* friendIds;
	
	UPROPERTY()
	int32 includeFirst;
	
	UPROPERTY()
	int32 includeLast;
	
	UPROPERTY()
	bool inverseSocial;
	
	UPROPERTY()
	FString leaderboardShortCode;
	
	UPROPERTY()
	int32 offset;

	
	UPROPERTY()
	bool social;
	
	UPROPERTY()
	UGameSparksRequestArray* teamIds;
	
	UPROPERTY()
	UGameSparksRequestArray* teamTypes;

	UPROPERTY()
	UGameSparksScriptData* scriptData;
	
	UPROPERTY()
	bool durable;
	
	UPROPERTY()
	int32 requestTimeoutSeconds;

	UPROPERTY()
	FString playerId;
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSocialStatusRequest_Response, FGSSocialStatusResponse, SocialStatusResponse, bool, hasErrors);

UCLASS()
class GAMESPARKS_API UGSSocialStatusRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnSocialStatusRequest_Response OnResponse;
	
	/**
	Returns detials of the current social connections of this player. Each connection .
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS SocialStatusRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Misc")
	static UGSSocialStatusRequest* SendSocialStatusRequest( UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);

	/**
	Returns detials of the current social connections of this player. Each connection .

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS SocialStatusRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks Server-side|Requests|Misc")
	static UGSSocialStatusRequest* SendSocialStatusRequestOnBehalfOf(const FString& PlayerId,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSSocialStatusRequest();

private:


	UPROPERTY()
	UGameSparksScriptData* scriptData;
	
	UPROPERTY()
	bool durable;
	
	UPROPERTY()
	int32 requestTimeoutSeconds;

	UPROPERTY()
	FString playerId;
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSteamBuyGoodsRequest_Response, FGSBuyVirtualGoodResponse, BuyVirtualGoodResponse, bool, hasErrors);

UCLASS()
class GAMESPARKS_API UGSSteamBuyGoodsRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnSteamBuyGoodsRequest_Response OnResponse;
	
	/**
	Processes a 'orderid' from a Steam.
	The GameSparks platform will validate the 'orderid' with Steam and process the response. The 'orderid' from the response will be recorded and the request will be rejected, if the 'orderid' has previously been processed, this prevents replay attacks.
	Once verified, the players account will be credited with the Virtual Good, or Virtual Currency the purchase contains. The virtual good will be looked up by matching the 'itemid' in the response with the 'Steam Product ID' configured against the virtual good.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS SteamBuyGoodsRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Store")
	static UGSSteamBuyGoodsRequest* SendSteamBuyGoodsRequest(FString CurrencyCode = "", FString OrderId = "", float SubUnitPrice = 0.0f, bool UniqueTransactionByPlayer = false,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);

	/**
	Processes a 'orderid' from a Steam.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	The GameSparks platform will validate the 'orderid' with Steam and process the response. The 'orderid' from the response will be recorded and the request will be rejected, if the 'orderid' has previously been processed, this prevents replay attacks.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	Once verified, the players account will be credited with the Virtual Good, or Virtual Currency the purchase contains. The virtual good will be looked up by matching the 'itemid' in the response with the 'Steam Product ID' configured against the virtual good.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS SteamBuyGoodsRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks Server-side|Requests|Store")
	static UGSSteamBuyGoodsRequest* SendSteamBuyGoodsRequestOnBehalfOf(const FString& PlayerId, FString CurrencyCode = "", FString OrderId = "", float SubUnitPrice = 0.0f, bool UniqueTransactionByPlayer = false,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSSteamBuyGoodsRequest();

private:
	
	UPROPERTY()
	FString currencyCode;
	
	UPROPERTY()
	FString orderId;

	
	UPROPERTY()
	float subUnitPrice;
	
	UPROPERTY()
	bool uniqueTransactionByPlayer;

	UPROPERTY()
	UGameSparksScriptData* scriptData;
	
	UPROPERTY()
	bool durable;
	
	UPROPERTY()
	int32 requestTimeoutSeconds;

	UPROPERTY()
	FString playerId;
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSteamConnectRequest_Response, FGSAuthenticationResponse, AuthenticationResponse, bool, hasErrors);

UCLASS()
class GAMESPARKS_API UGSSteamConnectRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnSteamConnectRequest_Response OnResponse;
	
	/**
	Allows a Steam sessionTicket to be used as an authentication mechanism.
	Once authenticated the platform can determine the current players details from the Steam platform and store them within GameSparks.
	GameSparks will determine the player's friends and whether any of them are currently registered with the game.
	If the Steam user is already linked to a player, the current session will switch to the linked player.
	If the current player has previously created an account using either DeviceAuthentictionRequest or RegistrationRequest AND the Steam user is not already registered with the game, the Steam user will be linked to the current player.
	If the current player has not authenticated and the Steam user is not known, a new player will be created using the Steam details and the session will be authenticated against the new player.
	If the Steam user is already known, the session will switch to being the previously created user.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS SteamConnectRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Authentication")
	static UGSSteamConnectRequest* SendSteamConnectRequest(bool DoNotLinkToCurrentPlayer = false, bool ErrorOnSwitch = false, UGameSparksScriptData* Segments = nullptr, FString SessionTicket = "", bool SwitchIfPossible = false, bool SyncDisplayName = false,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);

	/**
	Allows a Steam sessionTicket to be used as an authentication mechanism.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	Once authenticated the platform can determine the current players details from the Steam platform and store them within GameSparks.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	GameSparks will determine the player's friends and whether any of them are currently registered with the game.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	If the Steam user is already linked to a player, the current session will switch to the linked player.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	If the current player has previously created an account using either DeviceAuthentictionRequest or RegistrationRequest AND the Steam user is not already registered with the game, the Steam user will be linked to the current player.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	If the current player has not authenticated and the Steam user is not known, a new player will be created using the Steam details and the session will be authenticated against the new player.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	If the Steam user is already known, the session will switch to being the previously created user.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS SteamConnectRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks Server-side|Requests|Authentication")
	static UGSSteamConnectRequest* SendSteamConnectRequestOnBehalfOf(const FString& PlayerId, bool DoNotLinkToCurrentPlayer = false, bool ErrorOnSwitch = false, UGameSparksScriptData* Segments = nullptr, FString SessionTicket = "", bool SwitchIfPossible = false, bool SyncDisplayName = false,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSSteamConnectRequest();

private:
	
	UPROPERTY()
	bool doNotLinkToCurrentPlayer;
	
	UPROPERTY()
	bool errorOnSwitch;

	
	UPROPERTY()
	UGameSparksScriptData* segments;
	
	UPROPERTY()
	FString sessionTicket;
	
	UPROPERTY()
	bool switchIfPossible;
	
	UPROPERTY()
	bool syncDisplayName;

	UPROPERTY()
	UGameSparksScriptData* scriptData;
	
	UPROPERTY()
	bool durable;
	
	UPROPERTY()
	int32 requestTimeoutSeconds;

	UPROPERTY()
	FString playerId;
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnTwitchConnectRequest_Response, FGSAuthenticationResponse, AuthenticationResponse, bool, hasErrors);

UCLASS()
class GAMESPARKS_API UGSTwitchConnectRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnTwitchConnectRequest_Response OnResponse;
	
	/**
	Allows a Twitch account to be used as an authentication mechanism.
	Once authenticated the platform can determine the current players details from the Twitch platform and store them within GameSparks.
	If the Twitch user is already linked to a player, the current session will switch to the linked player.
	If the current player has previously created an account using either DeviceAuthentictionRequest or RegistrationRequest AND the Twitch user is not already registered with the game, the Twitch user will be linked to the current player.
	If the current player has not authenticated and the Twitch user is not known, a new player will be created using the Twitch details and the session will be authenticated against the new player.
	If the Twitch user is already known, the session will switch to being the previously created user.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS TwitchConnectRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Authentication")
	static UGSTwitchConnectRequest* SendTwitchConnectRequest(FString AccessToken = "", bool DoNotLinkToCurrentPlayer = false, bool ErrorOnSwitch = false, UGameSparksScriptData* Segments = nullptr, bool SwitchIfPossible = false, bool SyncDisplayName = false,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);

	/**
	Allows a Twitch account to be used as an authentication mechanism.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	Once authenticated the platform can determine the current players details from the Twitch platform and store them within GameSparks.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	If the Twitch user is already linked to a player, the current session will switch to the linked player.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	If the current player has previously created an account using either DeviceAuthentictionRequest or RegistrationRequest AND the Twitch user is not already registered with the game, the Twitch user will be linked to the current player.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	If the current player has not authenticated and the Twitch user is not known, a new player will be created using the Twitch details and the session will be authenticated against the new player.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	If the Twitch user is already known, the session will switch to being the previously created user.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS TwitchConnectRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks Server-side|Requests|Authentication")
	static UGSTwitchConnectRequest* SendTwitchConnectRequestOnBehalfOf(const FString& PlayerId, FString AccessToken = "", bool DoNotLinkToCurrentPlayer = false, bool ErrorOnSwitch = false, UGameSparksScriptData* Segments = nullptr, bool SwitchIfPossible = false, bool SyncDisplayName = false,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSTwitchConnectRequest();

private:
	
	UPROPERTY()
	FString accessToken;
	
	UPROPERTY()
	bool doNotLinkToCurrentPlayer;
	
	UPROPERTY()
	bool errorOnSwitch;

	
	UPROPERTY()
	UGameSparksScriptData* segments;
	
	UPROPERTY()
	bool switchIfPossible;
	
	UPROPERTY()
	bool syncDisplayName;

	UPROPERTY()
	UGameSparksScriptData* scriptData;
	
	UPROPERTY()
	bool durable;
	
	UPROPERTY()
	int32 requestTimeoutSeconds;

	UPROPERTY()
	FString playerId;
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnTwitterConnectRequest_Response, FGSAuthenticationResponse, AuthenticationResponse, bool, hasErrors);

UCLASS()
class GAMESPARKS_API UGSTwitterConnectRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnTwitterConnectRequest_Response OnResponse;
	
	/**
	Allows a Twitter account to be used as an authentication mechanism.
	Once authenticated the platform can determine the current players details from the Twitter platform and store them within GameSparks.
	GameSparks will determine the player's friends and whether any of them are currently registered with the game.
	If the Twitter user is already linked to a player, the current session will switch to the linked player.
	If the current player has previously created an account using either DeviceAuthentictionRequest or RegistrationRequest AND the Twitter user is not already registered with the game, the Twitter user will be linked to the current player.
	If the current player has not authenticated and the Twitter user is not known, a new player will be created using the Twitter details and the session will be authenticated against the new player.
	If the Twitter user is already known, the session will switch to being the previously created user.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS TwitterConnectRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Authentication")
	static UGSTwitterConnectRequest* SendTwitterConnectRequest(FString AccessSecret = "", FString AccessToken = "", bool DoNotLinkToCurrentPlayer = false, bool ErrorOnSwitch = false, UGameSparksScriptData* Segments = nullptr, bool SwitchIfPossible = false, bool SyncDisplayName = false,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);

	/**
	Allows a Twitter account to be used as an authentication mechanism.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	Once authenticated the platform can determine the current players details from the Twitter platform and store them within GameSparks.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	GameSparks will determine the player's friends and whether any of them are currently registered with the game.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	If the Twitter user is already linked to a player, the current session will switch to the linked player.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	If the current player has previously created an account using either DeviceAuthentictionRequest or RegistrationRequest AND the Twitter user is not already registered with the game, the Twitter user will be linked to the current player.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	If the current player has not authenticated and the Twitter user is not known, a new player will be created using the Twitter details and the session will be authenticated against the new player.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	If the Twitter user is already known, the session will switch to being the previously created user.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS TwitterConnectRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks Server-side|Requests|Authentication")
	static UGSTwitterConnectRequest* SendTwitterConnectRequestOnBehalfOf(const FString& PlayerId, FString AccessSecret = "", FString AccessToken = "", bool DoNotLinkToCurrentPlayer = false, bool ErrorOnSwitch = false, UGameSparksScriptData* Segments = nullptr, bool SwitchIfPossible = false, bool SyncDisplayName = false,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSTwitterConnectRequest();

private:
	
	UPROPERTY()
	FString accessSecret;
	
	UPROPERTY()
	FString accessToken;
	
	UPROPERTY()
	bool doNotLinkToCurrentPlayer;
	
	UPROPERTY()
	bool errorOnSwitch;

	
	UPROPERTY()
	UGameSparksScriptData* segments;
	
	UPROPERTY()
	bool switchIfPossible;
	
	UPROPERTY()
	bool syncDisplayName;

	UPROPERTY()
	UGameSparksScriptData* scriptData;
	
	UPROPERTY()
	bool durable;
	
	UPROPERTY()
	int32 requestTimeoutSeconds;

	UPROPERTY()
	FString playerId;
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnUpdateMessageRequest_Response, FGSUpdateMessageResponse, UpdateMessageResponse, bool, hasErrors);

UCLASS()
class GAMESPARKS_API UGSUpdateMessageRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnUpdateMessageRequest_Response OnResponse;
	
	/**
	Allows a message status to be updated.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS UpdateMessageRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Player")
	static UGSUpdateMessageRequest* SendUpdateMessageRequest(FString MessageId = "", FString Status = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);

	/**
	Allows a message status to be updated.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS UpdateMessageRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks Server-side|Requests|Player")
	static UGSUpdateMessageRequest* SendUpdateMessageRequestOnBehalfOf(const FString& PlayerId, FString MessageId = "", FString Status = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSUpdateMessageRequest();

private:
	
	UPROPERTY()
	FString messageId;

	
	UPROPERTY()
	FString status;

	UPROPERTY()
	UGameSparksScriptData* scriptData;
	
	UPROPERTY()
	bool durable;
	
	UPROPERTY()
	int32 requestTimeoutSeconds;

	UPROPERTY()
	FString playerId;
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnViberConnectRequest_Response, FGSAuthenticationResponse, AuthenticationResponse, bool, hasErrors);

UCLASS()
class GAMESPARKS_API UGSViberConnectRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnViberConnectRequest_Response OnResponse;
	
	/**
	Allows a Viber account to be used as an authentication mechanism.
	Once authenticated the platform can determine the current players details from the Viber platform and store them within GameSparks.
	A successful authentication will also register the player to receive Viber push notifications.
	GameSparks will determine the player's friends and whether any of them are currently registered with the game.
	If the Viber user is already linked to a player, the current session will switch to the linked player.
	If the current player has previously created an account using either DeviceAuthentictionRequest or RegistrationRequest AND the Viber user is not already registered with the game, the Viber user will be linked to the current player.
	If the current player has not authenticated and the Viber user is not known, a new player will be created using the Viber details and the session will be authenticated against the new player.
	If the Viber user is already known, the session will switch to being the previously created user.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS ViberConnectRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Authentication")
	static UGSViberConnectRequest* SendViberConnectRequest(FString AccessToken = "", bool DoNotLinkToCurrentPlayer = false, bool DoNotRegisterForPush = false, bool ErrorOnSwitch = false, UGameSparksScriptData* Segments = nullptr, bool SwitchIfPossible = false, bool SyncDisplayName = false,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);

	/**
	Allows a Viber account to be used as an authentication mechanism.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	Once authenticated the platform can determine the current players details from the Viber platform and store them within GameSparks.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	A successful authentication will also register the player to receive Viber push notifications.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	GameSparks will determine the player's friends and whether any of them are currently registered with the game.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	If the Viber user is already linked to a player, the current session will switch to the linked player.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	If the current player has previously created an account using either DeviceAuthentictionRequest or RegistrationRequest AND the Viber user is not already registered with the game, the Viber user will be linked to the current player.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	If the current player has not authenticated and the Viber user is not known, a new player will be created using the Viber details and the session will be authenticated against the new player.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	If the Viber user is already known, the session will switch to being the previously created user.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS ViberConnectRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks Server-side|Requests|Authentication")
	static UGSViberConnectRequest* SendViberConnectRequestOnBehalfOf(const FString& PlayerId, FString AccessToken = "", bool DoNotLinkToCurrentPlayer = false, bool DoNotRegisterForPush = false, bool ErrorOnSwitch = false, UGameSparksScriptData* Segments = nullptr, bool SwitchIfPossible = false, bool SyncDisplayName = false,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSViberConnectRequest();

private:
	
	UPROPERTY()
	FString accessToken;
	
	UPROPERTY()
	bool doNotLinkToCurrentPlayer;
	
	UPROPERTY()
	bool doNotRegisterForPush;
	
	UPROPERTY()
	bool errorOnSwitch;

	
	UPROPERTY()
	UGameSparksScriptData* segments;
	
	UPROPERTY()
	bool switchIfPossible;
	
	UPROPERTY()
	bool syncDisplayName;

	UPROPERTY()
	UGameSparksScriptData* scriptData;
	
	UPROPERTY()
	bool durable;
	
	UPROPERTY()
	int32 requestTimeoutSeconds;

	UPROPERTY()
	FString playerId;
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnWeChatConnectRequest_Response, FGSAuthenticationResponse, AuthenticationResponse, bool, hasErrors);

UCLASS()
class GAMESPARKS_API UGSWeChatConnectRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnWeChatConnectRequest_Response OnResponse;
	
	/**
	Allows a WeChat access token to be used as an authentication mechanism.
	Once authenticated the platform can determine the current players details from the WeChat platform and store them within GameSparks.
	If the WeChat user is already linked to a player, the current session will switch to the linked player.
	If the current player has previously created an account using either DeviceAuthenticationRequest or RegistrationRequest AND the WeChat user is not already registered with the game, the WeChat user will be linked to the current player.
	If the current player has not authenticated and the WeChat user is not known, a new player will be created using the WeChat details and the session will be authenticated against the new player.
	If the WeChat user is already known, the session will switch to being the previously created user.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS WeChatConnectRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Authentication")
	static UGSWeChatConnectRequest* SendWeChatConnectRequest(FString AccessToken = "", bool DoNotLinkToCurrentPlayer = false, bool ErrorOnSwitch = false, FString OpenId = "", UGameSparksScriptData* Segments = nullptr, bool SwitchIfPossible = false, bool SyncDisplayName = false,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);

	/**
	Allows a WeChat access token to be used as an authentication mechanism.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	Once authenticated the platform can determine the current players details from the WeChat platform and store them within GameSparks.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	If the WeChat user is already linked to a player, the current session will switch to the linked player.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	If the current player has previously created an account using either DeviceAuthenticationRequest or RegistrationRequest AND the WeChat user is not already registered with the game, the WeChat user will be linked to the current player.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	If the current player has not authenticated and the WeChat user is not known, a new player will be created using the WeChat details and the session will be authenticated against the new player.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	If the WeChat user is already known, the session will switch to being the previously created user.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS WeChatConnectRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks Server-side|Requests|Authentication")
	static UGSWeChatConnectRequest* SendWeChatConnectRequestOnBehalfOf(const FString& PlayerId, FString AccessToken = "", bool DoNotLinkToCurrentPlayer = false, bool ErrorOnSwitch = false, FString OpenId = "", UGameSparksScriptData* Segments = nullptr, bool SwitchIfPossible = false, bool SyncDisplayName = false,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSWeChatConnectRequest();

private:
	
	UPROPERTY()
	FString accessToken;
	
	UPROPERTY()
	bool doNotLinkToCurrentPlayer;
	
	UPROPERTY()
	bool errorOnSwitch;
	
	UPROPERTY()
	FString openId;

	
	UPROPERTY()
	UGameSparksScriptData* segments;
	
	UPROPERTY()
	bool switchIfPossible;
	
	UPROPERTY()
	bool syncDisplayName;

	UPROPERTY()
	UGameSparksScriptData* scriptData;
	
	UPROPERTY()
	bool durable;
	
	UPROPERTY()
	int32 requestTimeoutSeconds;

	UPROPERTY()
	FString playerId;
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnWindowsBuyGoodsRequest_Response, FGSBuyVirtualGoodResponse, BuyVirtualGoodResponse, bool, hasErrors);

UCLASS()
class GAMESPARKS_API UGSWindowsBuyGoodsRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnWindowsBuyGoodsRequest_Response OnResponse;
	
	/**
	Processes a transaction receipt from a windows store purchase.
	The GameSparks platform will validate the receipt using the signature embedded in the xml. The Id in the xml will be recorded and the request will be rejected if the Id has previously been processed, this prevents replay attacks.
	Once verified, the players account will be credited with the Virtual Good, or Virtual Currency the purchase contains. The virtual good will be looked up by matching the productId in the xml with the 'WP8 Product ID' configured against the virtual good.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS WindowsBuyGoodsRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Store")
	static UGSWindowsBuyGoodsRequest* SendWindowsBuyGoodsRequest(FString CurrencyCode = "", FString Platform = "", FString Receipt = "", float SubUnitPrice = 0.0f, bool UniqueTransactionByPlayer = false,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);

	/**
	Processes a transaction receipt from a windows store purchase.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	The GameSparks platform will validate the receipt using the signature embedded in the xml. The Id in the xml will be recorded and the request will be rejected if the Id has previously been processed, this prevents replay attacks.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	Once verified, the players account will be credited with the Virtual Good, or Virtual Currency the purchase contains. The virtual good will be looked up by matching the productId in the xml with the 'WP8 Product ID' configured against the virtual good.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS WindowsBuyGoodsRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks Server-side|Requests|Store")
	static UGSWindowsBuyGoodsRequest* SendWindowsBuyGoodsRequestOnBehalfOf(const FString& PlayerId, FString CurrencyCode = "", FString Platform = "", FString Receipt = "", float SubUnitPrice = 0.0f, bool UniqueTransactionByPlayer = false,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSWindowsBuyGoodsRequest();

private:
	
	UPROPERTY()
	FString currencyCode;
	
	UPROPERTY()
	FString platform;
	
	UPROPERTY()
	FString receipt;

	
	UPROPERTY()
	float subUnitPrice;
	
	UPROPERTY()
	bool uniqueTransactionByPlayer;

	UPROPERTY()
	UGameSparksScriptData* scriptData;
	
	UPROPERTY()
	bool durable;
	
	UPROPERTY()
	int32 requestTimeoutSeconds;

	UPROPERTY()
	FString playerId;
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnWithdrawChallengeRequest_Response, FGSWithdrawChallengeResponse, WithdrawChallengeResponse, bool, hasErrors);

UCLASS()
class GAMESPARKS_API UGSWithdrawChallengeRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnWithdrawChallengeRequest_Response OnResponse;
	
	/**
	Withdraws a challenge previously issued by the current player.
	This can only be done while the challenge is in the ISSUED state. Once it's been accepted the challenge can not be withdrawn.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS WithdrawChallengeRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Multiplayer")
	static UGSWithdrawChallengeRequest* SendWithdrawChallengeRequest(FString ChallengeInstanceId = "", FString Message = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);

	/**
	Withdraws a challenge previously issued by the current player.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	This can only be done while the challenge is in the ISSUED state. Once it's been accepted the challenge can not be withdrawn.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS WithdrawChallengeRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks Server-side|Requests|Multiplayer")
	static UGSWithdrawChallengeRequest* SendWithdrawChallengeRequestOnBehalfOf(const FString& PlayerId, FString ChallengeInstanceId = "", FString Message = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSWithdrawChallengeRequest();

private:
	
	UPROPERTY()
	FString challengeInstanceId;
	
	UPROPERTY()
	FString message;


	UPROPERTY()
	UGameSparksScriptData* scriptData;
	
	UPROPERTY()
	bool durable;
	
	UPROPERTY()
	int32 requestTimeoutSeconds;

	UPROPERTY()
	FString playerId;
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnXBOXLiveConnectRequest_Response, FGSAuthenticationResponse, AuthenticationResponse, bool, hasErrors);

UCLASS()
class GAMESPARKS_API UGSXBOXLiveConnectRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnXBOXLiveConnectRequest_Response OnResponse;
	
	/**
	Allows an Xbox Live Shared Token String to be used as an authentication mechanism.
	Once authenticated the platform can determine the current players details from the Xbox Live and store them within GameSparks.
	GameSparks will determine the player's friends and whether any of them are currently registered with the game.
	If the Xbox user is already linked to a player, the current session will switch to the linked player.
	If the current player has previously created an account using either DeviceAuthentictionRequest or RegistrationRequest AND the Xbox user is not already registered with the game, the Xbox user will be linked to the current player.
	If the current player has not authenticated and the Xbox user is not known, a new player will be created using the Xbox details and the session will be authenticated against the new player.
	If the Xbox user is already known, the session will switch to being the previously created user.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS XBOXLiveConnectRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Authentication")
	static UGSXBOXLiveConnectRequest* SendXBOXLiveConnectRequest(FString DisplayName = "", bool DoNotLinkToCurrentPlayer = false, bool ErrorOnSwitch = false, UGameSparksScriptData* Segments = nullptr, FString StsTokenString = "", bool SwitchIfPossible = false, bool SyncDisplayName = false,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);

	/**
	Allows an Xbox Live Shared Token String to be used as an authentication mechanism.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	Once authenticated the platform can determine the current players details from the Xbox Live and store them within GameSparks.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	GameSparks will determine the player's friends and whether any of them are currently registered with the game.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	If the Xbox user is already linked to a player, the current session will switch to the linked player.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	If the current player has previously created an account using either DeviceAuthentictionRequest or RegistrationRequest AND the Xbox user is not already registered with the game, the Xbox user will be linked to the current player.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	If the current player has not authenticated and the Xbox user is not known, a new player will be created using the Xbox details and the session will be authenticated against the new player.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	If the Xbox user is already known, the session will switch to being the previously created user.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS XBOXLiveConnectRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks Server-side|Requests|Authentication")
	static UGSXBOXLiveConnectRequest* SendXBOXLiveConnectRequestOnBehalfOf(const FString& PlayerId, FString DisplayName = "", bool DoNotLinkToCurrentPlayer = false, bool ErrorOnSwitch = false, UGameSparksScriptData* Segments = nullptr, FString StsTokenString = "", bool SwitchIfPossible = false, bool SyncDisplayName = false,  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSXBOXLiveConnectRequest();

private:
	
	UPROPERTY()
	FString displayName;
	
	UPROPERTY()
	bool doNotLinkToCurrentPlayer;
	
	UPROPERTY()
	bool errorOnSwitch;

	
	UPROPERTY()
	UGameSparksScriptData* segments;
	
	UPROPERTY()
	FString stsTokenString;
	
	UPROPERTY()
	bool switchIfPossible;
	
	UPROPERTY()
	bool syncDisplayName;

	UPROPERTY()
	UGameSparksScriptData* scriptData;
	
	UPROPERTY()
	bool durable;
	
	UPROPERTY()
	int32 requestTimeoutSeconds;

	UPROPERTY()
	FString playerId;
};


// Generate a delegate for the OnGetResult event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnXboxOneConnectRequest_Response, FGSAuthenticationResponse, AuthenticationResponse, bool, hasErrors);

UCLASS()
class GAMESPARKS_API UGSXboxOneConnectRequest : public UOnlineBlueprintCallProxyBase
{
	GENERATED_BODY()

public:
	
	/* Event which triggers when the content has been retrieved */
	UPROPERTY(BlueprintAssignable, Category = "GameSparks")
	FOnXboxOneConnectRequest_Response OnResponse;
	
	/**
	Allows an Xbox One XSTS token to be used as an authentication mechanism.
	Once authenticated the platform can determine the current players details from Xbox Live and store them within GameSparks.
	If the Xbox One user is already linked to a player, the current session will switch to the linked player.
	If the current player has previously created an account using either DeviceAuthentictionRequest or RegistrationRequest AND the Xbox One user is not already registered with the game, the Xbox One user will be linked to the current player.
	If the current player has not authenticated and the Xbox One user is not known, a new player will be created using the Xbox Live details and the session will be authenticated against the new player.
	If the Xbox One user is already known, the session will switch to being the previously created user.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS XboxOneConnectRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks|Requests|Authentication")
	static UGSXboxOneConnectRequest* SendXboxOneConnectRequest(bool DoNotLinkToCurrentPlayer = false, bool ErrorOnSwitch = false, FString Sandbox = "", UGameSparksScriptData* Segments = nullptr, bool SwitchIfPossible = false, bool SyncDisplayName = false, FString Token = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);

	/**
	Allows an Xbox One XSTS token to be used as an authentication mechanism.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	Once authenticated the platform can determine the current players details from Xbox Live and store them within GameSparks.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	If the Xbox One user is already linked to a player, the current session will switch to the linked player.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	If the current player has previously created an account using either DeviceAuthentictionRequest or RegistrationRequest AND the Xbox One user is not already registered with the game, the Xbox One user will be linked to the current player.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	If the current player has not authenticated and the Xbox One user is not known, a new player will be created using the Xbox Live details and the session will be authenticated against the new player.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	If the Xbox One user is already known, the session will switch to being the previously created user.

	Also sets the playerId for this request.
	This will only have an effect if you are using a server style credential, i.e. one with "Player" set to off.
	This will require the use of a server style credential in the code, you should NOT distribute this credential in your shipping code.
	This should only be used in a server binary, where you control it's execution (GameLift clients, etc.)
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName="GS XboxOneConnectRequest", BlueprintInternalUseOnly = "true"), Category = "GameSparks Server-side|Requests|Authentication")
	static UGSXboxOneConnectRequest* SendXboxOneConnectRequestOnBehalfOf(const FString& PlayerId, bool DoNotLinkToCurrentPlayer = false, bool ErrorOnSwitch = false, FString Sandbox = "", UGameSparksScriptData* Segments = nullptr, bool SwitchIfPossible = false, bool SyncDisplayName = false, FString Token = "",  UGameSparksScriptData* ScriptData = nullptr, bool Durable = false, int32 RequestTimeoutSeconds = 0);
	
	void Activate() override;
	
	~UGSXboxOneConnectRequest();

private:
	
	UPROPERTY()
	bool doNotLinkToCurrentPlayer;
	
	UPROPERTY()
	bool errorOnSwitch;

	
	UPROPERTY()
	FString sandbox;
	
	UPROPERTY()
	UGameSparksScriptData* segments;
	
	UPROPERTY()
	bool switchIfPossible;
	
	UPROPERTY()
	bool syncDisplayName;
	
	UPROPERTY()
	FString token;

	UPROPERTY()
	UGameSparksScriptData* scriptData;
	
	UPROPERTY()
	bool durable;
	
	UPROPERTY()
	int32 requestTimeoutSeconds;

	UPROPERTY()
	FString playerId;
};


