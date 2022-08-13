#include "EditorExampleToolModule.h"
#include "EditorExampleToolModuleInterface.h"
#include "LevelEditor.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"
#include "Framework/Docking/WorkspaceItem.h"
#include "MenuTool/MenuTool.h"

IMPLEMENT_MODULE(FEditorExampleTool, EditorExampleTool)

// TODO: look what this is for when you first use it. Also: What is an FWorkspaceItem?
TSharedRef<FWorkspaceItem> FEditorExampleTool::MenuRoot = FWorkspaceItem::NewGroup(FText::FromString(TEXT("Menu Root")));

void FEditorExampleTool::AddModuleListeners()
{
	// Add tools here once a tool actually is implemented in this module
	ModuleListeners.Add(MakeShareable<MenuTool>(new MenuTool));
}

void FEditorExampleTool::StartupModule()
{
	if(!IsRunningCommandlet()) // to prevent problems during cooking
	{
		FLevelEditorModule& LevelEditorModule = FModuleManager::LoadModuleChecked<FLevelEditorModule>("LevelEditor");
		LevelEditorMenuExtensibilityManager = LevelEditorModule.GetMenuExtensibilityManager();

		MenuExtender = MakeShareable<FExtender>(new FExtender);
		MenuExtender->AddMenuBarExtension(
			TEXT("Window"), // The extension hook 
			EExtensionHook::After, // position relative to the hook -> This button will be created just after the "Window" button
			NULL, // No particular command
			FMenuBarExtensionDelegate::CreateRaw(this, &FEditorExampleTool::MakePullownMenu)
		);

		LevelEditorMenuExtensibilityManager->AddExtender(MenuExtender);
	}

	IEditorExampleToolModuleInterface::StartupModule();
}

void FEditorExampleTool::ShutdownModule()
{
	IEditorExampleToolModuleInterface::ShutdownModule();
}

void FEditorExampleTool::AddMenuExtension(const FMenuExtensionDelegate& ExtensionDelegate, FName ExtensionHook,
	const TSharedPtr<FUICommandList>& CommandList /*= NULL */, EExtensionHook::Position Position /* = EExtensionHook::Before */)
{
	MenuExtender->AddMenuExtension(ExtensionHook, Position, CommandList, ExtensionDelegate);
}

TSharedRef<FWorkspaceItem> FEditorExampleTool::GetMenuRoot()
{
	return MenuRoot;
}

void FEditorExampleTool::MakePullownMenu(FMenuBarBuilder& MenuBarBuilder)
{
	MenuBarBuilder.AddPullDownMenu(
		FText::FromString(TEXT("Example")), // the text on the button that opens the dropdown menu
		FText::FromString(TEXT("Open the Example menu")), // tool tip
		FNewMenuDelegate::CreateRaw(this, &FEditorExampleTool::FillPulldownMenu), // delegate with method used to populate the drop down
		TEXT("Example"), //which extension hook name should this entry have?
		TEXT("ExampleMenu")
	);
}

void FEditorExampleTool::FillPulldownMenu(FMenuBuilder& MenuBuilder)
{
	MenuBuilder.BeginSection(TEXT("ExampleSection"), FText::FromString(TEXT("Section 1")));
	MenuBuilder.AddMenuSeparator(TEXT("Section_1"));
	MenuBuilder.EndSection();

	MenuBuilder.BeginSection(TEXT("ExampleSection"), FText::FromString(TEXT("Section 2")));
	MenuBuilder.AddMenuSeparator(TEXT("Section_2"));
	MenuBuilder.EndSection();
}
