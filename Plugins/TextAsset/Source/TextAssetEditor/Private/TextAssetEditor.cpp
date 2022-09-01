#include "Modules/ModuleManager.h"

#define LOCTEXT_NAMESPACE "FTextAssetEditorModule"


class FTextAssetEditorModule : public IModuleInterface
{
public:
	virtual void StartupModule() override {};
	virtual void ShutdownModule() override {};
};

#undef LOCTEXT_NAMESPACE
    
IMPLEMENT_MODULE(FTextAssetEditorModule, TextAssetEditor)