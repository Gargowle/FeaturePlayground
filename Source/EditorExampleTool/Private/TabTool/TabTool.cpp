#include "TabTool.h"
#include "EditorExampleToolModule.h"
#include "TabToolPanel.h"


void FTabTool::OnStartupModule()
{
	FExampleTabToolBase::OnStartupModule();
	FEditorExampleTool::Get().AddMenuExtension(FMenuExtensionDelegate::CreateRaw(this, &FTabTool::MakeMenuEntry), FName("Section_2"));
}

void FTabTool::OnShutdownModule()
{
	FExampleTabToolBase::OnShutdownModule();
}

void FTabTool::Initialize()
{
	TabName = TEXT("TabTool");
	TabDisplayName = FText::FromString("Tab Tool");
	ToolTipText = FText::FromString("Tab Tool Window");
}

TSharedRef<SDockTab> FTabTool::SpawnTab(const FSpawnTabArgs& TabSpawnArgs)
{
	TSharedRef<SDockTab> SpawnedTab = SNew(SDockTab)
		.TabRole(ETabRole::NomadTab)
		[
			SNew(STabToolPanel)
			.Tool(SharedThis(this))
		];
	return SpawnedTab;
}
