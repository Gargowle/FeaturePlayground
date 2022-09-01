// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "TextAssetFactory.generated.h"

/**
 * The factory for UTextAsset objects
 */
UCLASS(/*hide all properties that are related to UObject*/ HideCategories=(Object))
class UTextAssetFactory : public UFactory
{
	GENERATED_BODY()
public:
	UTextAssetFactory(const FObjectInitializer& ObjectInitializer);
	
	virtual UObject* FactoryCreateFile(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, const FString& Filename, const TCHAR* Parms, FFeedbackContext* Warn, bool& bOutOperationCanceled) override;
};
