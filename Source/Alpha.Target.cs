// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

/* Source for changes made to target .cs 
 * https://forums.unrealengine.com/development-discussion/c-gameplay-programming/118722-c-4-16-transition-guide
 */ 

using UnrealBuildTool;
using System.Collections.Generic;

public class AlphaTarget : TargetRules
{
	public AlphaTarget(TargetInfo Target) : base(Target)
	{
        Type = TargetType.Game;
        ExtraModuleNames.AddRange(new string[] { "Alpha" });
	}
}
