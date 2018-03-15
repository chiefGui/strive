#include "GSApi.h"
#include "GameSparksPrivatePCH.h"


void AcceptChallengeRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::AcceptChallengeResponse& response){
    
    if(response.GetUserData() == nullptr) {
        return;
    }
    
    FGSAcceptChallengeResponse unreal_response = FGSAcceptChallengeResponse(response.GetBaseData());
    
    UGSAcceptChallengeRequest* g_UGSAcceptChallengeRequest = static_cast<UGSAcceptChallengeRequest*>(response.GetUserData());
                               
    if(!g_UGSAcceptChallengeRequest->OnResponse.IsBound()){
        return;    
    }

    if (response.GetHasErrors())
    {
        g_UGSAcceptChallengeRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSAcceptChallengeRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSAcceptChallengeRequest* UGSAcceptChallengeRequest::SendAcceptChallengeRequest(FString ChallengeInstanceId, FString Message,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSAcceptChallengeRequest* proxy = NewObject<UGSAcceptChallengeRequest>();
    proxy->challengeInstanceId = ChallengeInstanceId;
    proxy->message = Message;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    return proxy;
}

UGSAcceptChallengeRequest* UGSAcceptChallengeRequest::SendAcceptChallengeRequestOnBehalfOf(const FString& PlayerId, FString ChallengeInstanceId, FString Message,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSAcceptChallengeRequest* proxy = NewObject<UGSAcceptChallengeRequest>();
    proxy->challengeInstanceId = ChallengeInstanceId;
    proxy->message = Message;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    proxy->playerId = PlayerId;
    return proxy;
}
    
void UGSAcceptChallengeRequest::Activate()
{
    GameSparks::Api::Requests::AcceptChallengeRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
    if(challengeInstanceId != ""){
        gsRequest.SetChallengeInstanceId(TCHAR_TO_UTF8(*challengeInstanceId));
    }
    if(message != ""){
        gsRequest.SetMessage(TCHAR_TO_UTF8(*message));
    }
    if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
        gsRequest.SetDurable(durable);
    }
    
    if(!playerId.IsEmpty())
    {
        gsRequest.SetPlayerId(TCHAR_TO_UTF8(*playerId));
    }

    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
        gsRequest.Send(AcceptChallengeRequestResponseCallback, requestTimeoutSeconds);  
    } else {
        gsRequest.Send(AcceptChallengeRequestResponseCallback);
    }
}

UGSAcceptChallengeRequest::~UGSAcceptChallengeRequest()
{
 if (UGameSparksModule* module = UGameSparksModule::GetModulePtr())
 {
  if (module->IsInitialized())
  {
    module->GetGSInstance().ChangeUserDataForRequests(this, nullptr);
  }
 }
}


void AccountDetailsRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::AccountDetailsResponse& response){
    
    if(response.GetUserData() == nullptr) {
        return;
    }
    
    FGSAccountDetailsResponse unreal_response = FGSAccountDetailsResponse(response.GetBaseData());
    
    UGSAccountDetailsRequest* g_UGSAccountDetailsRequest = static_cast<UGSAccountDetailsRequest*>(response.GetUserData());
                               
    if(!g_UGSAccountDetailsRequest->OnResponse.IsBound()){
        return;    
    }

    if (response.GetHasErrors())
    {
        g_UGSAccountDetailsRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSAccountDetailsRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSAccountDetailsRequest* UGSAccountDetailsRequest::SendAccountDetailsRequest( UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSAccountDetailsRequest* proxy = NewObject<UGSAccountDetailsRequest>();
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    return proxy;
}

UGSAccountDetailsRequest* UGSAccountDetailsRequest::SendAccountDetailsRequestOnBehalfOf(const FString& PlayerId,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSAccountDetailsRequest* proxy = NewObject<UGSAccountDetailsRequest>();
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    proxy->playerId = PlayerId;
    return proxy;
}
    
void UGSAccountDetailsRequest::Activate()
{
    GameSparks::Api::Requests::AccountDetailsRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
    if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
        gsRequest.SetDurable(durable);
    }
    
    if(!playerId.IsEmpty())
    {
        gsRequest.SetPlayerId(TCHAR_TO_UTF8(*playerId));
    }

    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
        gsRequest.Send(AccountDetailsRequestResponseCallback, requestTimeoutSeconds);  
    } else {
        gsRequest.Send(AccountDetailsRequestResponseCallback);
    }
}

UGSAccountDetailsRequest::~UGSAccountDetailsRequest()
{
 if (UGameSparksModule* module = UGameSparksModule::GetModulePtr())
 {
  if (module->IsInitialized())
  {
    module->GetGSInstance().ChangeUserDataForRequests(this, nullptr);
  }
 }
}


void AmazonBuyGoodsRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::BuyVirtualGoodResponse& response){
    
    if(response.GetUserData() == nullptr) {
        return;
    }
    
    FGSBuyVirtualGoodResponse unreal_response = FGSBuyVirtualGoodResponse(response.GetBaseData());
    
    UGSAmazonBuyGoodsRequest* g_UGSAmazonBuyGoodsRequest = static_cast<UGSAmazonBuyGoodsRequest*>(response.GetUserData());
                               
    if(!g_UGSAmazonBuyGoodsRequest->OnResponse.IsBound()){
        return;    
    }

    if (response.GetHasErrors())
    {
        g_UGSAmazonBuyGoodsRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSAmazonBuyGoodsRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSAmazonBuyGoodsRequest* UGSAmazonBuyGoodsRequest::SendAmazonBuyGoodsRequest(FString AmazonUserId, FString CurrencyCode, FString ReceiptId, float SubUnitPrice, bool UniqueTransactionByPlayer,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSAmazonBuyGoodsRequest* proxy = NewObject<UGSAmazonBuyGoodsRequest>();
    proxy->amazonUserId = AmazonUserId;
    proxy->currencyCode = CurrencyCode;
    proxy->receiptId = ReceiptId;
    proxy->subUnitPrice = SubUnitPrice;
    proxy->uniqueTransactionByPlayer = UniqueTransactionByPlayer;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    return proxy;
}

UGSAmazonBuyGoodsRequest* UGSAmazonBuyGoodsRequest::SendAmazonBuyGoodsRequestOnBehalfOf(const FString& PlayerId, FString AmazonUserId, FString CurrencyCode, FString ReceiptId, float SubUnitPrice, bool UniqueTransactionByPlayer,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSAmazonBuyGoodsRequest* proxy = NewObject<UGSAmazonBuyGoodsRequest>();
    proxy->amazonUserId = AmazonUserId;
    proxy->currencyCode = CurrencyCode;
    proxy->receiptId = ReceiptId;
    proxy->subUnitPrice = SubUnitPrice;
    proxy->uniqueTransactionByPlayer = UniqueTransactionByPlayer;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    proxy->playerId = PlayerId;
    return proxy;
}
    
void UGSAmazonBuyGoodsRequest::Activate()
{
    GameSparks::Api::Requests::AmazonBuyGoodsRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
    if(amazonUserId != ""){
        gsRequest.SetAmazonUserId(TCHAR_TO_UTF8(*amazonUserId));
    }
    if(currencyCode != ""){
        gsRequest.SetCurrencyCode(TCHAR_TO_UTF8(*currencyCode));
    }
    if(receiptId != ""){
        gsRequest.SetReceiptId(TCHAR_TO_UTF8(*receiptId));
    }
    if(subUnitPrice != 0.0f){
        gsRequest.SetSubUnitPrice(subUnitPrice);
    }
    if(uniqueTransactionByPlayer != false){
        gsRequest.SetUniqueTransactionByPlayer(uniqueTransactionByPlayer);
    }
    if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
        gsRequest.SetDurable(durable);
    }
    
    if(!playerId.IsEmpty())
    {
        gsRequest.SetPlayerId(TCHAR_TO_UTF8(*playerId));
    }

    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
        gsRequest.Send(AmazonBuyGoodsRequestResponseCallback, requestTimeoutSeconds);  
    } else {
        gsRequest.Send(AmazonBuyGoodsRequestResponseCallback);
    }
}

UGSAmazonBuyGoodsRequest::~UGSAmazonBuyGoodsRequest()
{
 if (UGameSparksModule* module = UGameSparksModule::GetModulePtr())
 {
  if (module->IsInitialized())
  {
    module->GetGSInstance().ChangeUserDataForRequests(this, nullptr);
  }
 }
}


void AmazonConnectRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::AuthenticationResponse& response){
    
    if(response.GetUserData() == nullptr) {
        return;
    }
    
    FGSAuthenticationResponse unreal_response = FGSAuthenticationResponse(response.GetBaseData());
    
    UGSAmazonConnectRequest* g_UGSAmazonConnectRequest = static_cast<UGSAmazonConnectRequest*>(response.GetUserData());
                               
    if(!g_UGSAmazonConnectRequest->OnResponse.IsBound()){
        return;    
    }

    if (response.GetHasErrors())
    {
        g_UGSAmazonConnectRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSAmazonConnectRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSAmazonConnectRequest* UGSAmazonConnectRequest::SendAmazonConnectRequest(FString AccessToken, bool DoNotLinkToCurrentPlayer, bool ErrorOnSwitch, UGameSparksScriptData* Segments, bool SwitchIfPossible, bool SyncDisplayName,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSAmazonConnectRequest* proxy = NewObject<UGSAmazonConnectRequest>();
    proxy->accessToken = AccessToken;
    proxy->doNotLinkToCurrentPlayer = DoNotLinkToCurrentPlayer;
    proxy->errorOnSwitch = ErrorOnSwitch;
    proxy->segments = Segments;
    proxy->switchIfPossible = SwitchIfPossible;
    proxy->syncDisplayName = SyncDisplayName;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    return proxy;
}

UGSAmazonConnectRequest* UGSAmazonConnectRequest::SendAmazonConnectRequestOnBehalfOf(const FString& PlayerId, FString AccessToken, bool DoNotLinkToCurrentPlayer, bool ErrorOnSwitch, UGameSparksScriptData* Segments, bool SwitchIfPossible, bool SyncDisplayName,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSAmazonConnectRequest* proxy = NewObject<UGSAmazonConnectRequest>();
    proxy->accessToken = AccessToken;
    proxy->doNotLinkToCurrentPlayer = DoNotLinkToCurrentPlayer;
    proxy->errorOnSwitch = ErrorOnSwitch;
    proxy->segments = Segments;
    proxy->switchIfPossible = SwitchIfPossible;
    proxy->syncDisplayName = SyncDisplayName;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    proxy->playerId = PlayerId;
    return proxy;
}
    
void UGSAmazonConnectRequest::Activate()
{
    GameSparks::Api::Requests::AmazonConnectRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
    if(accessToken != ""){
        gsRequest.SetAccessToken(TCHAR_TO_UTF8(*accessToken));
    }
    if(doNotLinkToCurrentPlayer != false){
        gsRequest.SetDoNotLinkToCurrentPlayer(doNotLinkToCurrentPlayer);
    }
    if(errorOnSwitch != false){
        gsRequest.SetErrorOnSwitch(errorOnSwitch);
    }
    if(segments != nullptr){
        gsRequest.SetSegments(segments->ToRequestData());
    }
    if(switchIfPossible != false){
        gsRequest.SetSwitchIfPossible(switchIfPossible);
    }
    if(syncDisplayName != false){
        gsRequest.SetSyncDisplayName(syncDisplayName);
    }
    if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
        gsRequest.SetDurable(durable);
    }
    
    if(!playerId.IsEmpty())
    {
        gsRequest.SetPlayerId(TCHAR_TO_UTF8(*playerId));
    }

    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
        gsRequest.Send(AmazonConnectRequestResponseCallback, requestTimeoutSeconds);  
    } else {
        gsRequest.Send(AmazonConnectRequestResponseCallback);
    }
}

UGSAmazonConnectRequest::~UGSAmazonConnectRequest()
{
 if (UGameSparksModule* module = UGameSparksModule::GetModulePtr())
 {
  if (module->IsInitialized())
  {
    module->GetGSInstance().ChangeUserDataForRequests(this, nullptr);
  }
 }
}


void AnalyticsRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::AnalyticsResponse& response){
    
    if(response.GetUserData() == nullptr) {
        return;
    }
    
    FGSAnalyticsResponse unreal_response = FGSAnalyticsResponse(response.GetBaseData());
    
    UGSAnalyticsRequest* g_UGSAnalyticsRequest = static_cast<UGSAnalyticsRequest*>(response.GetUserData());
                               
    if(!g_UGSAnalyticsRequest->OnResponse.IsBound()){
        return;    
    }

    if (response.GetHasErrors())
    {
        g_UGSAnalyticsRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSAnalyticsRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSAnalyticsRequest* UGSAnalyticsRequest::SendAnalyticsRequest(UGameSparksScriptData* Data, bool End, FString Key, bool Start,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSAnalyticsRequest* proxy = NewObject<UGSAnalyticsRequest>();
    proxy->data = Data;
    proxy->end = End;
    proxy->key = Key;
    proxy->start = Start;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    return proxy;
}

UGSAnalyticsRequest* UGSAnalyticsRequest::SendAnalyticsRequestOnBehalfOf(const FString& PlayerId, UGameSparksScriptData* Data, bool End, FString Key, bool Start,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSAnalyticsRequest* proxy = NewObject<UGSAnalyticsRequest>();
    proxy->data = Data;
    proxy->end = End;
    proxy->key = Key;
    proxy->start = Start;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    proxy->playerId = PlayerId;
    return proxy;
}
    
void UGSAnalyticsRequest::Activate()
{
    GameSparks::Api::Requests::AnalyticsRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
    if(data != nullptr){
        gsRequest.SetData(data->ToRequestData());
    }
    if(end != false){
        gsRequest.SetEnd(end);
    }
    if(key != ""){
        gsRequest.SetKey(TCHAR_TO_UTF8(*key));
    }
    if(start != false){
        gsRequest.SetStart(start);
    }
    if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
        gsRequest.SetDurable(durable);
    }
    
    if(!playerId.IsEmpty())
    {
        gsRequest.SetPlayerId(TCHAR_TO_UTF8(*playerId));
    }

    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
        gsRequest.Send(AnalyticsRequestResponseCallback, requestTimeoutSeconds);  
    } else {
        gsRequest.Send(AnalyticsRequestResponseCallback);
    }
}

UGSAnalyticsRequest::~UGSAnalyticsRequest()
{
 if (UGameSparksModule* module = UGameSparksModule::GetModulePtr())
 {
  if (module->IsInitialized())
  {
    module->GetGSInstance().ChangeUserDataForRequests(this, nullptr);
  }
 }
}


void AroundMeLeaderboardRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::AroundMeLeaderboardResponse& response){
    
    if(response.GetUserData() == nullptr) {
        return;
    }
    
    FGSAroundMeLeaderboardResponse unreal_response = FGSAroundMeLeaderboardResponse(response.GetBaseData());
    
    UGSAroundMeLeaderboardRequest* g_UGSAroundMeLeaderboardRequest = static_cast<UGSAroundMeLeaderboardRequest*>(response.GetUserData());
                               
    if(!g_UGSAroundMeLeaderboardRequest->OnResponse.IsBound()){
        return;    
    }

    if (response.GetHasErrors())
    {
        g_UGSAroundMeLeaderboardRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSAroundMeLeaderboardRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSAroundMeLeaderboardRequest* UGSAroundMeLeaderboardRequest::SendAroundMeLeaderboardRequest(FString ChallengeInstanceId, UGameSparksScriptData* CustomIdFilter, bool DontErrorOnNotSocial, int32 EntryCount, UGameSparksRequestArray* FriendIds, int32 IncludeFirst, int32 IncludeLast, bool InverseSocial, FString LeaderboardShortCode, bool Social, UGameSparksRequestArray* TeamIds, UGameSparksRequestArray* TeamTypes,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSAroundMeLeaderboardRequest* proxy = NewObject<UGSAroundMeLeaderboardRequest>();
    proxy->challengeInstanceId = ChallengeInstanceId;
    proxy->customIdFilter = CustomIdFilter;
    proxy->dontErrorOnNotSocial = DontErrorOnNotSocial;
    proxy->entryCount = EntryCount;
    proxy->friendIds = FriendIds;
    proxy->includeFirst = IncludeFirst;
    proxy->includeLast = IncludeLast;
    proxy->inverseSocial = InverseSocial;
    proxy->leaderboardShortCode = LeaderboardShortCode;
    proxy->social = Social;
    proxy->teamIds = TeamIds;
    proxy->teamTypes = TeamTypes;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    return proxy;
}

UGSAroundMeLeaderboardRequest* UGSAroundMeLeaderboardRequest::SendAroundMeLeaderboardRequestOnBehalfOf(const FString& PlayerId, FString ChallengeInstanceId, UGameSparksScriptData* CustomIdFilter, bool DontErrorOnNotSocial, int32 EntryCount, UGameSparksRequestArray* FriendIds, int32 IncludeFirst, int32 IncludeLast, bool InverseSocial, FString LeaderboardShortCode, bool Social, UGameSparksRequestArray* TeamIds, UGameSparksRequestArray* TeamTypes,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSAroundMeLeaderboardRequest* proxy = NewObject<UGSAroundMeLeaderboardRequest>();
    proxy->challengeInstanceId = ChallengeInstanceId;
    proxy->customIdFilter = CustomIdFilter;
    proxy->dontErrorOnNotSocial = DontErrorOnNotSocial;
    proxy->entryCount = EntryCount;
    proxy->friendIds = FriendIds;
    proxy->includeFirst = IncludeFirst;
    proxy->includeLast = IncludeLast;
    proxy->inverseSocial = InverseSocial;
    proxy->leaderboardShortCode = LeaderboardShortCode;
    proxy->social = Social;
    proxy->teamIds = TeamIds;
    proxy->teamTypes = TeamTypes;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    proxy->playerId = PlayerId;
    return proxy;
}
    
void UGSAroundMeLeaderboardRequest::Activate()
{
    GameSparks::Api::Requests::AroundMeLeaderboardRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
    if(challengeInstanceId != ""){
        gsRequest.SetChallengeInstanceId(TCHAR_TO_UTF8(*challengeInstanceId));
    }
    if(customIdFilter != nullptr){
        gsRequest.SetCustomIdFilter(customIdFilter->ToRequestData());
    }
    if(dontErrorOnNotSocial != false){
        gsRequest.SetDontErrorOnNotSocial(dontErrorOnNotSocial);
    }
    if(entryCount != 0){
        gsRequest.SetEntryCount(entryCount);
    }
    if(friendIds != nullptr){
        gsstl::vector<gsstl::string> arrFriendIds;
    
        for(int32 b_arrFriendIds = 0; b_arrFriendIds < friendIds->StringArray.Num(); b_arrFriendIds++)
        {
            arrFriendIds.push_back(TCHAR_TO_UTF8(*friendIds->StringArray[b_arrFriendIds]));
        }
        
        gsRequest.SetFriendIds(arrFriendIds);
    }
    if(includeFirst != 0){
        gsRequest.SetIncludeFirst(includeFirst);
    }
    if(includeLast != 0){
        gsRequest.SetIncludeLast(includeLast);
    }
    if(inverseSocial != false){
        gsRequest.SetInverseSocial(inverseSocial);
    }
    if(leaderboardShortCode != ""){
        gsRequest.SetLeaderboardShortCode(TCHAR_TO_UTF8(*leaderboardShortCode));
    }
    if(social != false){
        gsRequest.SetSocial(social);
    }
    if(teamIds != nullptr){
        gsstl::vector<gsstl::string> arrTeamIds;
    
        for(int32 b_arrTeamIds = 0; b_arrTeamIds < teamIds->StringArray.Num(); b_arrTeamIds++)
        {
            arrTeamIds.push_back(TCHAR_TO_UTF8(*teamIds->StringArray[b_arrTeamIds]));
        }
        
        gsRequest.SetTeamIds(arrTeamIds);
    }
    if(teamTypes != nullptr){
        gsstl::vector<gsstl::string> arrTeamTypes;
    
        for(int32 b_arrTeamTypes = 0; b_arrTeamTypes < teamTypes->StringArray.Num(); b_arrTeamTypes++)
        {
            arrTeamTypes.push_back(TCHAR_TO_UTF8(*teamTypes->StringArray[b_arrTeamTypes]));
        }
        
        gsRequest.SetTeamTypes(arrTeamTypes);
    }
    if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
        gsRequest.SetDurable(durable);
    }
    
    if(!playerId.IsEmpty())
    {
        gsRequest.SetPlayerId(TCHAR_TO_UTF8(*playerId));
    }

    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
        gsRequest.Send(AroundMeLeaderboardRequestResponseCallback, requestTimeoutSeconds);  
    } else {
        gsRequest.Send(AroundMeLeaderboardRequestResponseCallback);
    }
}

UGSAroundMeLeaderboardRequest::~UGSAroundMeLeaderboardRequest()
{
 if (UGameSparksModule* module = UGameSparksModule::GetModulePtr())
 {
  if (module->IsInitialized())
  {
    module->GetGSInstance().ChangeUserDataForRequests(this, nullptr);
  }
 }
}


void AuthenticationRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::AuthenticationResponse& response){
    
    if(response.GetUserData() == nullptr) {
        return;
    }
    
    FGSAuthenticationResponse unreal_response = FGSAuthenticationResponse(response.GetBaseData());
    
    UGSAuthenticationRequest* g_UGSAuthenticationRequest = static_cast<UGSAuthenticationRequest*>(response.GetUserData());
                               
    if(!g_UGSAuthenticationRequest->OnResponse.IsBound()){
        return;    
    }

    if (response.GetHasErrors())
    {
        g_UGSAuthenticationRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSAuthenticationRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSAuthenticationRequest* UGSAuthenticationRequest::SendAuthenticationRequest(FString Password, FString UserName,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSAuthenticationRequest* proxy = NewObject<UGSAuthenticationRequest>();
    proxy->password = Password;
    proxy->userName = UserName;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    return proxy;
}

UGSAuthenticationRequest* UGSAuthenticationRequest::SendAuthenticationRequestOnBehalfOf(const FString& PlayerId, FString Password, FString UserName,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSAuthenticationRequest* proxy = NewObject<UGSAuthenticationRequest>();
    proxy->password = Password;
    proxy->userName = UserName;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    proxy->playerId = PlayerId;
    return proxy;
}
    
void UGSAuthenticationRequest::Activate()
{
    GameSparks::Api::Requests::AuthenticationRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
    if(password != ""){
        gsRequest.SetPassword(TCHAR_TO_UTF8(*password));
    }
    if(userName != ""){
        gsRequest.SetUserName(TCHAR_TO_UTF8(*userName));
    }
    if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
        gsRequest.SetDurable(durable);
    }
    
    if(!playerId.IsEmpty())
    {
        gsRequest.SetPlayerId(TCHAR_TO_UTF8(*playerId));
    }

    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
        gsRequest.Send(AuthenticationRequestResponseCallback, requestTimeoutSeconds);  
    } else {
        gsRequest.Send(AuthenticationRequestResponseCallback);
    }
}

UGSAuthenticationRequest::~UGSAuthenticationRequest()
{
 if (UGameSparksModule* module = UGameSparksModule::GetModulePtr())
 {
  if (module->IsInitialized())
  {
    module->GetGSInstance().ChangeUserDataForRequests(this, nullptr);
  }
 }
}


void BatchAdminRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::BatchAdminResponse& response){
    
    if(response.GetUserData() == nullptr) {
        return;
    }
    
    FGSBatchAdminResponse unreal_response = FGSBatchAdminResponse(response.GetBaseData());
    
    UGSBatchAdminRequest* g_UGSBatchAdminRequest = static_cast<UGSBatchAdminRequest*>(response.GetUserData());
                               
    if(!g_UGSBatchAdminRequest->OnResponse.IsBound()){
        return;    
    }

    if (response.GetHasErrors())
    {
        g_UGSBatchAdminRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSBatchAdminRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSBatchAdminRequest* UGSBatchAdminRequest::SendBatchAdminRequest(UGameSparksRequestArray* PlayerIds, UGameSparksScriptData* Request,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSBatchAdminRequest* proxy = NewObject<UGSBatchAdminRequest>();
    proxy->playerIds = PlayerIds;
    proxy->request = Request;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    return proxy;
}

UGSBatchAdminRequest* UGSBatchAdminRequest::SendBatchAdminRequestOnBehalfOf(const FString& PlayerId, UGameSparksRequestArray* PlayerIds, UGameSparksScriptData* Request,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSBatchAdminRequest* proxy = NewObject<UGSBatchAdminRequest>();
    proxy->playerIds = PlayerIds;
    proxy->request = Request;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    proxy->playerId = PlayerId;
    return proxy;
}
    
void UGSBatchAdminRequest::Activate()
{
    GameSparks::Api::Requests::BatchAdminRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
    if(playerIds != nullptr){
        gsstl::vector<gsstl::string> arrPlayerIds;
    
        for(int32 b_arrPlayerIds = 0; b_arrPlayerIds < playerIds->StringArray.Num(); b_arrPlayerIds++)
        {
            arrPlayerIds.push_back(TCHAR_TO_UTF8(*playerIds->StringArray[b_arrPlayerIds]));
        }
        
        gsRequest.SetPlayerIds(arrPlayerIds);
    }
    if(request != nullptr){
        gsRequest.SetRequest(request->ToRequestData());
    }
    if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
        gsRequest.SetDurable(durable);
    }
    
    if(!playerId.IsEmpty())
    {
        gsRequest.SetPlayerId(TCHAR_TO_UTF8(*playerId));
    }

    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
        gsRequest.Send(BatchAdminRequestResponseCallback, requestTimeoutSeconds);  
    } else {
        gsRequest.Send(BatchAdminRequestResponseCallback);
    }
}

UGSBatchAdminRequest::~UGSBatchAdminRequest()
{
 if (UGameSparksModule* module = UGameSparksModule::GetModulePtr())
 {
  if (module->IsInitialized())
  {
    module->GetGSInstance().ChangeUserDataForRequests(this, nullptr);
  }
 }
}


void BuyVirtualGoodsRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::BuyVirtualGoodResponse& response){
    
    if(response.GetUserData() == nullptr) {
        return;
    }
    
    FGSBuyVirtualGoodResponse unreal_response = FGSBuyVirtualGoodResponse(response.GetBaseData());
    
    UGSBuyVirtualGoodsRequest* g_UGSBuyVirtualGoodsRequest = static_cast<UGSBuyVirtualGoodsRequest*>(response.GetUserData());
                               
    if(!g_UGSBuyVirtualGoodsRequest->OnResponse.IsBound()){
        return;    
    }

    if (response.GetHasErrors())
    {
        g_UGSBuyVirtualGoodsRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSBuyVirtualGoodsRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSBuyVirtualGoodsRequest* UGSBuyVirtualGoodsRequest::SendBuyVirtualGoodsRequest(FString CurrencyShortCode, int32 CurrencyType, int32 Quantity, FString ShortCode,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSBuyVirtualGoodsRequest* proxy = NewObject<UGSBuyVirtualGoodsRequest>();
    proxy->currencyShortCode = CurrencyShortCode;
    proxy->currencyType = CurrencyType;
    proxy->quantity = Quantity;
    proxy->shortCode = ShortCode;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    return proxy;
}

UGSBuyVirtualGoodsRequest* UGSBuyVirtualGoodsRequest::SendBuyVirtualGoodsRequestOnBehalfOf(const FString& PlayerId, FString CurrencyShortCode, int32 CurrencyType, int32 Quantity, FString ShortCode,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSBuyVirtualGoodsRequest* proxy = NewObject<UGSBuyVirtualGoodsRequest>();
    proxy->currencyShortCode = CurrencyShortCode;
    proxy->currencyType = CurrencyType;
    proxy->quantity = Quantity;
    proxy->shortCode = ShortCode;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    proxy->playerId = PlayerId;
    return proxy;
}
    
void UGSBuyVirtualGoodsRequest::Activate()
{
    GameSparks::Api::Requests::BuyVirtualGoodsRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
    if(currencyShortCode != ""){
        gsRequest.SetCurrencyShortCode(TCHAR_TO_UTF8(*currencyShortCode));
    }
    if(currencyType != 0){
        gsRequest.SetCurrencyType(currencyType);
    }
    if(quantity != 0){
        gsRequest.SetQuantity(quantity);
    }
    if(shortCode != ""){
        gsRequest.SetShortCode(TCHAR_TO_UTF8(*shortCode));
    }
    if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
        gsRequest.SetDurable(durable);
    }
    
    if(!playerId.IsEmpty())
    {
        gsRequest.SetPlayerId(TCHAR_TO_UTF8(*playerId));
    }

    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
        gsRequest.Send(BuyVirtualGoodsRequestResponseCallback, requestTimeoutSeconds);  
    } else {
        gsRequest.Send(BuyVirtualGoodsRequestResponseCallback);
    }
}

UGSBuyVirtualGoodsRequest::~UGSBuyVirtualGoodsRequest()
{
 if (UGameSparksModule* module = UGameSparksModule::GetModulePtr())
 {
  if (module->IsInitialized())
  {
    module->GetGSInstance().ChangeUserDataForRequests(this, nullptr);
  }
 }
}


void CancelBulkJobAdminRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::CancelBulkJobAdminResponse& response){
    
    if(response.GetUserData() == nullptr) {
        return;
    }
    
    FGSCancelBulkJobAdminResponse unreal_response = FGSCancelBulkJobAdminResponse(response.GetBaseData());
    
    UGSCancelBulkJobAdminRequest* g_UGSCancelBulkJobAdminRequest = static_cast<UGSCancelBulkJobAdminRequest*>(response.GetUserData());
                               
    if(!g_UGSCancelBulkJobAdminRequest->OnResponse.IsBound()){
        return;    
    }

    if (response.GetHasErrors())
    {
        g_UGSCancelBulkJobAdminRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSCancelBulkJobAdminRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSCancelBulkJobAdminRequest* UGSCancelBulkJobAdminRequest::SendCancelBulkJobAdminRequest(UGameSparksRequestArray* BulkJobIds,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSCancelBulkJobAdminRequest* proxy = NewObject<UGSCancelBulkJobAdminRequest>();
    proxy->bulkJobIds = BulkJobIds;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    return proxy;
}

UGSCancelBulkJobAdminRequest* UGSCancelBulkJobAdminRequest::SendCancelBulkJobAdminRequestOnBehalfOf(const FString& PlayerId, UGameSparksRequestArray* BulkJobIds,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSCancelBulkJobAdminRequest* proxy = NewObject<UGSCancelBulkJobAdminRequest>();
    proxy->bulkJobIds = BulkJobIds;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    proxy->playerId = PlayerId;
    return proxy;
}
    
void UGSCancelBulkJobAdminRequest::Activate()
{
    GameSparks::Api::Requests::CancelBulkJobAdminRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
    if(bulkJobIds != nullptr){
        gsstl::vector<gsstl::string> arrBulkJobIds;
    
        for(int32 b_arrBulkJobIds = 0; b_arrBulkJobIds < bulkJobIds->StringArray.Num(); b_arrBulkJobIds++)
        {
            arrBulkJobIds.push_back(TCHAR_TO_UTF8(*bulkJobIds->StringArray[b_arrBulkJobIds]));
        }
        
        gsRequest.SetBulkJobIds(arrBulkJobIds);
    }
    if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
        gsRequest.SetDurable(durable);
    }
    
    if(!playerId.IsEmpty())
    {
        gsRequest.SetPlayerId(TCHAR_TO_UTF8(*playerId));
    }

    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
        gsRequest.Send(CancelBulkJobAdminRequestResponseCallback, requestTimeoutSeconds);  
    } else {
        gsRequest.Send(CancelBulkJobAdminRequestResponseCallback);
    }
}

UGSCancelBulkJobAdminRequest::~UGSCancelBulkJobAdminRequest()
{
 if (UGameSparksModule* module = UGameSparksModule::GetModulePtr())
 {
  if (module->IsInitialized())
  {
    module->GetGSInstance().ChangeUserDataForRequests(this, nullptr);
  }
 }
}


void ChangeUserDetailsRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::ChangeUserDetailsResponse& response){
    
    if(response.GetUserData() == nullptr) {
        return;
    }
    
    FGSChangeUserDetailsResponse unreal_response = FGSChangeUserDetailsResponse(response.GetBaseData());
    
    UGSChangeUserDetailsRequest* g_UGSChangeUserDetailsRequest = static_cast<UGSChangeUserDetailsRequest*>(response.GetUserData());
                               
    if(!g_UGSChangeUserDetailsRequest->OnResponse.IsBound()){
        return;    
    }

    if (response.GetHasErrors())
    {
        g_UGSChangeUserDetailsRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSChangeUserDetailsRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSChangeUserDetailsRequest* UGSChangeUserDetailsRequest::SendChangeUserDetailsRequest(FString DisplayName, FString Language, FString NewPassword, FString OldPassword, FString UserName,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSChangeUserDetailsRequest* proxy = NewObject<UGSChangeUserDetailsRequest>();
    proxy->displayName = DisplayName;
    proxy->language = Language;
    proxy->newPassword = NewPassword;
    proxy->oldPassword = OldPassword;
    proxy->userName = UserName;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    return proxy;
}

UGSChangeUserDetailsRequest* UGSChangeUserDetailsRequest::SendChangeUserDetailsRequestOnBehalfOf(const FString& PlayerId, FString DisplayName, FString Language, FString NewPassword, FString OldPassword, FString UserName,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSChangeUserDetailsRequest* proxy = NewObject<UGSChangeUserDetailsRequest>();
    proxy->displayName = DisplayName;
    proxy->language = Language;
    proxy->newPassword = NewPassword;
    proxy->oldPassword = OldPassword;
    proxy->userName = UserName;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    proxy->playerId = PlayerId;
    return proxy;
}
    
void UGSChangeUserDetailsRequest::Activate()
{
    GameSparks::Api::Requests::ChangeUserDetailsRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
    if(displayName != ""){
        gsRequest.SetDisplayName(TCHAR_TO_UTF8(*displayName));
    }
    if(language != ""){
        gsRequest.SetLanguage(TCHAR_TO_UTF8(*language));
    }
    if(newPassword != ""){
        gsRequest.SetNewPassword(TCHAR_TO_UTF8(*newPassword));
    }
    if(oldPassword != ""){
        gsRequest.SetOldPassword(TCHAR_TO_UTF8(*oldPassword));
    }
    if(userName != ""){
        gsRequest.SetUserName(TCHAR_TO_UTF8(*userName));
    }
    if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
        gsRequest.SetDurable(durable);
    }
    
    if(!playerId.IsEmpty())
    {
        gsRequest.SetPlayerId(TCHAR_TO_UTF8(*playerId));
    }

    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
        gsRequest.Send(ChangeUserDetailsRequestResponseCallback, requestTimeoutSeconds);  
    } else {
        gsRequest.Send(ChangeUserDetailsRequestResponseCallback);
    }
}

UGSChangeUserDetailsRequest::~UGSChangeUserDetailsRequest()
{
 if (UGameSparksModule* module = UGameSparksModule::GetModulePtr())
 {
  if (module->IsInitialized())
  {
    module->GetGSInstance().ChangeUserDataForRequests(this, nullptr);
  }
 }
}


void ChatOnChallengeRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::ChatOnChallengeResponse& response){
    
    if(response.GetUserData() == nullptr) {
        return;
    }
    
    FGSChatOnChallengeResponse unreal_response = FGSChatOnChallengeResponse(response.GetBaseData());
    
    UGSChatOnChallengeRequest* g_UGSChatOnChallengeRequest = static_cast<UGSChatOnChallengeRequest*>(response.GetUserData());
                               
    if(!g_UGSChatOnChallengeRequest->OnResponse.IsBound()){
        return;    
    }

    if (response.GetHasErrors())
    {
        g_UGSChatOnChallengeRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSChatOnChallengeRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSChatOnChallengeRequest* UGSChatOnChallengeRequest::SendChatOnChallengeRequest(FString ChallengeInstanceId, FString Message,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSChatOnChallengeRequest* proxy = NewObject<UGSChatOnChallengeRequest>();
    proxy->challengeInstanceId = ChallengeInstanceId;
    proxy->message = Message;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    return proxy;
}

UGSChatOnChallengeRequest* UGSChatOnChallengeRequest::SendChatOnChallengeRequestOnBehalfOf(const FString& PlayerId, FString ChallengeInstanceId, FString Message,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSChatOnChallengeRequest* proxy = NewObject<UGSChatOnChallengeRequest>();
    proxy->challengeInstanceId = ChallengeInstanceId;
    proxy->message = Message;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    proxy->playerId = PlayerId;
    return proxy;
}
    
void UGSChatOnChallengeRequest::Activate()
{
    GameSparks::Api::Requests::ChatOnChallengeRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
    if(challengeInstanceId != ""){
        gsRequest.SetChallengeInstanceId(TCHAR_TO_UTF8(*challengeInstanceId));
    }
    if(message != ""){
        gsRequest.SetMessage(TCHAR_TO_UTF8(*message));
    }
    if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
        gsRequest.SetDurable(durable);
    }
    
    if(!playerId.IsEmpty())
    {
        gsRequest.SetPlayerId(TCHAR_TO_UTF8(*playerId));
    }

    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
        gsRequest.Send(ChatOnChallengeRequestResponseCallback, requestTimeoutSeconds);  
    } else {
        gsRequest.Send(ChatOnChallengeRequestResponseCallback);
    }
}

UGSChatOnChallengeRequest::~UGSChatOnChallengeRequest()
{
 if (UGameSparksModule* module = UGameSparksModule::GetModulePtr())
 {
  if (module->IsInitialized())
  {
    module->GetGSInstance().ChangeUserDataForRequests(this, nullptr);
  }
 }
}


void ConsumeVirtualGoodRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::ConsumeVirtualGoodResponse& response){
    
    if(response.GetUserData() == nullptr) {
        return;
    }
    
    FGSConsumeVirtualGoodResponse unreal_response = FGSConsumeVirtualGoodResponse(response.GetBaseData());
    
    UGSConsumeVirtualGoodRequest* g_UGSConsumeVirtualGoodRequest = static_cast<UGSConsumeVirtualGoodRequest*>(response.GetUserData());
                               
    if(!g_UGSConsumeVirtualGoodRequest->OnResponse.IsBound()){
        return;    
    }

    if (response.GetHasErrors())
    {
        g_UGSConsumeVirtualGoodRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSConsumeVirtualGoodRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSConsumeVirtualGoodRequest* UGSConsumeVirtualGoodRequest::SendConsumeVirtualGoodRequest(int32 Quantity, FString ShortCode,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSConsumeVirtualGoodRequest* proxy = NewObject<UGSConsumeVirtualGoodRequest>();
    proxy->quantity = Quantity;
    proxy->shortCode = ShortCode;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    return proxy;
}

UGSConsumeVirtualGoodRequest* UGSConsumeVirtualGoodRequest::SendConsumeVirtualGoodRequestOnBehalfOf(const FString& PlayerId, int32 Quantity, FString ShortCode,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSConsumeVirtualGoodRequest* proxy = NewObject<UGSConsumeVirtualGoodRequest>();
    proxy->quantity = Quantity;
    proxy->shortCode = ShortCode;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    proxy->playerId = PlayerId;
    return proxy;
}
    
void UGSConsumeVirtualGoodRequest::Activate()
{
    GameSparks::Api::Requests::ConsumeVirtualGoodRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
    if(quantity != 0){
        gsRequest.SetQuantity(quantity);
    }
    if(shortCode != ""){
        gsRequest.SetShortCode(TCHAR_TO_UTF8(*shortCode));
    }
    if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
        gsRequest.SetDurable(durable);
    }
    
    if(!playerId.IsEmpty())
    {
        gsRequest.SetPlayerId(TCHAR_TO_UTF8(*playerId));
    }

    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
        gsRequest.Send(ConsumeVirtualGoodRequestResponseCallback, requestTimeoutSeconds);  
    } else {
        gsRequest.Send(ConsumeVirtualGoodRequestResponseCallback);
    }
}

UGSConsumeVirtualGoodRequest::~UGSConsumeVirtualGoodRequest()
{
 if (UGameSparksModule* module = UGameSparksModule::GetModulePtr())
 {
  if (module->IsInitialized())
  {
    module->GetGSInstance().ChangeUserDataForRequests(this, nullptr);
  }
 }
}


void CreateChallengeRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::CreateChallengeResponse& response){
    
    if(response.GetUserData() == nullptr) {
        return;
    }
    
    FGSCreateChallengeResponse unreal_response = FGSCreateChallengeResponse(response.GetBaseData());
    
    UGSCreateChallengeRequest* g_UGSCreateChallengeRequest = static_cast<UGSCreateChallengeRequest*>(response.GetUserData());
                               
    if(!g_UGSCreateChallengeRequest->OnResponse.IsBound()){
        return;    
    }

    if (response.GetHasErrors())
    {
        g_UGSCreateChallengeRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSCreateChallengeRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSCreateChallengeRequest* UGSCreateChallengeRequest::SendCreateChallengeRequest(FString AccessType, bool AutoStartJoinedChallengeOnMaxPlayers, FString ChallengeMessage, FString ChallengeShortCode, int32 Currency1Wager, int32 Currency2Wager, int32 Currency3Wager, int32 Currency4Wager, int32 Currency5Wager, int32 Currency6Wager, UGameSparksScriptData* CurrencyWagers, UGameSparksScriptData* EligibilityCriteria, FString EndTime, FString ExpiryTime, int32 MaxAttempts, int32 MaxPlayers, int32 MinPlayers, bool Silent, FString StartTime, UGameSparksRequestArray* UsersToChallenge,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSCreateChallengeRequest* proxy = NewObject<UGSCreateChallengeRequest>();
    proxy->accessType = AccessType;
    proxy->autoStartJoinedChallengeOnMaxPlayers = AutoStartJoinedChallengeOnMaxPlayers;
    proxy->challengeMessage = ChallengeMessage;
    proxy->challengeShortCode = ChallengeShortCode;
    proxy->currency1Wager = Currency1Wager;
    proxy->currency2Wager = Currency2Wager;
    proxy->currency3Wager = Currency3Wager;
    proxy->currency4Wager = Currency4Wager;
    proxy->currency5Wager = Currency5Wager;
    proxy->currency6Wager = Currency6Wager;
    proxy->currencyWagers = CurrencyWagers;
    proxy->eligibilityCriteria = EligibilityCriteria;
    proxy->endTime = EndTime;
    proxy->expiryTime = ExpiryTime;
    proxy->maxAttempts = MaxAttempts;
    proxy->maxPlayers = MaxPlayers;
    proxy->minPlayers = MinPlayers;
    proxy->silent = Silent;
    proxy->startTime = StartTime;
    proxy->usersToChallenge = UsersToChallenge;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    return proxy;
}

UGSCreateChallengeRequest* UGSCreateChallengeRequest::SendCreateChallengeRequestOnBehalfOf(const FString& PlayerId, FString AccessType, bool AutoStartJoinedChallengeOnMaxPlayers, FString ChallengeMessage, FString ChallengeShortCode, int32 Currency1Wager, int32 Currency2Wager, int32 Currency3Wager, int32 Currency4Wager, int32 Currency5Wager, int32 Currency6Wager, UGameSparksScriptData* CurrencyWagers, UGameSparksScriptData* EligibilityCriteria, FString EndTime, FString ExpiryTime, int32 MaxAttempts, int32 MaxPlayers, int32 MinPlayers, bool Silent, FString StartTime, UGameSparksRequestArray* UsersToChallenge,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSCreateChallengeRequest* proxy = NewObject<UGSCreateChallengeRequest>();
    proxy->accessType = AccessType;
    proxy->autoStartJoinedChallengeOnMaxPlayers = AutoStartJoinedChallengeOnMaxPlayers;
    proxy->challengeMessage = ChallengeMessage;
    proxy->challengeShortCode = ChallengeShortCode;
    proxy->currency1Wager = Currency1Wager;
    proxy->currency2Wager = Currency2Wager;
    proxy->currency3Wager = Currency3Wager;
    proxy->currency4Wager = Currency4Wager;
    proxy->currency5Wager = Currency5Wager;
    proxy->currency6Wager = Currency6Wager;
    proxy->currencyWagers = CurrencyWagers;
    proxy->eligibilityCriteria = EligibilityCriteria;
    proxy->endTime = EndTime;
    proxy->expiryTime = ExpiryTime;
    proxy->maxAttempts = MaxAttempts;
    proxy->maxPlayers = MaxPlayers;
    proxy->minPlayers = MinPlayers;
    proxy->silent = Silent;
    proxy->startTime = StartTime;
    proxy->usersToChallenge = UsersToChallenge;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    proxy->playerId = PlayerId;
    return proxy;
}
    
void UGSCreateChallengeRequest::Activate()
{
    GameSparks::Api::Requests::CreateChallengeRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
    if(accessType != ""){
        gsRequest.SetAccessType(TCHAR_TO_UTF8(*accessType));
    }
    if(autoStartJoinedChallengeOnMaxPlayers != false){
        gsRequest.SetAutoStartJoinedChallengeOnMaxPlayers(autoStartJoinedChallengeOnMaxPlayers);
    }
    if(challengeMessage != ""){
        gsRequest.SetChallengeMessage(TCHAR_TO_UTF8(*challengeMessage));
    }
    if(challengeShortCode != ""){
        gsRequest.SetChallengeShortCode(TCHAR_TO_UTF8(*challengeShortCode));
    }
    if(currency1Wager != 0){
        gsRequest.SetCurrency1Wager(currency1Wager);
    }
    if(currency2Wager != 0){
        gsRequest.SetCurrency2Wager(currency2Wager);
    }
    if(currency3Wager != 0){
        gsRequest.SetCurrency3Wager(currency3Wager);
    }
    if(currency4Wager != 0){
        gsRequest.SetCurrency4Wager(currency4Wager);
    }
    if(currency5Wager != 0){
        gsRequest.SetCurrency5Wager(currency5Wager);
    }
    if(currency6Wager != 0){
        gsRequest.SetCurrency6Wager(currency6Wager);
    }
    if(currencyWagers != nullptr){
        gsRequest.SetCurrencyWagers(currencyWagers->ToRequestData());
    }
    if(eligibilityCriteria != nullptr){
        gsRequest.SetEligibilityCriteria(eligibilityCriteria->ToRequestData());
    }
    if(endTime != ""){
        gsRequest.SetEndTime(GameSparks::Core::GSDateTime(TCHAR_TO_UTF8(*endTime)));
    }
    if(expiryTime != ""){
        gsRequest.SetExpiryTime(GameSparks::Core::GSDateTime(TCHAR_TO_UTF8(*expiryTime)));
    }
    if(maxAttempts != 0){
        gsRequest.SetMaxAttempts(maxAttempts);
    }
    if(maxPlayers != 0){
        gsRequest.SetMaxPlayers(maxPlayers);
    }
    if(minPlayers != 0){
        gsRequest.SetMinPlayers(minPlayers);
    }
    if(silent != false){
        gsRequest.SetSilent(silent);
    }
    if(startTime != ""){
        gsRequest.SetStartTime(GameSparks::Core::GSDateTime(TCHAR_TO_UTF8(*startTime)));
    }
    if(usersToChallenge != nullptr){
        gsstl::vector<gsstl::string> arrUsersToChallenge;
    
        for(int32 b_arrUsersToChallenge = 0; b_arrUsersToChallenge < usersToChallenge->StringArray.Num(); b_arrUsersToChallenge++)
        {
            arrUsersToChallenge.push_back(TCHAR_TO_UTF8(*usersToChallenge->StringArray[b_arrUsersToChallenge]));
        }
        
        gsRequest.SetUsersToChallenge(arrUsersToChallenge);
    }
    if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
        gsRequest.SetDurable(durable);
    }
    
    if(!playerId.IsEmpty())
    {
        gsRequest.SetPlayerId(TCHAR_TO_UTF8(*playerId));
    }

    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
        gsRequest.Send(CreateChallengeRequestResponseCallback, requestTimeoutSeconds);  
    } else {
        gsRequest.Send(CreateChallengeRequestResponseCallback);
    }
}

UGSCreateChallengeRequest::~UGSCreateChallengeRequest()
{
 if (UGameSparksModule* module = UGameSparksModule::GetModulePtr())
 {
  if (module->IsInitialized())
  {
    module->GetGSInstance().ChangeUserDataForRequests(this, nullptr);
  }
 }
}


void CreateTeamRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::CreateTeamResponse& response){
    
    if(response.GetUserData() == nullptr) {
        return;
    }
    
    FGSCreateTeamResponse unreal_response = FGSCreateTeamResponse(response.GetBaseData());
    
    UGSCreateTeamRequest* g_UGSCreateTeamRequest = static_cast<UGSCreateTeamRequest*>(response.GetUserData());
                               
    if(!g_UGSCreateTeamRequest->OnResponse.IsBound()){
        return;    
    }

    if (response.GetHasErrors())
    {
        g_UGSCreateTeamRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSCreateTeamRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSCreateTeamRequest* UGSCreateTeamRequest::SendCreateTeamRequest(FString TeamId, FString TeamName, FString TeamType,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSCreateTeamRequest* proxy = NewObject<UGSCreateTeamRequest>();
    proxy->teamId = TeamId;
    proxy->teamName = TeamName;
    proxy->teamType = TeamType;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    return proxy;
}

UGSCreateTeamRequest* UGSCreateTeamRequest::SendCreateTeamRequestOnBehalfOf(const FString& PlayerId, FString TeamId, FString TeamName, FString TeamType,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSCreateTeamRequest* proxy = NewObject<UGSCreateTeamRequest>();
    proxy->teamId = TeamId;
    proxy->teamName = TeamName;
    proxy->teamType = TeamType;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    proxy->playerId = PlayerId;
    return proxy;
}
    
void UGSCreateTeamRequest::Activate()
{
    GameSparks::Api::Requests::CreateTeamRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
    if(teamId != ""){
        gsRequest.SetTeamId(TCHAR_TO_UTF8(*teamId));
    }
    if(teamName != ""){
        gsRequest.SetTeamName(TCHAR_TO_UTF8(*teamName));
    }
    if(teamType != ""){
        gsRequest.SetTeamType(TCHAR_TO_UTF8(*teamType));
    }
    if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
        gsRequest.SetDurable(durable);
    }
    
    if(!playerId.IsEmpty())
    {
        gsRequest.SetPlayerId(TCHAR_TO_UTF8(*playerId));
    }

    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
        gsRequest.Send(CreateTeamRequestResponseCallback, requestTimeoutSeconds);  
    } else {
        gsRequest.Send(CreateTeamRequestResponseCallback);
    }
}

UGSCreateTeamRequest::~UGSCreateTeamRequest()
{
 if (UGameSparksModule* module = UGameSparksModule::GetModulePtr())
 {
  if (module->IsInitialized())
  {
    module->GetGSInstance().ChangeUserDataForRequests(this, nullptr);
  }
 }
}


void DeclineChallengeRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::DeclineChallengeResponse& response){
    
    if(response.GetUserData() == nullptr) {
        return;
    }
    
    FGSDeclineChallengeResponse unreal_response = FGSDeclineChallengeResponse(response.GetBaseData());
    
    UGSDeclineChallengeRequest* g_UGSDeclineChallengeRequest = static_cast<UGSDeclineChallengeRequest*>(response.GetUserData());
                               
    if(!g_UGSDeclineChallengeRequest->OnResponse.IsBound()){
        return;    
    }

    if (response.GetHasErrors())
    {
        g_UGSDeclineChallengeRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSDeclineChallengeRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSDeclineChallengeRequest* UGSDeclineChallengeRequest::SendDeclineChallengeRequest(FString ChallengeInstanceId, FString Message,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSDeclineChallengeRequest* proxy = NewObject<UGSDeclineChallengeRequest>();
    proxy->challengeInstanceId = ChallengeInstanceId;
    proxy->message = Message;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    return proxy;
}

UGSDeclineChallengeRequest* UGSDeclineChallengeRequest::SendDeclineChallengeRequestOnBehalfOf(const FString& PlayerId, FString ChallengeInstanceId, FString Message,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSDeclineChallengeRequest* proxy = NewObject<UGSDeclineChallengeRequest>();
    proxy->challengeInstanceId = ChallengeInstanceId;
    proxy->message = Message;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    proxy->playerId = PlayerId;
    return proxy;
}
    
void UGSDeclineChallengeRequest::Activate()
{
    GameSparks::Api::Requests::DeclineChallengeRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
    if(challengeInstanceId != ""){
        gsRequest.SetChallengeInstanceId(TCHAR_TO_UTF8(*challengeInstanceId));
    }
    if(message != ""){
        gsRequest.SetMessage(TCHAR_TO_UTF8(*message));
    }
    if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
        gsRequest.SetDurable(durable);
    }
    
    if(!playerId.IsEmpty())
    {
        gsRequest.SetPlayerId(TCHAR_TO_UTF8(*playerId));
    }

    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
        gsRequest.Send(DeclineChallengeRequestResponseCallback, requestTimeoutSeconds);  
    } else {
        gsRequest.Send(DeclineChallengeRequestResponseCallback);
    }
}

UGSDeclineChallengeRequest::~UGSDeclineChallengeRequest()
{
 if (UGameSparksModule* module = UGameSparksModule::GetModulePtr())
 {
  if (module->IsInitialized())
  {
    module->GetGSInstance().ChangeUserDataForRequests(this, nullptr);
  }
 }
}


void DeviceAuthenticationRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::AuthenticationResponse& response){
    
    if(response.GetUserData() == nullptr) {
        return;
    }
    
    FGSAuthenticationResponse unreal_response = FGSAuthenticationResponse(response.GetBaseData());
    
    UGSDeviceAuthenticationRequest* g_UGSDeviceAuthenticationRequest = static_cast<UGSDeviceAuthenticationRequest*>(response.GetUserData());
                               
    if(!g_UGSDeviceAuthenticationRequest->OnResponse.IsBound()){
        return;    
    }

    if (response.GetHasErrors())
    {
        g_UGSDeviceAuthenticationRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSDeviceAuthenticationRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSDeviceAuthenticationRequest* UGSDeviceAuthenticationRequest::SendDeviceAuthenticationRequest(FString DeviceId, FString DeviceModel, FString DeviceName, FString DeviceOS, FString DeviceType, FString DisplayName, FString OperatingSystem, UGameSparksScriptData* Segments,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSDeviceAuthenticationRequest* proxy = NewObject<UGSDeviceAuthenticationRequest>();
    proxy->deviceId = DeviceId;
    proxy->deviceModel = DeviceModel;
    proxy->deviceName = DeviceName;
    proxy->deviceOS = DeviceOS;
    proxy->deviceType = DeviceType;
    proxy->displayName = DisplayName;
    proxy->operatingSystem = OperatingSystem;
    proxy->segments = Segments;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    return proxy;
}

UGSDeviceAuthenticationRequest* UGSDeviceAuthenticationRequest::SendDeviceAuthenticationRequestOnBehalfOf(const FString& PlayerId, FString DeviceId, FString DeviceModel, FString DeviceName, FString DeviceOS, FString DeviceType, FString DisplayName, FString OperatingSystem, UGameSparksScriptData* Segments,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSDeviceAuthenticationRequest* proxy = NewObject<UGSDeviceAuthenticationRequest>();
    proxy->deviceId = DeviceId;
    proxy->deviceModel = DeviceModel;
    proxy->deviceName = DeviceName;
    proxy->deviceOS = DeviceOS;
    proxy->deviceType = DeviceType;
    proxy->displayName = DisplayName;
    proxy->operatingSystem = OperatingSystem;
    proxy->segments = Segments;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    proxy->playerId = PlayerId;
    return proxy;
}
    
void UGSDeviceAuthenticationRequest::Activate()
{
    GameSparks::Api::Requests::DeviceAuthenticationRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
    if(deviceId != ""){
        gsRequest.SetDeviceId(TCHAR_TO_UTF8(*deviceId));
    }
    if(deviceModel != ""){
        gsRequest.SetDeviceModel(TCHAR_TO_UTF8(*deviceModel));
    }
    if(deviceName != ""){
        gsRequest.SetDeviceName(TCHAR_TO_UTF8(*deviceName));
    }
    if(deviceOS != ""){
        gsRequest.SetDeviceOS(TCHAR_TO_UTF8(*deviceOS));
    }
    if(deviceType != ""){
        gsRequest.SetDeviceType(TCHAR_TO_UTF8(*deviceType));
    }
    if(displayName != ""){
        gsRequest.SetDisplayName(TCHAR_TO_UTF8(*displayName));
    }
    if(operatingSystem != ""){
        gsRequest.SetOperatingSystem(TCHAR_TO_UTF8(*operatingSystem));
    }
    if(segments != nullptr){
        gsRequest.SetSegments(segments->ToRequestData());
    }
    if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
        gsRequest.SetDurable(durable);
    }
    
    if(!playerId.IsEmpty())
    {
        gsRequest.SetPlayerId(TCHAR_TO_UTF8(*playerId));
    }

    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
        gsRequest.Send(DeviceAuthenticationRequestResponseCallback, requestTimeoutSeconds);  
    } else {
        gsRequest.Send(DeviceAuthenticationRequestResponseCallback);
    }
}

UGSDeviceAuthenticationRequest::~UGSDeviceAuthenticationRequest()
{
 if (UGameSparksModule* module = UGameSparksModule::GetModulePtr())
 {
  if (module->IsInitialized())
  {
    module->GetGSInstance().ChangeUserDataForRequests(this, nullptr);
  }
 }
}


void DismissMessageRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::DismissMessageResponse& response){
    
    if(response.GetUserData() == nullptr) {
        return;
    }
    
    FGSDismissMessageResponse unreal_response = FGSDismissMessageResponse(response.GetBaseData());
    
    UGSDismissMessageRequest* g_UGSDismissMessageRequest = static_cast<UGSDismissMessageRequest*>(response.GetUserData());
                               
    if(!g_UGSDismissMessageRequest->OnResponse.IsBound()){
        return;    
    }

    if (response.GetHasErrors())
    {
        g_UGSDismissMessageRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSDismissMessageRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSDismissMessageRequest* UGSDismissMessageRequest::SendDismissMessageRequest(FString MessageId,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSDismissMessageRequest* proxy = NewObject<UGSDismissMessageRequest>();
    proxy->messageId = MessageId;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    return proxy;
}

UGSDismissMessageRequest* UGSDismissMessageRequest::SendDismissMessageRequestOnBehalfOf(const FString& PlayerId, FString MessageId,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSDismissMessageRequest* proxy = NewObject<UGSDismissMessageRequest>();
    proxy->messageId = MessageId;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    proxy->playerId = PlayerId;
    return proxy;
}
    
void UGSDismissMessageRequest::Activate()
{
    GameSparks::Api::Requests::DismissMessageRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
    if(messageId != ""){
        gsRequest.SetMessageId(TCHAR_TO_UTF8(*messageId));
    }
    if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
        gsRequest.SetDurable(durable);
    }
    
    if(!playerId.IsEmpty())
    {
        gsRequest.SetPlayerId(TCHAR_TO_UTF8(*playerId));
    }

    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
        gsRequest.Send(DismissMessageRequestResponseCallback, requestTimeoutSeconds);  
    } else {
        gsRequest.Send(DismissMessageRequestResponseCallback);
    }
}

UGSDismissMessageRequest::~UGSDismissMessageRequest()
{
 if (UGameSparksModule* module = UGameSparksModule::GetModulePtr())
 {
  if (module->IsInitialized())
  {
    module->GetGSInstance().ChangeUserDataForRequests(this, nullptr);
  }
 }
}


void DismissMultipleMessagesRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::DismissMultipleMessagesResponse& response){
    
    if(response.GetUserData() == nullptr) {
        return;
    }
    
    FGSDismissMultipleMessagesResponse unreal_response = FGSDismissMultipleMessagesResponse(response.GetBaseData());
    
    UGSDismissMultipleMessagesRequest* g_UGSDismissMultipleMessagesRequest = static_cast<UGSDismissMultipleMessagesRequest*>(response.GetUserData());
                               
    if(!g_UGSDismissMultipleMessagesRequest->OnResponse.IsBound()){
        return;    
    }

    if (response.GetHasErrors())
    {
        g_UGSDismissMultipleMessagesRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSDismissMultipleMessagesRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSDismissMultipleMessagesRequest* UGSDismissMultipleMessagesRequest::SendDismissMultipleMessagesRequest(UGameSparksRequestArray* MessageIds,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSDismissMultipleMessagesRequest* proxy = NewObject<UGSDismissMultipleMessagesRequest>();
    proxy->messageIds = MessageIds;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    return proxy;
}

UGSDismissMultipleMessagesRequest* UGSDismissMultipleMessagesRequest::SendDismissMultipleMessagesRequestOnBehalfOf(const FString& PlayerId, UGameSparksRequestArray* MessageIds,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSDismissMultipleMessagesRequest* proxy = NewObject<UGSDismissMultipleMessagesRequest>();
    proxy->messageIds = MessageIds;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    proxy->playerId = PlayerId;
    return proxy;
}
    
void UGSDismissMultipleMessagesRequest::Activate()
{
    GameSparks::Api::Requests::DismissMultipleMessagesRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
    if(messageIds != nullptr){
        gsstl::vector<gsstl::string> arrMessageIds;
    
        for(int32 b_arrMessageIds = 0; b_arrMessageIds < messageIds->StringArray.Num(); b_arrMessageIds++)
        {
            arrMessageIds.push_back(TCHAR_TO_UTF8(*messageIds->StringArray[b_arrMessageIds]));
        }
        
        gsRequest.SetMessageIds(arrMessageIds);
    }
    if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
        gsRequest.SetDurable(durable);
    }
    
    if(!playerId.IsEmpty())
    {
        gsRequest.SetPlayerId(TCHAR_TO_UTF8(*playerId));
    }

    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
        gsRequest.Send(DismissMultipleMessagesRequestResponseCallback, requestTimeoutSeconds);  
    } else {
        gsRequest.Send(DismissMultipleMessagesRequestResponseCallback);
    }
}

UGSDismissMultipleMessagesRequest::~UGSDismissMultipleMessagesRequest()
{
 if (UGameSparksModule* module = UGameSparksModule::GetModulePtr())
 {
  if (module->IsInitialized())
  {
    module->GetGSInstance().ChangeUserDataForRequests(this, nullptr);
  }
 }
}


void DropTeamRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::DropTeamResponse& response){
    
    if(response.GetUserData() == nullptr) {
        return;
    }
    
    FGSDropTeamResponse unreal_response = FGSDropTeamResponse(response.GetBaseData());
    
    UGSDropTeamRequest* g_UGSDropTeamRequest = static_cast<UGSDropTeamRequest*>(response.GetUserData());
                               
    if(!g_UGSDropTeamRequest->OnResponse.IsBound()){
        return;    
    }

    if (response.GetHasErrors())
    {
        g_UGSDropTeamRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSDropTeamRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSDropTeamRequest* UGSDropTeamRequest::SendDropTeamRequest(FString OwnerId, FString TeamId, FString TeamType,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSDropTeamRequest* proxy = NewObject<UGSDropTeamRequest>();
    proxy->ownerId = OwnerId;
    proxy->teamId = TeamId;
    proxy->teamType = TeamType;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    return proxy;
}

UGSDropTeamRequest* UGSDropTeamRequest::SendDropTeamRequestOnBehalfOf(const FString& PlayerId, FString OwnerId, FString TeamId, FString TeamType,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSDropTeamRequest* proxy = NewObject<UGSDropTeamRequest>();
    proxy->ownerId = OwnerId;
    proxy->teamId = TeamId;
    proxy->teamType = TeamType;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    proxy->playerId = PlayerId;
    return proxy;
}
    
void UGSDropTeamRequest::Activate()
{
    GameSparks::Api::Requests::DropTeamRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
    if(ownerId != ""){
        gsRequest.SetOwnerId(TCHAR_TO_UTF8(*ownerId));
    }
    if(teamId != ""){
        gsRequest.SetTeamId(TCHAR_TO_UTF8(*teamId));
    }
    if(teamType != ""){
        gsRequest.SetTeamType(TCHAR_TO_UTF8(*teamType));
    }
    if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
        gsRequest.SetDurable(durable);
    }
    
    if(!playerId.IsEmpty())
    {
        gsRequest.SetPlayerId(TCHAR_TO_UTF8(*playerId));
    }

    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
        gsRequest.Send(DropTeamRequestResponseCallback, requestTimeoutSeconds);  
    } else {
        gsRequest.Send(DropTeamRequestResponseCallback);
    }
}

UGSDropTeamRequest::~UGSDropTeamRequest()
{
 if (UGameSparksModule* module = UGameSparksModule::GetModulePtr())
 {
  if (module->IsInitialized())
  {
    module->GetGSInstance().ChangeUserDataForRequests(this, nullptr);
  }
 }
}


void EndSessionRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::EndSessionResponse& response){
    
    if(response.GetUserData() == nullptr) {
        return;
    }
    
    FGSEndSessionResponse unreal_response = FGSEndSessionResponse(response.GetBaseData());
    
    UGSEndSessionRequest* g_UGSEndSessionRequest = static_cast<UGSEndSessionRequest*>(response.GetUserData());
                               
    if(!g_UGSEndSessionRequest->OnResponse.IsBound()){
        return;    
    }

    if (response.GetHasErrors())
    {
        g_UGSEndSessionRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSEndSessionRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSEndSessionRequest* UGSEndSessionRequest::SendEndSessionRequest( UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSEndSessionRequest* proxy = NewObject<UGSEndSessionRequest>();
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    return proxy;
}

UGSEndSessionRequest* UGSEndSessionRequest::SendEndSessionRequestOnBehalfOf(const FString& PlayerId,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSEndSessionRequest* proxy = NewObject<UGSEndSessionRequest>();
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    proxy->playerId = PlayerId;
    return proxy;
}
    
void UGSEndSessionRequest::Activate()
{
    GameSparks::Api::Requests::EndSessionRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
    if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
        gsRequest.SetDurable(durable);
    }
    
    if(!playerId.IsEmpty())
    {
        gsRequest.SetPlayerId(TCHAR_TO_UTF8(*playerId));
    }

    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
        gsRequest.Send(EndSessionRequestResponseCallback, requestTimeoutSeconds);  
    } else {
        gsRequest.Send(EndSessionRequestResponseCallback);
    }
}

UGSEndSessionRequest::~UGSEndSessionRequest()
{
 if (UGameSparksModule* module = UGameSparksModule::GetModulePtr())
 {
  if (module->IsInitialized())
  {
    module->GetGSInstance().ChangeUserDataForRequests(this, nullptr);
  }
 }
}


void FacebookConnectRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::AuthenticationResponse& response){
    
    if(response.GetUserData() == nullptr) {
        return;
    }
    
    FGSAuthenticationResponse unreal_response = FGSAuthenticationResponse(response.GetBaseData());
    
    UGSFacebookConnectRequest* g_UGSFacebookConnectRequest = static_cast<UGSFacebookConnectRequest*>(response.GetUserData());
                               
    if(!g_UGSFacebookConnectRequest->OnResponse.IsBound()){
        return;    
    }

    if (response.GetHasErrors())
    {
        g_UGSFacebookConnectRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSFacebookConnectRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSFacebookConnectRequest* UGSFacebookConnectRequest::SendFacebookConnectRequest(FString AccessToken, FString Code, bool DoNotLinkToCurrentPlayer, bool ErrorOnSwitch, UGameSparksScriptData* Segments, bool SwitchIfPossible, bool SyncDisplayName,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSFacebookConnectRequest* proxy = NewObject<UGSFacebookConnectRequest>();
    proxy->accessToken = AccessToken;
    proxy->code = Code;
    proxy->doNotLinkToCurrentPlayer = DoNotLinkToCurrentPlayer;
    proxy->errorOnSwitch = ErrorOnSwitch;
    proxy->segments = Segments;
    proxy->switchIfPossible = SwitchIfPossible;
    proxy->syncDisplayName = SyncDisplayName;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    return proxy;
}

UGSFacebookConnectRequest* UGSFacebookConnectRequest::SendFacebookConnectRequestOnBehalfOf(const FString& PlayerId, FString AccessToken, FString Code, bool DoNotLinkToCurrentPlayer, bool ErrorOnSwitch, UGameSparksScriptData* Segments, bool SwitchIfPossible, bool SyncDisplayName,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSFacebookConnectRequest* proxy = NewObject<UGSFacebookConnectRequest>();
    proxy->accessToken = AccessToken;
    proxy->code = Code;
    proxy->doNotLinkToCurrentPlayer = DoNotLinkToCurrentPlayer;
    proxy->errorOnSwitch = ErrorOnSwitch;
    proxy->segments = Segments;
    proxy->switchIfPossible = SwitchIfPossible;
    proxy->syncDisplayName = SyncDisplayName;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    proxy->playerId = PlayerId;
    return proxy;
}
    
void UGSFacebookConnectRequest::Activate()
{
    GameSparks::Api::Requests::FacebookConnectRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
    if(accessToken != ""){
        gsRequest.SetAccessToken(TCHAR_TO_UTF8(*accessToken));
    }
    if(code != ""){
        gsRequest.SetCode(TCHAR_TO_UTF8(*code));
    }
    if(doNotLinkToCurrentPlayer != false){
        gsRequest.SetDoNotLinkToCurrentPlayer(doNotLinkToCurrentPlayer);
    }
    if(errorOnSwitch != false){
        gsRequest.SetErrorOnSwitch(errorOnSwitch);
    }
    if(segments != nullptr){
        gsRequest.SetSegments(segments->ToRequestData());
    }
    if(switchIfPossible != false){
        gsRequest.SetSwitchIfPossible(switchIfPossible);
    }
    if(syncDisplayName != false){
        gsRequest.SetSyncDisplayName(syncDisplayName);
    }
    if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
        gsRequest.SetDurable(durable);
    }
    
    if(!playerId.IsEmpty())
    {
        gsRequest.SetPlayerId(TCHAR_TO_UTF8(*playerId));
    }

    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
        gsRequest.Send(FacebookConnectRequestResponseCallback, requestTimeoutSeconds);  
    } else {
        gsRequest.Send(FacebookConnectRequestResponseCallback);
    }
}

UGSFacebookConnectRequest::~UGSFacebookConnectRequest()
{
 if (UGameSparksModule* module = UGameSparksModule::GetModulePtr())
 {
  if (module->IsInitialized())
  {
    module->GetGSInstance().ChangeUserDataForRequests(this, nullptr);
  }
 }
}


void FindChallengeRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::FindChallengeResponse& response){
    
    if(response.GetUserData() == nullptr) {
        return;
    }
    
    FGSFindChallengeResponse unreal_response = FGSFindChallengeResponse(response.GetBaseData());
    
    UGSFindChallengeRequest* g_UGSFindChallengeRequest = static_cast<UGSFindChallengeRequest*>(response.GetUserData());
                               
    if(!g_UGSFindChallengeRequest->OnResponse.IsBound()){
        return;    
    }

    if (response.GetHasErrors())
    {
        g_UGSFindChallengeRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSFindChallengeRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSFindChallengeRequest* UGSFindChallengeRequest::SendFindChallengeRequest(FString AccessType, int32 Count, UGameSparksScriptData* Eligibility, int32 Offset, UGameSparksRequestArray* ShortCode,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSFindChallengeRequest* proxy = NewObject<UGSFindChallengeRequest>();
    proxy->accessType = AccessType;
    proxy->count = Count;
    proxy->eligibility = Eligibility;
    proxy->offset = Offset;
    proxy->shortCode = ShortCode;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    return proxy;
}

UGSFindChallengeRequest* UGSFindChallengeRequest::SendFindChallengeRequestOnBehalfOf(const FString& PlayerId, FString AccessType, int32 Count, UGameSparksScriptData* Eligibility, int32 Offset, UGameSparksRequestArray* ShortCode,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSFindChallengeRequest* proxy = NewObject<UGSFindChallengeRequest>();
    proxy->accessType = AccessType;
    proxy->count = Count;
    proxy->eligibility = Eligibility;
    proxy->offset = Offset;
    proxy->shortCode = ShortCode;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    proxy->playerId = PlayerId;
    return proxy;
}
    
void UGSFindChallengeRequest::Activate()
{
    GameSparks::Api::Requests::FindChallengeRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
    if(accessType != ""){
        gsRequest.SetAccessType(TCHAR_TO_UTF8(*accessType));
    }
    if(count != 0){
        gsRequest.SetCount(count);
    }
    if(eligibility != nullptr){
        gsRequest.SetEligibility(eligibility->ToRequestData());
    }
    if(offset != 0){
        gsRequest.SetOffset(offset);
    }
    if(shortCode != nullptr){
        gsstl::vector<gsstl::string> arrShortCode;
    
        for(int32 b_arrShortCode = 0; b_arrShortCode < shortCode->StringArray.Num(); b_arrShortCode++)
        {
            arrShortCode.push_back(TCHAR_TO_UTF8(*shortCode->StringArray[b_arrShortCode]));
        }
        
        gsRequest.SetShortCode(arrShortCode);
    }
    if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
        gsRequest.SetDurable(durable);
    }
    
    if(!playerId.IsEmpty())
    {
        gsRequest.SetPlayerId(TCHAR_TO_UTF8(*playerId));
    }

    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
        gsRequest.Send(FindChallengeRequestResponseCallback, requestTimeoutSeconds);  
    } else {
        gsRequest.Send(FindChallengeRequestResponseCallback);
    }
}

UGSFindChallengeRequest::~UGSFindChallengeRequest()
{
 if (UGameSparksModule* module = UGameSparksModule::GetModulePtr())
 {
  if (module->IsInitialized())
  {
    module->GetGSInstance().ChangeUserDataForRequests(this, nullptr);
  }
 }
}


void FindMatchRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::FindMatchResponse& response){
    
    if(response.GetUserData() == nullptr) {
        return;
    }
    
    FGSFindMatchResponse unreal_response = FGSFindMatchResponse(response.GetBaseData());
    
    UGSFindMatchRequest* g_UGSFindMatchRequest = static_cast<UGSFindMatchRequest*>(response.GetUserData());
                               
    if(!g_UGSFindMatchRequest->OnResponse.IsBound()){
        return;    
    }

    if (response.GetHasErrors())
    {
        g_UGSFindMatchRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSFindMatchRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSFindMatchRequest* UGSFindMatchRequest::SendFindMatchRequest(FString Action, FString MatchGroup, FString MatchShortCode, int32 Skill,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSFindMatchRequest* proxy = NewObject<UGSFindMatchRequest>();
    proxy->action = Action;
    proxy->matchGroup = MatchGroup;
    proxy->matchShortCode = MatchShortCode;
    proxy->skill = Skill;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    return proxy;
}

UGSFindMatchRequest* UGSFindMatchRequest::SendFindMatchRequestOnBehalfOf(const FString& PlayerId, FString Action, FString MatchGroup, FString MatchShortCode, int32 Skill,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSFindMatchRequest* proxy = NewObject<UGSFindMatchRequest>();
    proxy->action = Action;
    proxy->matchGroup = MatchGroup;
    proxy->matchShortCode = MatchShortCode;
    proxy->skill = Skill;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    proxy->playerId = PlayerId;
    return proxy;
}
    
void UGSFindMatchRequest::Activate()
{
    GameSparks::Api::Requests::FindMatchRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
    if(action != ""){
        gsRequest.SetAction(TCHAR_TO_UTF8(*action));
    }
    if(matchGroup != ""){
        gsRequest.SetMatchGroup(TCHAR_TO_UTF8(*matchGroup));
    }
    if(matchShortCode != ""){
        gsRequest.SetMatchShortCode(TCHAR_TO_UTF8(*matchShortCode));
    }
    if(skill != 0){
        gsRequest.SetSkill(skill);
    }
    if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
        gsRequest.SetDurable(durable);
    }
    
    if(!playerId.IsEmpty())
    {
        gsRequest.SetPlayerId(TCHAR_TO_UTF8(*playerId));
    }

    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
        gsRequest.Send(FindMatchRequestResponseCallback, requestTimeoutSeconds);  
    } else {
        gsRequest.Send(FindMatchRequestResponseCallback);
    }
}

UGSFindMatchRequest::~UGSFindMatchRequest()
{
 if (UGameSparksModule* module = UGameSparksModule::GetModulePtr())
 {
  if (module->IsInitialized())
  {
    module->GetGSInstance().ChangeUserDataForRequests(this, nullptr);
  }
 }
}


void FindPendingMatchesRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::FindPendingMatchesResponse& response){
    
    if(response.GetUserData() == nullptr) {
        return;
    }
    
    FGSFindPendingMatchesResponse unreal_response = FGSFindPendingMatchesResponse(response.GetBaseData());
    
    UGSFindPendingMatchesRequest* g_UGSFindPendingMatchesRequest = static_cast<UGSFindPendingMatchesRequest*>(response.GetUserData());
                               
    if(!g_UGSFindPendingMatchesRequest->OnResponse.IsBound()){
        return;    
    }

    if (response.GetHasErrors())
    {
        g_UGSFindPendingMatchesRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSFindPendingMatchesRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSFindPendingMatchesRequest* UGSFindPendingMatchesRequest::SendFindPendingMatchesRequest(FString MatchGroup, FString MatchShortCode, int32 MaxMatchesToFind,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSFindPendingMatchesRequest* proxy = NewObject<UGSFindPendingMatchesRequest>();
    proxy->matchGroup = MatchGroup;
    proxy->matchShortCode = MatchShortCode;
    proxy->maxMatchesToFind = MaxMatchesToFind;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    return proxy;
}

UGSFindPendingMatchesRequest* UGSFindPendingMatchesRequest::SendFindPendingMatchesRequestOnBehalfOf(const FString& PlayerId, FString MatchGroup, FString MatchShortCode, int32 MaxMatchesToFind,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSFindPendingMatchesRequest* proxy = NewObject<UGSFindPendingMatchesRequest>();
    proxy->matchGroup = MatchGroup;
    proxy->matchShortCode = MatchShortCode;
    proxy->maxMatchesToFind = MaxMatchesToFind;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    proxy->playerId = PlayerId;
    return proxy;
}
    
void UGSFindPendingMatchesRequest::Activate()
{
    GameSparks::Api::Requests::FindPendingMatchesRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
    if(matchGroup != ""){
        gsRequest.SetMatchGroup(TCHAR_TO_UTF8(*matchGroup));
    }
    if(matchShortCode != ""){
        gsRequest.SetMatchShortCode(TCHAR_TO_UTF8(*matchShortCode));
    }
    if(maxMatchesToFind != 0){
        gsRequest.SetMaxMatchesToFind(maxMatchesToFind);
    }
    if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
        gsRequest.SetDurable(durable);
    }
    
    if(!playerId.IsEmpty())
    {
        gsRequest.SetPlayerId(TCHAR_TO_UTF8(*playerId));
    }

    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
        gsRequest.Send(FindPendingMatchesRequestResponseCallback, requestTimeoutSeconds);  
    } else {
        gsRequest.Send(FindPendingMatchesRequestResponseCallback);
    }
}

UGSFindPendingMatchesRequest::~UGSFindPendingMatchesRequest()
{
 if (UGameSparksModule* module = UGameSparksModule::GetModulePtr())
 {
  if (module->IsInitialized())
  {
    module->GetGSInstance().ChangeUserDataForRequests(this, nullptr);
  }
 }
}


void GameCenterConnectRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::AuthenticationResponse& response){
    
    if(response.GetUserData() == nullptr) {
        return;
    }
    
    FGSAuthenticationResponse unreal_response = FGSAuthenticationResponse(response.GetBaseData());
    
    UGSGameCenterConnectRequest* g_UGSGameCenterConnectRequest = static_cast<UGSGameCenterConnectRequest*>(response.GetUserData());
                               
    if(!g_UGSGameCenterConnectRequest->OnResponse.IsBound()){
        return;    
    }

    if (response.GetHasErrors())
    {
        g_UGSGameCenterConnectRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSGameCenterConnectRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSGameCenterConnectRequest* UGSGameCenterConnectRequest::SendGameCenterConnectRequest(FString DisplayName, bool DoNotLinkToCurrentPlayer, bool ErrorOnSwitch, FString ExternalPlayerId, FString PublicKeyUrl, FString Salt, UGameSparksScriptData* Segments, FString Signature, bool SwitchIfPossible, bool SyncDisplayName, int32 Timestamp,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSGameCenterConnectRequest* proxy = NewObject<UGSGameCenterConnectRequest>();
    proxy->displayName = DisplayName;
    proxy->doNotLinkToCurrentPlayer = DoNotLinkToCurrentPlayer;
    proxy->errorOnSwitch = ErrorOnSwitch;
    proxy->externalPlayerId = ExternalPlayerId;
    proxy->publicKeyUrl = PublicKeyUrl;
    proxy->salt = Salt;
    proxy->segments = Segments;
    proxy->signature = Signature;
    proxy->switchIfPossible = SwitchIfPossible;
    proxy->syncDisplayName = SyncDisplayName;
    proxy->timestamp = Timestamp;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    return proxy;
}

UGSGameCenterConnectRequest* UGSGameCenterConnectRequest::SendGameCenterConnectRequestOnBehalfOf(const FString& PlayerId, FString DisplayName, bool DoNotLinkToCurrentPlayer, bool ErrorOnSwitch, FString ExternalPlayerId, FString PublicKeyUrl, FString Salt, UGameSparksScriptData* Segments, FString Signature, bool SwitchIfPossible, bool SyncDisplayName, int32 Timestamp,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSGameCenterConnectRequest* proxy = NewObject<UGSGameCenterConnectRequest>();
    proxy->displayName = DisplayName;
    proxy->doNotLinkToCurrentPlayer = DoNotLinkToCurrentPlayer;
    proxy->errorOnSwitch = ErrorOnSwitch;
    proxy->externalPlayerId = ExternalPlayerId;
    proxy->publicKeyUrl = PublicKeyUrl;
    proxy->salt = Salt;
    proxy->segments = Segments;
    proxy->signature = Signature;
    proxy->switchIfPossible = SwitchIfPossible;
    proxy->syncDisplayName = SyncDisplayName;
    proxy->timestamp = Timestamp;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    proxy->playerId = PlayerId;
    return proxy;
}
    
void UGSGameCenterConnectRequest::Activate()
{
    GameSparks::Api::Requests::GameCenterConnectRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
    if(displayName != ""){
        gsRequest.SetDisplayName(TCHAR_TO_UTF8(*displayName));
    }
    if(doNotLinkToCurrentPlayer != false){
        gsRequest.SetDoNotLinkToCurrentPlayer(doNotLinkToCurrentPlayer);
    }
    if(errorOnSwitch != false){
        gsRequest.SetErrorOnSwitch(errorOnSwitch);
    }
    if(externalPlayerId != ""){
        gsRequest.SetExternalPlayerId(TCHAR_TO_UTF8(*externalPlayerId));
    }
    if(publicKeyUrl != ""){
        gsRequest.SetPublicKeyUrl(TCHAR_TO_UTF8(*publicKeyUrl));
    }
    if(salt != ""){
        gsRequest.SetSalt(TCHAR_TO_UTF8(*salt));
    }
    if(segments != nullptr){
        gsRequest.SetSegments(segments->ToRequestData());
    }
    if(signature != ""){
        gsRequest.SetSignature(TCHAR_TO_UTF8(*signature));
    }
    if(switchIfPossible != false){
        gsRequest.SetSwitchIfPossible(switchIfPossible);
    }
    if(syncDisplayName != false){
        gsRequest.SetSyncDisplayName(syncDisplayName);
    }
    if(timestamp != 0){
        gsRequest.SetTimestamp(timestamp);
    }
    if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
        gsRequest.SetDurable(durable);
    }
    
    if(!playerId.IsEmpty())
    {
        gsRequest.SetPlayerId(TCHAR_TO_UTF8(*playerId));
    }

    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
        gsRequest.Send(GameCenterConnectRequestResponseCallback, requestTimeoutSeconds);  
    } else {
        gsRequest.Send(GameCenterConnectRequestResponseCallback);
    }
}

UGSGameCenterConnectRequest::~UGSGameCenterConnectRequest()
{
 if (UGameSparksModule* module = UGameSparksModule::GetModulePtr())
 {
  if (module->IsInitialized())
  {
    module->GetGSInstance().ChangeUserDataForRequests(this, nullptr);
  }
 }
}


void GetChallengeRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::GetChallengeResponse& response){
    
    if(response.GetUserData() == nullptr) {
        return;
    }
    
    FGSGetChallengeResponse unreal_response = FGSGetChallengeResponse(response.GetBaseData());
    
    UGSGetChallengeRequest* g_UGSGetChallengeRequest = static_cast<UGSGetChallengeRequest*>(response.GetUserData());
                               
    if(!g_UGSGetChallengeRequest->OnResponse.IsBound()){
        return;    
    }

    if (response.GetHasErrors())
    {
        g_UGSGetChallengeRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSGetChallengeRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSGetChallengeRequest* UGSGetChallengeRequest::SendGetChallengeRequest(FString ChallengeInstanceId, FString Message,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSGetChallengeRequest* proxy = NewObject<UGSGetChallengeRequest>();
    proxy->challengeInstanceId = ChallengeInstanceId;
    proxy->message = Message;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    return proxy;
}

UGSGetChallengeRequest* UGSGetChallengeRequest::SendGetChallengeRequestOnBehalfOf(const FString& PlayerId, FString ChallengeInstanceId, FString Message,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSGetChallengeRequest* proxy = NewObject<UGSGetChallengeRequest>();
    proxy->challengeInstanceId = ChallengeInstanceId;
    proxy->message = Message;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    proxy->playerId = PlayerId;
    return proxy;
}
    
void UGSGetChallengeRequest::Activate()
{
    GameSparks::Api::Requests::GetChallengeRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
    if(challengeInstanceId != ""){
        gsRequest.SetChallengeInstanceId(TCHAR_TO_UTF8(*challengeInstanceId));
    }
    if(message != ""){
        gsRequest.SetMessage(TCHAR_TO_UTF8(*message));
    }
    if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
        gsRequest.SetDurable(durable);
    }
    
    if(!playerId.IsEmpty())
    {
        gsRequest.SetPlayerId(TCHAR_TO_UTF8(*playerId));
    }

    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
        gsRequest.Send(GetChallengeRequestResponseCallback, requestTimeoutSeconds);  
    } else {
        gsRequest.Send(GetChallengeRequestResponseCallback);
    }
}

UGSGetChallengeRequest::~UGSGetChallengeRequest()
{
 if (UGameSparksModule* module = UGameSparksModule::GetModulePtr())
 {
  if (module->IsInitialized())
  {
    module->GetGSInstance().ChangeUserDataForRequests(this, nullptr);
  }
 }
}


void GetDownloadableRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::GetDownloadableResponse& response){
    
    if(response.GetUserData() == nullptr) {
        return;
    }
    
    FGSGetDownloadableResponse unreal_response = FGSGetDownloadableResponse(response.GetBaseData());
    
    UGSGetDownloadableRequest* g_UGSGetDownloadableRequest = static_cast<UGSGetDownloadableRequest*>(response.GetUserData());
                               
    if(!g_UGSGetDownloadableRequest->OnResponse.IsBound()){
        return;    
    }

    if (response.GetHasErrors())
    {
        g_UGSGetDownloadableRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSGetDownloadableRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSGetDownloadableRequest* UGSGetDownloadableRequest::SendGetDownloadableRequest(FString ShortCode,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSGetDownloadableRequest* proxy = NewObject<UGSGetDownloadableRequest>();
    proxy->shortCode = ShortCode;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    return proxy;
}

UGSGetDownloadableRequest* UGSGetDownloadableRequest::SendGetDownloadableRequestOnBehalfOf(const FString& PlayerId, FString ShortCode,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSGetDownloadableRequest* proxy = NewObject<UGSGetDownloadableRequest>();
    proxy->shortCode = ShortCode;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    proxy->playerId = PlayerId;
    return proxy;
}
    
void UGSGetDownloadableRequest::Activate()
{
    GameSparks::Api::Requests::GetDownloadableRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
    if(shortCode != ""){
        gsRequest.SetShortCode(TCHAR_TO_UTF8(*shortCode));
    }
    if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
        gsRequest.SetDurable(durable);
    }
    
    if(!playerId.IsEmpty())
    {
        gsRequest.SetPlayerId(TCHAR_TO_UTF8(*playerId));
    }

    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
        gsRequest.Send(GetDownloadableRequestResponseCallback, requestTimeoutSeconds);  
    } else {
        gsRequest.Send(GetDownloadableRequestResponseCallback);
    }
}

UGSGetDownloadableRequest::~UGSGetDownloadableRequest()
{
 if (UGameSparksModule* module = UGameSparksModule::GetModulePtr())
 {
  if (module->IsInitialized())
  {
    module->GetGSInstance().ChangeUserDataForRequests(this, nullptr);
  }
 }
}


void GetLeaderboardEntriesRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::GetLeaderboardEntriesResponse& response){
    
    if(response.GetUserData() == nullptr) {
        return;
    }
    
    FGSGetLeaderboardEntriesResponse unreal_response = FGSGetLeaderboardEntriesResponse(response.GetBaseData());
    
    UGSGetLeaderboardEntriesRequest* g_UGSGetLeaderboardEntriesRequest = static_cast<UGSGetLeaderboardEntriesRequest*>(response.GetUserData());
                               
    if(!g_UGSGetLeaderboardEntriesRequest->OnResponse.IsBound()){
        return;    
    }

    if (response.GetHasErrors())
    {
        g_UGSGetLeaderboardEntriesRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSGetLeaderboardEntriesRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSGetLeaderboardEntriesRequest* UGSGetLeaderboardEntriesRequest::SendGetLeaderboardEntriesRequest(UGameSparksRequestArray* Challenges, bool InverseSocial, UGameSparksRequestArray* Leaderboards, FString Player, bool Social, UGameSparksRequestArray* TeamTypes,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSGetLeaderboardEntriesRequest* proxy = NewObject<UGSGetLeaderboardEntriesRequest>();
    proxy->challenges = Challenges;
    proxy->inverseSocial = InverseSocial;
    proxy->leaderboards = Leaderboards;
    proxy->player = Player;
    proxy->social = Social;
    proxy->teamTypes = TeamTypes;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    return proxy;
}

UGSGetLeaderboardEntriesRequest* UGSGetLeaderboardEntriesRequest::SendGetLeaderboardEntriesRequestOnBehalfOf(const FString& PlayerId, UGameSparksRequestArray* Challenges, bool InverseSocial, UGameSparksRequestArray* Leaderboards, FString Player, bool Social, UGameSparksRequestArray* TeamTypes,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSGetLeaderboardEntriesRequest* proxy = NewObject<UGSGetLeaderboardEntriesRequest>();
    proxy->challenges = Challenges;
    proxy->inverseSocial = InverseSocial;
    proxy->leaderboards = Leaderboards;
    proxy->player = Player;
    proxy->social = Social;
    proxy->teamTypes = TeamTypes;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    proxy->playerId = PlayerId;
    return proxy;
}
    
void UGSGetLeaderboardEntriesRequest::Activate()
{
    GameSparks::Api::Requests::GetLeaderboardEntriesRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
    if(challenges != nullptr){
        gsstl::vector<gsstl::string> arrChallenges;
    
        for(int32 b_arrChallenges = 0; b_arrChallenges < challenges->StringArray.Num(); b_arrChallenges++)
        {
            arrChallenges.push_back(TCHAR_TO_UTF8(*challenges->StringArray[b_arrChallenges]));
        }
        
        gsRequest.SetChallenges(arrChallenges);
    }
    if(inverseSocial != false){
        gsRequest.SetInverseSocial(inverseSocial);
    }
    if(leaderboards != nullptr){
        gsstl::vector<gsstl::string> arrLeaderboards;
    
        for(int32 b_arrLeaderboards = 0; b_arrLeaderboards < leaderboards->StringArray.Num(); b_arrLeaderboards++)
        {
            arrLeaderboards.push_back(TCHAR_TO_UTF8(*leaderboards->StringArray[b_arrLeaderboards]));
        }
        
        gsRequest.SetLeaderboards(arrLeaderboards);
    }
    if(player != ""){
        gsRequest.SetPlayer(TCHAR_TO_UTF8(*player));
    }
    if(social != false){
        gsRequest.SetSocial(social);
    }
    if(teamTypes != nullptr){
        gsstl::vector<gsstl::string> arrTeamTypes;
    
        for(int32 b_arrTeamTypes = 0; b_arrTeamTypes < teamTypes->StringArray.Num(); b_arrTeamTypes++)
        {
            arrTeamTypes.push_back(TCHAR_TO_UTF8(*teamTypes->StringArray[b_arrTeamTypes]));
        }
        
        gsRequest.SetTeamTypes(arrTeamTypes);
    }
    if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
        gsRequest.SetDurable(durable);
    }
    
    if(!playerId.IsEmpty())
    {
        gsRequest.SetPlayerId(TCHAR_TO_UTF8(*playerId));
    }

    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
        gsRequest.Send(GetLeaderboardEntriesRequestResponseCallback, requestTimeoutSeconds);  
    } else {
        gsRequest.Send(GetLeaderboardEntriesRequestResponseCallback);
    }
}

UGSGetLeaderboardEntriesRequest::~UGSGetLeaderboardEntriesRequest()
{
 if (UGameSparksModule* module = UGameSparksModule::GetModulePtr())
 {
  if (module->IsInitialized())
  {
    module->GetGSInstance().ChangeUserDataForRequests(this, nullptr);
  }
 }
}


void GetMessageRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::GetMessageResponse& response){
    
    if(response.GetUserData() == nullptr) {
        return;
    }
    
    FGSGetMessageResponse unreal_response = FGSGetMessageResponse(response.GetBaseData());
    
    UGSGetMessageRequest* g_UGSGetMessageRequest = static_cast<UGSGetMessageRequest*>(response.GetUserData());
                               
    if(!g_UGSGetMessageRequest->OnResponse.IsBound()){
        return;    
    }

    if (response.GetHasErrors())
    {
        g_UGSGetMessageRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSGetMessageRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSGetMessageRequest* UGSGetMessageRequest::SendGetMessageRequest(FString MessageId,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSGetMessageRequest* proxy = NewObject<UGSGetMessageRequest>();
    proxy->messageId = MessageId;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    return proxy;
}

UGSGetMessageRequest* UGSGetMessageRequest::SendGetMessageRequestOnBehalfOf(const FString& PlayerId, FString MessageId,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSGetMessageRequest* proxy = NewObject<UGSGetMessageRequest>();
    proxy->messageId = MessageId;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    proxy->playerId = PlayerId;
    return proxy;
}
    
void UGSGetMessageRequest::Activate()
{
    GameSparks::Api::Requests::GetMessageRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
    if(messageId != ""){
        gsRequest.SetMessageId(TCHAR_TO_UTF8(*messageId));
    }
    if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
        gsRequest.SetDurable(durable);
    }
    
    if(!playerId.IsEmpty())
    {
        gsRequest.SetPlayerId(TCHAR_TO_UTF8(*playerId));
    }

    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
        gsRequest.Send(GetMessageRequestResponseCallback, requestTimeoutSeconds);  
    } else {
        gsRequest.Send(GetMessageRequestResponseCallback);
    }
}

UGSGetMessageRequest::~UGSGetMessageRequest()
{
 if (UGameSparksModule* module = UGameSparksModule::GetModulePtr())
 {
  if (module->IsInitialized())
  {
    module->GetGSInstance().ChangeUserDataForRequests(this, nullptr);
  }
 }
}


void GetMyTeamsRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::GetMyTeamsResponse& response){
    
    if(response.GetUserData() == nullptr) {
        return;
    }
    
    FGSGetMyTeamsResponse unreal_response = FGSGetMyTeamsResponse(response.GetBaseData());
    
    UGSGetMyTeamsRequest* g_UGSGetMyTeamsRequest = static_cast<UGSGetMyTeamsRequest*>(response.GetUserData());
                               
    if(!g_UGSGetMyTeamsRequest->OnResponse.IsBound()){
        return;    
    }

    if (response.GetHasErrors())
    {
        g_UGSGetMyTeamsRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSGetMyTeamsRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSGetMyTeamsRequest* UGSGetMyTeamsRequest::SendGetMyTeamsRequest(bool OwnedOnly, UGameSparksRequestArray* TeamTypes,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSGetMyTeamsRequest* proxy = NewObject<UGSGetMyTeamsRequest>();
    proxy->ownedOnly = OwnedOnly;
    proxy->teamTypes = TeamTypes;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    return proxy;
}

UGSGetMyTeamsRequest* UGSGetMyTeamsRequest::SendGetMyTeamsRequestOnBehalfOf(const FString& PlayerId, bool OwnedOnly, UGameSparksRequestArray* TeamTypes,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSGetMyTeamsRequest* proxy = NewObject<UGSGetMyTeamsRequest>();
    proxy->ownedOnly = OwnedOnly;
    proxy->teamTypes = TeamTypes;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    proxy->playerId = PlayerId;
    return proxy;
}
    
void UGSGetMyTeamsRequest::Activate()
{
    GameSparks::Api::Requests::GetMyTeamsRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
    if(ownedOnly != false){
        gsRequest.SetOwnedOnly(ownedOnly);
    }
    if(teamTypes != nullptr){
        gsstl::vector<gsstl::string> arrTeamTypes;
    
        for(int32 b_arrTeamTypes = 0; b_arrTeamTypes < teamTypes->StringArray.Num(); b_arrTeamTypes++)
        {
            arrTeamTypes.push_back(TCHAR_TO_UTF8(*teamTypes->StringArray[b_arrTeamTypes]));
        }
        
        gsRequest.SetTeamTypes(arrTeamTypes);
    }
    if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
        gsRequest.SetDurable(durable);
    }
    
    if(!playerId.IsEmpty())
    {
        gsRequest.SetPlayerId(TCHAR_TO_UTF8(*playerId));
    }

    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
        gsRequest.Send(GetMyTeamsRequestResponseCallback, requestTimeoutSeconds);  
    } else {
        gsRequest.Send(GetMyTeamsRequestResponseCallback);
    }
}

UGSGetMyTeamsRequest::~UGSGetMyTeamsRequest()
{
 if (UGameSparksModule* module = UGameSparksModule::GetModulePtr())
 {
  if (module->IsInitialized())
  {
    module->GetGSInstance().ChangeUserDataForRequests(this, nullptr);
  }
 }
}


void GetPropertyRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::GetPropertyResponse& response){
    
    if(response.GetUserData() == nullptr) {
        return;
    }
    
    FGSGetPropertyResponse unreal_response = FGSGetPropertyResponse(response.GetBaseData());
    
    UGSGetPropertyRequest* g_UGSGetPropertyRequest = static_cast<UGSGetPropertyRequest*>(response.GetUserData());
                               
    if(!g_UGSGetPropertyRequest->OnResponse.IsBound()){
        return;    
    }

    if (response.GetHasErrors())
    {
        g_UGSGetPropertyRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSGetPropertyRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSGetPropertyRequest* UGSGetPropertyRequest::SendGetPropertyRequest(FString PropertyShortCode,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSGetPropertyRequest* proxy = NewObject<UGSGetPropertyRequest>();
    proxy->propertyShortCode = PropertyShortCode;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    return proxy;
}

UGSGetPropertyRequest* UGSGetPropertyRequest::SendGetPropertyRequestOnBehalfOf(const FString& PlayerId, FString PropertyShortCode,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSGetPropertyRequest* proxy = NewObject<UGSGetPropertyRequest>();
    proxy->propertyShortCode = PropertyShortCode;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    proxy->playerId = PlayerId;
    return proxy;
}
    
void UGSGetPropertyRequest::Activate()
{
    GameSparks::Api::Requests::GetPropertyRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
    if(propertyShortCode != ""){
        gsRequest.SetPropertyShortCode(TCHAR_TO_UTF8(*propertyShortCode));
    }
    if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
        gsRequest.SetDurable(durable);
    }
    
    if(!playerId.IsEmpty())
    {
        gsRequest.SetPlayerId(TCHAR_TO_UTF8(*playerId));
    }

    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
        gsRequest.Send(GetPropertyRequestResponseCallback, requestTimeoutSeconds);  
    } else {
        gsRequest.Send(GetPropertyRequestResponseCallback);
    }
}

UGSGetPropertyRequest::~UGSGetPropertyRequest()
{
 if (UGameSparksModule* module = UGameSparksModule::GetModulePtr())
 {
  if (module->IsInitialized())
  {
    module->GetGSInstance().ChangeUserDataForRequests(this, nullptr);
  }
 }
}


void GetPropertySetRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::GetPropertySetResponse& response){
    
    if(response.GetUserData() == nullptr) {
        return;
    }
    
    FGSGetPropertySetResponse unreal_response = FGSGetPropertySetResponse(response.GetBaseData());
    
    UGSGetPropertySetRequest* g_UGSGetPropertySetRequest = static_cast<UGSGetPropertySetRequest*>(response.GetUserData());
                               
    if(!g_UGSGetPropertySetRequest->OnResponse.IsBound()){
        return;    
    }

    if (response.GetHasErrors())
    {
        g_UGSGetPropertySetRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSGetPropertySetRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSGetPropertySetRequest* UGSGetPropertySetRequest::SendGetPropertySetRequest(FString PropertySetShortCode,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSGetPropertySetRequest* proxy = NewObject<UGSGetPropertySetRequest>();
    proxy->propertySetShortCode = PropertySetShortCode;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    return proxy;
}

UGSGetPropertySetRequest* UGSGetPropertySetRequest::SendGetPropertySetRequestOnBehalfOf(const FString& PlayerId, FString PropertySetShortCode,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSGetPropertySetRequest* proxy = NewObject<UGSGetPropertySetRequest>();
    proxy->propertySetShortCode = PropertySetShortCode;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    proxy->playerId = PlayerId;
    return proxy;
}
    
void UGSGetPropertySetRequest::Activate()
{
    GameSparks::Api::Requests::GetPropertySetRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
    if(propertySetShortCode != ""){
        gsRequest.SetPropertySetShortCode(TCHAR_TO_UTF8(*propertySetShortCode));
    }
    if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
        gsRequest.SetDurable(durable);
    }
    
    if(!playerId.IsEmpty())
    {
        gsRequest.SetPlayerId(TCHAR_TO_UTF8(*playerId));
    }

    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
        gsRequest.Send(GetPropertySetRequestResponseCallback, requestTimeoutSeconds);  
    } else {
        gsRequest.Send(GetPropertySetRequestResponseCallback);
    }
}

UGSGetPropertySetRequest::~UGSGetPropertySetRequest()
{
 if (UGameSparksModule* module = UGameSparksModule::GetModulePtr())
 {
  if (module->IsInitialized())
  {
    module->GetGSInstance().ChangeUserDataForRequests(this, nullptr);
  }
 }
}


void GetTeamRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::GetTeamResponse& response){
    
    if(response.GetUserData() == nullptr) {
        return;
    }
    
    FGSGetTeamResponse unreal_response = FGSGetTeamResponse(response.GetBaseData());
    
    UGSGetTeamRequest* g_UGSGetTeamRequest = static_cast<UGSGetTeamRequest*>(response.GetUserData());
                               
    if(!g_UGSGetTeamRequest->OnResponse.IsBound()){
        return;    
    }

    if (response.GetHasErrors())
    {
        g_UGSGetTeamRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSGetTeamRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSGetTeamRequest* UGSGetTeamRequest::SendGetTeamRequest(FString OwnerId, FString TeamId, FString TeamType,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSGetTeamRequest* proxy = NewObject<UGSGetTeamRequest>();
    proxy->ownerId = OwnerId;
    proxy->teamId = TeamId;
    proxy->teamType = TeamType;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    return proxy;
}

UGSGetTeamRequest* UGSGetTeamRequest::SendGetTeamRequestOnBehalfOf(const FString& PlayerId, FString OwnerId, FString TeamId, FString TeamType,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSGetTeamRequest* proxy = NewObject<UGSGetTeamRequest>();
    proxy->ownerId = OwnerId;
    proxy->teamId = TeamId;
    proxy->teamType = TeamType;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    proxy->playerId = PlayerId;
    return proxy;
}
    
void UGSGetTeamRequest::Activate()
{
    GameSparks::Api::Requests::GetTeamRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
    if(ownerId != ""){
        gsRequest.SetOwnerId(TCHAR_TO_UTF8(*ownerId));
    }
    if(teamId != ""){
        gsRequest.SetTeamId(TCHAR_TO_UTF8(*teamId));
    }
    if(teamType != ""){
        gsRequest.SetTeamType(TCHAR_TO_UTF8(*teamType));
    }
    if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
        gsRequest.SetDurable(durable);
    }
    
    if(!playerId.IsEmpty())
    {
        gsRequest.SetPlayerId(TCHAR_TO_UTF8(*playerId));
    }

    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
        gsRequest.Send(GetTeamRequestResponseCallback, requestTimeoutSeconds);  
    } else {
        gsRequest.Send(GetTeamRequestResponseCallback);
    }
}

UGSGetTeamRequest::~UGSGetTeamRequest()
{
 if (UGameSparksModule* module = UGameSparksModule::GetModulePtr())
 {
  if (module->IsInitialized())
  {
    module->GetGSInstance().ChangeUserDataForRequests(this, nullptr);
  }
 }
}


void GetUploadUrlRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::GetUploadUrlResponse& response){
    
    if(response.GetUserData() == nullptr) {
        return;
    }
    
    FGSGetUploadUrlResponse unreal_response = FGSGetUploadUrlResponse(response.GetBaseData());
    
    UGSGetUploadUrlRequest* g_UGSGetUploadUrlRequest = static_cast<UGSGetUploadUrlRequest*>(response.GetUserData());
                               
    if(!g_UGSGetUploadUrlRequest->OnResponse.IsBound()){
        return;    
    }

    if (response.GetHasErrors())
    {
        g_UGSGetUploadUrlRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSGetUploadUrlRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSGetUploadUrlRequest* UGSGetUploadUrlRequest::SendGetUploadUrlRequest(UGameSparksScriptData* UploadData,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSGetUploadUrlRequest* proxy = NewObject<UGSGetUploadUrlRequest>();
    proxy->uploadData = UploadData;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    return proxy;
}

UGSGetUploadUrlRequest* UGSGetUploadUrlRequest::SendGetUploadUrlRequestOnBehalfOf(const FString& PlayerId, UGameSparksScriptData* UploadData,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSGetUploadUrlRequest* proxy = NewObject<UGSGetUploadUrlRequest>();
    proxy->uploadData = UploadData;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    proxy->playerId = PlayerId;
    return proxy;
}
    
void UGSGetUploadUrlRequest::Activate()
{
    GameSparks::Api::Requests::GetUploadUrlRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
    if(uploadData != nullptr){
        gsRequest.SetUploadData(uploadData->ToRequestData());
    }
    if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
        gsRequest.SetDurable(durable);
    }
    
    if(!playerId.IsEmpty())
    {
        gsRequest.SetPlayerId(TCHAR_TO_UTF8(*playerId));
    }

    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
        gsRequest.Send(GetUploadUrlRequestResponseCallback, requestTimeoutSeconds);  
    } else {
        gsRequest.Send(GetUploadUrlRequestResponseCallback);
    }
}

UGSGetUploadUrlRequest::~UGSGetUploadUrlRequest()
{
 if (UGameSparksModule* module = UGameSparksModule::GetModulePtr())
 {
  if (module->IsInitialized())
  {
    module->GetGSInstance().ChangeUserDataForRequests(this, nullptr);
  }
 }
}


void GetUploadedRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::GetUploadedResponse& response){
    
    if(response.GetUserData() == nullptr) {
        return;
    }
    
    FGSGetUploadedResponse unreal_response = FGSGetUploadedResponse(response.GetBaseData());
    
    UGSGetUploadedRequest* g_UGSGetUploadedRequest = static_cast<UGSGetUploadedRequest*>(response.GetUserData());
                               
    if(!g_UGSGetUploadedRequest->OnResponse.IsBound()){
        return;    
    }

    if (response.GetHasErrors())
    {
        g_UGSGetUploadedRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSGetUploadedRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSGetUploadedRequest* UGSGetUploadedRequest::SendGetUploadedRequest(FString UploadId,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSGetUploadedRequest* proxy = NewObject<UGSGetUploadedRequest>();
    proxy->uploadId = UploadId;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    return proxy;
}

UGSGetUploadedRequest* UGSGetUploadedRequest::SendGetUploadedRequestOnBehalfOf(const FString& PlayerId, FString UploadId,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSGetUploadedRequest* proxy = NewObject<UGSGetUploadedRequest>();
    proxy->uploadId = UploadId;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    proxy->playerId = PlayerId;
    return proxy;
}
    
void UGSGetUploadedRequest::Activate()
{
    GameSparks::Api::Requests::GetUploadedRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
    if(uploadId != ""){
        gsRequest.SetUploadId(TCHAR_TO_UTF8(*uploadId));
    }
    if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
        gsRequest.SetDurable(durable);
    }
    
    if(!playerId.IsEmpty())
    {
        gsRequest.SetPlayerId(TCHAR_TO_UTF8(*playerId));
    }

    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
        gsRequest.Send(GetUploadedRequestResponseCallback, requestTimeoutSeconds);  
    } else {
        gsRequest.Send(GetUploadedRequestResponseCallback);
    }
}

UGSGetUploadedRequest::~UGSGetUploadedRequest()
{
 if (UGameSparksModule* module = UGameSparksModule::GetModulePtr())
 {
  if (module->IsInitialized())
  {
    module->GetGSInstance().ChangeUserDataForRequests(this, nullptr);
  }
 }
}


void GooglePlayBuyGoodsRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::BuyVirtualGoodResponse& response){
    
    if(response.GetUserData() == nullptr) {
        return;
    }
    
    FGSBuyVirtualGoodResponse unreal_response = FGSBuyVirtualGoodResponse(response.GetBaseData());
    
    UGSGooglePlayBuyGoodsRequest* g_UGSGooglePlayBuyGoodsRequest = static_cast<UGSGooglePlayBuyGoodsRequest*>(response.GetUserData());
                               
    if(!g_UGSGooglePlayBuyGoodsRequest->OnResponse.IsBound()){
        return;    
    }

    if (response.GetHasErrors())
    {
        g_UGSGooglePlayBuyGoodsRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSGooglePlayBuyGoodsRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSGooglePlayBuyGoodsRequest* UGSGooglePlayBuyGoodsRequest::SendGooglePlayBuyGoodsRequest(FString CurrencyCode, FString Signature, FString SignedData, float SubUnitPrice, bool UniqueTransactionByPlayer,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSGooglePlayBuyGoodsRequest* proxy = NewObject<UGSGooglePlayBuyGoodsRequest>();
    proxy->currencyCode = CurrencyCode;
    proxy->signature = Signature;
    proxy->signedData = SignedData;
    proxy->subUnitPrice = SubUnitPrice;
    proxy->uniqueTransactionByPlayer = UniqueTransactionByPlayer;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    return proxy;
}

UGSGooglePlayBuyGoodsRequest* UGSGooglePlayBuyGoodsRequest::SendGooglePlayBuyGoodsRequestOnBehalfOf(const FString& PlayerId, FString CurrencyCode, FString Signature, FString SignedData, float SubUnitPrice, bool UniqueTransactionByPlayer,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSGooglePlayBuyGoodsRequest* proxy = NewObject<UGSGooglePlayBuyGoodsRequest>();
    proxy->currencyCode = CurrencyCode;
    proxy->signature = Signature;
    proxy->signedData = SignedData;
    proxy->subUnitPrice = SubUnitPrice;
    proxy->uniqueTransactionByPlayer = UniqueTransactionByPlayer;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    proxy->playerId = PlayerId;
    return proxy;
}
    
void UGSGooglePlayBuyGoodsRequest::Activate()
{
    GameSparks::Api::Requests::GooglePlayBuyGoodsRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
    if(currencyCode != ""){
        gsRequest.SetCurrencyCode(TCHAR_TO_UTF8(*currencyCode));
    }
    if(signature != ""){
        gsRequest.SetSignature(TCHAR_TO_UTF8(*signature));
    }
    if(signedData != ""){
        gsRequest.SetSignedData(TCHAR_TO_UTF8(*signedData));
    }
    if(subUnitPrice != 0.0f){
        gsRequest.SetSubUnitPrice(subUnitPrice);
    }
    if(uniqueTransactionByPlayer != false){
        gsRequest.SetUniqueTransactionByPlayer(uniqueTransactionByPlayer);
    }
    if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
        gsRequest.SetDurable(durable);
    }
    
    if(!playerId.IsEmpty())
    {
        gsRequest.SetPlayerId(TCHAR_TO_UTF8(*playerId));
    }

    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
        gsRequest.Send(GooglePlayBuyGoodsRequestResponseCallback, requestTimeoutSeconds);  
    } else {
        gsRequest.Send(GooglePlayBuyGoodsRequestResponseCallback);
    }
}

UGSGooglePlayBuyGoodsRequest::~UGSGooglePlayBuyGoodsRequest()
{
 if (UGameSparksModule* module = UGameSparksModule::GetModulePtr())
 {
  if (module->IsInitialized())
  {
    module->GetGSInstance().ChangeUserDataForRequests(this, nullptr);
  }
 }
}


void GooglePlayConnectRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::AuthenticationResponse& response){
    
    if(response.GetUserData() == nullptr) {
        return;
    }
    
    FGSAuthenticationResponse unreal_response = FGSAuthenticationResponse(response.GetBaseData());
    
    UGSGooglePlayConnectRequest* g_UGSGooglePlayConnectRequest = static_cast<UGSGooglePlayConnectRequest*>(response.GetUserData());
                               
    if(!g_UGSGooglePlayConnectRequest->OnResponse.IsBound()){
        return;    
    }

    if (response.GetHasErrors())
    {
        g_UGSGooglePlayConnectRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSGooglePlayConnectRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSGooglePlayConnectRequest* UGSGooglePlayConnectRequest::SendGooglePlayConnectRequest(FString AccessToken, FString Code, FString DisplayName, bool DoNotLinkToCurrentPlayer, bool ErrorOnSwitch, bool GooglePlusScope, bool ProfileScope, FString RedirectUri, UGameSparksScriptData* Segments, bool SwitchIfPossible, bool SyncDisplayName,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSGooglePlayConnectRequest* proxy = NewObject<UGSGooglePlayConnectRequest>();
    proxy->accessToken = AccessToken;
    proxy->code = Code;
    proxy->displayName = DisplayName;
    proxy->doNotLinkToCurrentPlayer = DoNotLinkToCurrentPlayer;
    proxy->errorOnSwitch = ErrorOnSwitch;
    proxy->googlePlusScope = GooglePlusScope;
    proxy->profileScope = ProfileScope;
    proxy->redirectUri = RedirectUri;
    proxy->segments = Segments;
    proxy->switchIfPossible = SwitchIfPossible;
    proxy->syncDisplayName = SyncDisplayName;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    return proxy;
}

UGSGooglePlayConnectRequest* UGSGooglePlayConnectRequest::SendGooglePlayConnectRequestOnBehalfOf(const FString& PlayerId, FString AccessToken, FString Code, FString DisplayName, bool DoNotLinkToCurrentPlayer, bool ErrorOnSwitch, bool GooglePlusScope, bool ProfileScope, FString RedirectUri, UGameSparksScriptData* Segments, bool SwitchIfPossible, bool SyncDisplayName,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSGooglePlayConnectRequest* proxy = NewObject<UGSGooglePlayConnectRequest>();
    proxy->accessToken = AccessToken;
    proxy->code = Code;
    proxy->displayName = DisplayName;
    proxy->doNotLinkToCurrentPlayer = DoNotLinkToCurrentPlayer;
    proxy->errorOnSwitch = ErrorOnSwitch;
    proxy->googlePlusScope = GooglePlusScope;
    proxy->profileScope = ProfileScope;
    proxy->redirectUri = RedirectUri;
    proxy->segments = Segments;
    proxy->switchIfPossible = SwitchIfPossible;
    proxy->syncDisplayName = SyncDisplayName;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    proxy->playerId = PlayerId;
    return proxy;
}
    
void UGSGooglePlayConnectRequest::Activate()
{
    GameSparks::Api::Requests::GooglePlayConnectRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
    if(accessToken != ""){
        gsRequest.SetAccessToken(TCHAR_TO_UTF8(*accessToken));
    }
    if(code != ""){
        gsRequest.SetCode(TCHAR_TO_UTF8(*code));
    }
    if(displayName != ""){
        gsRequest.SetDisplayName(TCHAR_TO_UTF8(*displayName));
    }
    if(doNotLinkToCurrentPlayer != false){
        gsRequest.SetDoNotLinkToCurrentPlayer(doNotLinkToCurrentPlayer);
    }
    if(errorOnSwitch != false){
        gsRequest.SetErrorOnSwitch(errorOnSwitch);
    }
    if(googlePlusScope != false){
        gsRequest.SetGooglePlusScope(googlePlusScope);
    }
    if(profileScope != false){
        gsRequest.SetProfileScope(profileScope);
    }
    if(redirectUri != ""){
        gsRequest.SetRedirectUri(TCHAR_TO_UTF8(*redirectUri));
    }
    if(segments != nullptr){
        gsRequest.SetSegments(segments->ToRequestData());
    }
    if(switchIfPossible != false){
        gsRequest.SetSwitchIfPossible(switchIfPossible);
    }
    if(syncDisplayName != false){
        gsRequest.SetSyncDisplayName(syncDisplayName);
    }
    if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
        gsRequest.SetDurable(durable);
    }
    
    if(!playerId.IsEmpty())
    {
        gsRequest.SetPlayerId(TCHAR_TO_UTF8(*playerId));
    }

    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
        gsRequest.Send(GooglePlayConnectRequestResponseCallback, requestTimeoutSeconds);  
    } else {
        gsRequest.Send(GooglePlayConnectRequestResponseCallback);
    }
}

UGSGooglePlayConnectRequest::~UGSGooglePlayConnectRequest()
{
 if (UGameSparksModule* module = UGameSparksModule::GetModulePtr())
 {
  if (module->IsInitialized())
  {
    module->GetGSInstance().ChangeUserDataForRequests(this, nullptr);
  }
 }
}


void GooglePlusConnectRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::AuthenticationResponse& response){
    
    if(response.GetUserData() == nullptr) {
        return;
    }
    
    FGSAuthenticationResponse unreal_response = FGSAuthenticationResponse(response.GetBaseData());
    
    UGSGooglePlusConnectRequest* g_UGSGooglePlusConnectRequest = static_cast<UGSGooglePlusConnectRequest*>(response.GetUserData());
                               
    if(!g_UGSGooglePlusConnectRequest->OnResponse.IsBound()){
        return;    
    }

    if (response.GetHasErrors())
    {
        g_UGSGooglePlusConnectRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSGooglePlusConnectRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSGooglePlusConnectRequest* UGSGooglePlusConnectRequest::SendGooglePlusConnectRequest(FString AccessToken, FString Code, bool DoNotLinkToCurrentPlayer, bool ErrorOnSwitch, FString RedirectUri, UGameSparksScriptData* Segments, bool SwitchIfPossible, bool SyncDisplayName,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSGooglePlusConnectRequest* proxy = NewObject<UGSGooglePlusConnectRequest>();
    proxy->accessToken = AccessToken;
    proxy->code = Code;
    proxy->doNotLinkToCurrentPlayer = DoNotLinkToCurrentPlayer;
    proxy->errorOnSwitch = ErrorOnSwitch;
    proxy->redirectUri = RedirectUri;
    proxy->segments = Segments;
    proxy->switchIfPossible = SwitchIfPossible;
    proxy->syncDisplayName = SyncDisplayName;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    return proxy;
}

UGSGooglePlusConnectRequest* UGSGooglePlusConnectRequest::SendGooglePlusConnectRequestOnBehalfOf(const FString& PlayerId, FString AccessToken, FString Code, bool DoNotLinkToCurrentPlayer, bool ErrorOnSwitch, FString RedirectUri, UGameSparksScriptData* Segments, bool SwitchIfPossible, bool SyncDisplayName,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSGooglePlusConnectRequest* proxy = NewObject<UGSGooglePlusConnectRequest>();
    proxy->accessToken = AccessToken;
    proxy->code = Code;
    proxy->doNotLinkToCurrentPlayer = DoNotLinkToCurrentPlayer;
    proxy->errorOnSwitch = ErrorOnSwitch;
    proxy->redirectUri = RedirectUri;
    proxy->segments = Segments;
    proxy->switchIfPossible = SwitchIfPossible;
    proxy->syncDisplayName = SyncDisplayName;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    proxy->playerId = PlayerId;
    return proxy;
}
    
void UGSGooglePlusConnectRequest::Activate()
{
    GameSparks::Api::Requests::GooglePlusConnectRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
    if(accessToken != ""){
        gsRequest.SetAccessToken(TCHAR_TO_UTF8(*accessToken));
    }
    if(code != ""){
        gsRequest.SetCode(TCHAR_TO_UTF8(*code));
    }
    if(doNotLinkToCurrentPlayer != false){
        gsRequest.SetDoNotLinkToCurrentPlayer(doNotLinkToCurrentPlayer);
    }
    if(errorOnSwitch != false){
        gsRequest.SetErrorOnSwitch(errorOnSwitch);
    }
    if(redirectUri != ""){
        gsRequest.SetRedirectUri(TCHAR_TO_UTF8(*redirectUri));
    }
    if(segments != nullptr){
        gsRequest.SetSegments(segments->ToRequestData());
    }
    if(switchIfPossible != false){
        gsRequest.SetSwitchIfPossible(switchIfPossible);
    }
    if(syncDisplayName != false){
        gsRequest.SetSyncDisplayName(syncDisplayName);
    }
    if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
        gsRequest.SetDurable(durable);
    }
    
    if(!playerId.IsEmpty())
    {
        gsRequest.SetPlayerId(TCHAR_TO_UTF8(*playerId));
    }

    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
        gsRequest.Send(GooglePlusConnectRequestResponseCallback, requestTimeoutSeconds);  
    } else {
        gsRequest.Send(GooglePlusConnectRequestResponseCallback);
    }
}

UGSGooglePlusConnectRequest::~UGSGooglePlusConnectRequest()
{
 if (UGameSparksModule* module = UGameSparksModule::GetModulePtr())
 {
  if (module->IsInitialized())
  {
    module->GetGSInstance().ChangeUserDataForRequests(this, nullptr);
  }
 }
}


void IOSBuyGoodsRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::BuyVirtualGoodResponse& response){
    
    if(response.GetUserData() == nullptr) {
        return;
    }
    
    FGSBuyVirtualGoodResponse unreal_response = FGSBuyVirtualGoodResponse(response.GetBaseData());
    
    UGSIOSBuyGoodsRequest* g_UGSIOSBuyGoodsRequest = static_cast<UGSIOSBuyGoodsRequest*>(response.GetUserData());
                               
    if(!g_UGSIOSBuyGoodsRequest->OnResponse.IsBound()){
        return;    
    }

    if (response.GetHasErrors())
    {
        g_UGSIOSBuyGoodsRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSIOSBuyGoodsRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSIOSBuyGoodsRequest* UGSIOSBuyGoodsRequest::SendIOSBuyGoodsRequest(FString CurrencyCode, FString Receipt, bool Sandbox, float SubUnitPrice, bool UniqueTransactionByPlayer,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSIOSBuyGoodsRequest* proxy = NewObject<UGSIOSBuyGoodsRequest>();
    proxy->currencyCode = CurrencyCode;
    proxy->receipt = Receipt;
    proxy->sandbox = Sandbox;
    proxy->subUnitPrice = SubUnitPrice;
    proxy->uniqueTransactionByPlayer = UniqueTransactionByPlayer;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    return proxy;
}

UGSIOSBuyGoodsRequest* UGSIOSBuyGoodsRequest::SendIOSBuyGoodsRequestOnBehalfOf(const FString& PlayerId, FString CurrencyCode, FString Receipt, bool Sandbox, float SubUnitPrice, bool UniqueTransactionByPlayer,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSIOSBuyGoodsRequest* proxy = NewObject<UGSIOSBuyGoodsRequest>();
    proxy->currencyCode = CurrencyCode;
    proxy->receipt = Receipt;
    proxy->sandbox = Sandbox;
    proxy->subUnitPrice = SubUnitPrice;
    proxy->uniqueTransactionByPlayer = UniqueTransactionByPlayer;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    proxy->playerId = PlayerId;
    return proxy;
}
    
void UGSIOSBuyGoodsRequest::Activate()
{
    GameSparks::Api::Requests::IOSBuyGoodsRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
    if(currencyCode != ""){
        gsRequest.SetCurrencyCode(TCHAR_TO_UTF8(*currencyCode));
    }
    if(receipt != ""){
        gsRequest.SetReceipt(TCHAR_TO_UTF8(*receipt));
    }
    if(sandbox != false){
        gsRequest.SetSandbox(sandbox);
    }
    if(subUnitPrice != 0.0f){
        gsRequest.SetSubUnitPrice(subUnitPrice);
    }
    if(uniqueTransactionByPlayer != false){
        gsRequest.SetUniqueTransactionByPlayer(uniqueTransactionByPlayer);
    }
    if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
        gsRequest.SetDurable(durable);
    }
    
    if(!playerId.IsEmpty())
    {
        gsRequest.SetPlayerId(TCHAR_TO_UTF8(*playerId));
    }

    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
        gsRequest.Send(IOSBuyGoodsRequestResponseCallback, requestTimeoutSeconds);  
    } else {
        gsRequest.Send(IOSBuyGoodsRequestResponseCallback);
    }
}

UGSIOSBuyGoodsRequest::~UGSIOSBuyGoodsRequest()
{
 if (UGameSparksModule* module = UGameSparksModule::GetModulePtr())
 {
  if (module->IsInitialized())
  {
    module->GetGSInstance().ChangeUserDataForRequests(this, nullptr);
  }
 }
}


void JoinChallengeRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::JoinChallengeResponse& response){
    
    if(response.GetUserData() == nullptr) {
        return;
    }
    
    FGSJoinChallengeResponse unreal_response = FGSJoinChallengeResponse(response.GetBaseData());
    
    UGSJoinChallengeRequest* g_UGSJoinChallengeRequest = static_cast<UGSJoinChallengeRequest*>(response.GetUserData());
                               
    if(!g_UGSJoinChallengeRequest->OnResponse.IsBound()){
        return;    
    }

    if (response.GetHasErrors())
    {
        g_UGSJoinChallengeRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSJoinChallengeRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSJoinChallengeRequest* UGSJoinChallengeRequest::SendJoinChallengeRequest(FString ChallengeInstanceId, UGameSparksScriptData* Eligibility, FString Message,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSJoinChallengeRequest* proxy = NewObject<UGSJoinChallengeRequest>();
    proxy->challengeInstanceId = ChallengeInstanceId;
    proxy->eligibility = Eligibility;
    proxy->message = Message;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    return proxy;
}

UGSJoinChallengeRequest* UGSJoinChallengeRequest::SendJoinChallengeRequestOnBehalfOf(const FString& PlayerId, FString ChallengeInstanceId, UGameSparksScriptData* Eligibility, FString Message,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSJoinChallengeRequest* proxy = NewObject<UGSJoinChallengeRequest>();
    proxy->challengeInstanceId = ChallengeInstanceId;
    proxy->eligibility = Eligibility;
    proxy->message = Message;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    proxy->playerId = PlayerId;
    return proxy;
}
    
void UGSJoinChallengeRequest::Activate()
{
    GameSparks::Api::Requests::JoinChallengeRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
    if(challengeInstanceId != ""){
        gsRequest.SetChallengeInstanceId(TCHAR_TO_UTF8(*challengeInstanceId));
    }
    if(eligibility != nullptr){
        gsRequest.SetEligibility(eligibility->ToRequestData());
    }
    if(message != ""){
        gsRequest.SetMessage(TCHAR_TO_UTF8(*message));
    }
    if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
        gsRequest.SetDurable(durable);
    }
    
    if(!playerId.IsEmpty())
    {
        gsRequest.SetPlayerId(TCHAR_TO_UTF8(*playerId));
    }

    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
        gsRequest.Send(JoinChallengeRequestResponseCallback, requestTimeoutSeconds);  
    } else {
        gsRequest.Send(JoinChallengeRequestResponseCallback);
    }
}

UGSJoinChallengeRequest::~UGSJoinChallengeRequest()
{
 if (UGameSparksModule* module = UGameSparksModule::GetModulePtr())
 {
  if (module->IsInitialized())
  {
    module->GetGSInstance().ChangeUserDataForRequests(this, nullptr);
  }
 }
}


void JoinPendingMatchRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::JoinPendingMatchResponse& response){
    
    if(response.GetUserData() == nullptr) {
        return;
    }
    
    FGSJoinPendingMatchResponse unreal_response = FGSJoinPendingMatchResponse(response.GetBaseData());
    
    UGSJoinPendingMatchRequest* g_UGSJoinPendingMatchRequest = static_cast<UGSJoinPendingMatchRequest*>(response.GetUserData());
                               
    if(!g_UGSJoinPendingMatchRequest->OnResponse.IsBound()){
        return;    
    }

    if (response.GetHasErrors())
    {
        g_UGSJoinPendingMatchRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSJoinPendingMatchRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSJoinPendingMatchRequest* UGSJoinPendingMatchRequest::SendJoinPendingMatchRequest(FString MatchGroup, FString MatchShortCode, FString PendingMatchId,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSJoinPendingMatchRequest* proxy = NewObject<UGSJoinPendingMatchRequest>();
    proxy->matchGroup = MatchGroup;
    proxy->matchShortCode = MatchShortCode;
    proxy->pendingMatchId = PendingMatchId;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    return proxy;
}

UGSJoinPendingMatchRequest* UGSJoinPendingMatchRequest::SendJoinPendingMatchRequestOnBehalfOf(const FString& PlayerId, FString MatchGroup, FString MatchShortCode, FString PendingMatchId,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSJoinPendingMatchRequest* proxy = NewObject<UGSJoinPendingMatchRequest>();
    proxy->matchGroup = MatchGroup;
    proxy->matchShortCode = MatchShortCode;
    proxy->pendingMatchId = PendingMatchId;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    proxy->playerId = PlayerId;
    return proxy;
}
    
void UGSJoinPendingMatchRequest::Activate()
{
    GameSparks::Api::Requests::JoinPendingMatchRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
    if(matchGroup != ""){
        gsRequest.SetMatchGroup(TCHAR_TO_UTF8(*matchGroup));
    }
    if(matchShortCode != ""){
        gsRequest.SetMatchShortCode(TCHAR_TO_UTF8(*matchShortCode));
    }
    if(pendingMatchId != ""){
        gsRequest.SetPendingMatchId(TCHAR_TO_UTF8(*pendingMatchId));
    }
    if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
        gsRequest.SetDurable(durable);
    }
    
    if(!playerId.IsEmpty())
    {
        gsRequest.SetPlayerId(TCHAR_TO_UTF8(*playerId));
    }

    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
        gsRequest.Send(JoinPendingMatchRequestResponseCallback, requestTimeoutSeconds);  
    } else {
        gsRequest.Send(JoinPendingMatchRequestResponseCallback);
    }
}

UGSJoinPendingMatchRequest::~UGSJoinPendingMatchRequest()
{
 if (UGameSparksModule* module = UGameSparksModule::GetModulePtr())
 {
  if (module->IsInitialized())
  {
    module->GetGSInstance().ChangeUserDataForRequests(this, nullptr);
  }
 }
}


void JoinTeamRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::JoinTeamResponse& response){
    
    if(response.GetUserData() == nullptr) {
        return;
    }
    
    FGSJoinTeamResponse unreal_response = FGSJoinTeamResponse(response.GetBaseData());
    
    UGSJoinTeamRequest* g_UGSJoinTeamRequest = static_cast<UGSJoinTeamRequest*>(response.GetUserData());
                               
    if(!g_UGSJoinTeamRequest->OnResponse.IsBound()){
        return;    
    }

    if (response.GetHasErrors())
    {
        g_UGSJoinTeamRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSJoinTeamRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSJoinTeamRequest* UGSJoinTeamRequest::SendJoinTeamRequest(FString OwnerId, FString TeamId, FString TeamType,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSJoinTeamRequest* proxy = NewObject<UGSJoinTeamRequest>();
    proxy->ownerId = OwnerId;
    proxy->teamId = TeamId;
    proxy->teamType = TeamType;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    return proxy;
}

UGSJoinTeamRequest* UGSJoinTeamRequest::SendJoinTeamRequestOnBehalfOf(const FString& PlayerId, FString OwnerId, FString TeamId, FString TeamType,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSJoinTeamRequest* proxy = NewObject<UGSJoinTeamRequest>();
    proxy->ownerId = OwnerId;
    proxy->teamId = TeamId;
    proxy->teamType = TeamType;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    proxy->playerId = PlayerId;
    return proxy;
}
    
void UGSJoinTeamRequest::Activate()
{
    GameSparks::Api::Requests::JoinTeamRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
    if(ownerId != ""){
        gsRequest.SetOwnerId(TCHAR_TO_UTF8(*ownerId));
    }
    if(teamId != ""){
        gsRequest.SetTeamId(TCHAR_TO_UTF8(*teamId));
    }
    if(teamType != ""){
        gsRequest.SetTeamType(TCHAR_TO_UTF8(*teamType));
    }
    if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
        gsRequest.SetDurable(durable);
    }
    
    if(!playerId.IsEmpty())
    {
        gsRequest.SetPlayerId(TCHAR_TO_UTF8(*playerId));
    }

    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
        gsRequest.Send(JoinTeamRequestResponseCallback, requestTimeoutSeconds);  
    } else {
        gsRequest.Send(JoinTeamRequestResponseCallback);
    }
}

UGSJoinTeamRequest::~UGSJoinTeamRequest()
{
 if (UGameSparksModule* module = UGameSparksModule::GetModulePtr())
 {
  if (module->IsInitialized())
  {
    module->GetGSInstance().ChangeUserDataForRequests(this, nullptr);
  }
 }
}


void KongregateConnectRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::AuthenticationResponse& response){
    
    if(response.GetUserData() == nullptr) {
        return;
    }
    
    FGSAuthenticationResponse unreal_response = FGSAuthenticationResponse(response.GetBaseData());
    
    UGSKongregateConnectRequest* g_UGSKongregateConnectRequest = static_cast<UGSKongregateConnectRequest*>(response.GetUserData());
                               
    if(!g_UGSKongregateConnectRequest->OnResponse.IsBound()){
        return;    
    }

    if (response.GetHasErrors())
    {
        g_UGSKongregateConnectRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSKongregateConnectRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSKongregateConnectRequest* UGSKongregateConnectRequest::SendKongregateConnectRequest(bool DoNotLinkToCurrentPlayer, bool ErrorOnSwitch, FString GameAuthToken, UGameSparksScriptData* Segments, bool SwitchIfPossible, bool SyncDisplayName, FString UserId,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSKongregateConnectRequest* proxy = NewObject<UGSKongregateConnectRequest>();
    proxy->doNotLinkToCurrentPlayer = DoNotLinkToCurrentPlayer;
    proxy->errorOnSwitch = ErrorOnSwitch;
    proxy->gameAuthToken = GameAuthToken;
    proxy->segments = Segments;
    proxy->switchIfPossible = SwitchIfPossible;
    proxy->syncDisplayName = SyncDisplayName;
    proxy->userId = UserId;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    return proxy;
}

UGSKongregateConnectRequest* UGSKongregateConnectRequest::SendKongregateConnectRequestOnBehalfOf(const FString& PlayerId, bool DoNotLinkToCurrentPlayer, bool ErrorOnSwitch, FString GameAuthToken, UGameSparksScriptData* Segments, bool SwitchIfPossible, bool SyncDisplayName, FString UserId,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSKongregateConnectRequest* proxy = NewObject<UGSKongregateConnectRequest>();
    proxy->doNotLinkToCurrentPlayer = DoNotLinkToCurrentPlayer;
    proxy->errorOnSwitch = ErrorOnSwitch;
    proxy->gameAuthToken = GameAuthToken;
    proxy->segments = Segments;
    proxy->switchIfPossible = SwitchIfPossible;
    proxy->syncDisplayName = SyncDisplayName;
    proxy->userId = UserId;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    proxy->playerId = PlayerId;
    return proxy;
}
    
void UGSKongregateConnectRequest::Activate()
{
    GameSparks::Api::Requests::KongregateConnectRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
    if(doNotLinkToCurrentPlayer != false){
        gsRequest.SetDoNotLinkToCurrentPlayer(doNotLinkToCurrentPlayer);
    }
    if(errorOnSwitch != false){
        gsRequest.SetErrorOnSwitch(errorOnSwitch);
    }
    if(gameAuthToken != ""){
        gsRequest.SetGameAuthToken(TCHAR_TO_UTF8(*gameAuthToken));
    }
    if(segments != nullptr){
        gsRequest.SetSegments(segments->ToRequestData());
    }
    if(switchIfPossible != false){
        gsRequest.SetSwitchIfPossible(switchIfPossible);
    }
    if(syncDisplayName != false){
        gsRequest.SetSyncDisplayName(syncDisplayName);
    }
    if(userId != ""){
        gsRequest.SetUserId(TCHAR_TO_UTF8(*userId));
    }
    if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
        gsRequest.SetDurable(durable);
    }
    
    if(!playerId.IsEmpty())
    {
        gsRequest.SetPlayerId(TCHAR_TO_UTF8(*playerId));
    }

    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
        gsRequest.Send(KongregateConnectRequestResponseCallback, requestTimeoutSeconds);  
    } else {
        gsRequest.Send(KongregateConnectRequestResponseCallback);
    }
}

UGSKongregateConnectRequest::~UGSKongregateConnectRequest()
{
 if (UGameSparksModule* module = UGameSparksModule::GetModulePtr())
 {
  if (module->IsInitialized())
  {
    module->GetGSInstance().ChangeUserDataForRequests(this, nullptr);
  }
 }
}


void LeaderboardDataRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::LeaderboardDataResponse& response){
    
    if(response.GetUserData() == nullptr) {
        return;
    }
    
    FGSLeaderboardDataResponse unreal_response = FGSLeaderboardDataResponse(response.GetBaseData());
    
    UGSLeaderboardDataRequest* g_UGSLeaderboardDataRequest = static_cast<UGSLeaderboardDataRequest*>(response.GetUserData());
                               
    if(!g_UGSLeaderboardDataRequest->OnResponse.IsBound()){
        return;    
    }

    if (response.GetHasErrors())
    {
        g_UGSLeaderboardDataRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSLeaderboardDataRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSLeaderboardDataRequest* UGSLeaderboardDataRequest::SendLeaderboardDataRequest(FString ChallengeInstanceId, bool DontErrorOnNotSocial, int32 EntryCount, UGameSparksRequestArray* FriendIds, int32 IncludeFirst, int32 IncludeLast, bool InverseSocial, FString LeaderboardShortCode, int32 Offset, bool Social, UGameSparksRequestArray* TeamIds, UGameSparksRequestArray* TeamTypes,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSLeaderboardDataRequest* proxy = NewObject<UGSLeaderboardDataRequest>();
    proxy->challengeInstanceId = ChallengeInstanceId;
    proxy->dontErrorOnNotSocial = DontErrorOnNotSocial;
    proxy->entryCount = EntryCount;
    proxy->friendIds = FriendIds;
    proxy->includeFirst = IncludeFirst;
    proxy->includeLast = IncludeLast;
    proxy->inverseSocial = InverseSocial;
    proxy->leaderboardShortCode = LeaderboardShortCode;
    proxy->offset = Offset;
    proxy->social = Social;
    proxy->teamIds = TeamIds;
    proxy->teamTypes = TeamTypes;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    return proxy;
}

UGSLeaderboardDataRequest* UGSLeaderboardDataRequest::SendLeaderboardDataRequestOnBehalfOf(const FString& PlayerId, FString ChallengeInstanceId, bool DontErrorOnNotSocial, int32 EntryCount, UGameSparksRequestArray* FriendIds, int32 IncludeFirst, int32 IncludeLast, bool InverseSocial, FString LeaderboardShortCode, int32 Offset, bool Social, UGameSparksRequestArray* TeamIds, UGameSparksRequestArray* TeamTypes,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSLeaderboardDataRequest* proxy = NewObject<UGSLeaderboardDataRequest>();
    proxy->challengeInstanceId = ChallengeInstanceId;
    proxy->dontErrorOnNotSocial = DontErrorOnNotSocial;
    proxy->entryCount = EntryCount;
    proxy->friendIds = FriendIds;
    proxy->includeFirst = IncludeFirst;
    proxy->includeLast = IncludeLast;
    proxy->inverseSocial = InverseSocial;
    proxy->leaderboardShortCode = LeaderboardShortCode;
    proxy->offset = Offset;
    proxy->social = Social;
    proxy->teamIds = TeamIds;
    proxy->teamTypes = TeamTypes;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    proxy->playerId = PlayerId;
    return proxy;
}
    
void UGSLeaderboardDataRequest::Activate()
{
    GameSparks::Api::Requests::LeaderboardDataRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
    if(challengeInstanceId != ""){
        gsRequest.SetChallengeInstanceId(TCHAR_TO_UTF8(*challengeInstanceId));
    }
    if(dontErrorOnNotSocial != false){
        gsRequest.SetDontErrorOnNotSocial(dontErrorOnNotSocial);
    }
    if(entryCount != 0){
        gsRequest.SetEntryCount(entryCount);
    }
    if(friendIds != nullptr){
        gsstl::vector<gsstl::string> arrFriendIds;
    
        for(int32 b_arrFriendIds = 0; b_arrFriendIds < friendIds->StringArray.Num(); b_arrFriendIds++)
        {
            arrFriendIds.push_back(TCHAR_TO_UTF8(*friendIds->StringArray[b_arrFriendIds]));
        }
        
        gsRequest.SetFriendIds(arrFriendIds);
    }
    if(includeFirst != 0){
        gsRequest.SetIncludeFirst(includeFirst);
    }
    if(includeLast != 0){
        gsRequest.SetIncludeLast(includeLast);
    }
    if(inverseSocial != false){
        gsRequest.SetInverseSocial(inverseSocial);
    }
    if(leaderboardShortCode != ""){
        gsRequest.SetLeaderboardShortCode(TCHAR_TO_UTF8(*leaderboardShortCode));
    }
    if(offset != 0){
        gsRequest.SetOffset(offset);
    }
    if(social != false){
        gsRequest.SetSocial(social);
    }
    if(teamIds != nullptr){
        gsstl::vector<gsstl::string> arrTeamIds;
    
        for(int32 b_arrTeamIds = 0; b_arrTeamIds < teamIds->StringArray.Num(); b_arrTeamIds++)
        {
            arrTeamIds.push_back(TCHAR_TO_UTF8(*teamIds->StringArray[b_arrTeamIds]));
        }
        
        gsRequest.SetTeamIds(arrTeamIds);
    }
    if(teamTypes != nullptr){
        gsstl::vector<gsstl::string> arrTeamTypes;
    
        for(int32 b_arrTeamTypes = 0; b_arrTeamTypes < teamTypes->StringArray.Num(); b_arrTeamTypes++)
        {
            arrTeamTypes.push_back(TCHAR_TO_UTF8(*teamTypes->StringArray[b_arrTeamTypes]));
        }
        
        gsRequest.SetTeamTypes(arrTeamTypes);
    }
    if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
        gsRequest.SetDurable(durable);
    }
    
    if(!playerId.IsEmpty())
    {
        gsRequest.SetPlayerId(TCHAR_TO_UTF8(*playerId));
    }

    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
        gsRequest.Send(LeaderboardDataRequestResponseCallback, requestTimeoutSeconds);  
    } else {
        gsRequest.Send(LeaderboardDataRequestResponseCallback);
    }
}

UGSLeaderboardDataRequest::~UGSLeaderboardDataRequest()
{
 if (UGameSparksModule* module = UGameSparksModule::GetModulePtr())
 {
  if (module->IsInitialized())
  {
    module->GetGSInstance().ChangeUserDataForRequests(this, nullptr);
  }
 }
}


void LeaderboardsEntriesRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::LeaderboardsEntriesResponse& response){
    
    if(response.GetUserData() == nullptr) {
        return;
    }
    
    FGSLeaderboardsEntriesResponse unreal_response = FGSLeaderboardsEntriesResponse(response.GetBaseData());
    
    UGSLeaderboardsEntriesRequest* g_UGSLeaderboardsEntriesRequest = static_cast<UGSLeaderboardsEntriesRequest*>(response.GetUserData());
                               
    if(!g_UGSLeaderboardsEntriesRequest->OnResponse.IsBound()){
        return;    
    }

    if (response.GetHasErrors())
    {
        g_UGSLeaderboardsEntriesRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSLeaderboardsEntriesRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSLeaderboardsEntriesRequest* UGSLeaderboardsEntriesRequest::SendLeaderboardsEntriesRequest(UGameSparksRequestArray* Challenges, bool InverseSocial, UGameSparksRequestArray* Leaderboards, FString Player, bool Social, UGameSparksRequestArray* TeamTypes,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSLeaderboardsEntriesRequest* proxy = NewObject<UGSLeaderboardsEntriesRequest>();
    proxy->challenges = Challenges;
    proxy->inverseSocial = InverseSocial;
    proxy->leaderboards = Leaderboards;
    proxy->player = Player;
    proxy->social = Social;
    proxy->teamTypes = TeamTypes;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    return proxy;
}

UGSLeaderboardsEntriesRequest* UGSLeaderboardsEntriesRequest::SendLeaderboardsEntriesRequestOnBehalfOf(const FString& PlayerId, UGameSparksRequestArray* Challenges, bool InverseSocial, UGameSparksRequestArray* Leaderboards, FString Player, bool Social, UGameSparksRequestArray* TeamTypes,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSLeaderboardsEntriesRequest* proxy = NewObject<UGSLeaderboardsEntriesRequest>();
    proxy->challenges = Challenges;
    proxy->inverseSocial = InverseSocial;
    proxy->leaderboards = Leaderboards;
    proxy->player = Player;
    proxy->social = Social;
    proxy->teamTypes = TeamTypes;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    proxy->playerId = PlayerId;
    return proxy;
}
    
void UGSLeaderboardsEntriesRequest::Activate()
{
    GameSparks::Api::Requests::LeaderboardsEntriesRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
    if(challenges != nullptr){
        gsstl::vector<gsstl::string> arrChallenges;
    
        for(int32 b_arrChallenges = 0; b_arrChallenges < challenges->StringArray.Num(); b_arrChallenges++)
        {
            arrChallenges.push_back(TCHAR_TO_UTF8(*challenges->StringArray[b_arrChallenges]));
        }
        
        gsRequest.SetChallenges(arrChallenges);
    }
    if(inverseSocial != false){
        gsRequest.SetInverseSocial(inverseSocial);
    }
    if(leaderboards != nullptr){
        gsstl::vector<gsstl::string> arrLeaderboards;
    
        for(int32 b_arrLeaderboards = 0; b_arrLeaderboards < leaderboards->StringArray.Num(); b_arrLeaderboards++)
        {
            arrLeaderboards.push_back(TCHAR_TO_UTF8(*leaderboards->StringArray[b_arrLeaderboards]));
        }
        
        gsRequest.SetLeaderboards(arrLeaderboards);
    }
    if(player != ""){
        gsRequest.SetPlayer(TCHAR_TO_UTF8(*player));
    }
    if(social != false){
        gsRequest.SetSocial(social);
    }
    if(teamTypes != nullptr){
        gsstl::vector<gsstl::string> arrTeamTypes;
    
        for(int32 b_arrTeamTypes = 0; b_arrTeamTypes < teamTypes->StringArray.Num(); b_arrTeamTypes++)
        {
            arrTeamTypes.push_back(TCHAR_TO_UTF8(*teamTypes->StringArray[b_arrTeamTypes]));
        }
        
        gsRequest.SetTeamTypes(arrTeamTypes);
    }
    if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
        gsRequest.SetDurable(durable);
    }
    
    if(!playerId.IsEmpty())
    {
        gsRequest.SetPlayerId(TCHAR_TO_UTF8(*playerId));
    }

    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
        gsRequest.Send(LeaderboardsEntriesRequestResponseCallback, requestTimeoutSeconds);  
    } else {
        gsRequest.Send(LeaderboardsEntriesRequestResponseCallback);
    }
}

UGSLeaderboardsEntriesRequest::~UGSLeaderboardsEntriesRequest()
{
 if (UGameSparksModule* module = UGameSparksModule::GetModulePtr())
 {
  if (module->IsInitialized())
  {
    module->GetGSInstance().ChangeUserDataForRequests(this, nullptr);
  }
 }
}


void LeaveTeamRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::LeaveTeamResponse& response){
    
    if(response.GetUserData() == nullptr) {
        return;
    }
    
    FGSLeaveTeamResponse unreal_response = FGSLeaveTeamResponse(response.GetBaseData());
    
    UGSLeaveTeamRequest* g_UGSLeaveTeamRequest = static_cast<UGSLeaveTeamRequest*>(response.GetUserData());
                               
    if(!g_UGSLeaveTeamRequest->OnResponse.IsBound()){
        return;    
    }

    if (response.GetHasErrors())
    {
        g_UGSLeaveTeamRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSLeaveTeamRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSLeaveTeamRequest* UGSLeaveTeamRequest::SendLeaveTeamRequest(FString OwnerId, FString TeamId, FString TeamType,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSLeaveTeamRequest* proxy = NewObject<UGSLeaveTeamRequest>();
    proxy->ownerId = OwnerId;
    proxy->teamId = TeamId;
    proxy->teamType = TeamType;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    return proxy;
}

UGSLeaveTeamRequest* UGSLeaveTeamRequest::SendLeaveTeamRequestOnBehalfOf(const FString& PlayerId, FString OwnerId, FString TeamId, FString TeamType,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSLeaveTeamRequest* proxy = NewObject<UGSLeaveTeamRequest>();
    proxy->ownerId = OwnerId;
    proxy->teamId = TeamId;
    proxy->teamType = TeamType;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    proxy->playerId = PlayerId;
    return proxy;
}
    
void UGSLeaveTeamRequest::Activate()
{
    GameSparks::Api::Requests::LeaveTeamRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
    if(ownerId != ""){
        gsRequest.SetOwnerId(TCHAR_TO_UTF8(*ownerId));
    }
    if(teamId != ""){
        gsRequest.SetTeamId(TCHAR_TO_UTF8(*teamId));
    }
    if(teamType != ""){
        gsRequest.SetTeamType(TCHAR_TO_UTF8(*teamType));
    }
    if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
        gsRequest.SetDurable(durable);
    }
    
    if(!playerId.IsEmpty())
    {
        gsRequest.SetPlayerId(TCHAR_TO_UTF8(*playerId));
    }

    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
        gsRequest.Send(LeaveTeamRequestResponseCallback, requestTimeoutSeconds);  
    } else {
        gsRequest.Send(LeaveTeamRequestResponseCallback);
    }
}

UGSLeaveTeamRequest::~UGSLeaveTeamRequest()
{
 if (UGameSparksModule* module = UGameSparksModule::GetModulePtr())
 {
  if (module->IsInitialized())
  {
    module->GetGSInstance().ChangeUserDataForRequests(this, nullptr);
  }
 }
}


void ListAchievementsRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::ListAchievementsResponse& response){
    
    if(response.GetUserData() == nullptr) {
        return;
    }
    
    FGSListAchievementsResponse unreal_response = FGSListAchievementsResponse(response.GetBaseData());
    
    UGSListAchievementsRequest* g_UGSListAchievementsRequest = static_cast<UGSListAchievementsRequest*>(response.GetUserData());
                               
    if(!g_UGSListAchievementsRequest->OnResponse.IsBound()){
        return;    
    }

    if (response.GetHasErrors())
    {
        g_UGSListAchievementsRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSListAchievementsRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSListAchievementsRequest* UGSListAchievementsRequest::SendListAchievementsRequest( UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSListAchievementsRequest* proxy = NewObject<UGSListAchievementsRequest>();
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    return proxy;
}

UGSListAchievementsRequest* UGSListAchievementsRequest::SendListAchievementsRequestOnBehalfOf(const FString& PlayerId,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSListAchievementsRequest* proxy = NewObject<UGSListAchievementsRequest>();
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    proxy->playerId = PlayerId;
    return proxy;
}
    
void UGSListAchievementsRequest::Activate()
{
    GameSparks::Api::Requests::ListAchievementsRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
    if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
        gsRequest.SetDurable(durable);
    }
    
    if(!playerId.IsEmpty())
    {
        gsRequest.SetPlayerId(TCHAR_TO_UTF8(*playerId));
    }

    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
        gsRequest.Send(ListAchievementsRequestResponseCallback, requestTimeoutSeconds);  
    } else {
        gsRequest.Send(ListAchievementsRequestResponseCallback);
    }
}

UGSListAchievementsRequest::~UGSListAchievementsRequest()
{
 if (UGameSparksModule* module = UGameSparksModule::GetModulePtr())
 {
  if (module->IsInitialized())
  {
    module->GetGSInstance().ChangeUserDataForRequests(this, nullptr);
  }
 }
}


void ListBulkJobsAdminRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::ListBulkJobsAdminResponse& response){
    
    if(response.GetUserData() == nullptr) {
        return;
    }
    
    FGSListBulkJobsAdminResponse unreal_response = FGSListBulkJobsAdminResponse(response.GetBaseData());
    
    UGSListBulkJobsAdminRequest* g_UGSListBulkJobsAdminRequest = static_cast<UGSListBulkJobsAdminRequest*>(response.GetUserData());
                               
    if(!g_UGSListBulkJobsAdminRequest->OnResponse.IsBound()){
        return;    
    }

    if (response.GetHasErrors())
    {
        g_UGSListBulkJobsAdminRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSListBulkJobsAdminRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSListBulkJobsAdminRequest* UGSListBulkJobsAdminRequest::SendListBulkJobsAdminRequest(UGameSparksRequestArray* BulkJobIds,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSListBulkJobsAdminRequest* proxy = NewObject<UGSListBulkJobsAdminRequest>();
    proxy->bulkJobIds = BulkJobIds;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    return proxy;
}

UGSListBulkJobsAdminRequest* UGSListBulkJobsAdminRequest::SendListBulkJobsAdminRequestOnBehalfOf(const FString& PlayerId, UGameSparksRequestArray* BulkJobIds,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSListBulkJobsAdminRequest* proxy = NewObject<UGSListBulkJobsAdminRequest>();
    proxy->bulkJobIds = BulkJobIds;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    proxy->playerId = PlayerId;
    return proxy;
}
    
void UGSListBulkJobsAdminRequest::Activate()
{
    GameSparks::Api::Requests::ListBulkJobsAdminRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
    if(bulkJobIds != nullptr){
        gsstl::vector<gsstl::string> arrBulkJobIds;
    
        for(int32 b_arrBulkJobIds = 0; b_arrBulkJobIds < bulkJobIds->StringArray.Num(); b_arrBulkJobIds++)
        {
            arrBulkJobIds.push_back(TCHAR_TO_UTF8(*bulkJobIds->StringArray[b_arrBulkJobIds]));
        }
        
        gsRequest.SetBulkJobIds(arrBulkJobIds);
    }
    if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
        gsRequest.SetDurable(durable);
    }
    
    if(!playerId.IsEmpty())
    {
        gsRequest.SetPlayerId(TCHAR_TO_UTF8(*playerId));
    }

    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
        gsRequest.Send(ListBulkJobsAdminRequestResponseCallback, requestTimeoutSeconds);  
    } else {
        gsRequest.Send(ListBulkJobsAdminRequestResponseCallback);
    }
}

UGSListBulkJobsAdminRequest::~UGSListBulkJobsAdminRequest()
{
 if (UGameSparksModule* module = UGameSparksModule::GetModulePtr())
 {
  if (module->IsInitialized())
  {
    module->GetGSInstance().ChangeUserDataForRequests(this, nullptr);
  }
 }
}


void ListChallengeRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::ListChallengeResponse& response){
    
    if(response.GetUserData() == nullptr) {
        return;
    }
    
    FGSListChallengeResponse unreal_response = FGSListChallengeResponse(response.GetBaseData());
    
    UGSListChallengeRequest* g_UGSListChallengeRequest = static_cast<UGSListChallengeRequest*>(response.GetUserData());
                               
    if(!g_UGSListChallengeRequest->OnResponse.IsBound()){
        return;    
    }

    if (response.GetHasErrors())
    {
        g_UGSListChallengeRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSListChallengeRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSListChallengeRequest* UGSListChallengeRequest::SendListChallengeRequest(int32 EntryCount, int32 Offset, FString ShortCode, FString State, UGameSparksRequestArray* States,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSListChallengeRequest* proxy = NewObject<UGSListChallengeRequest>();
    proxy->entryCount = EntryCount;
    proxy->offset = Offset;
    proxy->shortCode = ShortCode;
    proxy->state = State;
    proxy->states = States;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    return proxy;
}

UGSListChallengeRequest* UGSListChallengeRequest::SendListChallengeRequestOnBehalfOf(const FString& PlayerId, int32 EntryCount, int32 Offset, FString ShortCode, FString State, UGameSparksRequestArray* States,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSListChallengeRequest* proxy = NewObject<UGSListChallengeRequest>();
    proxy->entryCount = EntryCount;
    proxy->offset = Offset;
    proxy->shortCode = ShortCode;
    proxy->state = State;
    proxy->states = States;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    proxy->playerId = PlayerId;
    return proxy;
}
    
void UGSListChallengeRequest::Activate()
{
    GameSparks::Api::Requests::ListChallengeRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
    if(entryCount != 0){
        gsRequest.SetEntryCount(entryCount);
    }
    if(offset != 0){
        gsRequest.SetOffset(offset);
    }
    if(shortCode != ""){
        gsRequest.SetShortCode(TCHAR_TO_UTF8(*shortCode));
    }
    if(state != ""){
        gsRequest.SetState(TCHAR_TO_UTF8(*state));
    }
    if(states != nullptr){
        gsstl::vector<gsstl::string> arrStates;
    
        for(int32 b_arrStates = 0; b_arrStates < states->StringArray.Num(); b_arrStates++)
        {
            arrStates.push_back(TCHAR_TO_UTF8(*states->StringArray[b_arrStates]));
        }
        
        gsRequest.SetStates(arrStates);
    }
    if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
        gsRequest.SetDurable(durable);
    }
    
    if(!playerId.IsEmpty())
    {
        gsRequest.SetPlayerId(TCHAR_TO_UTF8(*playerId));
    }

    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
        gsRequest.Send(ListChallengeRequestResponseCallback, requestTimeoutSeconds);  
    } else {
        gsRequest.Send(ListChallengeRequestResponseCallback);
    }
}

UGSListChallengeRequest::~UGSListChallengeRequest()
{
 if (UGameSparksModule* module = UGameSparksModule::GetModulePtr())
 {
  if (module->IsInitialized())
  {
    module->GetGSInstance().ChangeUserDataForRequests(this, nullptr);
  }
 }
}


void ListChallengeTypeRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::ListChallengeTypeResponse& response){
    
    if(response.GetUserData() == nullptr) {
        return;
    }
    
    FGSListChallengeTypeResponse unreal_response = FGSListChallengeTypeResponse(response.GetBaseData());
    
    UGSListChallengeTypeRequest* g_UGSListChallengeTypeRequest = static_cast<UGSListChallengeTypeRequest*>(response.GetUserData());
                               
    if(!g_UGSListChallengeTypeRequest->OnResponse.IsBound()){
        return;    
    }

    if (response.GetHasErrors())
    {
        g_UGSListChallengeTypeRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSListChallengeTypeRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSListChallengeTypeRequest* UGSListChallengeTypeRequest::SendListChallengeTypeRequest( UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSListChallengeTypeRequest* proxy = NewObject<UGSListChallengeTypeRequest>();
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    return proxy;
}

UGSListChallengeTypeRequest* UGSListChallengeTypeRequest::SendListChallengeTypeRequestOnBehalfOf(const FString& PlayerId,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSListChallengeTypeRequest* proxy = NewObject<UGSListChallengeTypeRequest>();
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    proxy->playerId = PlayerId;
    return proxy;
}
    
void UGSListChallengeTypeRequest::Activate()
{
    GameSparks::Api::Requests::ListChallengeTypeRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
    if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
        gsRequest.SetDurable(durable);
    }
    
    if(!playerId.IsEmpty())
    {
        gsRequest.SetPlayerId(TCHAR_TO_UTF8(*playerId));
    }

    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
        gsRequest.Send(ListChallengeTypeRequestResponseCallback, requestTimeoutSeconds);  
    } else {
        gsRequest.Send(ListChallengeTypeRequestResponseCallback);
    }
}

UGSListChallengeTypeRequest::~UGSListChallengeTypeRequest()
{
 if (UGameSparksModule* module = UGameSparksModule::GetModulePtr())
 {
  if (module->IsInitialized())
  {
    module->GetGSInstance().ChangeUserDataForRequests(this, nullptr);
  }
 }
}


void ListGameFriendsRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::ListGameFriendsResponse& response){
    
    if(response.GetUserData() == nullptr) {
        return;
    }
    
    FGSListGameFriendsResponse unreal_response = FGSListGameFriendsResponse(response.GetBaseData());
    
    UGSListGameFriendsRequest* g_UGSListGameFriendsRequest = static_cast<UGSListGameFriendsRequest*>(response.GetUserData());
                               
    if(!g_UGSListGameFriendsRequest->OnResponse.IsBound()){
        return;    
    }

    if (response.GetHasErrors())
    {
        g_UGSListGameFriendsRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSListGameFriendsRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSListGameFriendsRequest* UGSListGameFriendsRequest::SendListGameFriendsRequest( UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSListGameFriendsRequest* proxy = NewObject<UGSListGameFriendsRequest>();
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    return proxy;
}

UGSListGameFriendsRequest* UGSListGameFriendsRequest::SendListGameFriendsRequestOnBehalfOf(const FString& PlayerId,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSListGameFriendsRequest* proxy = NewObject<UGSListGameFriendsRequest>();
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    proxy->playerId = PlayerId;
    return proxy;
}
    
void UGSListGameFriendsRequest::Activate()
{
    GameSparks::Api::Requests::ListGameFriendsRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
    if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
        gsRequest.SetDurable(durable);
    }
    
    if(!playerId.IsEmpty())
    {
        gsRequest.SetPlayerId(TCHAR_TO_UTF8(*playerId));
    }

    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
        gsRequest.Send(ListGameFriendsRequestResponseCallback, requestTimeoutSeconds);  
    } else {
        gsRequest.Send(ListGameFriendsRequestResponseCallback);
    }
}

UGSListGameFriendsRequest::~UGSListGameFriendsRequest()
{
 if (UGameSparksModule* module = UGameSparksModule::GetModulePtr())
 {
  if (module->IsInitialized())
  {
    module->GetGSInstance().ChangeUserDataForRequests(this, nullptr);
  }
 }
}


void ListInviteFriendsRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::ListInviteFriendsResponse& response){
    
    if(response.GetUserData() == nullptr) {
        return;
    }
    
    FGSListInviteFriendsResponse unreal_response = FGSListInviteFriendsResponse(response.GetBaseData());
    
    UGSListInviteFriendsRequest* g_UGSListInviteFriendsRequest = static_cast<UGSListInviteFriendsRequest*>(response.GetUserData());
                               
    if(!g_UGSListInviteFriendsRequest->OnResponse.IsBound()){
        return;    
    }

    if (response.GetHasErrors())
    {
        g_UGSListInviteFriendsRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSListInviteFriendsRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSListInviteFriendsRequest* UGSListInviteFriendsRequest::SendListInviteFriendsRequest( UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSListInviteFriendsRequest* proxy = NewObject<UGSListInviteFriendsRequest>();
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    return proxy;
}

UGSListInviteFriendsRequest* UGSListInviteFriendsRequest::SendListInviteFriendsRequestOnBehalfOf(const FString& PlayerId,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSListInviteFriendsRequest* proxy = NewObject<UGSListInviteFriendsRequest>();
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    proxy->playerId = PlayerId;
    return proxy;
}
    
void UGSListInviteFriendsRequest::Activate()
{
    GameSparks::Api::Requests::ListInviteFriendsRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
    if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
        gsRequest.SetDurable(durable);
    }
    
    if(!playerId.IsEmpty())
    {
        gsRequest.SetPlayerId(TCHAR_TO_UTF8(*playerId));
    }

    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
        gsRequest.Send(ListInviteFriendsRequestResponseCallback, requestTimeoutSeconds);  
    } else {
        gsRequest.Send(ListInviteFriendsRequestResponseCallback);
    }
}

UGSListInviteFriendsRequest::~UGSListInviteFriendsRequest()
{
 if (UGameSparksModule* module = UGameSparksModule::GetModulePtr())
 {
  if (module->IsInitialized())
  {
    module->GetGSInstance().ChangeUserDataForRequests(this, nullptr);
  }
 }
}


void ListLeaderboardsRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::ListLeaderboardsResponse& response){
    
    if(response.GetUserData() == nullptr) {
        return;
    }
    
    FGSListLeaderboardsResponse unreal_response = FGSListLeaderboardsResponse(response.GetBaseData());
    
    UGSListLeaderboardsRequest* g_UGSListLeaderboardsRequest = static_cast<UGSListLeaderboardsRequest*>(response.GetUserData());
                               
    if(!g_UGSListLeaderboardsRequest->OnResponse.IsBound()){
        return;    
    }

    if (response.GetHasErrors())
    {
        g_UGSListLeaderboardsRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSListLeaderboardsRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSListLeaderboardsRequest* UGSListLeaderboardsRequest::SendListLeaderboardsRequest( UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSListLeaderboardsRequest* proxy = NewObject<UGSListLeaderboardsRequest>();
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    return proxy;
}

UGSListLeaderboardsRequest* UGSListLeaderboardsRequest::SendListLeaderboardsRequestOnBehalfOf(const FString& PlayerId,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSListLeaderboardsRequest* proxy = NewObject<UGSListLeaderboardsRequest>();
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    proxy->playerId = PlayerId;
    return proxy;
}
    
void UGSListLeaderboardsRequest::Activate()
{
    GameSparks::Api::Requests::ListLeaderboardsRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
    if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
        gsRequest.SetDurable(durable);
    }
    
    if(!playerId.IsEmpty())
    {
        gsRequest.SetPlayerId(TCHAR_TO_UTF8(*playerId));
    }

    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
        gsRequest.Send(ListLeaderboardsRequestResponseCallback, requestTimeoutSeconds);  
    } else {
        gsRequest.Send(ListLeaderboardsRequestResponseCallback);
    }
}

UGSListLeaderboardsRequest::~UGSListLeaderboardsRequest()
{
 if (UGameSparksModule* module = UGameSparksModule::GetModulePtr())
 {
  if (module->IsInitialized())
  {
    module->GetGSInstance().ChangeUserDataForRequests(this, nullptr);
  }
 }
}


void ListMessageDetailRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::ListMessageDetailResponse& response){
    
    if(response.GetUserData() == nullptr) {
        return;
    }
    
    FGSListMessageDetailResponse unreal_response = FGSListMessageDetailResponse(response.GetBaseData());
    
    UGSListMessageDetailRequest* g_UGSListMessageDetailRequest = static_cast<UGSListMessageDetailRequest*>(response.GetUserData());
                               
    if(!g_UGSListMessageDetailRequest->OnResponse.IsBound()){
        return;    
    }

    if (response.GetHasErrors())
    {
        g_UGSListMessageDetailRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSListMessageDetailRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSListMessageDetailRequest* UGSListMessageDetailRequest::SendListMessageDetailRequest(int32 EntryCount, FString Include, int32 Offset, FString Status,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSListMessageDetailRequest* proxy = NewObject<UGSListMessageDetailRequest>();
    proxy->entryCount = EntryCount;
    proxy->include = Include;
    proxy->offset = Offset;
    proxy->status = Status;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    return proxy;
}

UGSListMessageDetailRequest* UGSListMessageDetailRequest::SendListMessageDetailRequestOnBehalfOf(const FString& PlayerId, int32 EntryCount, FString Include, int32 Offset, FString Status,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSListMessageDetailRequest* proxy = NewObject<UGSListMessageDetailRequest>();
    proxy->entryCount = EntryCount;
    proxy->include = Include;
    proxy->offset = Offset;
    proxy->status = Status;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    proxy->playerId = PlayerId;
    return proxy;
}
    
void UGSListMessageDetailRequest::Activate()
{
    GameSparks::Api::Requests::ListMessageDetailRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
    if(entryCount != 0){
        gsRequest.SetEntryCount(entryCount);
    }
    if(include != ""){
        gsRequest.SetInclude(TCHAR_TO_UTF8(*include));
    }
    if(offset != 0){
        gsRequest.SetOffset(offset);
    }
    if(status != ""){
        gsRequest.SetStatus(TCHAR_TO_UTF8(*status));
    }
    if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
        gsRequest.SetDurable(durable);
    }
    
    if(!playerId.IsEmpty())
    {
        gsRequest.SetPlayerId(TCHAR_TO_UTF8(*playerId));
    }

    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
        gsRequest.Send(ListMessageDetailRequestResponseCallback, requestTimeoutSeconds);  
    } else {
        gsRequest.Send(ListMessageDetailRequestResponseCallback);
    }
}

UGSListMessageDetailRequest::~UGSListMessageDetailRequest()
{
 if (UGameSparksModule* module = UGameSparksModule::GetModulePtr())
 {
  if (module->IsInitialized())
  {
    module->GetGSInstance().ChangeUserDataForRequests(this, nullptr);
  }
 }
}


void ListMessageRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::ListMessageResponse& response){
    
    if(response.GetUserData() == nullptr) {
        return;
    }
    
    FGSListMessageResponse unreal_response = FGSListMessageResponse(response.GetBaseData());
    
    UGSListMessageRequest* g_UGSListMessageRequest = static_cast<UGSListMessageRequest*>(response.GetUserData());
                               
    if(!g_UGSListMessageRequest->OnResponse.IsBound()){
        return;    
    }

    if (response.GetHasErrors())
    {
        g_UGSListMessageRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSListMessageRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSListMessageRequest* UGSListMessageRequest::SendListMessageRequest(int32 EntryCount, FString Include, int32 Offset,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSListMessageRequest* proxy = NewObject<UGSListMessageRequest>();
    proxy->entryCount = EntryCount;
    proxy->include = Include;
    proxy->offset = Offset;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    return proxy;
}

UGSListMessageRequest* UGSListMessageRequest::SendListMessageRequestOnBehalfOf(const FString& PlayerId, int32 EntryCount, FString Include, int32 Offset,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSListMessageRequest* proxy = NewObject<UGSListMessageRequest>();
    proxy->entryCount = EntryCount;
    proxy->include = Include;
    proxy->offset = Offset;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    proxy->playerId = PlayerId;
    return proxy;
}
    
void UGSListMessageRequest::Activate()
{
    GameSparks::Api::Requests::ListMessageRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
    if(entryCount != 0){
        gsRequest.SetEntryCount(entryCount);
    }
    if(include != ""){
        gsRequest.SetInclude(TCHAR_TO_UTF8(*include));
    }
    if(offset != 0){
        gsRequest.SetOffset(offset);
    }
    if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
        gsRequest.SetDurable(durable);
    }
    
    if(!playerId.IsEmpty())
    {
        gsRequest.SetPlayerId(TCHAR_TO_UTF8(*playerId));
    }

    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
        gsRequest.Send(ListMessageRequestResponseCallback, requestTimeoutSeconds);  
    } else {
        gsRequest.Send(ListMessageRequestResponseCallback);
    }
}

UGSListMessageRequest::~UGSListMessageRequest()
{
 if (UGameSparksModule* module = UGameSparksModule::GetModulePtr())
 {
  if (module->IsInitialized())
  {
    module->GetGSInstance().ChangeUserDataForRequests(this, nullptr);
  }
 }
}


void ListMessageSummaryRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::ListMessageSummaryResponse& response){
    
    if(response.GetUserData() == nullptr) {
        return;
    }
    
    FGSListMessageSummaryResponse unreal_response = FGSListMessageSummaryResponse(response.GetBaseData());
    
    UGSListMessageSummaryRequest* g_UGSListMessageSummaryRequest = static_cast<UGSListMessageSummaryRequest*>(response.GetUserData());
                               
    if(!g_UGSListMessageSummaryRequest->OnResponse.IsBound()){
        return;    
    }

    if (response.GetHasErrors())
    {
        g_UGSListMessageSummaryRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSListMessageSummaryRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSListMessageSummaryRequest* UGSListMessageSummaryRequest::SendListMessageSummaryRequest(int32 EntryCount, int32 Offset,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSListMessageSummaryRequest* proxy = NewObject<UGSListMessageSummaryRequest>();
    proxy->entryCount = EntryCount;
    proxy->offset = Offset;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    return proxy;
}

UGSListMessageSummaryRequest* UGSListMessageSummaryRequest::SendListMessageSummaryRequestOnBehalfOf(const FString& PlayerId, int32 EntryCount, int32 Offset,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSListMessageSummaryRequest* proxy = NewObject<UGSListMessageSummaryRequest>();
    proxy->entryCount = EntryCount;
    proxy->offset = Offset;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    proxy->playerId = PlayerId;
    return proxy;
}
    
void UGSListMessageSummaryRequest::Activate()
{
    GameSparks::Api::Requests::ListMessageSummaryRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
    if(entryCount != 0){
        gsRequest.SetEntryCount(entryCount);
    }
    if(offset != 0){
        gsRequest.SetOffset(offset);
    }
    if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
        gsRequest.SetDurable(durable);
    }
    
    if(!playerId.IsEmpty())
    {
        gsRequest.SetPlayerId(TCHAR_TO_UTF8(*playerId));
    }

    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
        gsRequest.Send(ListMessageSummaryRequestResponseCallback, requestTimeoutSeconds);  
    } else {
        gsRequest.Send(ListMessageSummaryRequestResponseCallback);
    }
}

UGSListMessageSummaryRequest::~UGSListMessageSummaryRequest()
{
 if (UGameSparksModule* module = UGameSparksModule::GetModulePtr())
 {
  if (module->IsInitialized())
  {
    module->GetGSInstance().ChangeUserDataForRequests(this, nullptr);
  }
 }
}


void ListTeamChatRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::ListTeamChatResponse& response){
    
    if(response.GetUserData() == nullptr) {
        return;
    }
    
    FGSListTeamChatResponse unreal_response = FGSListTeamChatResponse(response.GetBaseData());
    
    UGSListTeamChatRequest* g_UGSListTeamChatRequest = static_cast<UGSListTeamChatRequest*>(response.GetUserData());
                               
    if(!g_UGSListTeamChatRequest->OnResponse.IsBound()){
        return;    
    }

    if (response.GetHasErrors())
    {
        g_UGSListTeamChatRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSListTeamChatRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSListTeamChatRequest* UGSListTeamChatRequest::SendListTeamChatRequest(int32 EntryCount, int32 Offset, FString OwnerId, FString TeamId, FString TeamType,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSListTeamChatRequest* proxy = NewObject<UGSListTeamChatRequest>();
    proxy->entryCount = EntryCount;
    proxy->offset = Offset;
    proxy->ownerId = OwnerId;
    proxy->teamId = TeamId;
    proxy->teamType = TeamType;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    return proxy;
}

UGSListTeamChatRequest* UGSListTeamChatRequest::SendListTeamChatRequestOnBehalfOf(const FString& PlayerId, int32 EntryCount, int32 Offset, FString OwnerId, FString TeamId, FString TeamType,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSListTeamChatRequest* proxy = NewObject<UGSListTeamChatRequest>();
    proxy->entryCount = EntryCount;
    proxy->offset = Offset;
    proxy->ownerId = OwnerId;
    proxy->teamId = TeamId;
    proxy->teamType = TeamType;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    proxy->playerId = PlayerId;
    return proxy;
}
    
void UGSListTeamChatRequest::Activate()
{
    GameSparks::Api::Requests::ListTeamChatRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
    if(entryCount != 0){
        gsRequest.SetEntryCount(entryCount);
    }
    if(offset != 0){
        gsRequest.SetOffset(offset);
    }
    if(ownerId != ""){
        gsRequest.SetOwnerId(TCHAR_TO_UTF8(*ownerId));
    }
    if(teamId != ""){
        gsRequest.SetTeamId(TCHAR_TO_UTF8(*teamId));
    }
    if(teamType != ""){
        gsRequest.SetTeamType(TCHAR_TO_UTF8(*teamType));
    }
    if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
        gsRequest.SetDurable(durable);
    }
    
    if(!playerId.IsEmpty())
    {
        gsRequest.SetPlayerId(TCHAR_TO_UTF8(*playerId));
    }

    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
        gsRequest.Send(ListTeamChatRequestResponseCallback, requestTimeoutSeconds);  
    } else {
        gsRequest.Send(ListTeamChatRequestResponseCallback);
    }
}

UGSListTeamChatRequest::~UGSListTeamChatRequest()
{
 if (UGameSparksModule* module = UGameSparksModule::GetModulePtr())
 {
  if (module->IsInitialized())
  {
    module->GetGSInstance().ChangeUserDataForRequests(this, nullptr);
  }
 }
}


void ListTeamsRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::ListTeamsResponse& response){
    
    if(response.GetUserData() == nullptr) {
        return;
    }
    
    FGSListTeamsResponse unreal_response = FGSListTeamsResponse(response.GetBaseData());
    
    UGSListTeamsRequest* g_UGSListTeamsRequest = static_cast<UGSListTeamsRequest*>(response.GetUserData());
                               
    if(!g_UGSListTeamsRequest->OnResponse.IsBound()){
        return;    
    }

    if (response.GetHasErrors())
    {
        g_UGSListTeamsRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSListTeamsRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSListTeamsRequest* UGSListTeamsRequest::SendListTeamsRequest(int32 EntryCount, int32 Offset, FString TeamNameFilter, FString TeamTypeFilter,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSListTeamsRequest* proxy = NewObject<UGSListTeamsRequest>();
    proxy->entryCount = EntryCount;
    proxy->offset = Offset;
    proxy->teamNameFilter = TeamNameFilter;
    proxy->teamTypeFilter = TeamTypeFilter;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    return proxy;
}

UGSListTeamsRequest* UGSListTeamsRequest::SendListTeamsRequestOnBehalfOf(const FString& PlayerId, int32 EntryCount, int32 Offset, FString TeamNameFilter, FString TeamTypeFilter,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSListTeamsRequest* proxy = NewObject<UGSListTeamsRequest>();
    proxy->entryCount = EntryCount;
    proxy->offset = Offset;
    proxy->teamNameFilter = TeamNameFilter;
    proxy->teamTypeFilter = TeamTypeFilter;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    proxy->playerId = PlayerId;
    return proxy;
}
    
void UGSListTeamsRequest::Activate()
{
    GameSparks::Api::Requests::ListTeamsRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
    if(entryCount != 0){
        gsRequest.SetEntryCount(entryCount);
    }
    if(offset != 0){
        gsRequest.SetOffset(offset);
    }
    if(teamNameFilter != ""){
        gsRequest.SetTeamNameFilter(TCHAR_TO_UTF8(*teamNameFilter));
    }
    if(teamTypeFilter != ""){
        gsRequest.SetTeamTypeFilter(TCHAR_TO_UTF8(*teamTypeFilter));
    }
    if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
        gsRequest.SetDurable(durable);
    }
    
    if(!playerId.IsEmpty())
    {
        gsRequest.SetPlayerId(TCHAR_TO_UTF8(*playerId));
    }

    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
        gsRequest.Send(ListTeamsRequestResponseCallback, requestTimeoutSeconds);  
    } else {
        gsRequest.Send(ListTeamsRequestResponseCallback);
    }
}

UGSListTeamsRequest::~UGSListTeamsRequest()
{
 if (UGameSparksModule* module = UGameSparksModule::GetModulePtr())
 {
  if (module->IsInitialized())
  {
    module->GetGSInstance().ChangeUserDataForRequests(this, nullptr);
  }
 }
}


void ListTransactionsRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::ListTransactionsResponse& response){
    
    if(response.GetUserData() == nullptr) {
        return;
    }
    
    FGSListTransactionsResponse unreal_response = FGSListTransactionsResponse(response.GetBaseData());
    
    UGSListTransactionsRequest* g_UGSListTransactionsRequest = static_cast<UGSListTransactionsRequest*>(response.GetUserData());
                               
    if(!g_UGSListTransactionsRequest->OnResponse.IsBound()){
        return;    
    }

    if (response.GetHasErrors())
    {
        g_UGSListTransactionsRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSListTransactionsRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSListTransactionsRequest* UGSListTransactionsRequest::SendListTransactionsRequest(FString DateFrom, FString DateTo, int32 EntryCount, FString Include, int32 Offset,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSListTransactionsRequest* proxy = NewObject<UGSListTransactionsRequest>();
    proxy->dateFrom = DateFrom;
    proxy->dateTo = DateTo;
    proxy->entryCount = EntryCount;
    proxy->include = Include;
    proxy->offset = Offset;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    return proxy;
}

UGSListTransactionsRequest* UGSListTransactionsRequest::SendListTransactionsRequestOnBehalfOf(const FString& PlayerId, FString DateFrom, FString DateTo, int32 EntryCount, FString Include, int32 Offset,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSListTransactionsRequest* proxy = NewObject<UGSListTransactionsRequest>();
    proxy->dateFrom = DateFrom;
    proxy->dateTo = DateTo;
    proxy->entryCount = EntryCount;
    proxy->include = Include;
    proxy->offset = Offset;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    proxy->playerId = PlayerId;
    return proxy;
}
    
void UGSListTransactionsRequest::Activate()
{
    GameSparks::Api::Requests::ListTransactionsRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
    if(dateFrom != ""){
        gsRequest.SetDateFrom(GameSparks::Core::GSDateTime(TCHAR_TO_UTF8(*dateFrom)));
    }
    if(dateTo != ""){
        gsRequest.SetDateTo(GameSparks::Core::GSDateTime(TCHAR_TO_UTF8(*dateTo)));
    }
    if(entryCount != 0){
        gsRequest.SetEntryCount(entryCount);
    }
    if(include != ""){
        gsRequest.SetInclude(TCHAR_TO_UTF8(*include));
    }
    if(offset != 0){
        gsRequest.SetOffset(offset);
    }
    if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
        gsRequest.SetDurable(durable);
    }
    
    if(!playerId.IsEmpty())
    {
        gsRequest.SetPlayerId(TCHAR_TO_UTF8(*playerId));
    }

    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
        gsRequest.Send(ListTransactionsRequestResponseCallback, requestTimeoutSeconds);  
    } else {
        gsRequest.Send(ListTransactionsRequestResponseCallback);
    }
}

UGSListTransactionsRequest::~UGSListTransactionsRequest()
{
 if (UGameSparksModule* module = UGameSparksModule::GetModulePtr())
 {
  if (module->IsInitialized())
  {
    module->GetGSInstance().ChangeUserDataForRequests(this, nullptr);
  }
 }
}


void ListVirtualGoodsRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::ListVirtualGoodsResponse& response){
    
    if(response.GetUserData() == nullptr) {
        return;
    }
    
    FGSListVirtualGoodsResponse unreal_response = FGSListVirtualGoodsResponse(response.GetBaseData());
    
    UGSListVirtualGoodsRequest* g_UGSListVirtualGoodsRequest = static_cast<UGSListVirtualGoodsRequest*>(response.GetUserData());
                               
    if(!g_UGSListVirtualGoodsRequest->OnResponse.IsBound()){
        return;    
    }

    if (response.GetHasErrors())
    {
        g_UGSListVirtualGoodsRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSListVirtualGoodsRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSListVirtualGoodsRequest* UGSListVirtualGoodsRequest::SendListVirtualGoodsRequest(bool IncludeDisabled, UGameSparksRequestArray* Tags,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSListVirtualGoodsRequest* proxy = NewObject<UGSListVirtualGoodsRequest>();
    proxy->includeDisabled = IncludeDisabled;
    proxy->tags = Tags;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    return proxy;
}

UGSListVirtualGoodsRequest* UGSListVirtualGoodsRequest::SendListVirtualGoodsRequestOnBehalfOf(const FString& PlayerId, bool IncludeDisabled, UGameSparksRequestArray* Tags,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSListVirtualGoodsRequest* proxy = NewObject<UGSListVirtualGoodsRequest>();
    proxy->includeDisabled = IncludeDisabled;
    proxy->tags = Tags;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    proxy->playerId = PlayerId;
    return proxy;
}
    
void UGSListVirtualGoodsRequest::Activate()
{
    GameSparks::Api::Requests::ListVirtualGoodsRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
    if(includeDisabled != false){
        gsRequest.SetIncludeDisabled(includeDisabled);
    }
    if(tags != nullptr){
        gsstl::vector<gsstl::string> arrTags;
    
        for(int32 b_arrTags = 0; b_arrTags < tags->StringArray.Num(); b_arrTags++)
        {
            arrTags.push_back(TCHAR_TO_UTF8(*tags->StringArray[b_arrTags]));
        }
        
        gsRequest.SetTags(arrTags);
    }
    if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
        gsRequest.SetDurable(durable);
    }
    
    if(!playerId.IsEmpty())
    {
        gsRequest.SetPlayerId(TCHAR_TO_UTF8(*playerId));
    }

    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
        gsRequest.Send(ListVirtualGoodsRequestResponseCallback, requestTimeoutSeconds);  
    } else {
        gsRequest.Send(ListVirtualGoodsRequestResponseCallback);
    }
}

UGSListVirtualGoodsRequest::~UGSListVirtualGoodsRequest()
{
 if (UGameSparksModule* module = UGameSparksModule::GetModulePtr())
 {
  if (module->IsInitialized())
  {
    module->GetGSInstance().ChangeUserDataForRequests(this, nullptr);
  }
 }
}


void LogChallengeEventRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::LogChallengeEventResponse& response){
    
    if(response.GetUserData() == nullptr) {
        return;
    }
    
    FGSLogChallengeEventResponse unreal_response = FGSLogChallengeEventResponse(response.GetBaseData());
    
    UGSLogChallengeEventRequest* g_UGSLogChallengeEventRequest = static_cast<UGSLogChallengeEventRequest*>(response.GetUserData());
                               
    if(!g_UGSLogChallengeEventRequest->OnResponse.IsBound()){
        return;    
    }

    if (response.GetHasErrors())
    {
        g_UGSLogChallengeEventRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSLogChallengeEventRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSLogChallengeEventRequest* UGSLogChallengeEventRequest::SendLogChallengeEventRequest(FString ChallengeInstanceId, FString EventKey,  UGameSparksLogEventData* LogEventData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSLogChallengeEventRequest* proxy = NewObject<UGSLogChallengeEventRequest>();
    proxy->challengeInstanceId = ChallengeInstanceId;
    proxy->eventKey = EventKey;
    proxy->logEventData = LogEventData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    return proxy;
}

UGSLogChallengeEventRequest* UGSLogChallengeEventRequest::SendLogChallengeEventRequestOnBehalfOf(const FString& PlayerId, FString ChallengeInstanceId, FString EventKey,  UGameSparksLogEventData* LogEventData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSLogChallengeEventRequest* proxy = NewObject<UGSLogChallengeEventRequest>();
    proxy->challengeInstanceId = ChallengeInstanceId;
    proxy->eventKey = EventKey;
    proxy->logEventData = LogEventData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    proxy->playerId = PlayerId;
    return proxy;
}
    
void UGSLogChallengeEventRequest::Activate()
{
    GameSparks::Api::Requests::LogChallengeEventRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
    if(challengeInstanceId != ""){
        gsRequest.SetChallengeInstanceId(TCHAR_TO_UTF8(*challengeInstanceId));
    }
    if(eventKey != ""){
        gsRequest.SetEventKey(TCHAR_TO_UTF8(*eventKey));
    }
    if(logEventData != nullptr){
        logEventData->AddToLogEvent(&gsRequest);
    }
    if(durable){
        gsRequest.SetDurable(durable);
    }
    
    if(!playerId.IsEmpty())
    {
        gsRequest.SetPlayerId(TCHAR_TO_UTF8(*playerId));
    }

    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
        gsRequest.Send(LogChallengeEventRequestResponseCallback, requestTimeoutSeconds);  
    } else {
        gsRequest.Send(LogChallengeEventRequestResponseCallback);
    }
}

UGSLogChallengeEventRequest::~UGSLogChallengeEventRequest()
{
 if (UGameSparksModule* module = UGameSparksModule::GetModulePtr())
 {
  if (module->IsInitialized())
  {
    module->GetGSInstance().ChangeUserDataForRequests(this, nullptr);
  }
 }
}


void LogEventRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::LogEventResponse& response){
    
    if(response.GetUserData() == nullptr) {
        return;
    }
    
    FGSLogEventResponse unreal_response = FGSLogEventResponse(response.GetBaseData());
    
    UGSLogEventRequest* g_UGSLogEventRequest = static_cast<UGSLogEventRequest*>(response.GetUserData());
                               
    if(!g_UGSLogEventRequest->OnResponse.IsBound()){
        return;    
    }

    if (response.GetHasErrors())
    {
        g_UGSLogEventRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSLogEventRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSLogEventRequest* UGSLogEventRequest::SendLogEventRequest(FString EventKey,  UGameSparksLogEventData* LogEventData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSLogEventRequest* proxy = NewObject<UGSLogEventRequest>();
    proxy->eventKey = EventKey;
    proxy->logEventData = LogEventData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    return proxy;
}

UGSLogEventRequest* UGSLogEventRequest::SendLogEventRequestOnBehalfOf(const FString& PlayerId, FString EventKey,  UGameSparksLogEventData* LogEventData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSLogEventRequest* proxy = NewObject<UGSLogEventRequest>();
    proxy->eventKey = EventKey;
    proxy->logEventData = LogEventData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    proxy->playerId = PlayerId;
    return proxy;
}
    
void UGSLogEventRequest::Activate()
{
    GameSparks::Api::Requests::LogEventRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
    if(eventKey != ""){
        gsRequest.SetEventKey(TCHAR_TO_UTF8(*eventKey));
    }
    if(logEventData != nullptr){
        logEventData->AddToLogEvent(&gsRequest);
    }
    if(durable){
        gsRequest.SetDurable(durable);
    }
    
    if(!playerId.IsEmpty())
    {
        gsRequest.SetPlayerId(TCHAR_TO_UTF8(*playerId));
    }

    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
        gsRequest.Send(LogEventRequestResponseCallback, requestTimeoutSeconds);  
    } else {
        gsRequest.Send(LogEventRequestResponseCallback);
    }
}

UGSLogEventRequest::~UGSLogEventRequest()
{
 if (UGameSparksModule* module = UGameSparksModule::GetModulePtr())
 {
  if (module->IsInitialized())
  {
    module->GetGSInstance().ChangeUserDataForRequests(this, nullptr);
  }
 }
}


void MatchDetailsRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::MatchDetailsResponse& response){
    
    if(response.GetUserData() == nullptr) {
        return;
    }
    
    FGSMatchDetailsResponse unreal_response = FGSMatchDetailsResponse(response.GetBaseData());
    
    UGSMatchDetailsRequest* g_UGSMatchDetailsRequest = static_cast<UGSMatchDetailsRequest*>(response.GetUserData());
                               
    if(!g_UGSMatchDetailsRequest->OnResponse.IsBound()){
        return;    
    }

    if (response.GetHasErrors())
    {
        g_UGSMatchDetailsRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSMatchDetailsRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSMatchDetailsRequest* UGSMatchDetailsRequest::SendMatchDetailsRequest(FString MatchId, bool RealtimeEnabled,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSMatchDetailsRequest* proxy = NewObject<UGSMatchDetailsRequest>();
    proxy->matchId = MatchId;
    proxy->realtimeEnabled = RealtimeEnabled;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    return proxy;
}

UGSMatchDetailsRequest* UGSMatchDetailsRequest::SendMatchDetailsRequestOnBehalfOf(const FString& PlayerId, FString MatchId, bool RealtimeEnabled,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSMatchDetailsRequest* proxy = NewObject<UGSMatchDetailsRequest>();
    proxy->matchId = MatchId;
    proxy->realtimeEnabled = RealtimeEnabled;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    proxy->playerId = PlayerId;
    return proxy;
}
    
void UGSMatchDetailsRequest::Activate()
{
    GameSparks::Api::Requests::MatchDetailsRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
    if(matchId != ""){
        gsRequest.SetMatchId(TCHAR_TO_UTF8(*matchId));
    }
    if(realtimeEnabled != false){
        gsRequest.SetRealtimeEnabled(realtimeEnabled);
    }
    if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
        gsRequest.SetDurable(durable);
    }
    
    if(!playerId.IsEmpty())
    {
        gsRequest.SetPlayerId(TCHAR_TO_UTF8(*playerId));
    }

    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
        gsRequest.Send(MatchDetailsRequestResponseCallback, requestTimeoutSeconds);  
    } else {
        gsRequest.Send(MatchDetailsRequestResponseCallback);
    }
}

UGSMatchDetailsRequest::~UGSMatchDetailsRequest()
{
 if (UGameSparksModule* module = UGameSparksModule::GetModulePtr())
 {
  if (module->IsInitialized())
  {
    module->GetGSInstance().ChangeUserDataForRequests(this, nullptr);
  }
 }
}


void MatchmakingRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::MatchmakingResponse& response){
    
    if(response.GetUserData() == nullptr) {
        return;
    }
    
    FGSMatchmakingResponse unreal_response = FGSMatchmakingResponse(response.GetBaseData());
    
    UGSMatchmakingRequest* g_UGSMatchmakingRequest = static_cast<UGSMatchmakingRequest*>(response.GetUserData());
                               
    if(!g_UGSMatchmakingRequest->OnResponse.IsBound()){
        return;    
    }

    if (response.GetHasErrors())
    {
        g_UGSMatchmakingRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSMatchmakingRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSMatchmakingRequest* UGSMatchmakingRequest::SendMatchmakingRequest(FString Action, UGameSparksScriptData* CustomQuery, UGameSparksScriptData* MatchData, FString MatchGroup, FString MatchShortCode, UGameSparksScriptData* ParticipantData, int32 Skill,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSMatchmakingRequest* proxy = NewObject<UGSMatchmakingRequest>();
    proxy->action = Action;
    proxy->customQuery = CustomQuery;
    proxy->matchData = MatchData;
    proxy->matchGroup = MatchGroup;
    proxy->matchShortCode = MatchShortCode;
    proxy->participantData = ParticipantData;
    proxy->skill = Skill;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    return proxy;
}

UGSMatchmakingRequest* UGSMatchmakingRequest::SendMatchmakingRequestOnBehalfOf(const FString& PlayerId, FString Action, UGameSparksScriptData* CustomQuery, UGameSparksScriptData* MatchData, FString MatchGroup, FString MatchShortCode, UGameSparksScriptData* ParticipantData, int32 Skill,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSMatchmakingRequest* proxy = NewObject<UGSMatchmakingRequest>();
    proxy->action = Action;
    proxy->customQuery = CustomQuery;
    proxy->matchData = MatchData;
    proxy->matchGroup = MatchGroup;
    proxy->matchShortCode = MatchShortCode;
    proxy->participantData = ParticipantData;
    proxy->skill = Skill;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    proxy->playerId = PlayerId;
    return proxy;
}
    
void UGSMatchmakingRequest::Activate()
{
    GameSparks::Api::Requests::MatchmakingRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
    if(action != ""){
        gsRequest.SetAction(TCHAR_TO_UTF8(*action));
    }
    if(customQuery != nullptr){
        gsRequest.SetCustomQuery(customQuery->ToRequestData());
    }
    if(matchData != nullptr){
        gsRequest.SetMatchData(matchData->ToRequestData());
    }
    if(matchGroup != ""){
        gsRequest.SetMatchGroup(TCHAR_TO_UTF8(*matchGroup));
    }
    if(matchShortCode != ""){
        gsRequest.SetMatchShortCode(TCHAR_TO_UTF8(*matchShortCode));
    }
    if(participantData != nullptr){
        gsRequest.SetParticipantData(participantData->ToRequestData());
    }
    if(skill != 0){
        gsRequest.SetSkill(skill);
    }
    if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
        gsRequest.SetDurable(durable);
    }
    
    if(!playerId.IsEmpty())
    {
        gsRequest.SetPlayerId(TCHAR_TO_UTF8(*playerId));
    }

    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
        gsRequest.Send(MatchmakingRequestResponseCallback, requestTimeoutSeconds);  
    } else {
        gsRequest.Send(MatchmakingRequestResponseCallback);
    }
}

UGSMatchmakingRequest::~UGSMatchmakingRequest()
{
 if (UGameSparksModule* module = UGameSparksModule::GetModulePtr())
 {
  if (module->IsInitialized())
  {
    module->GetGSInstance().ChangeUserDataForRequests(this, nullptr);
  }
 }
}


void NXConnectRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::AuthenticationResponse& response){
    
    if(response.GetUserData() == nullptr) {
        return;
    }
    
    FGSAuthenticationResponse unreal_response = FGSAuthenticationResponse(response.GetBaseData());
    
    UGSNXConnectRequest* g_UGSNXConnectRequest = static_cast<UGSNXConnectRequest*>(response.GetUserData());
                               
    if(!g_UGSNXConnectRequest->OnResponse.IsBound()){
        return;    
    }

    if (response.GetHasErrors())
    {
        g_UGSNXConnectRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSNXConnectRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSNXConnectRequest* UGSNXConnectRequest::SendNXConnectRequest(bool AccountPerLoginId, FString DisplayName, bool DoNotLinkToCurrentPlayer, bool ErrorOnSwitch, FString NsaIdToken, UGameSparksScriptData* Segments, bool SwitchIfPossible, bool SyncDisplayName,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSNXConnectRequest* proxy = NewObject<UGSNXConnectRequest>();
    proxy->accountPerLoginId = AccountPerLoginId;
    proxy->displayName = DisplayName;
    proxy->doNotLinkToCurrentPlayer = DoNotLinkToCurrentPlayer;
    proxy->errorOnSwitch = ErrorOnSwitch;
    proxy->nsaIdToken = NsaIdToken;
    proxy->segments = Segments;
    proxy->switchIfPossible = SwitchIfPossible;
    proxy->syncDisplayName = SyncDisplayName;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    return proxy;
}

UGSNXConnectRequest* UGSNXConnectRequest::SendNXConnectRequestOnBehalfOf(const FString& PlayerId, bool AccountPerLoginId, FString DisplayName, bool DoNotLinkToCurrentPlayer, bool ErrorOnSwitch, FString NsaIdToken, UGameSparksScriptData* Segments, bool SwitchIfPossible, bool SyncDisplayName,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSNXConnectRequest* proxy = NewObject<UGSNXConnectRequest>();
    proxy->accountPerLoginId = AccountPerLoginId;
    proxy->displayName = DisplayName;
    proxy->doNotLinkToCurrentPlayer = DoNotLinkToCurrentPlayer;
    proxy->errorOnSwitch = ErrorOnSwitch;
    proxy->nsaIdToken = NsaIdToken;
    proxy->segments = Segments;
    proxy->switchIfPossible = SwitchIfPossible;
    proxy->syncDisplayName = SyncDisplayName;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    proxy->playerId = PlayerId;
    return proxy;
}
    
void UGSNXConnectRequest::Activate()
{
    GameSparks::Api::Requests::NXConnectRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
    if(accountPerLoginId != false){
        gsRequest.SetAccountPerLoginId(accountPerLoginId);
    }
    if(displayName != ""){
        gsRequest.SetDisplayName(TCHAR_TO_UTF8(*displayName));
    }
    if(doNotLinkToCurrentPlayer != false){
        gsRequest.SetDoNotLinkToCurrentPlayer(doNotLinkToCurrentPlayer);
    }
    if(errorOnSwitch != false){
        gsRequest.SetErrorOnSwitch(errorOnSwitch);
    }
    if(nsaIdToken != ""){
        gsRequest.SetNsaIdToken(TCHAR_TO_UTF8(*nsaIdToken));
    }
    if(segments != nullptr){
        gsRequest.SetSegments(segments->ToRequestData());
    }
    if(switchIfPossible != false){
        gsRequest.SetSwitchIfPossible(switchIfPossible);
    }
    if(syncDisplayName != false){
        gsRequest.SetSyncDisplayName(syncDisplayName);
    }
    if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
        gsRequest.SetDurable(durable);
    }
    
    if(!playerId.IsEmpty())
    {
        gsRequest.SetPlayerId(TCHAR_TO_UTF8(*playerId));
    }

    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
        gsRequest.Send(NXConnectRequestResponseCallback, requestTimeoutSeconds);  
    } else {
        gsRequest.Send(NXConnectRequestResponseCallback);
    }
}

UGSNXConnectRequest::~UGSNXConnectRequest()
{
 if (UGameSparksModule* module = UGameSparksModule::GetModulePtr())
 {
  if (module->IsInitialized())
  {
    module->GetGSInstance().ChangeUserDataForRequests(this, nullptr);
  }
 }
}


void PSNConnectRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::AuthenticationResponse& response){
    
    if(response.GetUserData() == nullptr) {
        return;
    }
    
    FGSAuthenticationResponse unreal_response = FGSAuthenticationResponse(response.GetBaseData());
    
    UGSPSNConnectRequest* g_UGSPSNConnectRequest = static_cast<UGSPSNConnectRequest*>(response.GetUserData());
                               
    if(!g_UGSPSNConnectRequest->OnResponse.IsBound()){
        return;    
    }

    if (response.GetHasErrors())
    {
        g_UGSPSNConnectRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSPSNConnectRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSPSNConnectRequest* UGSPSNConnectRequest::SendPSNConnectRequest(FString AuthorizationCode, bool DoNotLinkToCurrentPlayer, bool ErrorOnSwitch, FString RedirectUri, UGameSparksScriptData* Segments, bool SwitchIfPossible, bool SyncDisplayName,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSPSNConnectRequest* proxy = NewObject<UGSPSNConnectRequest>();
    proxy->authorizationCode = AuthorizationCode;
    proxy->doNotLinkToCurrentPlayer = DoNotLinkToCurrentPlayer;
    proxy->errorOnSwitch = ErrorOnSwitch;
    proxy->redirectUri = RedirectUri;
    proxy->segments = Segments;
    proxy->switchIfPossible = SwitchIfPossible;
    proxy->syncDisplayName = SyncDisplayName;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    return proxy;
}

UGSPSNConnectRequest* UGSPSNConnectRequest::SendPSNConnectRequestOnBehalfOf(const FString& PlayerId, FString AuthorizationCode, bool DoNotLinkToCurrentPlayer, bool ErrorOnSwitch, FString RedirectUri, UGameSparksScriptData* Segments, bool SwitchIfPossible, bool SyncDisplayName,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSPSNConnectRequest* proxy = NewObject<UGSPSNConnectRequest>();
    proxy->authorizationCode = AuthorizationCode;
    proxy->doNotLinkToCurrentPlayer = DoNotLinkToCurrentPlayer;
    proxy->errorOnSwitch = ErrorOnSwitch;
    proxy->redirectUri = RedirectUri;
    proxy->segments = Segments;
    proxy->switchIfPossible = SwitchIfPossible;
    proxy->syncDisplayName = SyncDisplayName;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    proxy->playerId = PlayerId;
    return proxy;
}
    
void UGSPSNConnectRequest::Activate()
{
    GameSparks::Api::Requests::PSNConnectRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
    if(authorizationCode != ""){
        gsRequest.SetAuthorizationCode(TCHAR_TO_UTF8(*authorizationCode));
    }
    if(doNotLinkToCurrentPlayer != false){
        gsRequest.SetDoNotLinkToCurrentPlayer(doNotLinkToCurrentPlayer);
    }
    if(errorOnSwitch != false){
        gsRequest.SetErrorOnSwitch(errorOnSwitch);
    }
    if(redirectUri != ""){
        gsRequest.SetRedirectUri(TCHAR_TO_UTF8(*redirectUri));
    }
    if(segments != nullptr){
        gsRequest.SetSegments(segments->ToRequestData());
    }
    if(switchIfPossible != false){
        gsRequest.SetSwitchIfPossible(switchIfPossible);
    }
    if(syncDisplayName != false){
        gsRequest.SetSyncDisplayName(syncDisplayName);
    }
    if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
        gsRequest.SetDurable(durable);
    }
    
    if(!playerId.IsEmpty())
    {
        gsRequest.SetPlayerId(TCHAR_TO_UTF8(*playerId));
    }

    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
        gsRequest.Send(PSNConnectRequestResponseCallback, requestTimeoutSeconds);  
    } else {
        gsRequest.Send(PSNConnectRequestResponseCallback);
    }
}

UGSPSNConnectRequest::~UGSPSNConnectRequest()
{
 if (UGameSparksModule* module = UGameSparksModule::GetModulePtr())
 {
  if (module->IsInitialized())
  {
    module->GetGSInstance().ChangeUserDataForRequests(this, nullptr);
  }
 }
}


void PsnBuyGoodsRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::BuyVirtualGoodResponse& response){
    
    if(response.GetUserData() == nullptr) {
        return;
    }
    
    FGSBuyVirtualGoodResponse unreal_response = FGSBuyVirtualGoodResponse(response.GetBaseData());
    
    UGSPsnBuyGoodsRequest* g_UGSPsnBuyGoodsRequest = static_cast<UGSPsnBuyGoodsRequest*>(response.GetUserData());
                               
    if(!g_UGSPsnBuyGoodsRequest->OnResponse.IsBound()){
        return;    
    }

    if (response.GetHasErrors())
    {
        g_UGSPsnBuyGoodsRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSPsnBuyGoodsRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSPsnBuyGoodsRequest* UGSPsnBuyGoodsRequest::SendPsnBuyGoodsRequest(FString AuthorizationCode, FString CurrencyCode, FString EntitlementLabel, FString RedirectUri, float SubUnitPrice, bool UniqueTransactionByPlayer, int32 UseCount,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSPsnBuyGoodsRequest* proxy = NewObject<UGSPsnBuyGoodsRequest>();
    proxy->authorizationCode = AuthorizationCode;
    proxy->currencyCode = CurrencyCode;
    proxy->entitlementLabel = EntitlementLabel;
    proxy->redirectUri = RedirectUri;
    proxy->subUnitPrice = SubUnitPrice;
    proxy->uniqueTransactionByPlayer = UniqueTransactionByPlayer;
    proxy->useCount = UseCount;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    return proxy;
}

UGSPsnBuyGoodsRequest* UGSPsnBuyGoodsRequest::SendPsnBuyGoodsRequestOnBehalfOf(const FString& PlayerId, FString AuthorizationCode, FString CurrencyCode, FString EntitlementLabel, FString RedirectUri, float SubUnitPrice, bool UniqueTransactionByPlayer, int32 UseCount,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSPsnBuyGoodsRequest* proxy = NewObject<UGSPsnBuyGoodsRequest>();
    proxy->authorizationCode = AuthorizationCode;
    proxy->currencyCode = CurrencyCode;
    proxy->entitlementLabel = EntitlementLabel;
    proxy->redirectUri = RedirectUri;
    proxy->subUnitPrice = SubUnitPrice;
    proxy->uniqueTransactionByPlayer = UniqueTransactionByPlayer;
    proxy->useCount = UseCount;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    proxy->playerId = PlayerId;
    return proxy;
}
    
void UGSPsnBuyGoodsRequest::Activate()
{
    GameSparks::Api::Requests::PsnBuyGoodsRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
    if(authorizationCode != ""){
        gsRequest.SetAuthorizationCode(TCHAR_TO_UTF8(*authorizationCode));
    }
    if(currencyCode != ""){
        gsRequest.SetCurrencyCode(TCHAR_TO_UTF8(*currencyCode));
    }
    if(entitlementLabel != ""){
        gsRequest.SetEntitlementLabel(TCHAR_TO_UTF8(*entitlementLabel));
    }
    if(redirectUri != ""){
        gsRequest.SetRedirectUri(TCHAR_TO_UTF8(*redirectUri));
    }
    if(subUnitPrice != 0.0f){
        gsRequest.SetSubUnitPrice(subUnitPrice);
    }
    if(uniqueTransactionByPlayer != false){
        gsRequest.SetUniqueTransactionByPlayer(uniqueTransactionByPlayer);
    }
    if(useCount != 0){
        gsRequest.SetUseCount(useCount);
    }
    if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
        gsRequest.SetDurable(durable);
    }
    
    if(!playerId.IsEmpty())
    {
        gsRequest.SetPlayerId(TCHAR_TO_UTF8(*playerId));
    }

    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
        gsRequest.Send(PsnBuyGoodsRequestResponseCallback, requestTimeoutSeconds);  
    } else {
        gsRequest.Send(PsnBuyGoodsRequestResponseCallback);
    }
}

UGSPsnBuyGoodsRequest::~UGSPsnBuyGoodsRequest()
{
 if (UGameSparksModule* module = UGameSparksModule::GetModulePtr())
 {
  if (module->IsInitialized())
  {
    module->GetGSInstance().ChangeUserDataForRequests(this, nullptr);
  }
 }
}


void PushRegistrationRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::PushRegistrationResponse& response){
    
    if(response.GetUserData() == nullptr) {
        return;
    }
    
    FGSPushRegistrationResponse unreal_response = FGSPushRegistrationResponse(response.GetBaseData());
    
    UGSPushRegistrationRequest* g_UGSPushRegistrationRequest = static_cast<UGSPushRegistrationRequest*>(response.GetUserData());
                               
    if(!g_UGSPushRegistrationRequest->OnResponse.IsBound()){
        return;    
    }

    if (response.GetHasErrors())
    {
        g_UGSPushRegistrationRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSPushRegistrationRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSPushRegistrationRequest* UGSPushRegistrationRequest::SendPushRegistrationRequest(FString DeviceOS, FString PushId,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSPushRegistrationRequest* proxy = NewObject<UGSPushRegistrationRequest>();
    proxy->deviceOS = DeviceOS;
    proxy->pushId = PushId;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    return proxy;
}

UGSPushRegistrationRequest* UGSPushRegistrationRequest::SendPushRegistrationRequestOnBehalfOf(const FString& PlayerId, FString DeviceOS, FString PushId,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSPushRegistrationRequest* proxy = NewObject<UGSPushRegistrationRequest>();
    proxy->deviceOS = DeviceOS;
    proxy->pushId = PushId;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    proxy->playerId = PlayerId;
    return proxy;
}
    
void UGSPushRegistrationRequest::Activate()
{
    GameSparks::Api::Requests::PushRegistrationRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
    if(deviceOS != ""){
        gsRequest.SetDeviceOS(TCHAR_TO_UTF8(*deviceOS));
    }
    if(pushId != ""){
        gsRequest.SetPushId(TCHAR_TO_UTF8(*pushId));
    }
    if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
        gsRequest.SetDurable(durable);
    }
    
    if(!playerId.IsEmpty())
    {
        gsRequest.SetPlayerId(TCHAR_TO_UTF8(*playerId));
    }

    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
        gsRequest.Send(PushRegistrationRequestResponseCallback, requestTimeoutSeconds);  
    } else {
        gsRequest.Send(PushRegistrationRequestResponseCallback);
    }
}

UGSPushRegistrationRequest::~UGSPushRegistrationRequest()
{
 if (UGameSparksModule* module = UGameSparksModule::GetModulePtr())
 {
  if (module->IsInitialized())
  {
    module->GetGSInstance().ChangeUserDataForRequests(this, nullptr);
  }
 }
}


void QQConnectRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::AuthenticationResponse& response){
    
    if(response.GetUserData() == nullptr) {
        return;
    }
    
    FGSAuthenticationResponse unreal_response = FGSAuthenticationResponse(response.GetBaseData());
    
    UGSQQConnectRequest* g_UGSQQConnectRequest = static_cast<UGSQQConnectRequest*>(response.GetUserData());
                               
    if(!g_UGSQQConnectRequest->OnResponse.IsBound()){
        return;    
    }

    if (response.GetHasErrors())
    {
        g_UGSQQConnectRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSQQConnectRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSQQConnectRequest* UGSQQConnectRequest::SendQQConnectRequest(FString AccessToken, bool DoNotLinkToCurrentPlayer, bool ErrorOnSwitch, UGameSparksScriptData* Segments, bool SwitchIfPossible, bool SyncDisplayName,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSQQConnectRequest* proxy = NewObject<UGSQQConnectRequest>();
    proxy->accessToken = AccessToken;
    proxy->doNotLinkToCurrentPlayer = DoNotLinkToCurrentPlayer;
    proxy->errorOnSwitch = ErrorOnSwitch;
    proxy->segments = Segments;
    proxy->switchIfPossible = SwitchIfPossible;
    proxy->syncDisplayName = SyncDisplayName;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    return proxy;
}

UGSQQConnectRequest* UGSQQConnectRequest::SendQQConnectRequestOnBehalfOf(const FString& PlayerId, FString AccessToken, bool DoNotLinkToCurrentPlayer, bool ErrorOnSwitch, UGameSparksScriptData* Segments, bool SwitchIfPossible, bool SyncDisplayName,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSQQConnectRequest* proxy = NewObject<UGSQQConnectRequest>();
    proxy->accessToken = AccessToken;
    proxy->doNotLinkToCurrentPlayer = DoNotLinkToCurrentPlayer;
    proxy->errorOnSwitch = ErrorOnSwitch;
    proxy->segments = Segments;
    proxy->switchIfPossible = SwitchIfPossible;
    proxy->syncDisplayName = SyncDisplayName;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    proxy->playerId = PlayerId;
    return proxy;
}
    
void UGSQQConnectRequest::Activate()
{
    GameSparks::Api::Requests::QQConnectRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
    if(accessToken != ""){
        gsRequest.SetAccessToken(TCHAR_TO_UTF8(*accessToken));
    }
    if(doNotLinkToCurrentPlayer != false){
        gsRequest.SetDoNotLinkToCurrentPlayer(doNotLinkToCurrentPlayer);
    }
    if(errorOnSwitch != false){
        gsRequest.SetErrorOnSwitch(errorOnSwitch);
    }
    if(segments != nullptr){
        gsRequest.SetSegments(segments->ToRequestData());
    }
    if(switchIfPossible != false){
        gsRequest.SetSwitchIfPossible(switchIfPossible);
    }
    if(syncDisplayName != false){
        gsRequest.SetSyncDisplayName(syncDisplayName);
    }
    if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
        gsRequest.SetDurable(durable);
    }
    
    if(!playerId.IsEmpty())
    {
        gsRequest.SetPlayerId(TCHAR_TO_UTF8(*playerId));
    }

    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
        gsRequest.Send(QQConnectRequestResponseCallback, requestTimeoutSeconds);  
    } else {
        gsRequest.Send(QQConnectRequestResponseCallback);
    }
}

UGSQQConnectRequest::~UGSQQConnectRequest()
{
 if (UGameSparksModule* module = UGameSparksModule::GetModulePtr())
 {
  if (module->IsInitialized())
  {
    module->GetGSInstance().ChangeUserDataForRequests(this, nullptr);
  }
 }
}


void RegistrationRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::RegistrationResponse& response){
    
    if(response.GetUserData() == nullptr) {
        return;
    }
    
    FGSRegistrationResponse unreal_response = FGSRegistrationResponse(response.GetBaseData());
    
    UGSRegistrationRequest* g_UGSRegistrationRequest = static_cast<UGSRegistrationRequest*>(response.GetUserData());
                               
    if(!g_UGSRegistrationRequest->OnResponse.IsBound()){
        return;    
    }

    if (response.GetHasErrors())
    {
        g_UGSRegistrationRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSRegistrationRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSRegistrationRequest* UGSRegistrationRequest::SendRegistrationRequest(FString DisplayName, FString Password, UGameSparksScriptData* Segments, FString UserName,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSRegistrationRequest* proxy = NewObject<UGSRegistrationRequest>();
    proxy->displayName = DisplayName;
    proxy->password = Password;
    proxy->segments = Segments;
    proxy->userName = UserName;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    return proxy;
}

UGSRegistrationRequest* UGSRegistrationRequest::SendRegistrationRequestOnBehalfOf(const FString& PlayerId, FString DisplayName, FString Password, UGameSparksScriptData* Segments, FString UserName,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSRegistrationRequest* proxy = NewObject<UGSRegistrationRequest>();
    proxy->displayName = DisplayName;
    proxy->password = Password;
    proxy->segments = Segments;
    proxy->userName = UserName;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    proxy->playerId = PlayerId;
    return proxy;
}
    
void UGSRegistrationRequest::Activate()
{
    GameSparks::Api::Requests::RegistrationRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
    if(displayName != ""){
        gsRequest.SetDisplayName(TCHAR_TO_UTF8(*displayName));
    }
    if(password != ""){
        gsRequest.SetPassword(TCHAR_TO_UTF8(*password));
    }
    if(segments != nullptr){
        gsRequest.SetSegments(segments->ToRequestData());
    }
    if(userName != ""){
        gsRequest.SetUserName(TCHAR_TO_UTF8(*userName));
    }
    if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
        gsRequest.SetDurable(durable);
    }
    
    if(!playerId.IsEmpty())
    {
        gsRequest.SetPlayerId(TCHAR_TO_UTF8(*playerId));
    }

    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
        gsRequest.Send(RegistrationRequestResponseCallback, requestTimeoutSeconds);  
    } else {
        gsRequest.Send(RegistrationRequestResponseCallback);
    }
}

UGSRegistrationRequest::~UGSRegistrationRequest()
{
 if (UGameSparksModule* module = UGameSparksModule::GetModulePtr())
 {
  if (module->IsInitialized())
  {
    module->GetGSInstance().ChangeUserDataForRequests(this, nullptr);
  }
 }
}


void RevokePurchaseGoodsRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::RevokePurchaseGoodsResponse& response){
    
    if(response.GetUserData() == nullptr) {
        return;
    }
    
    FGSRevokePurchaseGoodsResponse unreal_response = FGSRevokePurchaseGoodsResponse(response.GetBaseData());
    
    UGSRevokePurchaseGoodsRequest* g_UGSRevokePurchaseGoodsRequest = static_cast<UGSRevokePurchaseGoodsRequest*>(response.GetUserData());
                               
    if(!g_UGSRevokePurchaseGoodsRequest->OnResponse.IsBound()){
        return;    
    }

    if (response.GetHasErrors())
    {
        g_UGSRevokePurchaseGoodsRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSRevokePurchaseGoodsRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSRevokePurchaseGoodsRequest* UGSRevokePurchaseGoodsRequest::SendRevokePurchaseGoodsRequest(FString PlayerId, FString StoreType, UGameSparksRequestArray* TransactionIds,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSRevokePurchaseGoodsRequest* proxy = NewObject<UGSRevokePurchaseGoodsRequest>();
    proxy->playerId = PlayerId;
    proxy->storeType = StoreType;
    proxy->transactionIds = TransactionIds;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    return proxy;
}

UGSRevokePurchaseGoodsRequest* UGSRevokePurchaseGoodsRequest::SendRevokePurchaseGoodsRequestOnBehalfOf(const FString& PlayerId, FString StoreType, UGameSparksRequestArray* TransactionIds,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSRevokePurchaseGoodsRequest* proxy = NewObject<UGSRevokePurchaseGoodsRequest>();
    proxy->playerId = PlayerId;
    proxy->storeType = StoreType;
    proxy->transactionIds = TransactionIds;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    proxy->playerId = PlayerId;
    return proxy;
}
    
void UGSRevokePurchaseGoodsRequest::Activate()
{
    GameSparks::Api::Requests::RevokePurchaseGoodsRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
    if(playerId != ""){
        gsRequest.SetPlayerId(TCHAR_TO_UTF8(*playerId));
    }
    if(storeType != ""){
        gsRequest.SetStoreType(TCHAR_TO_UTF8(*storeType));
    }
    if(transactionIds != nullptr){
        gsstl::vector<gsstl::string> arrTransactionIds;
    
        for(int32 b_arrTransactionIds = 0; b_arrTransactionIds < transactionIds->StringArray.Num(); b_arrTransactionIds++)
        {
            arrTransactionIds.push_back(TCHAR_TO_UTF8(*transactionIds->StringArray[b_arrTransactionIds]));
        }
        
        gsRequest.SetTransactionIds(arrTransactionIds);
    }
    if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
        gsRequest.SetDurable(durable);
    }
    
    if(!playerId.IsEmpty())
    {
        gsRequest.SetPlayerId(TCHAR_TO_UTF8(*playerId));
    }

    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
        gsRequest.Send(RevokePurchaseGoodsRequestResponseCallback, requestTimeoutSeconds);  
    } else {
        gsRequest.Send(RevokePurchaseGoodsRequestResponseCallback);
    }
}

UGSRevokePurchaseGoodsRequest::~UGSRevokePurchaseGoodsRequest()
{
 if (UGameSparksModule* module = UGameSparksModule::GetModulePtr())
 {
  if (module->IsInitialized())
  {
    module->GetGSInstance().ChangeUserDataForRequests(this, nullptr);
  }
 }
}


void ScheduleBulkJobAdminRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::ScheduleBulkJobAdminResponse& response){
    
    if(response.GetUserData() == nullptr) {
        return;
    }
    
    FGSScheduleBulkJobAdminResponse unreal_response = FGSScheduleBulkJobAdminResponse(response.GetBaseData());
    
    UGSScheduleBulkJobAdminRequest* g_UGSScheduleBulkJobAdminRequest = static_cast<UGSScheduleBulkJobAdminRequest*>(response.GetUserData());
                               
    if(!g_UGSScheduleBulkJobAdminRequest->OnResponse.IsBound()){
        return;    
    }

    if (response.GetHasErrors())
    {
        g_UGSScheduleBulkJobAdminRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSScheduleBulkJobAdminRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSScheduleBulkJobAdminRequest* UGSScheduleBulkJobAdminRequest::SendScheduleBulkJobAdminRequest(UGameSparksScriptData* Data, FString ModuleShortCode, UGameSparksScriptData* PlayerQuery, FString ScheduledTime, FString Script,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSScheduleBulkJobAdminRequest* proxy = NewObject<UGSScheduleBulkJobAdminRequest>();
    proxy->data = Data;
    proxy->moduleShortCode = ModuleShortCode;
    proxy->playerQuery = PlayerQuery;
    proxy->scheduledTime = ScheduledTime;
    proxy->script = Script;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    return proxy;
}

UGSScheduleBulkJobAdminRequest* UGSScheduleBulkJobAdminRequest::SendScheduleBulkJobAdminRequestOnBehalfOf(const FString& PlayerId, UGameSparksScriptData* Data, FString ModuleShortCode, UGameSparksScriptData* PlayerQuery, FString ScheduledTime, FString Script,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSScheduleBulkJobAdminRequest* proxy = NewObject<UGSScheduleBulkJobAdminRequest>();
    proxy->data = Data;
    proxy->moduleShortCode = ModuleShortCode;
    proxy->playerQuery = PlayerQuery;
    proxy->scheduledTime = ScheduledTime;
    proxy->script = Script;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    proxy->playerId = PlayerId;
    return proxy;
}
    
void UGSScheduleBulkJobAdminRequest::Activate()
{
    GameSparks::Api::Requests::ScheduleBulkJobAdminRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
    if(data != nullptr){
        gsRequest.SetData(data->ToRequestData());
    }
    if(moduleShortCode != ""){
        gsRequest.SetModuleShortCode(TCHAR_TO_UTF8(*moduleShortCode));
    }
    if(playerQuery != nullptr){
        gsRequest.SetPlayerQuery(playerQuery->ToRequestData());
    }
    if(scheduledTime != ""){
        gsRequest.SetScheduledTime(GameSparks::Core::GSDateTime(TCHAR_TO_UTF8(*scheduledTime)));
    }
    if(script != ""){
        gsRequest.SetScript(TCHAR_TO_UTF8(*script));
    }
    if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
        gsRequest.SetDurable(durable);
    }
    
    if(!playerId.IsEmpty())
    {
        gsRequest.SetPlayerId(TCHAR_TO_UTF8(*playerId));
    }

    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
        gsRequest.Send(ScheduleBulkJobAdminRequestResponseCallback, requestTimeoutSeconds);  
    } else {
        gsRequest.Send(ScheduleBulkJobAdminRequestResponseCallback);
    }
}

UGSScheduleBulkJobAdminRequest::~UGSScheduleBulkJobAdminRequest()
{
 if (UGameSparksModule* module = UGameSparksModule::GetModulePtr())
 {
  if (module->IsInitialized())
  {
    module->GetGSInstance().ChangeUserDataForRequests(this, nullptr);
  }
 }
}


void SendFriendMessageRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::SendFriendMessageResponse& response){
    
    if(response.GetUserData() == nullptr) {
        return;
    }
    
    FGSSendFriendMessageResponse unreal_response = FGSSendFriendMessageResponse(response.GetBaseData());
    
    UGSSendFriendMessageRequest* g_UGSSendFriendMessageRequest = static_cast<UGSSendFriendMessageRequest*>(response.GetUserData());
                               
    if(!g_UGSSendFriendMessageRequest->OnResponse.IsBound()){
        return;    
    }

    if (response.GetHasErrors())
    {
        g_UGSSendFriendMessageRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSSendFriendMessageRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSSendFriendMessageRequest* UGSSendFriendMessageRequest::SendSendFriendMessageRequest(UGameSparksRequestArray* FriendIds, FString Message,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSSendFriendMessageRequest* proxy = NewObject<UGSSendFriendMessageRequest>();
    proxy->friendIds = FriendIds;
    proxy->message = Message;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    return proxy;
}

UGSSendFriendMessageRequest* UGSSendFriendMessageRequest::SendSendFriendMessageRequestOnBehalfOf(const FString& PlayerId, UGameSparksRequestArray* FriendIds, FString Message,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSSendFriendMessageRequest* proxy = NewObject<UGSSendFriendMessageRequest>();
    proxy->friendIds = FriendIds;
    proxy->message = Message;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    proxy->playerId = PlayerId;
    return proxy;
}
    
void UGSSendFriendMessageRequest::Activate()
{
    GameSparks::Api::Requests::SendFriendMessageRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
    if(friendIds != nullptr){
        gsstl::vector<gsstl::string> arrFriendIds;
    
        for(int32 b_arrFriendIds = 0; b_arrFriendIds < friendIds->StringArray.Num(); b_arrFriendIds++)
        {
            arrFriendIds.push_back(TCHAR_TO_UTF8(*friendIds->StringArray[b_arrFriendIds]));
        }
        
        gsRequest.SetFriendIds(arrFriendIds);
    }
    if(message != ""){
        gsRequest.SetMessage(TCHAR_TO_UTF8(*message));
    }
    if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
        gsRequest.SetDurable(durable);
    }
    
    if(!playerId.IsEmpty())
    {
        gsRequest.SetPlayerId(TCHAR_TO_UTF8(*playerId));
    }

    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
        gsRequest.Send(SendFriendMessageRequestResponseCallback, requestTimeoutSeconds);  
    } else {
        gsRequest.Send(SendFriendMessageRequestResponseCallback);
    }
}

UGSSendFriendMessageRequest::~UGSSendFriendMessageRequest()
{
 if (UGameSparksModule* module = UGameSparksModule::GetModulePtr())
 {
  if (module->IsInitialized())
  {
    module->GetGSInstance().ChangeUserDataForRequests(this, nullptr);
  }
 }
}


void SendTeamChatMessageRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::SendTeamChatMessageResponse& response){
    
    if(response.GetUserData() == nullptr) {
        return;
    }
    
    FGSSendTeamChatMessageResponse unreal_response = FGSSendTeamChatMessageResponse(response.GetBaseData());
    
    UGSSendTeamChatMessageRequest* g_UGSSendTeamChatMessageRequest = static_cast<UGSSendTeamChatMessageRequest*>(response.GetUserData());
                               
    if(!g_UGSSendTeamChatMessageRequest->OnResponse.IsBound()){
        return;    
    }

    if (response.GetHasErrors())
    {
        g_UGSSendTeamChatMessageRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSSendTeamChatMessageRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSSendTeamChatMessageRequest* UGSSendTeamChatMessageRequest::SendSendTeamChatMessageRequest(FString Message, FString OwnerId, FString TeamId, FString TeamType,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSSendTeamChatMessageRequest* proxy = NewObject<UGSSendTeamChatMessageRequest>();
    proxy->message = Message;
    proxy->ownerId = OwnerId;
    proxy->teamId = TeamId;
    proxy->teamType = TeamType;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    return proxy;
}

UGSSendTeamChatMessageRequest* UGSSendTeamChatMessageRequest::SendSendTeamChatMessageRequestOnBehalfOf(const FString& PlayerId, FString Message, FString OwnerId, FString TeamId, FString TeamType,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSSendTeamChatMessageRequest* proxy = NewObject<UGSSendTeamChatMessageRequest>();
    proxy->message = Message;
    proxy->ownerId = OwnerId;
    proxy->teamId = TeamId;
    proxy->teamType = TeamType;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    proxy->playerId = PlayerId;
    return proxy;
}
    
void UGSSendTeamChatMessageRequest::Activate()
{
    GameSparks::Api::Requests::SendTeamChatMessageRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
    if(message != ""){
        gsRequest.SetMessage(TCHAR_TO_UTF8(*message));
    }
    if(ownerId != ""){
        gsRequest.SetOwnerId(TCHAR_TO_UTF8(*ownerId));
    }
    if(teamId != ""){
        gsRequest.SetTeamId(TCHAR_TO_UTF8(*teamId));
    }
    if(teamType != ""){
        gsRequest.SetTeamType(TCHAR_TO_UTF8(*teamType));
    }
    if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
        gsRequest.SetDurable(durable);
    }
    
    if(!playerId.IsEmpty())
    {
        gsRequest.SetPlayerId(TCHAR_TO_UTF8(*playerId));
    }

    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
        gsRequest.Send(SendTeamChatMessageRequestResponseCallback, requestTimeoutSeconds);  
    } else {
        gsRequest.Send(SendTeamChatMessageRequestResponseCallback);
    }
}

UGSSendTeamChatMessageRequest::~UGSSendTeamChatMessageRequest()
{
 if (UGameSparksModule* module = UGameSparksModule::GetModulePtr())
 {
  if (module->IsInitialized())
  {
    module->GetGSInstance().ChangeUserDataForRequests(this, nullptr);
  }
 }
}


void SocialDisconnectRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::SocialDisconnectResponse& response){
    
    if(response.GetUserData() == nullptr) {
        return;
    }
    
    FGSSocialDisconnectResponse unreal_response = FGSSocialDisconnectResponse(response.GetBaseData());
    
    UGSSocialDisconnectRequest* g_UGSSocialDisconnectRequest = static_cast<UGSSocialDisconnectRequest*>(response.GetUserData());
                               
    if(!g_UGSSocialDisconnectRequest->OnResponse.IsBound()){
        return;    
    }

    if (response.GetHasErrors())
    {
        g_UGSSocialDisconnectRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSSocialDisconnectRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSSocialDisconnectRequest* UGSSocialDisconnectRequest::SendSocialDisconnectRequest(FString SystemId,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSSocialDisconnectRequest* proxy = NewObject<UGSSocialDisconnectRequest>();
    proxy->systemId = SystemId;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    return proxy;
}

UGSSocialDisconnectRequest* UGSSocialDisconnectRequest::SendSocialDisconnectRequestOnBehalfOf(const FString& PlayerId, FString SystemId,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSSocialDisconnectRequest* proxy = NewObject<UGSSocialDisconnectRequest>();
    proxy->systemId = SystemId;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    proxy->playerId = PlayerId;
    return proxy;
}
    
void UGSSocialDisconnectRequest::Activate()
{
    GameSparks::Api::Requests::SocialDisconnectRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
    if(systemId != ""){
        gsRequest.SetSystemId(TCHAR_TO_UTF8(*systemId));
    }
    if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
        gsRequest.SetDurable(durable);
    }
    
    if(!playerId.IsEmpty())
    {
        gsRequest.SetPlayerId(TCHAR_TO_UTF8(*playerId));
    }

    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
        gsRequest.Send(SocialDisconnectRequestResponseCallback, requestTimeoutSeconds);  
    } else {
        gsRequest.Send(SocialDisconnectRequestResponseCallback);
    }
}

UGSSocialDisconnectRequest::~UGSSocialDisconnectRequest()
{
 if (UGameSparksModule* module = UGameSparksModule::GetModulePtr())
 {
  if (module->IsInitialized())
  {
    module->GetGSInstance().ChangeUserDataForRequests(this, nullptr);
  }
 }
}


void SocialLeaderboardDataRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::LeaderboardDataResponse& response){
    
    if(response.GetUserData() == nullptr) {
        return;
    }
    
    FGSLeaderboardDataResponse unreal_response = FGSLeaderboardDataResponse(response.GetBaseData());
    
    UGSSocialLeaderboardDataRequest* g_UGSSocialLeaderboardDataRequest = static_cast<UGSSocialLeaderboardDataRequest*>(response.GetUserData());
                               
    if(!g_UGSSocialLeaderboardDataRequest->OnResponse.IsBound()){
        return;    
    }

    if (response.GetHasErrors())
    {
        g_UGSSocialLeaderboardDataRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSSocialLeaderboardDataRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSSocialLeaderboardDataRequest* UGSSocialLeaderboardDataRequest::SendSocialLeaderboardDataRequest(FString ChallengeInstanceId, bool DontErrorOnNotSocial, int32 EntryCount, UGameSparksRequestArray* FriendIds, int32 IncludeFirst, int32 IncludeLast, bool InverseSocial, FString LeaderboardShortCode, int32 Offset, bool Social, UGameSparksRequestArray* TeamIds, UGameSparksRequestArray* TeamTypes,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSSocialLeaderboardDataRequest* proxy = NewObject<UGSSocialLeaderboardDataRequest>();
    proxy->challengeInstanceId = ChallengeInstanceId;
    proxy->dontErrorOnNotSocial = DontErrorOnNotSocial;
    proxy->entryCount = EntryCount;
    proxy->friendIds = FriendIds;
    proxy->includeFirst = IncludeFirst;
    proxy->includeLast = IncludeLast;
    proxy->inverseSocial = InverseSocial;
    proxy->leaderboardShortCode = LeaderboardShortCode;
    proxy->offset = Offset;
    proxy->social = Social;
    proxy->teamIds = TeamIds;
    proxy->teamTypes = TeamTypes;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    return proxy;
}

UGSSocialLeaderboardDataRequest* UGSSocialLeaderboardDataRequest::SendSocialLeaderboardDataRequestOnBehalfOf(const FString& PlayerId, FString ChallengeInstanceId, bool DontErrorOnNotSocial, int32 EntryCount, UGameSparksRequestArray* FriendIds, int32 IncludeFirst, int32 IncludeLast, bool InverseSocial, FString LeaderboardShortCode, int32 Offset, bool Social, UGameSparksRequestArray* TeamIds, UGameSparksRequestArray* TeamTypes,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSSocialLeaderboardDataRequest* proxy = NewObject<UGSSocialLeaderboardDataRequest>();
    proxy->challengeInstanceId = ChallengeInstanceId;
    proxy->dontErrorOnNotSocial = DontErrorOnNotSocial;
    proxy->entryCount = EntryCount;
    proxy->friendIds = FriendIds;
    proxy->includeFirst = IncludeFirst;
    proxy->includeLast = IncludeLast;
    proxy->inverseSocial = InverseSocial;
    proxy->leaderboardShortCode = LeaderboardShortCode;
    proxy->offset = Offset;
    proxy->social = Social;
    proxy->teamIds = TeamIds;
    proxy->teamTypes = TeamTypes;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    proxy->playerId = PlayerId;
    return proxy;
}
    
void UGSSocialLeaderboardDataRequest::Activate()
{
    GameSparks::Api::Requests::SocialLeaderboardDataRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
    if(challengeInstanceId != ""){
        gsRequest.SetChallengeInstanceId(TCHAR_TO_UTF8(*challengeInstanceId));
    }
    if(dontErrorOnNotSocial != false){
        gsRequest.SetDontErrorOnNotSocial(dontErrorOnNotSocial);
    }
    if(entryCount != 0){
        gsRequest.SetEntryCount(entryCount);
    }
    if(friendIds != nullptr){
        gsstl::vector<gsstl::string> arrFriendIds;
    
        for(int32 b_arrFriendIds = 0; b_arrFriendIds < friendIds->StringArray.Num(); b_arrFriendIds++)
        {
            arrFriendIds.push_back(TCHAR_TO_UTF8(*friendIds->StringArray[b_arrFriendIds]));
        }
        
        gsRequest.SetFriendIds(arrFriendIds);
    }
    if(includeFirst != 0){
        gsRequest.SetIncludeFirst(includeFirst);
    }
    if(includeLast != 0){
        gsRequest.SetIncludeLast(includeLast);
    }
    if(inverseSocial != false){
        gsRequest.SetInverseSocial(inverseSocial);
    }
    if(leaderboardShortCode != ""){
        gsRequest.SetLeaderboardShortCode(TCHAR_TO_UTF8(*leaderboardShortCode));
    }
    if(offset != 0){
        gsRequest.SetOffset(offset);
    }
    if(social != false){
        gsRequest.SetSocial(social);
    }
    if(teamIds != nullptr){
        gsstl::vector<gsstl::string> arrTeamIds;
    
        for(int32 b_arrTeamIds = 0; b_arrTeamIds < teamIds->StringArray.Num(); b_arrTeamIds++)
        {
            arrTeamIds.push_back(TCHAR_TO_UTF8(*teamIds->StringArray[b_arrTeamIds]));
        }
        
        gsRequest.SetTeamIds(arrTeamIds);
    }
    if(teamTypes != nullptr){
        gsstl::vector<gsstl::string> arrTeamTypes;
    
        for(int32 b_arrTeamTypes = 0; b_arrTeamTypes < teamTypes->StringArray.Num(); b_arrTeamTypes++)
        {
            arrTeamTypes.push_back(TCHAR_TO_UTF8(*teamTypes->StringArray[b_arrTeamTypes]));
        }
        
        gsRequest.SetTeamTypes(arrTeamTypes);
    }
    if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
        gsRequest.SetDurable(durable);
    }
    
    if(!playerId.IsEmpty())
    {
        gsRequest.SetPlayerId(TCHAR_TO_UTF8(*playerId));
    }

    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
        gsRequest.Send(SocialLeaderboardDataRequestResponseCallback, requestTimeoutSeconds);  
    } else {
        gsRequest.Send(SocialLeaderboardDataRequestResponseCallback);
    }
}

UGSSocialLeaderboardDataRequest::~UGSSocialLeaderboardDataRequest()
{
 if (UGameSparksModule* module = UGameSparksModule::GetModulePtr())
 {
  if (module->IsInitialized())
  {
    module->GetGSInstance().ChangeUserDataForRequests(this, nullptr);
  }
 }
}


void SocialStatusRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::SocialStatusResponse& response){
    
    if(response.GetUserData() == nullptr) {
        return;
    }
    
    FGSSocialStatusResponse unreal_response = FGSSocialStatusResponse(response.GetBaseData());
    
    UGSSocialStatusRequest* g_UGSSocialStatusRequest = static_cast<UGSSocialStatusRequest*>(response.GetUserData());
                               
    if(!g_UGSSocialStatusRequest->OnResponse.IsBound()){
        return;    
    }

    if (response.GetHasErrors())
    {
        g_UGSSocialStatusRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSSocialStatusRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSSocialStatusRequest* UGSSocialStatusRequest::SendSocialStatusRequest( UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSSocialStatusRequest* proxy = NewObject<UGSSocialStatusRequest>();
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    return proxy;
}

UGSSocialStatusRequest* UGSSocialStatusRequest::SendSocialStatusRequestOnBehalfOf(const FString& PlayerId,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSSocialStatusRequest* proxy = NewObject<UGSSocialStatusRequest>();
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    proxy->playerId = PlayerId;
    return proxy;
}
    
void UGSSocialStatusRequest::Activate()
{
    GameSparks::Api::Requests::SocialStatusRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
    if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
        gsRequest.SetDurable(durable);
    }
    
    if(!playerId.IsEmpty())
    {
        gsRequest.SetPlayerId(TCHAR_TO_UTF8(*playerId));
    }

    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
        gsRequest.Send(SocialStatusRequestResponseCallback, requestTimeoutSeconds);  
    } else {
        gsRequest.Send(SocialStatusRequestResponseCallback);
    }
}

UGSSocialStatusRequest::~UGSSocialStatusRequest()
{
 if (UGameSparksModule* module = UGameSparksModule::GetModulePtr())
 {
  if (module->IsInitialized())
  {
    module->GetGSInstance().ChangeUserDataForRequests(this, nullptr);
  }
 }
}


void SteamBuyGoodsRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::BuyVirtualGoodResponse& response){
    
    if(response.GetUserData() == nullptr) {
        return;
    }
    
    FGSBuyVirtualGoodResponse unreal_response = FGSBuyVirtualGoodResponse(response.GetBaseData());
    
    UGSSteamBuyGoodsRequest* g_UGSSteamBuyGoodsRequest = static_cast<UGSSteamBuyGoodsRequest*>(response.GetUserData());
                               
    if(!g_UGSSteamBuyGoodsRequest->OnResponse.IsBound()){
        return;    
    }

    if (response.GetHasErrors())
    {
        g_UGSSteamBuyGoodsRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSSteamBuyGoodsRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSSteamBuyGoodsRequest* UGSSteamBuyGoodsRequest::SendSteamBuyGoodsRequest(FString CurrencyCode, FString OrderId, float SubUnitPrice, bool UniqueTransactionByPlayer,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSSteamBuyGoodsRequest* proxy = NewObject<UGSSteamBuyGoodsRequest>();
    proxy->currencyCode = CurrencyCode;
    proxy->orderId = OrderId;
    proxy->subUnitPrice = SubUnitPrice;
    proxy->uniqueTransactionByPlayer = UniqueTransactionByPlayer;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    return proxy;
}

UGSSteamBuyGoodsRequest* UGSSteamBuyGoodsRequest::SendSteamBuyGoodsRequestOnBehalfOf(const FString& PlayerId, FString CurrencyCode, FString OrderId, float SubUnitPrice, bool UniqueTransactionByPlayer,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSSteamBuyGoodsRequest* proxy = NewObject<UGSSteamBuyGoodsRequest>();
    proxy->currencyCode = CurrencyCode;
    proxy->orderId = OrderId;
    proxy->subUnitPrice = SubUnitPrice;
    proxy->uniqueTransactionByPlayer = UniqueTransactionByPlayer;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    proxy->playerId = PlayerId;
    return proxy;
}
    
void UGSSteamBuyGoodsRequest::Activate()
{
    GameSparks::Api::Requests::SteamBuyGoodsRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
    if(currencyCode != ""){
        gsRequest.SetCurrencyCode(TCHAR_TO_UTF8(*currencyCode));
    }
    if(orderId != ""){
        gsRequest.SetOrderId(TCHAR_TO_UTF8(*orderId));
    }
    if(subUnitPrice != 0.0f){
        gsRequest.SetSubUnitPrice(subUnitPrice);
    }
    if(uniqueTransactionByPlayer != false){
        gsRequest.SetUniqueTransactionByPlayer(uniqueTransactionByPlayer);
    }
    if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
        gsRequest.SetDurable(durable);
    }
    
    if(!playerId.IsEmpty())
    {
        gsRequest.SetPlayerId(TCHAR_TO_UTF8(*playerId));
    }

    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
        gsRequest.Send(SteamBuyGoodsRequestResponseCallback, requestTimeoutSeconds);  
    } else {
        gsRequest.Send(SteamBuyGoodsRequestResponseCallback);
    }
}

UGSSteamBuyGoodsRequest::~UGSSteamBuyGoodsRequest()
{
 if (UGameSparksModule* module = UGameSparksModule::GetModulePtr())
 {
  if (module->IsInitialized())
  {
    module->GetGSInstance().ChangeUserDataForRequests(this, nullptr);
  }
 }
}


void SteamConnectRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::AuthenticationResponse& response){
    
    if(response.GetUserData() == nullptr) {
        return;
    }
    
    FGSAuthenticationResponse unreal_response = FGSAuthenticationResponse(response.GetBaseData());
    
    UGSSteamConnectRequest* g_UGSSteamConnectRequest = static_cast<UGSSteamConnectRequest*>(response.GetUserData());
                               
    if(!g_UGSSteamConnectRequest->OnResponse.IsBound()){
        return;    
    }

    if (response.GetHasErrors())
    {
        g_UGSSteamConnectRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSSteamConnectRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSSteamConnectRequest* UGSSteamConnectRequest::SendSteamConnectRequest(bool DoNotLinkToCurrentPlayer, bool ErrorOnSwitch, UGameSparksScriptData* Segments, FString SessionTicket, bool SwitchIfPossible, bool SyncDisplayName,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSSteamConnectRequest* proxy = NewObject<UGSSteamConnectRequest>();
    proxy->doNotLinkToCurrentPlayer = DoNotLinkToCurrentPlayer;
    proxy->errorOnSwitch = ErrorOnSwitch;
    proxy->segments = Segments;
    proxy->sessionTicket = SessionTicket;
    proxy->switchIfPossible = SwitchIfPossible;
    proxy->syncDisplayName = SyncDisplayName;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    return proxy;
}

UGSSteamConnectRequest* UGSSteamConnectRequest::SendSteamConnectRequestOnBehalfOf(const FString& PlayerId, bool DoNotLinkToCurrentPlayer, bool ErrorOnSwitch, UGameSparksScriptData* Segments, FString SessionTicket, bool SwitchIfPossible, bool SyncDisplayName,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSSteamConnectRequest* proxy = NewObject<UGSSteamConnectRequest>();
    proxy->doNotLinkToCurrentPlayer = DoNotLinkToCurrentPlayer;
    proxy->errorOnSwitch = ErrorOnSwitch;
    proxy->segments = Segments;
    proxy->sessionTicket = SessionTicket;
    proxy->switchIfPossible = SwitchIfPossible;
    proxy->syncDisplayName = SyncDisplayName;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    proxy->playerId = PlayerId;
    return proxy;
}
    
void UGSSteamConnectRequest::Activate()
{
    GameSparks::Api::Requests::SteamConnectRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
    if(doNotLinkToCurrentPlayer != false){
        gsRequest.SetDoNotLinkToCurrentPlayer(doNotLinkToCurrentPlayer);
    }
    if(errorOnSwitch != false){
        gsRequest.SetErrorOnSwitch(errorOnSwitch);
    }
    if(segments != nullptr){
        gsRequest.SetSegments(segments->ToRequestData());
    }
    if(sessionTicket != ""){
        gsRequest.SetSessionTicket(TCHAR_TO_UTF8(*sessionTicket));
    }
    if(switchIfPossible != false){
        gsRequest.SetSwitchIfPossible(switchIfPossible);
    }
    if(syncDisplayName != false){
        gsRequest.SetSyncDisplayName(syncDisplayName);
    }
    if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
        gsRequest.SetDurable(durable);
    }
    
    if(!playerId.IsEmpty())
    {
        gsRequest.SetPlayerId(TCHAR_TO_UTF8(*playerId));
    }

    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
        gsRequest.Send(SteamConnectRequestResponseCallback, requestTimeoutSeconds);  
    } else {
        gsRequest.Send(SteamConnectRequestResponseCallback);
    }
}

UGSSteamConnectRequest::~UGSSteamConnectRequest()
{
 if (UGameSparksModule* module = UGameSparksModule::GetModulePtr())
 {
  if (module->IsInitialized())
  {
    module->GetGSInstance().ChangeUserDataForRequests(this, nullptr);
  }
 }
}


void TwitchConnectRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::AuthenticationResponse& response){
    
    if(response.GetUserData() == nullptr) {
        return;
    }
    
    FGSAuthenticationResponse unreal_response = FGSAuthenticationResponse(response.GetBaseData());
    
    UGSTwitchConnectRequest* g_UGSTwitchConnectRequest = static_cast<UGSTwitchConnectRequest*>(response.GetUserData());
                               
    if(!g_UGSTwitchConnectRequest->OnResponse.IsBound()){
        return;    
    }

    if (response.GetHasErrors())
    {
        g_UGSTwitchConnectRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSTwitchConnectRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSTwitchConnectRequest* UGSTwitchConnectRequest::SendTwitchConnectRequest(FString AccessToken, bool DoNotLinkToCurrentPlayer, bool ErrorOnSwitch, UGameSparksScriptData* Segments, bool SwitchIfPossible, bool SyncDisplayName,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSTwitchConnectRequest* proxy = NewObject<UGSTwitchConnectRequest>();
    proxy->accessToken = AccessToken;
    proxy->doNotLinkToCurrentPlayer = DoNotLinkToCurrentPlayer;
    proxy->errorOnSwitch = ErrorOnSwitch;
    proxy->segments = Segments;
    proxy->switchIfPossible = SwitchIfPossible;
    proxy->syncDisplayName = SyncDisplayName;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    return proxy;
}

UGSTwitchConnectRequest* UGSTwitchConnectRequest::SendTwitchConnectRequestOnBehalfOf(const FString& PlayerId, FString AccessToken, bool DoNotLinkToCurrentPlayer, bool ErrorOnSwitch, UGameSparksScriptData* Segments, bool SwitchIfPossible, bool SyncDisplayName,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSTwitchConnectRequest* proxy = NewObject<UGSTwitchConnectRequest>();
    proxy->accessToken = AccessToken;
    proxy->doNotLinkToCurrentPlayer = DoNotLinkToCurrentPlayer;
    proxy->errorOnSwitch = ErrorOnSwitch;
    proxy->segments = Segments;
    proxy->switchIfPossible = SwitchIfPossible;
    proxy->syncDisplayName = SyncDisplayName;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    proxy->playerId = PlayerId;
    return proxy;
}
    
void UGSTwitchConnectRequest::Activate()
{
    GameSparks::Api::Requests::TwitchConnectRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
    if(accessToken != ""){
        gsRequest.SetAccessToken(TCHAR_TO_UTF8(*accessToken));
    }
    if(doNotLinkToCurrentPlayer != false){
        gsRequest.SetDoNotLinkToCurrentPlayer(doNotLinkToCurrentPlayer);
    }
    if(errorOnSwitch != false){
        gsRequest.SetErrorOnSwitch(errorOnSwitch);
    }
    if(segments != nullptr){
        gsRequest.SetSegments(segments->ToRequestData());
    }
    if(switchIfPossible != false){
        gsRequest.SetSwitchIfPossible(switchIfPossible);
    }
    if(syncDisplayName != false){
        gsRequest.SetSyncDisplayName(syncDisplayName);
    }
    if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
        gsRequest.SetDurable(durable);
    }
    
    if(!playerId.IsEmpty())
    {
        gsRequest.SetPlayerId(TCHAR_TO_UTF8(*playerId));
    }

    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
        gsRequest.Send(TwitchConnectRequestResponseCallback, requestTimeoutSeconds);  
    } else {
        gsRequest.Send(TwitchConnectRequestResponseCallback);
    }
}

UGSTwitchConnectRequest::~UGSTwitchConnectRequest()
{
 if (UGameSparksModule* module = UGameSparksModule::GetModulePtr())
 {
  if (module->IsInitialized())
  {
    module->GetGSInstance().ChangeUserDataForRequests(this, nullptr);
  }
 }
}


void TwitterConnectRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::AuthenticationResponse& response){
    
    if(response.GetUserData() == nullptr) {
        return;
    }
    
    FGSAuthenticationResponse unreal_response = FGSAuthenticationResponse(response.GetBaseData());
    
    UGSTwitterConnectRequest* g_UGSTwitterConnectRequest = static_cast<UGSTwitterConnectRequest*>(response.GetUserData());
                               
    if(!g_UGSTwitterConnectRequest->OnResponse.IsBound()){
        return;    
    }

    if (response.GetHasErrors())
    {
        g_UGSTwitterConnectRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSTwitterConnectRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSTwitterConnectRequest* UGSTwitterConnectRequest::SendTwitterConnectRequest(FString AccessSecret, FString AccessToken, bool DoNotLinkToCurrentPlayer, bool ErrorOnSwitch, UGameSparksScriptData* Segments, bool SwitchIfPossible, bool SyncDisplayName,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSTwitterConnectRequest* proxy = NewObject<UGSTwitterConnectRequest>();
    proxy->accessSecret = AccessSecret;
    proxy->accessToken = AccessToken;
    proxy->doNotLinkToCurrentPlayer = DoNotLinkToCurrentPlayer;
    proxy->errorOnSwitch = ErrorOnSwitch;
    proxy->segments = Segments;
    proxy->switchIfPossible = SwitchIfPossible;
    proxy->syncDisplayName = SyncDisplayName;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    return proxy;
}

UGSTwitterConnectRequest* UGSTwitterConnectRequest::SendTwitterConnectRequestOnBehalfOf(const FString& PlayerId, FString AccessSecret, FString AccessToken, bool DoNotLinkToCurrentPlayer, bool ErrorOnSwitch, UGameSparksScriptData* Segments, bool SwitchIfPossible, bool SyncDisplayName,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSTwitterConnectRequest* proxy = NewObject<UGSTwitterConnectRequest>();
    proxy->accessSecret = AccessSecret;
    proxy->accessToken = AccessToken;
    proxy->doNotLinkToCurrentPlayer = DoNotLinkToCurrentPlayer;
    proxy->errorOnSwitch = ErrorOnSwitch;
    proxy->segments = Segments;
    proxy->switchIfPossible = SwitchIfPossible;
    proxy->syncDisplayName = SyncDisplayName;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    proxy->playerId = PlayerId;
    return proxy;
}
    
void UGSTwitterConnectRequest::Activate()
{
    GameSparks::Api::Requests::TwitterConnectRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
    if(accessSecret != ""){
        gsRequest.SetAccessSecret(TCHAR_TO_UTF8(*accessSecret));
    }
    if(accessToken != ""){
        gsRequest.SetAccessToken(TCHAR_TO_UTF8(*accessToken));
    }
    if(doNotLinkToCurrentPlayer != false){
        gsRequest.SetDoNotLinkToCurrentPlayer(doNotLinkToCurrentPlayer);
    }
    if(errorOnSwitch != false){
        gsRequest.SetErrorOnSwitch(errorOnSwitch);
    }
    if(segments != nullptr){
        gsRequest.SetSegments(segments->ToRequestData());
    }
    if(switchIfPossible != false){
        gsRequest.SetSwitchIfPossible(switchIfPossible);
    }
    if(syncDisplayName != false){
        gsRequest.SetSyncDisplayName(syncDisplayName);
    }
    if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
        gsRequest.SetDurable(durable);
    }
    
    if(!playerId.IsEmpty())
    {
        gsRequest.SetPlayerId(TCHAR_TO_UTF8(*playerId));
    }

    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
        gsRequest.Send(TwitterConnectRequestResponseCallback, requestTimeoutSeconds);  
    } else {
        gsRequest.Send(TwitterConnectRequestResponseCallback);
    }
}

UGSTwitterConnectRequest::~UGSTwitterConnectRequest()
{
 if (UGameSparksModule* module = UGameSparksModule::GetModulePtr())
 {
  if (module->IsInitialized())
  {
    module->GetGSInstance().ChangeUserDataForRequests(this, nullptr);
  }
 }
}


void UpdateMessageRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::UpdateMessageResponse& response){
    
    if(response.GetUserData() == nullptr) {
        return;
    }
    
    FGSUpdateMessageResponse unreal_response = FGSUpdateMessageResponse(response.GetBaseData());
    
    UGSUpdateMessageRequest* g_UGSUpdateMessageRequest = static_cast<UGSUpdateMessageRequest*>(response.GetUserData());
                               
    if(!g_UGSUpdateMessageRequest->OnResponse.IsBound()){
        return;    
    }

    if (response.GetHasErrors())
    {
        g_UGSUpdateMessageRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSUpdateMessageRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSUpdateMessageRequest* UGSUpdateMessageRequest::SendUpdateMessageRequest(FString MessageId, FString Status,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSUpdateMessageRequest* proxy = NewObject<UGSUpdateMessageRequest>();
    proxy->messageId = MessageId;
    proxy->status = Status;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    return proxy;
}

UGSUpdateMessageRequest* UGSUpdateMessageRequest::SendUpdateMessageRequestOnBehalfOf(const FString& PlayerId, FString MessageId, FString Status,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSUpdateMessageRequest* proxy = NewObject<UGSUpdateMessageRequest>();
    proxy->messageId = MessageId;
    proxy->status = Status;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    proxy->playerId = PlayerId;
    return proxy;
}
    
void UGSUpdateMessageRequest::Activate()
{
    GameSparks::Api::Requests::UpdateMessageRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
    if(messageId != ""){
        gsRequest.SetMessageId(TCHAR_TO_UTF8(*messageId));
    }
    if(status != ""){
        gsRequest.SetStatus(TCHAR_TO_UTF8(*status));
    }
    if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
        gsRequest.SetDurable(durable);
    }
    
    if(!playerId.IsEmpty())
    {
        gsRequest.SetPlayerId(TCHAR_TO_UTF8(*playerId));
    }

    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
        gsRequest.Send(UpdateMessageRequestResponseCallback, requestTimeoutSeconds);  
    } else {
        gsRequest.Send(UpdateMessageRequestResponseCallback);
    }
}

UGSUpdateMessageRequest::~UGSUpdateMessageRequest()
{
 if (UGameSparksModule* module = UGameSparksModule::GetModulePtr())
 {
  if (module->IsInitialized())
  {
    module->GetGSInstance().ChangeUserDataForRequests(this, nullptr);
  }
 }
}


void ViberConnectRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::AuthenticationResponse& response){
    
    if(response.GetUserData() == nullptr) {
        return;
    }
    
    FGSAuthenticationResponse unreal_response = FGSAuthenticationResponse(response.GetBaseData());
    
    UGSViberConnectRequest* g_UGSViberConnectRequest = static_cast<UGSViberConnectRequest*>(response.GetUserData());
                               
    if(!g_UGSViberConnectRequest->OnResponse.IsBound()){
        return;    
    }

    if (response.GetHasErrors())
    {
        g_UGSViberConnectRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSViberConnectRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSViberConnectRequest* UGSViberConnectRequest::SendViberConnectRequest(FString AccessToken, bool DoNotLinkToCurrentPlayer, bool DoNotRegisterForPush, bool ErrorOnSwitch, UGameSparksScriptData* Segments, bool SwitchIfPossible, bool SyncDisplayName,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSViberConnectRequest* proxy = NewObject<UGSViberConnectRequest>();
    proxy->accessToken = AccessToken;
    proxy->doNotLinkToCurrentPlayer = DoNotLinkToCurrentPlayer;
    proxy->doNotRegisterForPush = DoNotRegisterForPush;
    proxy->errorOnSwitch = ErrorOnSwitch;
    proxy->segments = Segments;
    proxy->switchIfPossible = SwitchIfPossible;
    proxy->syncDisplayName = SyncDisplayName;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    return proxy;
}

UGSViberConnectRequest* UGSViberConnectRequest::SendViberConnectRequestOnBehalfOf(const FString& PlayerId, FString AccessToken, bool DoNotLinkToCurrentPlayer, bool DoNotRegisterForPush, bool ErrorOnSwitch, UGameSparksScriptData* Segments, bool SwitchIfPossible, bool SyncDisplayName,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSViberConnectRequest* proxy = NewObject<UGSViberConnectRequest>();
    proxy->accessToken = AccessToken;
    proxy->doNotLinkToCurrentPlayer = DoNotLinkToCurrentPlayer;
    proxy->doNotRegisterForPush = DoNotRegisterForPush;
    proxy->errorOnSwitch = ErrorOnSwitch;
    proxy->segments = Segments;
    proxy->switchIfPossible = SwitchIfPossible;
    proxy->syncDisplayName = SyncDisplayName;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    proxy->playerId = PlayerId;
    return proxy;
}
    
void UGSViberConnectRequest::Activate()
{
    GameSparks::Api::Requests::ViberConnectRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
    if(accessToken != ""){
        gsRequest.SetAccessToken(TCHAR_TO_UTF8(*accessToken));
    }
    if(doNotLinkToCurrentPlayer != false){
        gsRequest.SetDoNotLinkToCurrentPlayer(doNotLinkToCurrentPlayer);
    }
    if(doNotRegisterForPush != false){
        gsRequest.SetDoNotRegisterForPush(doNotRegisterForPush);
    }
    if(errorOnSwitch != false){
        gsRequest.SetErrorOnSwitch(errorOnSwitch);
    }
    if(segments != nullptr){
        gsRequest.SetSegments(segments->ToRequestData());
    }
    if(switchIfPossible != false){
        gsRequest.SetSwitchIfPossible(switchIfPossible);
    }
    if(syncDisplayName != false){
        gsRequest.SetSyncDisplayName(syncDisplayName);
    }
    if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
        gsRequest.SetDurable(durable);
    }
    
    if(!playerId.IsEmpty())
    {
        gsRequest.SetPlayerId(TCHAR_TO_UTF8(*playerId));
    }

    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
        gsRequest.Send(ViberConnectRequestResponseCallback, requestTimeoutSeconds);  
    } else {
        gsRequest.Send(ViberConnectRequestResponseCallback);
    }
}

UGSViberConnectRequest::~UGSViberConnectRequest()
{
 if (UGameSparksModule* module = UGameSparksModule::GetModulePtr())
 {
  if (module->IsInitialized())
  {
    module->GetGSInstance().ChangeUserDataForRequests(this, nullptr);
  }
 }
}


void WeChatConnectRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::AuthenticationResponse& response){
    
    if(response.GetUserData() == nullptr) {
        return;
    }
    
    FGSAuthenticationResponse unreal_response = FGSAuthenticationResponse(response.GetBaseData());
    
    UGSWeChatConnectRequest* g_UGSWeChatConnectRequest = static_cast<UGSWeChatConnectRequest*>(response.GetUserData());
                               
    if(!g_UGSWeChatConnectRequest->OnResponse.IsBound()){
        return;    
    }

    if (response.GetHasErrors())
    {
        g_UGSWeChatConnectRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSWeChatConnectRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSWeChatConnectRequest* UGSWeChatConnectRequest::SendWeChatConnectRequest(FString AccessToken, bool DoNotLinkToCurrentPlayer, bool ErrorOnSwitch, FString OpenId, UGameSparksScriptData* Segments, bool SwitchIfPossible, bool SyncDisplayName,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSWeChatConnectRequest* proxy = NewObject<UGSWeChatConnectRequest>();
    proxy->accessToken = AccessToken;
    proxy->doNotLinkToCurrentPlayer = DoNotLinkToCurrentPlayer;
    proxy->errorOnSwitch = ErrorOnSwitch;
    proxy->openId = OpenId;
    proxy->segments = Segments;
    proxy->switchIfPossible = SwitchIfPossible;
    proxy->syncDisplayName = SyncDisplayName;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    return proxy;
}

UGSWeChatConnectRequest* UGSWeChatConnectRequest::SendWeChatConnectRequestOnBehalfOf(const FString& PlayerId, FString AccessToken, bool DoNotLinkToCurrentPlayer, bool ErrorOnSwitch, FString OpenId, UGameSparksScriptData* Segments, bool SwitchIfPossible, bool SyncDisplayName,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSWeChatConnectRequest* proxy = NewObject<UGSWeChatConnectRequest>();
    proxy->accessToken = AccessToken;
    proxy->doNotLinkToCurrentPlayer = DoNotLinkToCurrentPlayer;
    proxy->errorOnSwitch = ErrorOnSwitch;
    proxy->openId = OpenId;
    proxy->segments = Segments;
    proxy->switchIfPossible = SwitchIfPossible;
    proxy->syncDisplayName = SyncDisplayName;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    proxy->playerId = PlayerId;
    return proxy;
}
    
void UGSWeChatConnectRequest::Activate()
{
    GameSparks::Api::Requests::WeChatConnectRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
    if(accessToken != ""){
        gsRequest.SetAccessToken(TCHAR_TO_UTF8(*accessToken));
    }
    if(doNotLinkToCurrentPlayer != false){
        gsRequest.SetDoNotLinkToCurrentPlayer(doNotLinkToCurrentPlayer);
    }
    if(errorOnSwitch != false){
        gsRequest.SetErrorOnSwitch(errorOnSwitch);
    }
    if(openId != ""){
        gsRequest.SetOpenId(TCHAR_TO_UTF8(*openId));
    }
    if(segments != nullptr){
        gsRequest.SetSegments(segments->ToRequestData());
    }
    if(switchIfPossible != false){
        gsRequest.SetSwitchIfPossible(switchIfPossible);
    }
    if(syncDisplayName != false){
        gsRequest.SetSyncDisplayName(syncDisplayName);
    }
    if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
        gsRequest.SetDurable(durable);
    }
    
    if(!playerId.IsEmpty())
    {
        gsRequest.SetPlayerId(TCHAR_TO_UTF8(*playerId));
    }

    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
        gsRequest.Send(WeChatConnectRequestResponseCallback, requestTimeoutSeconds);  
    } else {
        gsRequest.Send(WeChatConnectRequestResponseCallback);
    }
}

UGSWeChatConnectRequest::~UGSWeChatConnectRequest()
{
 if (UGameSparksModule* module = UGameSparksModule::GetModulePtr())
 {
  if (module->IsInitialized())
  {
    module->GetGSInstance().ChangeUserDataForRequests(this, nullptr);
  }
 }
}


void WindowsBuyGoodsRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::BuyVirtualGoodResponse& response){
    
    if(response.GetUserData() == nullptr) {
        return;
    }
    
    FGSBuyVirtualGoodResponse unreal_response = FGSBuyVirtualGoodResponse(response.GetBaseData());
    
    UGSWindowsBuyGoodsRequest* g_UGSWindowsBuyGoodsRequest = static_cast<UGSWindowsBuyGoodsRequest*>(response.GetUserData());
                               
    if(!g_UGSWindowsBuyGoodsRequest->OnResponse.IsBound()){
        return;    
    }

    if (response.GetHasErrors())
    {
        g_UGSWindowsBuyGoodsRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSWindowsBuyGoodsRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSWindowsBuyGoodsRequest* UGSWindowsBuyGoodsRequest::SendWindowsBuyGoodsRequest(FString CurrencyCode, FString Platform, FString Receipt, float SubUnitPrice, bool UniqueTransactionByPlayer,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSWindowsBuyGoodsRequest* proxy = NewObject<UGSWindowsBuyGoodsRequest>();
    proxy->currencyCode = CurrencyCode;
    proxy->platform = Platform;
    proxy->receipt = Receipt;
    proxy->subUnitPrice = SubUnitPrice;
    proxy->uniqueTransactionByPlayer = UniqueTransactionByPlayer;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    return proxy;
}

UGSWindowsBuyGoodsRequest* UGSWindowsBuyGoodsRequest::SendWindowsBuyGoodsRequestOnBehalfOf(const FString& PlayerId, FString CurrencyCode, FString Platform, FString Receipt, float SubUnitPrice, bool UniqueTransactionByPlayer,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSWindowsBuyGoodsRequest* proxy = NewObject<UGSWindowsBuyGoodsRequest>();
    proxy->currencyCode = CurrencyCode;
    proxy->platform = Platform;
    proxy->receipt = Receipt;
    proxy->subUnitPrice = SubUnitPrice;
    proxy->uniqueTransactionByPlayer = UniqueTransactionByPlayer;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    proxy->playerId = PlayerId;
    return proxy;
}
    
void UGSWindowsBuyGoodsRequest::Activate()
{
    GameSparks::Api::Requests::WindowsBuyGoodsRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
    if(currencyCode != ""){
        gsRequest.SetCurrencyCode(TCHAR_TO_UTF8(*currencyCode));
    }
    if(platform != ""){
        gsRequest.SetPlatform(TCHAR_TO_UTF8(*platform));
    }
    if(receipt != ""){
        gsRequest.SetReceipt(TCHAR_TO_UTF8(*receipt));
    }
    if(subUnitPrice != 0.0f){
        gsRequest.SetSubUnitPrice(subUnitPrice);
    }
    if(uniqueTransactionByPlayer != false){
        gsRequest.SetUniqueTransactionByPlayer(uniqueTransactionByPlayer);
    }
    if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
        gsRequest.SetDurable(durable);
    }
    
    if(!playerId.IsEmpty())
    {
        gsRequest.SetPlayerId(TCHAR_TO_UTF8(*playerId));
    }

    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
        gsRequest.Send(WindowsBuyGoodsRequestResponseCallback, requestTimeoutSeconds);  
    } else {
        gsRequest.Send(WindowsBuyGoodsRequestResponseCallback);
    }
}

UGSWindowsBuyGoodsRequest::~UGSWindowsBuyGoodsRequest()
{
 if (UGameSparksModule* module = UGameSparksModule::GetModulePtr())
 {
  if (module->IsInitialized())
  {
    module->GetGSInstance().ChangeUserDataForRequests(this, nullptr);
  }
 }
}


void WithdrawChallengeRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::WithdrawChallengeResponse& response){
    
    if(response.GetUserData() == nullptr) {
        return;
    }
    
    FGSWithdrawChallengeResponse unreal_response = FGSWithdrawChallengeResponse(response.GetBaseData());
    
    UGSWithdrawChallengeRequest* g_UGSWithdrawChallengeRequest = static_cast<UGSWithdrawChallengeRequest*>(response.GetUserData());
                               
    if(!g_UGSWithdrawChallengeRequest->OnResponse.IsBound()){
        return;    
    }

    if (response.GetHasErrors())
    {
        g_UGSWithdrawChallengeRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSWithdrawChallengeRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSWithdrawChallengeRequest* UGSWithdrawChallengeRequest::SendWithdrawChallengeRequest(FString ChallengeInstanceId, FString Message,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSWithdrawChallengeRequest* proxy = NewObject<UGSWithdrawChallengeRequest>();
    proxy->challengeInstanceId = ChallengeInstanceId;
    proxy->message = Message;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    return proxy;
}

UGSWithdrawChallengeRequest* UGSWithdrawChallengeRequest::SendWithdrawChallengeRequestOnBehalfOf(const FString& PlayerId, FString ChallengeInstanceId, FString Message,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSWithdrawChallengeRequest* proxy = NewObject<UGSWithdrawChallengeRequest>();
    proxy->challengeInstanceId = ChallengeInstanceId;
    proxy->message = Message;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    proxy->playerId = PlayerId;
    return proxy;
}
    
void UGSWithdrawChallengeRequest::Activate()
{
    GameSparks::Api::Requests::WithdrawChallengeRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
    if(challengeInstanceId != ""){
        gsRequest.SetChallengeInstanceId(TCHAR_TO_UTF8(*challengeInstanceId));
    }
    if(message != ""){
        gsRequest.SetMessage(TCHAR_TO_UTF8(*message));
    }
    if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
        gsRequest.SetDurable(durable);
    }
    
    if(!playerId.IsEmpty())
    {
        gsRequest.SetPlayerId(TCHAR_TO_UTF8(*playerId));
    }

    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
        gsRequest.Send(WithdrawChallengeRequestResponseCallback, requestTimeoutSeconds);  
    } else {
        gsRequest.Send(WithdrawChallengeRequestResponseCallback);
    }
}

UGSWithdrawChallengeRequest::~UGSWithdrawChallengeRequest()
{
 if (UGameSparksModule* module = UGameSparksModule::GetModulePtr())
 {
  if (module->IsInitialized())
  {
    module->GetGSInstance().ChangeUserDataForRequests(this, nullptr);
  }
 }
}


void XBOXLiveConnectRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::AuthenticationResponse& response){
    
    if(response.GetUserData() == nullptr) {
        return;
    }
    
    FGSAuthenticationResponse unreal_response = FGSAuthenticationResponse(response.GetBaseData());
    
    UGSXBOXLiveConnectRequest* g_UGSXBOXLiveConnectRequest = static_cast<UGSXBOXLiveConnectRequest*>(response.GetUserData());
                               
    if(!g_UGSXBOXLiveConnectRequest->OnResponse.IsBound()){
        return;    
    }

    if (response.GetHasErrors())
    {
        g_UGSXBOXLiveConnectRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSXBOXLiveConnectRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSXBOXLiveConnectRequest* UGSXBOXLiveConnectRequest::SendXBOXLiveConnectRequest(FString DisplayName, bool DoNotLinkToCurrentPlayer, bool ErrorOnSwitch, UGameSparksScriptData* Segments, FString StsTokenString, bool SwitchIfPossible, bool SyncDisplayName,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSXBOXLiveConnectRequest* proxy = NewObject<UGSXBOXLiveConnectRequest>();
    proxy->displayName = DisplayName;
    proxy->doNotLinkToCurrentPlayer = DoNotLinkToCurrentPlayer;
    proxy->errorOnSwitch = ErrorOnSwitch;
    proxy->segments = Segments;
    proxy->stsTokenString = StsTokenString;
    proxy->switchIfPossible = SwitchIfPossible;
    proxy->syncDisplayName = SyncDisplayName;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    return proxy;
}

UGSXBOXLiveConnectRequest* UGSXBOXLiveConnectRequest::SendXBOXLiveConnectRequestOnBehalfOf(const FString& PlayerId, FString DisplayName, bool DoNotLinkToCurrentPlayer, bool ErrorOnSwitch, UGameSparksScriptData* Segments, FString StsTokenString, bool SwitchIfPossible, bool SyncDisplayName,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSXBOXLiveConnectRequest* proxy = NewObject<UGSXBOXLiveConnectRequest>();
    proxy->displayName = DisplayName;
    proxy->doNotLinkToCurrentPlayer = DoNotLinkToCurrentPlayer;
    proxy->errorOnSwitch = ErrorOnSwitch;
    proxy->segments = Segments;
    proxy->stsTokenString = StsTokenString;
    proxy->switchIfPossible = SwitchIfPossible;
    proxy->syncDisplayName = SyncDisplayName;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    proxy->playerId = PlayerId;
    return proxy;
}
    
void UGSXBOXLiveConnectRequest::Activate()
{
    GameSparks::Api::Requests::XBOXLiveConnectRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
    if(displayName != ""){
        gsRequest.SetDisplayName(TCHAR_TO_UTF8(*displayName));
    }
    if(doNotLinkToCurrentPlayer != false){
        gsRequest.SetDoNotLinkToCurrentPlayer(doNotLinkToCurrentPlayer);
    }
    if(errorOnSwitch != false){
        gsRequest.SetErrorOnSwitch(errorOnSwitch);
    }
    if(segments != nullptr){
        gsRequest.SetSegments(segments->ToRequestData());
    }
    if(stsTokenString != ""){
        gsRequest.SetStsTokenString(TCHAR_TO_UTF8(*stsTokenString));
    }
    if(switchIfPossible != false){
        gsRequest.SetSwitchIfPossible(switchIfPossible);
    }
    if(syncDisplayName != false){
        gsRequest.SetSyncDisplayName(syncDisplayName);
    }
    if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
        gsRequest.SetDurable(durable);
    }
    
    if(!playerId.IsEmpty())
    {
        gsRequest.SetPlayerId(TCHAR_TO_UTF8(*playerId));
    }

    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
        gsRequest.Send(XBOXLiveConnectRequestResponseCallback, requestTimeoutSeconds);  
    } else {
        gsRequest.Send(XBOXLiveConnectRequestResponseCallback);
    }
}

UGSXBOXLiveConnectRequest::~UGSXBOXLiveConnectRequest()
{
 if (UGameSparksModule* module = UGameSparksModule::GetModulePtr())
 {
  if (module->IsInitialized())
  {
    module->GetGSInstance().ChangeUserDataForRequests(this, nullptr);
  }
 }
}


void XboxOneConnectRequestResponseCallback(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Responses::AuthenticationResponse& response){
    
    if(response.GetUserData() == nullptr) {
        return;
    }
    
    FGSAuthenticationResponse unreal_response = FGSAuthenticationResponse(response.GetBaseData());
    
    UGSXboxOneConnectRequest* g_UGSXboxOneConnectRequest = static_cast<UGSXboxOneConnectRequest*>(response.GetUserData());
                               
    if(!g_UGSXboxOneConnectRequest->OnResponse.IsBound()){
        return;    
    }

    if (response.GetHasErrors())
    {
        g_UGSXboxOneConnectRequest->OnResponse.Broadcast(unreal_response, true);
    }
    else
    {
        g_UGSXboxOneConnectRequest->OnResponse.Broadcast(unreal_response, false);
    }
}

UGSXboxOneConnectRequest* UGSXboxOneConnectRequest::SendXboxOneConnectRequest(bool DoNotLinkToCurrentPlayer, bool ErrorOnSwitch, FString Sandbox, UGameSparksScriptData* Segments, bool SwitchIfPossible, bool SyncDisplayName, FString Token,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSXboxOneConnectRequest* proxy = NewObject<UGSXboxOneConnectRequest>();
    proxy->doNotLinkToCurrentPlayer = DoNotLinkToCurrentPlayer;
    proxy->errorOnSwitch = ErrorOnSwitch;
    proxy->sandbox = Sandbox;
    proxy->segments = Segments;
    proxy->switchIfPossible = SwitchIfPossible;
    proxy->syncDisplayName = SyncDisplayName;
    proxy->token = Token;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    return proxy;
}

UGSXboxOneConnectRequest* UGSXboxOneConnectRequest::SendXboxOneConnectRequestOnBehalfOf(const FString& PlayerId, bool DoNotLinkToCurrentPlayer, bool ErrorOnSwitch, FString Sandbox, UGameSparksScriptData* Segments, bool SwitchIfPossible, bool SyncDisplayName, FString Token,  UGameSparksScriptData* ScriptData, bool Durable, int32 RequestTimeoutSeconds)
{
    UGSXboxOneConnectRequest* proxy = NewObject<UGSXboxOneConnectRequest>();
    proxy->doNotLinkToCurrentPlayer = DoNotLinkToCurrentPlayer;
    proxy->errorOnSwitch = ErrorOnSwitch;
    proxy->sandbox = Sandbox;
    proxy->segments = Segments;
    proxy->switchIfPossible = SwitchIfPossible;
    proxy->syncDisplayName = SyncDisplayName;
    proxy->token = Token;
    proxy->scriptData = ScriptData;
    proxy->durable = Durable;
    proxy->requestTimeoutSeconds = RequestTimeoutSeconds;
    proxy->playerId = PlayerId;
    return proxy;
}
    
void UGSXboxOneConnectRequest::Activate()
{
    GameSparks::Api::Requests::XboxOneConnectRequest gsRequest(UGameSparksModule::GetModulePtr()->GetGSInstance());
    if(doNotLinkToCurrentPlayer != false){
        gsRequest.SetDoNotLinkToCurrentPlayer(doNotLinkToCurrentPlayer);
    }
    if(errorOnSwitch != false){
        gsRequest.SetErrorOnSwitch(errorOnSwitch);
    }
    if(sandbox != ""){
        gsRequest.SetSandbox(TCHAR_TO_UTF8(*sandbox));
    }
    if(segments != nullptr){
        gsRequest.SetSegments(segments->ToRequestData());
    }
    if(switchIfPossible != false){
        gsRequest.SetSwitchIfPossible(switchIfPossible);
    }
    if(syncDisplayName != false){
        gsRequest.SetSyncDisplayName(syncDisplayName);
    }
    if(token != ""){
        gsRequest.SetToken(TCHAR_TO_UTF8(*token));
    }
    if(scriptData != nullptr){
        gsRequest.SetScriptData(scriptData->ToRequestData());
    }
    if(durable){
        gsRequest.SetDurable(durable);
    }
    
    if(!playerId.IsEmpty())
    {
        gsRequest.SetPlayerId(TCHAR_TO_UTF8(*playerId));
    }

    gsRequest.SetUserData(this);

    if(requestTimeoutSeconds > 0){
        gsRequest.Send(XboxOneConnectRequestResponseCallback, requestTimeoutSeconds);  
    } else {
        gsRequest.Send(XboxOneConnectRequestResponseCallback);
    }
}

UGSXboxOneConnectRequest::~UGSXboxOneConnectRequest()
{
 if (UGameSparksModule* module = UGameSparksModule::GetModulePtr())
 {
  if (module->IsInitialized())
  {
    module->GetGSInstance().ChangeUserDataForRequests(this, nullptr);
  }
 }
}


