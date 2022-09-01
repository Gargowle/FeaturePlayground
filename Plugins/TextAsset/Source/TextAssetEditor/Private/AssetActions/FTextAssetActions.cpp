// Fill out your copyright notice in the Description page of Project Settings.


#include "FTextAssetActions.h"

#include "TextAsset.h"

FText FTextAssetActions::GetName() const
{
	return NSLOCTEXT("AssetTypeActions", "AssetTypeActions_TextAsset", "Text Asset");
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
