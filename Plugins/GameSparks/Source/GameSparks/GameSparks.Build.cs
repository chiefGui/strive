using UnrealBuildTool;
using System.IO;
using System;

public class GameSparks : ModuleRules
{
    #if WITH_FORWARDED_MODULE_RULES_CTOR
    public GameSparks(ReadOnlyTargetRules Target) : base(Target) // > 4.15
    #else
    public GameSparks(TargetInfo Target) // < 4.15
    #endif
    {
        AddDefinition("GS_BUILDING_MODULE=1");
        AddDefinition("GAMESPARKS_PACKAGE=1");

        PrivateDependencyModuleNames.AddRange(
            new string[] { 
                "Core", 
                "CoreUObject", 
                "Engine", 
                "InputCore",
                "OnlineSubsystemUtils",
                "OnlineSubsystem", // required for OnlineDelegateMacros.h
                "Json",
            }
        );

        PublicIncludePaths.Add(Path.Combine(GameSparksPath, "include"));

        PrivateIncludePaths.AddRange(new string[]{
            Path.Combine(GameSparksPath, "src", "GameSparks"),
            Path.Combine(GameSparksPath, "src", "cjson"),
            Path.Combine(GameSparksPath, "src", "easywsclient"),
            Path.Combine(GameSparksPath, "src", "google"),
            Path.Combine(GameSparksPath, "src", "hmac"),
            Path.Combine(GameSparksPath, "src", "mbedtls"),
            Path.Combine(GameSparksPath, "src")
        });

        switch (Target.Platform)
        {
            case UnrealTargetPlatform.Win32:
                break;
            case UnrealTargetPlatform.Win64:
                break;
            case UnrealTargetPlatform.Android:
                break;
            case UnrealTargetPlatform.IOS:
                PublicAdditionalLibraries.Add("c++");
                break;
            case UnrealTargetPlatform.Mac:
                break;
            case UnrealTargetPlatform.PS4:
                break;
            case UnrealTargetPlatform.XboxOne:
                break;
            case UnrealTargetPlatform.Linux:
                break;
            case UnrealTargetPlatform.Switch:
                AddDefinition("GS_USE_IN_MEMORY_PERSISTENT_STORAGE=1");
                break;

            case UnrealTargetPlatform.HTML5:
            default:
                throw new NotImplementedException("This target platform is not configured for GameSparks SDK: " + Target.Platform.ToString());
        }

        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
    }

    private void AddDefinition(string def)
    {
        #if UE_4_19_OR_LATER
            PublicDefinitions.Add(def);
        #else
            Definitions.Add(def);
        #endif
    }

    private string ModulePath
    {
        get { return ModuleDirectory; }
    }

    private string GameSparksPath
    {
        get { return Path.GetFullPath(Path.Combine(ModulePath, "..", "GameSparksBaseSDK")); }
    }
}
