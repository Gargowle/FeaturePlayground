#include "Modules/ModuleManager.h"
#include "AssetToolsModule.h"

#include "AssetActions/FTextAssetActions.h"

#define LOCTEXT_NAMESPACE "FTextAssetEditorModule"


class FTextAssetEditorModule : public IModuleInterface
{
public:
	virtual void StartupModule() override
	{
		RegisterAssetTools();
	};
	virtual void ShutdownModule() override
	{
		UnregisterAssetTools();
	};

protected:
	/** Register asset tool actions */
	void RegisterAssetTools()
	{
		IAssetTools& AssetTools = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();

		// currently just one asset type action to add, if more consider refactoring this into a sub-method
		TSharedRef<IAssetTypeActions> TextAssetAction = MakeShareable(new FTextAssetActions());
		AssetTools.RegisterAssetTypeActions(TextAssetAction);
		RegisteredAssetTypeActions.Add(TextAssetAction);
	}

	void UnregisterAssetTools()
	{
		FAssetToolsModule* AssetToolsModule = FModuleManager::GetModulePtr<FAssetToolsModule>("AssetTools");

		if (AssetToolsModule != nullptr)
		{
			IAssetTools& AssetTools = AssetToolsModule->Get();
			for (auto Action : RegisteredAssetTypeActions)
			{
				AssetTools.UnregisterAssetTypeActions(Action);
			}			
		}
	}
	
private:
	
	/** The collection of registered asset type actions. */
	TArray<TSharedRef<IAssetTypeActions>> RegisteredAssetTypeActions;
};

#undef LOCTEXT_NAMESPACE
    
IMPLEMENT_MODULE(FTextAssetEditorModule, TextAssetEditor)