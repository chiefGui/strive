// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

[SupportedPlatforms(UnrealPlatformClass.Server)]
public class MantiquenServerTarget : TargetRules
{
    public MantiquenServerTarget(TargetInfo Target) : base(Target)
    {
        Type = TargetType.Server;

        ExtraModuleNames.AddRange(new string[] { "Mantiquen" });
    }
}