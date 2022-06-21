// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class FeaturePlaygroundEditorTarget : TargetRules
{
	public FeaturePlaygroundEditorTarget( TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		ExtraModuleNames.AddRange( new string[] { "FeaturePlayground" } );
		ExtraModuleNames.AddRange( new string[] { "EditorExampleTool" } );
	}
}
