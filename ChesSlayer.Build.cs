// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ChesSlayer : ModuleRules
{
	public ChesSlayer(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", 
			"HeadMountedDisplay", "NavigationSystem", "AIModule", "Niagara", "EnhancedInput", "UMG", "Slate", 
			"SlateCore", "AIModule", "GameplayTasks", "MediaAssets"});
    }
}
