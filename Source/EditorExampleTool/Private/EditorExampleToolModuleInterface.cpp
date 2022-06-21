#include "EditorExampleToolModuleInterface.h"

void IEditorExampleToolModuleInterface::StartupModule()
{
	if(!IsRunningCommandlet()) // TODO: find out what this command does
	{
		AddModuleListeners();
		for (int32 i = 0; i < ModuleListeners.Num() ; i++) // TODO: look which  data type is returned by the .Num() method and adapt the type of i accordingly
		{
			ModuleListeners[i]->OnStartupModule();
		}
	}
}

void IEditorExampleToolModuleInterface::ShutdownModule()
{
	for (int32 i = 0; i < ModuleListeners.Num(); i++) // TODO: look which  data type is returned by the .Num() method and adapt the type of i accordingly
	{
		ModuleListeners[i]->OnShutdownModule();
	}
}
