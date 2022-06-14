// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FPMyFooModuleTestingActor.generated.h"

class AMyFooModuleActorBase;

UCLASS()
class FEATUREPLAYGROUND_API AFPMyFooModuleTestingActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFPMyFooModuleTestingActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY()
	AMyFooModuleActorBase* MyFooModuleActorBasePointer;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
