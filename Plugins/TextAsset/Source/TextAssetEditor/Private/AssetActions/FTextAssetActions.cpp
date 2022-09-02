// Fill out your copyright notice in the Description page of Project Settings.

#include "FTextAssetActions.h"

#include "TextAsset.h"

#define LOCTEXT_NAMESPACE "AssetTypeActions"

FText FTextAssetActions::GetName() const
{
	return LOCTEXT("AssetTypeActions_TextAsset", "Text Asset");
}

UClass* FTextAssetActions::GetSupportedClass() const
{
	return UTextAsset::StaticClass();
}

FColor FTextAssetActions::GetTypeColor() const
{
	return FColor::White;
}

uint32 FTextAssetActions::GetCategories()
{
	return EAssetTypeCategories::Misc;
}

void FTextAssetActions::GetActions(const TArray<UObject*>& InObjects, FMenuBuilder& MenuBuilder)
{
	FAssetTypeActions_Base::GetActions(InObjects, MenuBuilder);

	// trick to only operate on TextAssets because also other objects could be selected that are no TextAssets
	// non-TextAssets will return false in IsValid check down below
	TArray<TWeakObjectPtr<UTextAsset>> TextAssets = GetTypedWeakObjectPtrs<UTextAsset>(InObjects);

	// Add the action to reverse the text stored in the selected TextAssets
	MenuBuilder.AddMenuEntry(
		LOCTEXT("TextAsset_ReverseText", "Reverse Text"),
		LOCTEXT("TextAsset_ReverseTextToolTip", "Reverse the text stored in teh selected text asset(s)."),
		FSlateIcon(),
		FUIAction(
			FExecuteAction::CreateLambda([=]
			{
				for (auto& TextAsset : TextAssets)
				{
					if(TextAsset.IsValid() && !TextAsset->Text.IsEmpty())
					{
						TextAsset->Text = FText::FromString(TextAsset->Text.ToString().Reverse());
						TextAsset->PostEditChange();
						TextAsset->MarkPackageDirty();
					}
				}
			}),
			FCanExecuteAction::CreateLambda([=]
			{
				// action can be executed once at least one non-empty TextAsset in selection
				for (auto& TextAsset : TextAssets)
				{
					if(TextAsset.IsValid() && !TextAsset->Text.IsEmpty())
					{
						return true;
					}
				}
				return false;
			})
		)
	);
}

#undef LOCTEXT_NAMESPACE
