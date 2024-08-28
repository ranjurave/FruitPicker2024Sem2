// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class FruitPicker : ModuleRules
{
	public FruitPicker(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
