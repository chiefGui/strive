using UnrealBuildTool;
using System.Collections.Generic;

public class StriveServerTarget : TargetRules
{
    public StriveServerTarget(TargetInfo Target) : base(Target)
    {
        Type = TargetType.Server;

        ExtraModuleNames.AddRange(new string[] { "Strive" });

        bUseLoggingInShipping = true;
    }
}