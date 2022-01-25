// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Fighting_Demo : ModuleRules
{
	public Fighting_Demo(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });
	}
}
