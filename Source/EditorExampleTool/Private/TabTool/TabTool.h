#pragma once

#include "ExampleTabToolBase.h"

class FTabTool : public FExampleTabToolBase
{
public:
	virtual ~FTabTool(){}
	virtual void OnStartupModule() override;
	virtual void OnShutdownModule() override;
	virtual void Initialize() override;
	virtual TSharedRef<SDockTab> SpawnTab(const FSpawnTabArgs& TabSpawnArgs) override;
};
