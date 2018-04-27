// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;

public class Strive : ModuleRules
{
	public Strive(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] {
            "Core",
            "CoreUObject",
            "Engine",
            "InputCore",
            "Sockets",
            "GameSparks",
            "OnlineSubsystem",
            "OnlineSubsystemUtils",
            "GameLiftServerSDK"
        });

        PrivateDependencyModuleNames.AddRange(new string[] { });

        DynamicallyLoadedModuleNames.Add("OnlineSubsystemSteam");

        bEnableExceptions = true;

        if (Target.Type == TargetType.Server)
        {
            Definitions.Add("WITH_GAMELIFT=1");
        } else
        {
            Definitions.Add("WITH_GAMELIFT=0");
        }

        /**
        if (Target.Type == TargetType.Server)
        {
            bEnableExceptions = true;
            PublicDependencyModuleNames.AddRange(new string[] { "GameLiftServerSDK" });
        } else
        {
            Definitions.Add("WITH_GAMELIFT=0");
        }
        */

        // Uncomment if you are using Slate UI
        // PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

        // Uncomment if you are using online features
        // PrivateDependencyModuleNames.Add("OnlineSubsystem");

        // To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
    }
}
