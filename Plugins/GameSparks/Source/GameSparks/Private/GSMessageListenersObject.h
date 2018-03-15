#pragma once

#include "GameSparksPrivatePCH.h"
#include "GameSparks/GS.h"
#include "GameSparks/generated/GSMessages.h"
#include "GameSparksModule.h"
#include "GSTypes.h"
#include "GSMessageListenersObject.generated.h"

UCLASS(Blueprintable, BlueprintType)
class GAMESPARKS_API UGSMessageListenersObject : public UObject
{
	GENERATED_BODY()

public:
    UGSMessageListenersObject();
    virtual class UWorld* GetWorld() const override;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAchievementEarnedMessage, FGSAchievementEarnedMessage, AchievementEarnedMessage);
	UPROPERTY(BlueprintAssignable, Category = GameSparks)
	FOnAchievementEarnedMessage OnAchievementEarnedMessage;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnChallengeAcceptedMessage, FGSChallengeAcceptedMessage, ChallengeAcceptedMessage);
	UPROPERTY(BlueprintAssignable, Category = GameSparks)
	FOnChallengeAcceptedMessage OnChallengeAcceptedMessage;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnChallengeChangedMessage, FGSChallengeChangedMessage, ChallengeChangedMessage);
	UPROPERTY(BlueprintAssignable, Category = GameSparks)
	FOnChallengeChangedMessage OnChallengeChangedMessage;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnChallengeChatMessage, FGSChallengeChatMessage, ChallengeChatMessage);
	UPROPERTY(BlueprintAssignable, Category = GameSparks)
	FOnChallengeChatMessage OnChallengeChatMessage;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnChallengeDeclinedMessage, FGSChallengeDeclinedMessage, ChallengeDeclinedMessage);
	UPROPERTY(BlueprintAssignable, Category = GameSparks)
	FOnChallengeDeclinedMessage OnChallengeDeclinedMessage;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnChallengeDrawnMessage, FGSChallengeDrawnMessage, ChallengeDrawnMessage);
	UPROPERTY(BlueprintAssignable, Category = GameSparks)
	FOnChallengeDrawnMessage OnChallengeDrawnMessage;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnChallengeExpiredMessage, FGSChallengeExpiredMessage, ChallengeExpiredMessage);
	UPROPERTY(BlueprintAssignable, Category = GameSparks)
	FOnChallengeExpiredMessage OnChallengeExpiredMessage;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnChallengeIssuedMessage, FGSChallengeIssuedMessage, ChallengeIssuedMessage);
	UPROPERTY(BlueprintAssignable, Category = GameSparks)
	FOnChallengeIssuedMessage OnChallengeIssuedMessage;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnChallengeJoinedMessage, FGSChallengeJoinedMessage, ChallengeJoinedMessage);
	UPROPERTY(BlueprintAssignable, Category = GameSparks)
	FOnChallengeJoinedMessage OnChallengeJoinedMessage;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnChallengeLapsedMessage, FGSChallengeLapsedMessage, ChallengeLapsedMessage);
	UPROPERTY(BlueprintAssignable, Category = GameSparks)
	FOnChallengeLapsedMessage OnChallengeLapsedMessage;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnChallengeLostMessage, FGSChallengeLostMessage, ChallengeLostMessage);
	UPROPERTY(BlueprintAssignable, Category = GameSparks)
	FOnChallengeLostMessage OnChallengeLostMessage;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnChallengeStartedMessage, FGSChallengeStartedMessage, ChallengeStartedMessage);
	UPROPERTY(BlueprintAssignable, Category = GameSparks)
	FOnChallengeStartedMessage OnChallengeStartedMessage;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnChallengeTurnTakenMessage, FGSChallengeTurnTakenMessage, ChallengeTurnTakenMessage);
	UPROPERTY(BlueprintAssignable, Category = GameSparks)
	FOnChallengeTurnTakenMessage OnChallengeTurnTakenMessage;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnChallengeWaitingMessage, FGSChallengeWaitingMessage, ChallengeWaitingMessage);
	UPROPERTY(BlueprintAssignable, Category = GameSparks)
	FOnChallengeWaitingMessage OnChallengeWaitingMessage;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnChallengeWithdrawnMessage, FGSChallengeWithdrawnMessage, ChallengeWithdrawnMessage);
	UPROPERTY(BlueprintAssignable, Category = GameSparks)
	FOnChallengeWithdrawnMessage OnChallengeWithdrawnMessage;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnChallengeWonMessage, FGSChallengeWonMessage, ChallengeWonMessage);
	UPROPERTY(BlueprintAssignable, Category = GameSparks)
	FOnChallengeWonMessage OnChallengeWonMessage;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnFriendMessage, FGSFriendMessage, FriendMessage);
	UPROPERTY(BlueprintAssignable, Category = GameSparks)
	FOnFriendMessage OnFriendMessage;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGlobalRankChangedMessage, FGSGlobalRankChangedMessage, GlobalRankChangedMessage);
	UPROPERTY(BlueprintAssignable, Category = GameSparks)
	FOnGlobalRankChangedMessage OnGlobalRankChangedMessage;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMatchFoundMessage, FGSMatchFoundMessage, MatchFoundMessage);
	UPROPERTY(BlueprintAssignable, Category = GameSparks)
	FOnMatchFoundMessage OnMatchFoundMessage;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMatchNotFoundMessage, FGSMatchNotFoundMessage, MatchNotFoundMessage);
	UPROPERTY(BlueprintAssignable, Category = GameSparks)
	FOnMatchNotFoundMessage OnMatchNotFoundMessage;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMatchUpdatedMessage, FGSMatchUpdatedMessage, MatchUpdatedMessage);
	UPROPERTY(BlueprintAssignable, Category = GameSparks)
	FOnMatchUpdatedMessage OnMatchUpdatedMessage;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnNewHighScoreMessage, FGSNewHighScoreMessage, NewHighScoreMessage);
	UPROPERTY(BlueprintAssignable, Category = GameSparks)
	FOnNewHighScoreMessage OnNewHighScoreMessage;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnNewTeamScoreMessage, FGSNewTeamScoreMessage, NewTeamScoreMessage);
	UPROPERTY(BlueprintAssignable, Category = GameSparks)
	FOnNewTeamScoreMessage OnNewTeamScoreMessage;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnScriptMessage, FGSScriptMessage, ScriptMessage);
	UPROPERTY(BlueprintAssignable, Category = GameSparks)
	FOnScriptMessage OnScriptMessage;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSessionTerminatedMessage, FGSSessionTerminatedMessage, SessionTerminatedMessage);
	UPROPERTY(BlueprintAssignable, Category = GameSparks)
	FOnSessionTerminatedMessage OnSessionTerminatedMessage;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSocialRankChangedMessage, FGSSocialRankChangedMessage, SocialRankChangedMessage);
	UPROPERTY(BlueprintAssignable, Category = GameSparks)
	FOnSocialRankChangedMessage OnSocialRankChangedMessage;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTeamChatMessage, FGSTeamChatMessage, TeamChatMessage);
	UPROPERTY(BlueprintAssignable, Category = GameSparks)
	FOnTeamChatMessage OnTeamChatMessage;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTeamRankChangedMessage, FGSTeamRankChangedMessage, TeamRankChangedMessage);
	UPROPERTY(BlueprintAssignable, Category = GameSparks)
	FOnTeamRankChangedMessage OnTeamRankChangedMessage;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnUploadCompleteMessage, FGSUploadCompleteMessage, UploadCompleteMessage);
	UPROPERTY(BlueprintAssignable, Category = GameSparks)
	FOnUploadCompleteMessage OnUploadCompleteMessage;

    
};
