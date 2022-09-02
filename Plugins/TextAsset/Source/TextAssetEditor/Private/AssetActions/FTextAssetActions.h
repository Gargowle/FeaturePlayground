// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AssetTypeActions_Base.h"

/**
 * 
 */
class FTextAssetActions : public FAssetTypeActions_Base
{
public:
	//FTextAssetActions(const TSharedRef<ISlateStyle>& InStyle);

public:
	/* methods that need to be overwritten from abstract parent class */
	FText GetName() const override;
	UClass* GetSupportedClass() const override;
	FColor GetTypeColor() const override;

	/* method that needs to be overwritten for the dialog to add an instance of the class to appear in the editor's add dialog */
	virtual uint32 GetCategories() override;

	/* for better clarity, override the CanFilter and HasActions methods to return true explicitly */
	virtual bool CanFilter() override { return true; }
	virtual bool HasActions(const TArray<UObject*>& InObjects) const override { return true; }

	/**
	 * Add actions that can be performed from the right-click menu when right-clicking on TextAssets selected in the content browser
	 */
	virtual void GetActions(const TArray<UObject*>& InObjects, FMenuBuilder& MenuBuilder) override;
	//implement after editor has been implemented//virtual void OpenAssetEditor(const TArray<UObject*>& InObjects, TSharedPtr<IToolkitHost> EditWithinLevelEditor) override; 
	
};
