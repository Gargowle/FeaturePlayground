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
};
