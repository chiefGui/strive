#include "GSMessageListeners.h"
#include "GameSparksPrivatePCH.h"
#include "GameSparks/GS.h"
#include "GameSparks/generated/GSMessages.h"
#include "GameSparksComponent.h"
#include "GameSparksModule.h"
#include "GSMessageListenersObject.h"

void UGSMessageListeners_OnAchievementEarnedMessage(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Messages::AchievementEarnedMessage& message)
{
    FGSAchievementEarnedMessage unreal_message(message.GetBaseData());
    
    for ( TObjectIterator<UGSMessageListeners> Itr; Itr; ++Itr )
    {
        #if GS_UE_VERSION < GS_MAKE_VERSION(4, 14) // since 4.14 auto-generated enums no longer use TEnumAsByte
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType.GetValue() == EWorldType::Game || Itr->GetWorld()->WorldType.GetValue() == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #else
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType == EWorldType::Game || Itr->GetWorld()->WorldType == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #endif
		{
               Itr->OnAchievementEarnedMessage.Broadcast(unreal_message);
		}
    }

    // Also notify UGSMessageListenersObject instances
    for (TObjectIterator<UGSMessageListenersObject> Itr; Itr; ++Itr)
    {
        #if GS_UE_VERSION < GS_MAKE_VERSION(4, 14) // since 4.14 auto-generated enums no longer use TEnumAsByte
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType.GetValue() == EWorldType::Game || Itr->GetWorld()->WorldType.GetValue() == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #else
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType == EWorldType::Game || Itr->GetWorld()->WorldType == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #endif
        {
            Itr->OnAchievementEarnedMessage.Broadcast(unreal_message);
        }
    }
}

void UGSMessageListeners_OnChallengeAcceptedMessage(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Messages::ChallengeAcceptedMessage& message)
{
    FGSChallengeAcceptedMessage unreal_message(message.GetBaseData());
    
    for ( TObjectIterator<UGSMessageListeners> Itr; Itr; ++Itr )
    {
        #if GS_UE_VERSION < GS_MAKE_VERSION(4, 14) // since 4.14 auto-generated enums no longer use TEnumAsByte
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType.GetValue() == EWorldType::Game || Itr->GetWorld()->WorldType.GetValue() == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #else
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType == EWorldType::Game || Itr->GetWorld()->WorldType == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #endif
		{
               Itr->OnChallengeAcceptedMessage.Broadcast(unreal_message);
		}
    }

    // Also notify UGSMessageListenersObject instances
    for (TObjectIterator<UGSMessageListenersObject> Itr; Itr; ++Itr)
    {
        #if GS_UE_VERSION < GS_MAKE_VERSION(4, 14) // since 4.14 auto-generated enums no longer use TEnumAsByte
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType.GetValue() == EWorldType::Game || Itr->GetWorld()->WorldType.GetValue() == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #else
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType == EWorldType::Game || Itr->GetWorld()->WorldType == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #endif
        {
            Itr->OnChallengeAcceptedMessage.Broadcast(unreal_message);
        }
    }
}

void UGSMessageListeners_OnChallengeChangedMessage(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Messages::ChallengeChangedMessage& message)
{
    FGSChallengeChangedMessage unreal_message(message.GetBaseData());
    
    for ( TObjectIterator<UGSMessageListeners> Itr; Itr; ++Itr )
    {
        #if GS_UE_VERSION < GS_MAKE_VERSION(4, 14) // since 4.14 auto-generated enums no longer use TEnumAsByte
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType.GetValue() == EWorldType::Game || Itr->GetWorld()->WorldType.GetValue() == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #else
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType == EWorldType::Game || Itr->GetWorld()->WorldType == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #endif
		{
               Itr->OnChallengeChangedMessage.Broadcast(unreal_message);
		}
    }

    // Also notify UGSMessageListenersObject instances
    for (TObjectIterator<UGSMessageListenersObject> Itr; Itr; ++Itr)
    {
        #if GS_UE_VERSION < GS_MAKE_VERSION(4, 14) // since 4.14 auto-generated enums no longer use TEnumAsByte
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType.GetValue() == EWorldType::Game || Itr->GetWorld()->WorldType.GetValue() == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #else
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType == EWorldType::Game || Itr->GetWorld()->WorldType == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #endif
        {
            Itr->OnChallengeChangedMessage.Broadcast(unreal_message);
        }
    }
}

void UGSMessageListeners_OnChallengeChatMessage(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Messages::ChallengeChatMessage& message)
{
    FGSChallengeChatMessage unreal_message(message.GetBaseData());
    
    for ( TObjectIterator<UGSMessageListeners> Itr; Itr; ++Itr )
    {
        #if GS_UE_VERSION < GS_MAKE_VERSION(4, 14) // since 4.14 auto-generated enums no longer use TEnumAsByte
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType.GetValue() == EWorldType::Game || Itr->GetWorld()->WorldType.GetValue() == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #else
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType == EWorldType::Game || Itr->GetWorld()->WorldType == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #endif
		{
               Itr->OnChallengeChatMessage.Broadcast(unreal_message);
		}
    }

    // Also notify UGSMessageListenersObject instances
    for (TObjectIterator<UGSMessageListenersObject> Itr; Itr; ++Itr)
    {
        #if GS_UE_VERSION < GS_MAKE_VERSION(4, 14) // since 4.14 auto-generated enums no longer use TEnumAsByte
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType.GetValue() == EWorldType::Game || Itr->GetWorld()->WorldType.GetValue() == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #else
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType == EWorldType::Game || Itr->GetWorld()->WorldType == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #endif
        {
            Itr->OnChallengeChatMessage.Broadcast(unreal_message);
        }
    }
}

void UGSMessageListeners_OnChallengeDeclinedMessage(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Messages::ChallengeDeclinedMessage& message)
{
    FGSChallengeDeclinedMessage unreal_message(message.GetBaseData());
    
    for ( TObjectIterator<UGSMessageListeners> Itr; Itr; ++Itr )
    {
        #if GS_UE_VERSION < GS_MAKE_VERSION(4, 14) // since 4.14 auto-generated enums no longer use TEnumAsByte
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType.GetValue() == EWorldType::Game || Itr->GetWorld()->WorldType.GetValue() == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #else
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType == EWorldType::Game || Itr->GetWorld()->WorldType == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #endif
		{
               Itr->OnChallengeDeclinedMessage.Broadcast(unreal_message);
		}
    }

    // Also notify UGSMessageListenersObject instances
    for (TObjectIterator<UGSMessageListenersObject> Itr; Itr; ++Itr)
    {
        #if GS_UE_VERSION < GS_MAKE_VERSION(4, 14) // since 4.14 auto-generated enums no longer use TEnumAsByte
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType.GetValue() == EWorldType::Game || Itr->GetWorld()->WorldType.GetValue() == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #else
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType == EWorldType::Game || Itr->GetWorld()->WorldType == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #endif
        {
            Itr->OnChallengeDeclinedMessage.Broadcast(unreal_message);
        }
    }
}

void UGSMessageListeners_OnChallengeDrawnMessage(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Messages::ChallengeDrawnMessage& message)
{
    FGSChallengeDrawnMessage unreal_message(message.GetBaseData());
    
    for ( TObjectIterator<UGSMessageListeners> Itr; Itr; ++Itr )
    {
        #if GS_UE_VERSION < GS_MAKE_VERSION(4, 14) // since 4.14 auto-generated enums no longer use TEnumAsByte
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType.GetValue() == EWorldType::Game || Itr->GetWorld()->WorldType.GetValue() == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #else
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType == EWorldType::Game || Itr->GetWorld()->WorldType == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #endif
		{
               Itr->OnChallengeDrawnMessage.Broadcast(unreal_message);
		}
    }

    // Also notify UGSMessageListenersObject instances
    for (TObjectIterator<UGSMessageListenersObject> Itr; Itr; ++Itr)
    {
        #if GS_UE_VERSION < GS_MAKE_VERSION(4, 14) // since 4.14 auto-generated enums no longer use TEnumAsByte
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType.GetValue() == EWorldType::Game || Itr->GetWorld()->WorldType.GetValue() == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #else
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType == EWorldType::Game || Itr->GetWorld()->WorldType == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #endif
        {
            Itr->OnChallengeDrawnMessage.Broadcast(unreal_message);
        }
    }
}

void UGSMessageListeners_OnChallengeExpiredMessage(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Messages::ChallengeExpiredMessage& message)
{
    FGSChallengeExpiredMessage unreal_message(message.GetBaseData());
    
    for ( TObjectIterator<UGSMessageListeners> Itr; Itr; ++Itr )
    {
        #if GS_UE_VERSION < GS_MAKE_VERSION(4, 14) // since 4.14 auto-generated enums no longer use TEnumAsByte
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType.GetValue() == EWorldType::Game || Itr->GetWorld()->WorldType.GetValue() == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #else
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType == EWorldType::Game || Itr->GetWorld()->WorldType == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #endif
		{
               Itr->OnChallengeExpiredMessage.Broadcast(unreal_message);
		}
    }

    // Also notify UGSMessageListenersObject instances
    for (TObjectIterator<UGSMessageListenersObject> Itr; Itr; ++Itr)
    {
        #if GS_UE_VERSION < GS_MAKE_VERSION(4, 14) // since 4.14 auto-generated enums no longer use TEnumAsByte
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType.GetValue() == EWorldType::Game || Itr->GetWorld()->WorldType.GetValue() == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #else
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType == EWorldType::Game || Itr->GetWorld()->WorldType == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #endif
        {
            Itr->OnChallengeExpiredMessage.Broadcast(unreal_message);
        }
    }
}

void UGSMessageListeners_OnChallengeIssuedMessage(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Messages::ChallengeIssuedMessage& message)
{
    FGSChallengeIssuedMessage unreal_message(message.GetBaseData());
    
    for ( TObjectIterator<UGSMessageListeners> Itr; Itr; ++Itr )
    {
        #if GS_UE_VERSION < GS_MAKE_VERSION(4, 14) // since 4.14 auto-generated enums no longer use TEnumAsByte
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType.GetValue() == EWorldType::Game || Itr->GetWorld()->WorldType.GetValue() == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #else
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType == EWorldType::Game || Itr->GetWorld()->WorldType == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #endif
		{
               Itr->OnChallengeIssuedMessage.Broadcast(unreal_message);
		}
    }

    // Also notify UGSMessageListenersObject instances
    for (TObjectIterator<UGSMessageListenersObject> Itr; Itr; ++Itr)
    {
        #if GS_UE_VERSION < GS_MAKE_VERSION(4, 14) // since 4.14 auto-generated enums no longer use TEnumAsByte
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType.GetValue() == EWorldType::Game || Itr->GetWorld()->WorldType.GetValue() == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #else
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType == EWorldType::Game || Itr->GetWorld()->WorldType == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #endif
        {
            Itr->OnChallengeIssuedMessage.Broadcast(unreal_message);
        }
    }
}

void UGSMessageListeners_OnChallengeJoinedMessage(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Messages::ChallengeJoinedMessage& message)
{
    FGSChallengeJoinedMessage unreal_message(message.GetBaseData());
    
    for ( TObjectIterator<UGSMessageListeners> Itr; Itr; ++Itr )
    {
        #if GS_UE_VERSION < GS_MAKE_VERSION(4, 14) // since 4.14 auto-generated enums no longer use TEnumAsByte
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType.GetValue() == EWorldType::Game || Itr->GetWorld()->WorldType.GetValue() == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #else
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType == EWorldType::Game || Itr->GetWorld()->WorldType == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #endif
		{
               Itr->OnChallengeJoinedMessage.Broadcast(unreal_message);
		}
    }

    // Also notify UGSMessageListenersObject instances
    for (TObjectIterator<UGSMessageListenersObject> Itr; Itr; ++Itr)
    {
        #if GS_UE_VERSION < GS_MAKE_VERSION(4, 14) // since 4.14 auto-generated enums no longer use TEnumAsByte
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType.GetValue() == EWorldType::Game || Itr->GetWorld()->WorldType.GetValue() == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #else
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType == EWorldType::Game || Itr->GetWorld()->WorldType == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #endif
        {
            Itr->OnChallengeJoinedMessage.Broadcast(unreal_message);
        }
    }
}

void UGSMessageListeners_OnChallengeLapsedMessage(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Messages::ChallengeLapsedMessage& message)
{
    FGSChallengeLapsedMessage unreal_message(message.GetBaseData());
    
    for ( TObjectIterator<UGSMessageListeners> Itr; Itr; ++Itr )
    {
        #if GS_UE_VERSION < GS_MAKE_VERSION(4, 14) // since 4.14 auto-generated enums no longer use TEnumAsByte
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType.GetValue() == EWorldType::Game || Itr->GetWorld()->WorldType.GetValue() == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #else
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType == EWorldType::Game || Itr->GetWorld()->WorldType == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #endif
		{
               Itr->OnChallengeLapsedMessage.Broadcast(unreal_message);
		}
    }

    // Also notify UGSMessageListenersObject instances
    for (TObjectIterator<UGSMessageListenersObject> Itr; Itr; ++Itr)
    {
        #if GS_UE_VERSION < GS_MAKE_VERSION(4, 14) // since 4.14 auto-generated enums no longer use TEnumAsByte
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType.GetValue() == EWorldType::Game || Itr->GetWorld()->WorldType.GetValue() == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #else
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType == EWorldType::Game || Itr->GetWorld()->WorldType == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #endif
        {
            Itr->OnChallengeLapsedMessage.Broadcast(unreal_message);
        }
    }
}

void UGSMessageListeners_OnChallengeLostMessage(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Messages::ChallengeLostMessage& message)
{
    FGSChallengeLostMessage unreal_message(message.GetBaseData());
    
    for ( TObjectIterator<UGSMessageListeners> Itr; Itr; ++Itr )
    {
        #if GS_UE_VERSION < GS_MAKE_VERSION(4, 14) // since 4.14 auto-generated enums no longer use TEnumAsByte
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType.GetValue() == EWorldType::Game || Itr->GetWorld()->WorldType.GetValue() == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #else
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType == EWorldType::Game || Itr->GetWorld()->WorldType == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #endif
		{
               Itr->OnChallengeLostMessage.Broadcast(unreal_message);
		}
    }

    // Also notify UGSMessageListenersObject instances
    for (TObjectIterator<UGSMessageListenersObject> Itr; Itr; ++Itr)
    {
        #if GS_UE_VERSION < GS_MAKE_VERSION(4, 14) // since 4.14 auto-generated enums no longer use TEnumAsByte
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType.GetValue() == EWorldType::Game || Itr->GetWorld()->WorldType.GetValue() == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #else
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType == EWorldType::Game || Itr->GetWorld()->WorldType == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #endif
        {
            Itr->OnChallengeLostMessage.Broadcast(unreal_message);
        }
    }
}

void UGSMessageListeners_OnChallengeStartedMessage(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Messages::ChallengeStartedMessage& message)
{
    FGSChallengeStartedMessage unreal_message(message.GetBaseData());
    
    for ( TObjectIterator<UGSMessageListeners> Itr; Itr; ++Itr )
    {
        #if GS_UE_VERSION < GS_MAKE_VERSION(4, 14) // since 4.14 auto-generated enums no longer use TEnumAsByte
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType.GetValue() == EWorldType::Game || Itr->GetWorld()->WorldType.GetValue() == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #else
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType == EWorldType::Game || Itr->GetWorld()->WorldType == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #endif
		{
               Itr->OnChallengeStartedMessage.Broadcast(unreal_message);
		}
    }

    // Also notify UGSMessageListenersObject instances
    for (TObjectIterator<UGSMessageListenersObject> Itr; Itr; ++Itr)
    {
        #if GS_UE_VERSION < GS_MAKE_VERSION(4, 14) // since 4.14 auto-generated enums no longer use TEnumAsByte
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType.GetValue() == EWorldType::Game || Itr->GetWorld()->WorldType.GetValue() == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #else
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType == EWorldType::Game || Itr->GetWorld()->WorldType == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #endif
        {
            Itr->OnChallengeStartedMessage.Broadcast(unreal_message);
        }
    }
}

void UGSMessageListeners_OnChallengeTurnTakenMessage(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Messages::ChallengeTurnTakenMessage& message)
{
    FGSChallengeTurnTakenMessage unreal_message(message.GetBaseData());
    
    for ( TObjectIterator<UGSMessageListeners> Itr; Itr; ++Itr )
    {
        #if GS_UE_VERSION < GS_MAKE_VERSION(4, 14) // since 4.14 auto-generated enums no longer use TEnumAsByte
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType.GetValue() == EWorldType::Game || Itr->GetWorld()->WorldType.GetValue() == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #else
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType == EWorldType::Game || Itr->GetWorld()->WorldType == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #endif
		{
               Itr->OnChallengeTurnTakenMessage.Broadcast(unreal_message);
		}
    }

    // Also notify UGSMessageListenersObject instances
    for (TObjectIterator<UGSMessageListenersObject> Itr; Itr; ++Itr)
    {
        #if GS_UE_VERSION < GS_MAKE_VERSION(4, 14) // since 4.14 auto-generated enums no longer use TEnumAsByte
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType.GetValue() == EWorldType::Game || Itr->GetWorld()->WorldType.GetValue() == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #else
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType == EWorldType::Game || Itr->GetWorld()->WorldType == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #endif
        {
            Itr->OnChallengeTurnTakenMessage.Broadcast(unreal_message);
        }
    }
}

void UGSMessageListeners_OnChallengeWaitingMessage(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Messages::ChallengeWaitingMessage& message)
{
    FGSChallengeWaitingMessage unreal_message(message.GetBaseData());
    
    for ( TObjectIterator<UGSMessageListeners> Itr; Itr; ++Itr )
    {
        #if GS_UE_VERSION < GS_MAKE_VERSION(4, 14) // since 4.14 auto-generated enums no longer use TEnumAsByte
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType.GetValue() == EWorldType::Game || Itr->GetWorld()->WorldType.GetValue() == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #else
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType == EWorldType::Game || Itr->GetWorld()->WorldType == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #endif
		{
               Itr->OnChallengeWaitingMessage.Broadcast(unreal_message);
		}
    }

    // Also notify UGSMessageListenersObject instances
    for (TObjectIterator<UGSMessageListenersObject> Itr; Itr; ++Itr)
    {
        #if GS_UE_VERSION < GS_MAKE_VERSION(4, 14) // since 4.14 auto-generated enums no longer use TEnumAsByte
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType.GetValue() == EWorldType::Game || Itr->GetWorld()->WorldType.GetValue() == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #else
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType == EWorldType::Game || Itr->GetWorld()->WorldType == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #endif
        {
            Itr->OnChallengeWaitingMessage.Broadcast(unreal_message);
        }
    }
}

void UGSMessageListeners_OnChallengeWithdrawnMessage(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Messages::ChallengeWithdrawnMessage& message)
{
    FGSChallengeWithdrawnMessage unreal_message(message.GetBaseData());
    
    for ( TObjectIterator<UGSMessageListeners> Itr; Itr; ++Itr )
    {
        #if GS_UE_VERSION < GS_MAKE_VERSION(4, 14) // since 4.14 auto-generated enums no longer use TEnumAsByte
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType.GetValue() == EWorldType::Game || Itr->GetWorld()->WorldType.GetValue() == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #else
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType == EWorldType::Game || Itr->GetWorld()->WorldType == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #endif
		{
               Itr->OnChallengeWithdrawnMessage.Broadcast(unreal_message);
		}
    }

    // Also notify UGSMessageListenersObject instances
    for (TObjectIterator<UGSMessageListenersObject> Itr; Itr; ++Itr)
    {
        #if GS_UE_VERSION < GS_MAKE_VERSION(4, 14) // since 4.14 auto-generated enums no longer use TEnumAsByte
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType.GetValue() == EWorldType::Game || Itr->GetWorld()->WorldType.GetValue() == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #else
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType == EWorldType::Game || Itr->GetWorld()->WorldType == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #endif
        {
            Itr->OnChallengeWithdrawnMessage.Broadcast(unreal_message);
        }
    }
}

void UGSMessageListeners_OnChallengeWonMessage(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Messages::ChallengeWonMessage& message)
{
    FGSChallengeWonMessage unreal_message(message.GetBaseData());
    
    for ( TObjectIterator<UGSMessageListeners> Itr; Itr; ++Itr )
    {
        #if GS_UE_VERSION < GS_MAKE_VERSION(4, 14) // since 4.14 auto-generated enums no longer use TEnumAsByte
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType.GetValue() == EWorldType::Game || Itr->GetWorld()->WorldType.GetValue() == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #else
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType == EWorldType::Game || Itr->GetWorld()->WorldType == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #endif
		{
               Itr->OnChallengeWonMessage.Broadcast(unreal_message);
		}
    }

    // Also notify UGSMessageListenersObject instances
    for (TObjectIterator<UGSMessageListenersObject> Itr; Itr; ++Itr)
    {
        #if GS_UE_VERSION < GS_MAKE_VERSION(4, 14) // since 4.14 auto-generated enums no longer use TEnumAsByte
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType.GetValue() == EWorldType::Game || Itr->GetWorld()->WorldType.GetValue() == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #else
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType == EWorldType::Game || Itr->GetWorld()->WorldType == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #endif
        {
            Itr->OnChallengeWonMessage.Broadcast(unreal_message);
        }
    }
}

void UGSMessageListeners_OnFriendMessage(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Messages::FriendMessage& message)
{
    FGSFriendMessage unreal_message(message.GetBaseData());
    
    for ( TObjectIterator<UGSMessageListeners> Itr; Itr; ++Itr )
    {
        #if GS_UE_VERSION < GS_MAKE_VERSION(4, 14) // since 4.14 auto-generated enums no longer use TEnumAsByte
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType.GetValue() == EWorldType::Game || Itr->GetWorld()->WorldType.GetValue() == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #else
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType == EWorldType::Game || Itr->GetWorld()->WorldType == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #endif
		{
               Itr->OnFriendMessage.Broadcast(unreal_message);
		}
    }

    // Also notify UGSMessageListenersObject instances
    for (TObjectIterator<UGSMessageListenersObject> Itr; Itr; ++Itr)
    {
        #if GS_UE_VERSION < GS_MAKE_VERSION(4, 14) // since 4.14 auto-generated enums no longer use TEnumAsByte
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType.GetValue() == EWorldType::Game || Itr->GetWorld()->WorldType.GetValue() == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #else
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType == EWorldType::Game || Itr->GetWorld()->WorldType == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #endif
        {
            Itr->OnFriendMessage.Broadcast(unreal_message);
        }
    }
}

void UGSMessageListeners_OnGlobalRankChangedMessage(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Messages::GlobalRankChangedMessage& message)
{
    FGSGlobalRankChangedMessage unreal_message(message.GetBaseData());
    
    for ( TObjectIterator<UGSMessageListeners> Itr; Itr; ++Itr )
    {
        #if GS_UE_VERSION < GS_MAKE_VERSION(4, 14) // since 4.14 auto-generated enums no longer use TEnumAsByte
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType.GetValue() == EWorldType::Game || Itr->GetWorld()->WorldType.GetValue() == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #else
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType == EWorldType::Game || Itr->GetWorld()->WorldType == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #endif
		{
               Itr->OnGlobalRankChangedMessage.Broadcast(unreal_message);
		}
    }

    // Also notify UGSMessageListenersObject instances
    for (TObjectIterator<UGSMessageListenersObject> Itr; Itr; ++Itr)
    {
        #if GS_UE_VERSION < GS_MAKE_VERSION(4, 14) // since 4.14 auto-generated enums no longer use TEnumAsByte
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType.GetValue() == EWorldType::Game || Itr->GetWorld()->WorldType.GetValue() == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #else
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType == EWorldType::Game || Itr->GetWorld()->WorldType == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #endif
        {
            Itr->OnGlobalRankChangedMessage.Broadcast(unreal_message);
        }
    }
}

void UGSMessageListeners_OnMatchFoundMessage(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Messages::MatchFoundMessage& message)
{
    FGSMatchFoundMessage unreal_message(message.GetBaseData());
    
    for ( TObjectIterator<UGSMessageListeners> Itr; Itr; ++Itr )
    {
        #if GS_UE_VERSION < GS_MAKE_VERSION(4, 14) // since 4.14 auto-generated enums no longer use TEnumAsByte
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType.GetValue() == EWorldType::Game || Itr->GetWorld()->WorldType.GetValue() == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #else
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType == EWorldType::Game || Itr->GetWorld()->WorldType == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #endif
		{
               Itr->OnMatchFoundMessage.Broadcast(unreal_message);
		}
    }

    // Also notify UGSMessageListenersObject instances
    for (TObjectIterator<UGSMessageListenersObject> Itr; Itr; ++Itr)
    {
        #if GS_UE_VERSION < GS_MAKE_VERSION(4, 14) // since 4.14 auto-generated enums no longer use TEnumAsByte
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType.GetValue() == EWorldType::Game || Itr->GetWorld()->WorldType.GetValue() == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #else
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType == EWorldType::Game || Itr->GetWorld()->WorldType == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #endif
        {
            Itr->OnMatchFoundMessage.Broadcast(unreal_message);
        }
    }
}

void UGSMessageListeners_OnMatchNotFoundMessage(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Messages::MatchNotFoundMessage& message)
{
    FGSMatchNotFoundMessage unreal_message(message.GetBaseData());
    
    for ( TObjectIterator<UGSMessageListeners> Itr; Itr; ++Itr )
    {
        #if GS_UE_VERSION < GS_MAKE_VERSION(4, 14) // since 4.14 auto-generated enums no longer use TEnumAsByte
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType.GetValue() == EWorldType::Game || Itr->GetWorld()->WorldType.GetValue() == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #else
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType == EWorldType::Game || Itr->GetWorld()->WorldType == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #endif
		{
               Itr->OnMatchNotFoundMessage.Broadcast(unreal_message);
		}
    }

    // Also notify UGSMessageListenersObject instances
    for (TObjectIterator<UGSMessageListenersObject> Itr; Itr; ++Itr)
    {
        #if GS_UE_VERSION < GS_MAKE_VERSION(4, 14) // since 4.14 auto-generated enums no longer use TEnumAsByte
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType.GetValue() == EWorldType::Game || Itr->GetWorld()->WorldType.GetValue() == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #else
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType == EWorldType::Game || Itr->GetWorld()->WorldType == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #endif
        {
            Itr->OnMatchNotFoundMessage.Broadcast(unreal_message);
        }
    }
}

void UGSMessageListeners_OnMatchUpdatedMessage(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Messages::MatchUpdatedMessage& message)
{
    FGSMatchUpdatedMessage unreal_message(message.GetBaseData());
    
    for ( TObjectIterator<UGSMessageListeners> Itr; Itr; ++Itr )
    {
        #if GS_UE_VERSION < GS_MAKE_VERSION(4, 14) // since 4.14 auto-generated enums no longer use TEnumAsByte
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType.GetValue() == EWorldType::Game || Itr->GetWorld()->WorldType.GetValue() == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #else
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType == EWorldType::Game || Itr->GetWorld()->WorldType == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #endif
		{
               Itr->OnMatchUpdatedMessage.Broadcast(unreal_message);
		}
    }

    // Also notify UGSMessageListenersObject instances
    for (TObjectIterator<UGSMessageListenersObject> Itr; Itr; ++Itr)
    {
        #if GS_UE_VERSION < GS_MAKE_VERSION(4, 14) // since 4.14 auto-generated enums no longer use TEnumAsByte
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType.GetValue() == EWorldType::Game || Itr->GetWorld()->WorldType.GetValue() == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #else
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType == EWorldType::Game || Itr->GetWorld()->WorldType == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #endif
        {
            Itr->OnMatchUpdatedMessage.Broadcast(unreal_message);
        }
    }
}

void UGSMessageListeners_OnNewHighScoreMessage(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Messages::NewHighScoreMessage& message)
{
    FGSNewHighScoreMessage unreal_message(message.GetBaseData());
    
    for ( TObjectIterator<UGSMessageListeners> Itr; Itr; ++Itr )
    {
        #if GS_UE_VERSION < GS_MAKE_VERSION(4, 14) // since 4.14 auto-generated enums no longer use TEnumAsByte
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType.GetValue() == EWorldType::Game || Itr->GetWorld()->WorldType.GetValue() == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #else
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType == EWorldType::Game || Itr->GetWorld()->WorldType == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #endif
		{
               Itr->OnNewHighScoreMessage.Broadcast(unreal_message);
		}
    }

    // Also notify UGSMessageListenersObject instances
    for (TObjectIterator<UGSMessageListenersObject> Itr; Itr; ++Itr)
    {
        #if GS_UE_VERSION < GS_MAKE_VERSION(4, 14) // since 4.14 auto-generated enums no longer use TEnumAsByte
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType.GetValue() == EWorldType::Game || Itr->GetWorld()->WorldType.GetValue() == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #else
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType == EWorldType::Game || Itr->GetWorld()->WorldType == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #endif
        {
            Itr->OnNewHighScoreMessage.Broadcast(unreal_message);
        }
    }
}

void UGSMessageListeners_OnNewTeamScoreMessage(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Messages::NewTeamScoreMessage& message)
{
    FGSNewTeamScoreMessage unreal_message(message.GetBaseData());
    
    for ( TObjectIterator<UGSMessageListeners> Itr; Itr; ++Itr )
    {
        #if GS_UE_VERSION < GS_MAKE_VERSION(4, 14) // since 4.14 auto-generated enums no longer use TEnumAsByte
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType.GetValue() == EWorldType::Game || Itr->GetWorld()->WorldType.GetValue() == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #else
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType == EWorldType::Game || Itr->GetWorld()->WorldType == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #endif
		{
               Itr->OnNewTeamScoreMessage.Broadcast(unreal_message);
		}
    }

    // Also notify UGSMessageListenersObject instances
    for (TObjectIterator<UGSMessageListenersObject> Itr; Itr; ++Itr)
    {
        #if GS_UE_VERSION < GS_MAKE_VERSION(4, 14) // since 4.14 auto-generated enums no longer use TEnumAsByte
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType.GetValue() == EWorldType::Game || Itr->GetWorld()->WorldType.GetValue() == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #else
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType == EWorldType::Game || Itr->GetWorld()->WorldType == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #endif
        {
            Itr->OnNewTeamScoreMessage.Broadcast(unreal_message);
        }
    }
}

void UGSMessageListeners_OnScriptMessage(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Messages::ScriptMessage& message)
{
    FGSScriptMessage unreal_message(message.GetBaseData());
    
    for ( TObjectIterator<UGSMessageListeners> Itr; Itr; ++Itr )
    {
        #if GS_UE_VERSION < GS_MAKE_VERSION(4, 14) // since 4.14 auto-generated enums no longer use TEnumAsByte
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType.GetValue() == EWorldType::Game || Itr->GetWorld()->WorldType.GetValue() == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #else
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType == EWorldType::Game || Itr->GetWorld()->WorldType == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #endif
		{
               Itr->OnScriptMessage.Broadcast(unreal_message);
		}
    }

    // Also notify UGSMessageListenersObject instances
    for (TObjectIterator<UGSMessageListenersObject> Itr; Itr; ++Itr)
    {
        #if GS_UE_VERSION < GS_MAKE_VERSION(4, 14) // since 4.14 auto-generated enums no longer use TEnumAsByte
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType.GetValue() == EWorldType::Game || Itr->GetWorld()->WorldType.GetValue() == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #else
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType == EWorldType::Game || Itr->GetWorld()->WorldType == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #endif
        {
            Itr->OnScriptMessage.Broadcast(unreal_message);
        }
    }
}

void UGSMessageListeners_OnSessionTerminatedMessage(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Messages::SessionTerminatedMessage& message)
{
    FGSSessionTerminatedMessage unreal_message(message.GetBaseData());
    
    for ( TObjectIterator<UGSMessageListeners> Itr; Itr; ++Itr )
    {
        #if GS_UE_VERSION < GS_MAKE_VERSION(4, 14) // since 4.14 auto-generated enums no longer use TEnumAsByte
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType.GetValue() == EWorldType::Game || Itr->GetWorld()->WorldType.GetValue() == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #else
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType == EWorldType::Game || Itr->GetWorld()->WorldType == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #endif
		{
               Itr->OnSessionTerminatedMessage.Broadcast(unreal_message);
		}
    }

    // Also notify UGSMessageListenersObject instances
    for (TObjectIterator<UGSMessageListenersObject> Itr; Itr; ++Itr)
    {
        #if GS_UE_VERSION < GS_MAKE_VERSION(4, 14) // since 4.14 auto-generated enums no longer use TEnumAsByte
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType.GetValue() == EWorldType::Game || Itr->GetWorld()->WorldType.GetValue() == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #else
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType == EWorldType::Game || Itr->GetWorld()->WorldType == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #endif
        {
            Itr->OnSessionTerminatedMessage.Broadcast(unreal_message);
        }
    }
}

void UGSMessageListeners_OnSocialRankChangedMessage(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Messages::SocialRankChangedMessage& message)
{
    FGSSocialRankChangedMessage unreal_message(message.GetBaseData());
    
    for ( TObjectIterator<UGSMessageListeners> Itr; Itr; ++Itr )
    {
        #if GS_UE_VERSION < GS_MAKE_VERSION(4, 14) // since 4.14 auto-generated enums no longer use TEnumAsByte
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType.GetValue() == EWorldType::Game || Itr->GetWorld()->WorldType.GetValue() == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #else
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType == EWorldType::Game || Itr->GetWorld()->WorldType == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #endif
		{
               Itr->OnSocialRankChangedMessage.Broadcast(unreal_message);
		}
    }

    // Also notify UGSMessageListenersObject instances
    for (TObjectIterator<UGSMessageListenersObject> Itr; Itr; ++Itr)
    {
        #if GS_UE_VERSION < GS_MAKE_VERSION(4, 14) // since 4.14 auto-generated enums no longer use TEnumAsByte
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType.GetValue() == EWorldType::Game || Itr->GetWorld()->WorldType.GetValue() == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #else
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType == EWorldType::Game || Itr->GetWorld()->WorldType == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #endif
        {
            Itr->OnSocialRankChangedMessage.Broadcast(unreal_message);
        }
    }
}

void UGSMessageListeners_OnTeamChatMessage(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Messages::TeamChatMessage& message)
{
    FGSTeamChatMessage unreal_message(message.GetBaseData());
    
    for ( TObjectIterator<UGSMessageListeners> Itr; Itr; ++Itr )
    {
        #if GS_UE_VERSION < GS_MAKE_VERSION(4, 14) // since 4.14 auto-generated enums no longer use TEnumAsByte
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType.GetValue() == EWorldType::Game || Itr->GetWorld()->WorldType.GetValue() == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #else
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType == EWorldType::Game || Itr->GetWorld()->WorldType == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #endif
		{
               Itr->OnTeamChatMessage.Broadcast(unreal_message);
		}
    }

    // Also notify UGSMessageListenersObject instances
    for (TObjectIterator<UGSMessageListenersObject> Itr; Itr; ++Itr)
    {
        #if GS_UE_VERSION < GS_MAKE_VERSION(4, 14) // since 4.14 auto-generated enums no longer use TEnumAsByte
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType.GetValue() == EWorldType::Game || Itr->GetWorld()->WorldType.GetValue() == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #else
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType == EWorldType::Game || Itr->GetWorld()->WorldType == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #endif
        {
            Itr->OnTeamChatMessage.Broadcast(unreal_message);
        }
    }
}

void UGSMessageListeners_OnTeamRankChangedMessage(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Messages::TeamRankChangedMessage& message)
{
    FGSTeamRankChangedMessage unreal_message(message.GetBaseData());
    
    for ( TObjectIterator<UGSMessageListeners> Itr; Itr; ++Itr )
    {
        #if GS_UE_VERSION < GS_MAKE_VERSION(4, 14) // since 4.14 auto-generated enums no longer use TEnumAsByte
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType.GetValue() == EWorldType::Game || Itr->GetWorld()->WorldType.GetValue() == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #else
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType == EWorldType::Game || Itr->GetWorld()->WorldType == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #endif
		{
               Itr->OnTeamRankChangedMessage.Broadcast(unreal_message);
		}
    }

    // Also notify UGSMessageListenersObject instances
    for (TObjectIterator<UGSMessageListenersObject> Itr; Itr; ++Itr)
    {
        #if GS_UE_VERSION < GS_MAKE_VERSION(4, 14) // since 4.14 auto-generated enums no longer use TEnumAsByte
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType.GetValue() == EWorldType::Game || Itr->GetWorld()->WorldType.GetValue() == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #else
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType == EWorldType::Game || Itr->GetWorld()->WorldType == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #endif
        {
            Itr->OnTeamRankChangedMessage.Broadcast(unreal_message);
        }
    }
}

void UGSMessageListeners_OnUploadCompleteMessage(GameSparks::Core::GS& gsInstance, const GameSparks::Api::Messages::UploadCompleteMessage& message)
{
    FGSUploadCompleteMessage unreal_message(message.GetBaseData());
    
    for ( TObjectIterator<UGSMessageListeners> Itr; Itr; ++Itr )
    {
        #if GS_UE_VERSION < GS_MAKE_VERSION(4, 14) // since 4.14 auto-generated enums no longer use TEnumAsByte
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType.GetValue() == EWorldType::Game || Itr->GetWorld()->WorldType.GetValue() == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #else
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType == EWorldType::Game || Itr->GetWorld()->WorldType == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #endif
		{
               Itr->OnUploadCompleteMessage.Broadcast(unreal_message);
		}
    }

    // Also notify UGSMessageListenersObject instances
    for (TObjectIterator<UGSMessageListenersObject> Itr; Itr; ++Itr)
    {
        #if GS_UE_VERSION < GS_MAKE_VERSION(4, 14) // since 4.14 auto-generated enums no longer use TEnumAsByte
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType.GetValue() == EWorldType::Game || Itr->GetWorld()->WorldType.GetValue() == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #else
        if(Itr->GetWorld() != nullptr && (Itr->GetWorld()->WorldType == EWorldType::Game || Itr->GetWorld()->WorldType == EWorldType::PIE) && (!Itr->IsPendingKill()))
        #endif
        {
            Itr->OnUploadCompleteMessage.Broadcast(unreal_message);
        }
    }
}


UGSMessageListeners::UGSMessageListeners(){}

void UGSMessageListeners::RegisterListeners(GS& GS)
{
    GS.SetMessageListener<GameSparks::Api::Messages::AchievementEarnedMessage>(UGSMessageListeners_OnAchievementEarnedMessage);
    GS.SetMessageListener<GameSparks::Api::Messages::ChallengeAcceptedMessage>(UGSMessageListeners_OnChallengeAcceptedMessage);
    GS.SetMessageListener<GameSparks::Api::Messages::ChallengeChangedMessage>(UGSMessageListeners_OnChallengeChangedMessage);
    GS.SetMessageListener<GameSparks::Api::Messages::ChallengeChatMessage>(UGSMessageListeners_OnChallengeChatMessage);
    GS.SetMessageListener<GameSparks::Api::Messages::ChallengeDeclinedMessage>(UGSMessageListeners_OnChallengeDeclinedMessage);
    GS.SetMessageListener<GameSparks::Api::Messages::ChallengeDrawnMessage>(UGSMessageListeners_OnChallengeDrawnMessage);
    GS.SetMessageListener<GameSparks::Api::Messages::ChallengeExpiredMessage>(UGSMessageListeners_OnChallengeExpiredMessage);
    GS.SetMessageListener<GameSparks::Api::Messages::ChallengeIssuedMessage>(UGSMessageListeners_OnChallengeIssuedMessage);
    GS.SetMessageListener<GameSparks::Api::Messages::ChallengeJoinedMessage>(UGSMessageListeners_OnChallengeJoinedMessage);
    GS.SetMessageListener<GameSparks::Api::Messages::ChallengeLapsedMessage>(UGSMessageListeners_OnChallengeLapsedMessage);
    GS.SetMessageListener<GameSparks::Api::Messages::ChallengeLostMessage>(UGSMessageListeners_OnChallengeLostMessage);
    GS.SetMessageListener<GameSparks::Api::Messages::ChallengeStartedMessage>(UGSMessageListeners_OnChallengeStartedMessage);
    GS.SetMessageListener<GameSparks::Api::Messages::ChallengeTurnTakenMessage>(UGSMessageListeners_OnChallengeTurnTakenMessage);
    GS.SetMessageListener<GameSparks::Api::Messages::ChallengeWaitingMessage>(UGSMessageListeners_OnChallengeWaitingMessage);
    GS.SetMessageListener<GameSparks::Api::Messages::ChallengeWithdrawnMessage>(UGSMessageListeners_OnChallengeWithdrawnMessage);
    GS.SetMessageListener<GameSparks::Api::Messages::ChallengeWonMessage>(UGSMessageListeners_OnChallengeWonMessage);
    GS.SetMessageListener<GameSparks::Api::Messages::FriendMessage>(UGSMessageListeners_OnFriendMessage);
    GS.SetMessageListener<GameSparks::Api::Messages::GlobalRankChangedMessage>(UGSMessageListeners_OnGlobalRankChangedMessage);
    GS.SetMessageListener<GameSparks::Api::Messages::MatchFoundMessage>(UGSMessageListeners_OnMatchFoundMessage);
    GS.SetMessageListener<GameSparks::Api::Messages::MatchNotFoundMessage>(UGSMessageListeners_OnMatchNotFoundMessage);
    GS.SetMessageListener<GameSparks::Api::Messages::MatchUpdatedMessage>(UGSMessageListeners_OnMatchUpdatedMessage);
    GS.SetMessageListener<GameSparks::Api::Messages::NewHighScoreMessage>(UGSMessageListeners_OnNewHighScoreMessage);
    GS.SetMessageListener<GameSparks::Api::Messages::NewTeamScoreMessage>(UGSMessageListeners_OnNewTeamScoreMessage);
    GS.SetMessageListener<GameSparks::Api::Messages::ScriptMessage>(UGSMessageListeners_OnScriptMessage);
    GS.SetMessageListener<GameSparks::Api::Messages::SessionTerminatedMessage>(UGSMessageListeners_OnSessionTerminatedMessage);
    GS.SetMessageListener<GameSparks::Api::Messages::SocialRankChangedMessage>(UGSMessageListeners_OnSocialRankChangedMessage);
    GS.SetMessageListener<GameSparks::Api::Messages::TeamChatMessage>(UGSMessageListeners_OnTeamChatMessage);
    GS.SetMessageListener<GameSparks::Api::Messages::TeamRankChangedMessage>(UGSMessageListeners_OnTeamRankChangedMessage);
    GS.SetMessageListener<GameSparks::Api::Messages::UploadCompleteMessage>(UGSMessageListeners_OnUploadCompleteMessage);
}
