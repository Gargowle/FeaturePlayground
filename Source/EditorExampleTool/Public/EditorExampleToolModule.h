#pragma once

#include "EditorExampleToolModuleInterface.h"

class FEditorExampleTool : public IEditorExampleToolModuleInterface
{
public:
	// IModuleInterface implementation
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	virtual void AddModuleListeners() override;

	// convenience functions
	/*
	 * Getter function for this module that allows for easier and less verbose access to the module than the FModuleManager::LoadModuleChecked method
	 */
	static inline FEditorExampleTool& Get()
	{
		return FModuleManager::LoadModuleChecked<FEditorExampleTool>("EditorExampleTool");
	}

	static inline bool IsAvailable()
	{
		return FModuleManager::Get().IsModuleLoaded("EditorExampleTool");
	}

};
