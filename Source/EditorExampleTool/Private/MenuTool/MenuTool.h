#pragma once

#include "EditorExampleToolModuleInterface.h"


class MenuTool : public IEditorExampleToolModuleListenerInterface, public TSharedFromThis<MenuTool>
{
public:
	virtual ~MenuTool() {}

	virtual void OnStartupModule() override;
	virtual void OnShutdownModule() override;

	void MakeMenuEntry(FMenuBuilder& menuBuilder);

protected:
	// Define and map a menu item to a function
	TSharedPtr<FUICommandList> CommandList;

	void MapCommands();

	// Function to be called when user clicks on the menu item
	void MenuCommand1();
};
