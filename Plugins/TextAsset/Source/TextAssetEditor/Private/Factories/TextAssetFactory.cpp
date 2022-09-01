// Fill out your copyright notice in the Description page of Project Settings.


#include "Factories/TextAssetFactory.h"

#include "TextAsset.h"
#include "Misc/FileHelper.h"

#define LOCTEXT_NAMESPACE "UTextAssetFactory"

/**
 * Configures what this factory is used for: loading from disk
 */
UTextAssetFactory::UTextAssetFactory(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	Formats.Add(FString(TEXT("txt;"))+ LOCTEXT("FormatTxt", "Text File").ToString());
	SupportedClass = UTextAsset::StaticClass();
	bCreateNew = false; // factory cannot create object from scratch but needs a file to import
	bEditorImport = true; // factory is made for importing a file to editor
}

UObject* UTextAssetFactory::FactoryCreateFile(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags,
                                              const FString& Filename, const TCHAR* Parms, FFeedbackContext* Warn, bool& bOutOperationCanceled)
{
	UTextAsset* TextAsset = nullptr;
	FString TextString;

	if (FFileHelper::LoadFileToString(TextString, *Filename))
	{
		TextAsset = NewObject<UTextAsset>(InParent, InClass, InName, Flags);
		TextAsset->Text = FText::FromString(TextString);
	}

	bOutOperationCanceled = false;

	return TextAsset;
}

#undef LOCTEXT_NAMESPACE
