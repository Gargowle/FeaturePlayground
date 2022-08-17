using UnrealBuildTool;

public class EditorExampleTool : ModuleRules

{
	public EditorExampleTool(ReadOnlyTargetRules Target) : base(Target)
	{
		PublicDependencyModuleNames.AddRange(new string[] {"InputCore"});
		PrivateDependencyModuleNames.AddRange(new string[] {"Core", "Engine", "CoreUObject", "Slate", "SlateCore", "EditorStyle", "LevelEditor", "UnrealEd" });
	}
}
