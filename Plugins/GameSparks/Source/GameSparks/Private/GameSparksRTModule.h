#pragma once

#include "IGameSparksRT.h"
#include "Runtime/Engine/Public/Tickable.h"
#include <string>

DECLARE_LOG_CATEGORY_EXTERN(UGameSparksRTModuleLog, Log, All);

class UGameSparksRTModule : public IGameSparksRT, public FTickableGameObject
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule();
	virtual void ShutdownModule();

	/** FTickableGameObject implementation */
    virtual bool IsTickableWhenPaused() const;
    virtual bool IsTickableInEditor() const;
    virtual void Tick(float DeltaTime);
	virtual bool IsTickable() const;
	virtual TStatId GetStatId() const;

	/* Initialization and destruction of gamesparks */
	static UGameSparksRTModule* GetModulePtr();
private:

    
    //GameSparks::Core::GS GS;
    
    bool isInitialised = false;
    

};
