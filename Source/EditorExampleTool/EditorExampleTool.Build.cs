using UnrealBuildTool;

public class EditorExampleTool : ModuleRules

{
	public EditorExampleTool(ReadOnlyTargetRules Target) : base(Target)
	{
		PublicDependencyModuleNames.AddRange(new string[] {});
		PrivateDependencyModuleNames.AddRange(new string[] {"Core", "Engine", "CoreUObject"});
	}
}
