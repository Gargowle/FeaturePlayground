// Fill out your copyright notice in the Description page of Project Settings.


#include "Factories/TextAssetFactoryNew.h"

#include "TextAsset.h"

#define LOCTEXT_NAMESPACE "UTextAssetFactoryNew"

UTextAssetFactoryNew::UTextAssetFactoryNew(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	SupportedClass = UTextAsset::StaticClass();
	bCreateNew = true; // factory can create object from scratch; makes ShouldShowInNewMenu return true
	bEditorImport = false; // factory is made for importing a file to editor
	bEditAfterNew = true;
}

UObject* UTextAssetFactoryNew::FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags,
	UObject* Context, FFeedbackContext* Warn)
{
	return NewObject<UTextAsset>(InParent, InClass, InName, Flags);
}

#undef LOCTEXT_NAMESPACE
