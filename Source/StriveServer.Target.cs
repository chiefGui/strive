// Copyright 1998-2018 Vincae Entertainment. All rights reserved.

using UnrealBuildTool;
using System.Collections.Generic;

[SupportedPlatforms(UnrealPlatformClass.Server)]
public class StriveServerTarget : TargetRules
{
    public StriveServerTarget(TargetInfo Target) : base(Target)
    {
        Type = TargetType.Server;
        ExtraModuleNames.Add("Strive");

        bUseLoggingInShipping = true;
    }
}