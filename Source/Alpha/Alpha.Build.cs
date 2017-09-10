// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

/* Source for changes made to target .cs 
 * https://forums.unrealengine.com/development-discussion/c-gameplay-programming/118722-c-4-16-transition-guide
 */

public class Alpha : ModuleRules
{
    public Alpha(ReadOnlyTargetRules Target) : base(Target) 
    {
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "UMG", "Slate", "SlateCore" });
    }
    /*
	//public Alpha(TargetInfo Target) :
	{
	}
 */
}
