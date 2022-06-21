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
	static inline FEditorExampleTool& Get()
	{
		// TODO: completely understan what this method call does;
		// TODO: write according docstring
		return FModuleManager::LoadModuleChecked<FEditorExampleTool>("EditorExampleTool");
	}

	static inline bool IsAvailable()
	{
		return FModuleManager::Get().IsModuleLoaded("EditorExampleTool");
	}

};
