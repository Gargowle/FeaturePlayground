// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "FeaturePlaygroundGameModeBase.generated.h"

class FMyRunnable;

/**
 * 
 */
UCLASS()
class FEATUREPLAYGROUND_API AFeaturePlaygroundGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	virtual void StartPlay() override;

	virtual ~AFeaturePlaygroundGameModeBase() override;

protected:
	FMyRunnable* MyRunnable;
	
};
