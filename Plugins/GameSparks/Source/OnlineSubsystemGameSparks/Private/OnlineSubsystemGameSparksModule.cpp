#include "OnlineSubsystemGameSparksModule.h"
#include "OnlineSubsystemGameSparksPrivatePCH.h"

// FOnlineSubsystemGameSparksModule

IMPLEMENT_MODULE(FOnlineSubsystemGameSparksModule, OnlineSubsystemGameSparks);

/**
 * Class responsible for creating instance(s) of the subsystem
 */
class FOnlineFactoryGameSparks : public IOnlineFactory
{
public:

	FOnlineFactoryGameSparks() {}
	virtual ~FOnlineFactoryGameSparks() {}

	virtual IOnlineSubsystemPtr CreateSubsystem(FName InstanceName)
	{
		FOnlineSubsystemGameSparksPtr OnlineSub = MakeShareable(new FOnlineSubsystemGameSparks());
		if (OnlineSub->IsEnabled())
		{
			if(!OnlineSub->Init())
			{
				UE_LOG(LogOnline, Warning, TEXT("GameSparks API failed to initialize!"));
				OnlineSub->Shutdown();
				OnlineSub = NULL;
			}
		}
		else
		{
			UE_LOG(LogOnline, Warning, TEXT("GameSparks API disabled!"));
			OnlineSub->Shutdown();
			OnlineSub = NULL;
		}

		return OnlineSub;
	}
};

// inclusion into OnlineSubsystemNames.h ?
#ifndef GAMESPARKS_SUBSYSTEM
#	define GAMESPARKS_SUBSYSTEM FName(TEXT("GAMESPARKS"))
#endif

void FOnlineSubsystemGameSparksModule::StartupModule()
{
	UE_LOG(LogOnline, Log, TEXT("SubsystemGameSparks Startup!"));

	GameSparksFactory = new FOnlineFactoryGameSparks();

	// Create and register our singleton factory with the main online subsystem for easy access
	FOnlineSubsystemModule* OSS = FModuleManager::GetModulePtr<FOnlineSubsystemModule>("OnlineSubsystem");
	if(OSS)
	{
		OSS->RegisterPlatformService(GAMESPARKS_SUBSYSTEM, GameSparksFactory);		
	}
}

void FOnlineSubsystemGameSparksModule::ShutdownModule()
{
	UE_LOG(LogOnline, Log, TEXT("SubsystemGameSparks Shutdown!"));

	FOnlineSubsystemModule* OSS = FModuleManager::GetModulePtr<FOnlineSubsystemModule>("OnlineSubsystem");

	if(OSS)
	{
		OSS->UnregisterPlatformService(GAMESPARKS_SUBSYSTEM);		
	}

	delete GameSparksFactory;
	GameSparksFactory = NULL;
}

DEFINE_LOG_CATEGORY(GSOSSLog);