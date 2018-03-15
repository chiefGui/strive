#pragma once
#include "../GameSparksPrivatePCH.h"
#include "Engine.h"

#if !defined(GS_BUILDING_DLL)
#       define GS_BUILDING_DLL 1
#endif /* !defined(GS_BUILDING_DLL) */

#include <GameSparks/GSLinking.h>
#include <GameSparksRT/IRTSession.hpp>
#include <GameSparksRT/IRTSessionListener.hpp>
#include <memory>
#include <mutex>
#include "UGSRTVector.h"
#include "UGSRTData.h"
#include "UGSRTSession.generated.h"

UENUM(BlueprintType)		//"BlueprintType" is essential to include
enum class DeliveryIntent : uint8
{
	RELIABLE = 0 UMETA(DisplayName = "RELIABLE"),

	/// <summary>
	/// Send over UDP, don't discard out of sequence packets
	/// </summary>
	UNRELIABLE = 1 UMETA(DisplayName = "UNRELIABLE"),

	/// <summary>
	/// Send over UDP, discard out of sequence packets
	/// </summary>
	UNRELIABLE_SEQUENCED = 2 UMETA(DisplayName = "UNRELIABLE_SEQUENCED")
};

UCLASS(BlueprintType, Blueprintable)
class UGSRTSession : public UObject, public FTickableGameObject//, public GameSparks::RT::IRTSessionListener
{
		GENERATED_UCLASS_BODY()
		virtual ~UGSRTSession();
    public:

		/* Create a new GS Data object. */
		UFUNCTION(BlueprintCallable, meta = (DisplayName = "Create GS RT Session", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"), Category = "GameSparksRT|Session")
		static UGSRTSession* CreateRTSession(UObject* WorldContextObject, FString host, FString port, FString token);

		UFUNCTION(BlueprintCallable, Category = "GameSparksRT|Session")
		void Start();

        UFUNCTION(BlueprintCallable, Category = "GameSparksRT|Session")
        void Stop();

        UFUNCTION(BlueprintCallable, Category = "GameSparksRT|Session")
        void Send(int32 opCode, DeliveryIntent intent, UGSRTData* data, TArray<int32> peerIds);

		UFUNCTION(BlueprintPure, Category = "GameSparksRT|Session")
		TArray<int32> GetActivePeers();

		UFUNCTION(BlueprintPure, Category = "GameSparksRT|Session")
		int32 GetPeerId();

		DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnReady, UGSRTSession*, session, bool, ready);
		UPROPERTY(BlueprintAssignable, Category = GameSparksRT)
		FOnReady OnReadyDelegate;

		DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPlayerConnect, UGSRTSession*, session, int32, peerId);
		UPROPERTY(BlueprintAssignable, Category = GameSparksRT)
        FOnPlayerConnect OnPlayerConnectDelegate;

		DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPlayerDisconnect, UGSRTSession*, session, int32, peerId);
		UPROPERTY(BlueprintAssignable, Category = GameSparksRT)
		FOnPlayerDisconnect OnPlayerDisconnectDelegate;

		DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnData, UGSRTSession*, session, int32, sender, int32, opCode, UGSRTData*, data);
		UPROPERTY(BlueprintAssignable, Category = GameSparksRT)
		FOnData OnDataDelegate;

		UPROPERTY(EditAnywhere, Category = GameSparksRT)
		bool IsReady;

        /*DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPlayerDisconnect, int, peerId);
        UPROPERTY(BlueprintAssignable, Category = GameSparksRT)
        FOnPlayerDisconnect OnPlayerDisconnectDelegate;

        DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnReady, int, peerId);
        UPROPERTY(BlueprintAssignable, Category = GameSparksRT)
        FOnReady OnReadyDelegate;*/
    private:
		virtual void Tick(float DeltaTime) override;
		virtual bool IsTickable() const override;
		virtual TStatId GetStatId() const override;

        /// <summary>
        /// Executed when another player joins the room.
        /// </summary>
        /// <param name="peerId">The player who has just joined</param>
        virtual void OnPlayerConnect (int peerId);

        /// <summary>
        /// Executed when another player leaves the room.
        /// </summary>
        /// <param name="peerId">The player who has just left</param>
        virtual void OnPlayerDisconnect (int peerId);

        /// <summary>
        /// Executed when the SDK moves between a ready and non ready state
        /// </summary>
        /// <param name="ready">Whether the SDK is in a ready state (or not)</param>
        virtual void OnReady (bool ready);

        /// <summary>
        /// Executed when the SDK recieves a message from another player via SendPacket
        /// </summary>
        /// <param name="opCode">The opCode sent by the other player</param>
        /// <param name="sender">The peerId of the other player</param>
        /// <param name="stream">The stream of bytes sent by the other player</param>
        /// <param name="length">The number of bytes in the stream that can be read</param>
        virtual void OnPacket (const GameSparks::RT::RTPacket& packet);

		// unfortunately, UObject do not support multiple inheritance, so we have to jump some hoops and
		// forward the calls
		class RTSessionListenerProxy : public GameSparks::RT::IRTSessionListener
		{
		public:
			RTSessionListenerProxy(UGSRTSession* proxy_)
				:proxy(proxy_) {}

			virtual void OnPlayerConnect(int peerId) override
			{
				proxy->OnPlayerConnect(peerId);
			}

			virtual void OnPlayerDisconnect(int peerId) override
			{
				proxy->OnPlayerDisconnect(peerId);
			}

			virtual void OnReady(bool ready) override
			{
				proxy->OnReady(ready);
			}

			virtual void OnPacket(const GameSparks::RT::RTPacket& packet) override
			{
				proxy->OnPacket(packet);
			}
		private:
			UGSRTSession* proxy;
		};
		TUniquePtr<RTSessionListenerProxy> sessionListener;
        TUniquePtr<GameSparks::RT::IRTSession> session;
		std::recursive_mutex sessionMutex;
		bool started = false;
};
