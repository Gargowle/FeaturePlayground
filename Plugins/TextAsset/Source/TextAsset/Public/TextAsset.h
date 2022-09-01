// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

#include "TextAsset.generated.h"


UCLASS(BlueprintType)
class TEXTASSET_API UTextAsset : public UObject
{
	GENERATED_BODY()
public:

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category="TextAsset")
	FText Text;
};
