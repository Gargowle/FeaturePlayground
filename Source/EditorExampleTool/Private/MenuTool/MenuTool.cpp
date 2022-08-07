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

	virtual void RegisterCommands() override
	{
		UI_COMMAND(MenuCommand1, "Menu Command 1", "Test Menu Command 1.", EUserInterfaceActionType::Button, FInputGesture());		
	}
};

void MenuTool::OnStartupModule()
{
	CommandList = MakeShareable<FUICommandList>(new FUICommandList);

	MenuToolCommands::Register();
	MapCommands();
	FEditorExampleTool::Get().AddMenuExtension(FMenuExtensionDelegate::CreateRaw(this, &MenuTool::MakeMenuEntry), FName("Section_1"), CommandList);
}

void MenuTool::OnShutdownModule()
{
	MenuToolCommands::Unregister();
}

void MenuTool::MakeMenuEntry(FMenuBuilder& menuBuilder)
{
	menuBuilder.AddMenuEntry(MenuToolCommands::Get().MenuCommand1);
}

void MenuTool::MapCommands()
{
	const MenuToolCommands& Commands = MenuToolCommands::Get();

	CommandList->MapAction(Commands.MenuCommand1, FExecuteAction::CreateSP(this, &MenuTool::MenuCommand1), FCanExecuteAction());
}

void MenuTool::MenuCommand1()
{
	UE_LOG(LogClass, Log, TEXT("clicked MenuCommand1")); //TODO: actually use LOCTEXT
}


#undef LOCTEXT_NAMESPACE
