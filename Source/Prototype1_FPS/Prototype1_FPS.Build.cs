// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Prototype1_FPS : ModuleRules
{
	public Prototype1_FPS(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
