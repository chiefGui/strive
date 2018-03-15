#pragma once

#include "Core.h"
#include "ModuleInterface.h"
#include "OnlineSubsystemGameSparksPackage.h"

/**
 * Online subsystem module class (GameSparks Implementation)
 * Code related to the loading and handling of the GameSparks module.
 */
class FOnlineSubsystemGameSparksModule : public IModuleInterface
{
private:

	/** Class responsible for creating instance(s) of the subsystem */
	class FOnlineFactoryGameSparks* GameSparksFactory;

public:	

	// IModuleInterface 

	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	virtual bool SupportsDynamicReloading() override
	{
		return false;
	}
	virtual bool SupportsAutomaticShutdown() override
	{
		return false;
	}

	// FOnlineSubsystemGameSparksModule

	/**
	 * Constructor
	 */
	FOnlineSubsystemGameSparksModule() :
		GameSparksFactory(NULL)
	{}

	/**
	 * Destructor
	 */
	virtual ~FOnlineSubsystemGameSparksModule() 
	{}
};


