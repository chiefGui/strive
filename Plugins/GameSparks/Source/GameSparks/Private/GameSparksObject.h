#pragma once

#include "GSTypes.h"
#include "Components/SceneComponent.h"
#include "GameSparksObject.generated.h"

UCLASS(Blueprintable, BlueprintType)
class GAMESPARKS_API UGameSparksObject : public UObject
{
	GENERATED_BODY()

public:

    UGameSparksObject(const FObjectInitializer& ObjectInitializer);
    
    // Connects to the GameSparks service with the supplied details
    // * apiKey - The API Key of the game to connect to
    // * secret - The API Secret of the game to connect to
    // * Preview Server - Whether to connect to the live, or preview servers
    // * clearCachedAuthentication - Forgets any cached authentication details before connecting
    UFUNCTION(Category = GameSparks, BlueprintCallable)
    void Connect(FString apikey, FString secret, bool previewServer=true, bool clearCachedAuthentication=false);

    //! set the API credential type (like device, server, etc.) - use empty string to reset to the default. the default is "device"
    UFUNCTION(Category = GameSparks, BlueprintCallable)
    void SetApiCredential(FString credential);

    //! Set the api stage. if you passed usePreviewServer=true into Connect(), this will be "preview", "live" otherwise.
    UFUNCTION(Category = GameSparks, BlueprintCallable)
    void SetApiStage(FString stage);

    //! set api domain to use. pass empty string to reset to the default. The default is "ws.gamesparks.net"
    UFUNCTION(Category = GameSparks, BlueprintCallable)
    void SetApiDomain(FString domain);

    // Disconnects the socket, clears cached authentication details, and reconnects
    UFUNCTION(Category = GameSparks, BlueprintCallable)
    void Logout();
    
    // Disconnects the from GameSparks
    UFUNCTION(Category = GameSparks, BlueprintCallable)
    void Disconnect();

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGameSparksAvailable, bool, available);

	// Called by GameSparks when the availability changed
	UPROPERTY(BlueprintAssignable, Category = GameSparks)
	FOnGameSparksAvailable OnGameSparksAvailableDelegate;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGameSparksLogEvent, FString, logMessage);

	// Called by GameSparks when a new log message was generated, useful for debugging
	UPROPERTY(BlueprintAssignable, Category = GameSparks)
	FOnGameSparksLogEvent OnGameSparksDebugLog;

    // Indicates if the current socket is connected and has an associated player
    UFUNCTION(Category = GameSparks, BlueprintCallable)
    bool IsAuthenticated();

    // Indicates if the current socket is connected
    UFUNCTION(Category = GameSparks, BlueprintCallable)
    bool IsAvailable();

	virtual class UWorld* GetWorld() const override;
};