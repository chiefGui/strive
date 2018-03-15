// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

[SupportedPlatforms(UnrealPlatformClass.Server)]
public class MantiquenServerTarget : TargetRules   // Change this line as shown previously
{
    public MantiquenServerTarget(TargetInfo Target) : base(Target)  // Change this line as shown previously
    {
        Type = TargetType.Server;
        ExtraModuleNames.Add("Mantiquen");    // Change this line as shown previously
    }
}