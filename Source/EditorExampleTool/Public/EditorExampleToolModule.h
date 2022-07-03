#pragma once

#include "EditorExampleToolModuleInterface.h"

class FExtensibilityManager;
class FExtender;
class FWorkspaceItem;
class FMenuBarBuilder;
class FMenuBuilder;

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

public:
	void AddMenuExtension(const FMenuExtensionDelegate& ExtensionDelegate, FName ExtensionHook, const TSharedPtr<FUICommandList>& CommandList = NULL, EExtensionHook::Position Position = EExtensionHook::Before);
	static TSharedRef<FWorkspaceItem> GetMenuRoot();

protected:
	TSharedPtr<FExtensibilityManager> LevelEditorMenuExtensibilityManager;
	TSharedPtr<FExtender> MenuExtender;

	static TSharedRef<FWorkspaceItem> MenuRoot;

	void MakePullownMenu(FMenuBarBuilder& MenuBarBuilder);
	void FillPulldownMenu(FMenuBuilder& MenuBuilder);
};
