using UnrealBuildTool; 

public class MyFooModule: ModuleRules 

{
	public MyFooModule(ReadOnlyTargetRules Target) : base(Target) 
	{
		PublicDependencyModuleNames.AddRange(new string[] {});
		PrivateDependencyModuleNames.AddRange(new string[] {"Core", "CoreUObject", "Engine"});
	} 
}