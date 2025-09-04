// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Game_C_01 : ModuleRules
{
	public Game_C_01(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
