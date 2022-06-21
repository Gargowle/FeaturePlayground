#include "EditorExampleToolModule.h"
#include "EditorExampleToolModuleInterface.h"

IMPLEMENT_MODULE(FEditorExampleTool, EditorExampleTool)

void FEditorExampleTool::AddModuleListeners()
{
	// Add tools here once a tool actually is implemented in this module
}

void FEditorExampleTool::StartupModule()
{
	IEditorExampleToolModuleInterface::StartupModule();
}

void FEditorExampleTool::ShutdownModule()
{
	IEditorExampleToolModuleInterface::ShutdownModule();
}
