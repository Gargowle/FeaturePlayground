#pragma once

#include "CallStackViewer.h"
#include "EditorExampleToolModule.h"
#include "EditorExampleToolModuleInterface.h"

class FExampleTabToolBase : public IEditorExampleToolModuleListenerInterface, public TSharedFromThis<FExampleTabToolBase>
{
public:
	virtual void OnStartupModule() override
	{
		Initialize();
		FGlobalTabmanager::Get()->RegisterNomadTabSpawner(TabName, FOnSpawnTab::CreateRaw(this, &FExampleTabToolBase::SpawnTab))
			.SetGroup(FEditorExampleTool::Get().GetMenuRoot())
			.SetDisplayName(TabDisplayName)
			.SetTooltipText(ToolTipText);
	}

	virtual void OnShutdownModule() override
	{
		FGlobalTabmanager::Get()->UnregisterNomadTabSpawner(TabName);
	}

	// In this function, set TabName, TabDisplayName, ToolTipText
	virtual void Initialize() {};

	virtual TSharedRef<SDockTab> SpawnTab(const FSpawnTabArgs& TabSpawnArgs)
	{
		return SNew(SDockTab);
	}

	virtual void MakeMenuEntry(FMenuBuilder &menuBuilder)
	{
		FGlobalTabmanager::Get()->PopulateTabSpawnerMenu(menuBuilder, TabName);
	}

	// add a virtual destructor in order to avoid warnings about non-virtual destructor
	virtual ~FExampleTabToolBase() {};

protected:
	FName TabName;
	FText TabDisplayName;
	FText ToolTipText;
};
