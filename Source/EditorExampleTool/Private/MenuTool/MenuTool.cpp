#include "MenuTool.h"

#include "EditorExampleToolModule.h"
#include "Framework/Commands/UICommandList.h"
#include "Framework/Commands/Commands.h"

//Required for UI_COMMAND macro
#define LOCTEXT_NAMESPACE "MenuTool"

class MenuToolCommands : public TCommands<MenuToolCommands>
{
public:
	// Default constructor passes some default arguments to parent class
	MenuToolCommands() : TCommands<MenuToolCommands>(
								TEXT("MenuTool"), // Context name for fast lookup
								FText::FromString("Example Menu Tool"), // Context name for displaying
								NAME_None, // No parent context
								FEditorStyle::GetStyleSetName() //Icon styleSet
								)
	{
	}

	TSharedPtr<FUICommandInfo> MenuCommand1;
	TSharedPtr<FUICommandInfo> MenuCommand2;
	TSharedPtr<FUICommandInfo> MenuCommand3;

	virtual void RegisterCommands() override
	{
		UI_COMMAND(MenuCommand1, "Menu Command 1", "Test Menu Command 1.", EUserInterfaceActionType::Button, FInputGesture());		
		UI_COMMAND(MenuCommand2, "Menu Command 2", "Test Menu Command 2.", EUserInterfaceActionType::Button, FInputGesture());		
		UI_COMMAND(MenuCommand3, "Menu Command 3", "Test Menu Command 3.", EUserInterfaceActionType::Button, FInputGesture());		
	}
};

void MenuTool::OnStartupModule()
{
	CommandList = MakeShareable<FUICommandList>(new FUICommandList);

	MenuToolCommands::Register();
	MapCommands();
	FEditorExampleTool::Get().AddMenuExtension(FMenuExtensionDelegate::CreateRaw(this, &MenuTool::MakeMenuEntries), FName("Section_1"), CommandList);
}

void MenuTool::OnShutdownModule()
{
	MenuToolCommands::Unregister();
}

void MenuTool::MakeMenuEntries(FMenuBuilder& menuBuilder)
{
	menuBuilder.AddMenuEntry(MenuToolCommands::Get().MenuCommand1);
	menuBuilder.AddSubMenu(
		FText::FromString("Sub Menu"),
		FText::FromString("This is an example sub menu"),
		FNewMenuDelegate::CreateSP(this, &MenuTool::MakeSubMenu)
		);
}

void MenuTool::MakeSubMenu(FMenuBuilder& menuBuilder)
{
	menuBuilder.AddMenuEntry(MenuToolCommands::Get().MenuCommand2);
	menuBuilder.AddMenuEntry(MenuToolCommands::Get().MenuCommand3);
}

void MenuTool::MapCommands()
{
	const MenuToolCommands& Commands = MenuToolCommands::Get();

	CommandList->MapAction(Commands.MenuCommand1, FExecuteAction::CreateSP(this, &MenuTool::MenuCommand1), FCanExecuteAction());
	CommandList->MapAction(Commands.MenuCommand2, FExecuteAction::CreateSP(this, &MenuTool::MenuCommand2), FCanExecuteAction());
	CommandList->MapAction(Commands.MenuCommand3, FExecuteAction::CreateSP(this, &MenuTool::MenuCommand3), FCanExecuteAction());
}

void MenuTool::MenuCommand1()
{
	UE_LOG(LogClass, Log, TEXT("clicked MenuCommand1")); //TODO: actually use LOCTEXT
}

void MenuTool::MenuCommand2()
{
	UE_LOG(LogClass, Log, TEXT("clicked MenuCommand2")); //TODO: actually use LOCTEXT
}

void MenuTool::MenuCommand3()
{
	UE_LOG(LogClass, Log, TEXT("clicked MenuCommand3")); //TODO: actually use LOCTEXT
}


#undef LOCTEXT_NAMESPACE
