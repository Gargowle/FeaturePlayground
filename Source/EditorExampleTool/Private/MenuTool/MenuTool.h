#pragma once

#include "EditorExampleToolModuleInterface.h"


class MenuTool : public IEditorExampleToolModuleListenerInterface, public TSharedFromThis<MenuTool>
{
public:
	virtual ~MenuTool() {}

	virtual void OnStartupModule() override;
	virtual void OnShutdownModule() override;

	void MakeMenuEntries(FMenuBuilder& menuBuilder);
	void MakeSubMenu(FMenuBuilder& menuBuilder);

protected:
	// Define and map a menu item to a function
	TSharedPtr<FUICommandList> CommandList;

	void MapCommands();

	// Functions to be called when user clicks on the menu item
	void MenuCommand1();
	void MenuCommand2();
	void MenuCommand3();

	// properties used for small widget inside the pulldown menu to set tags on a selected actor
	FName TagToAdd;

	FReply AddTag();
	FText GetTagToAddText() const;
	void OnTagToAddTextCommitted(const FText& InText, ETextCommit::Type CommitInfo);
};
