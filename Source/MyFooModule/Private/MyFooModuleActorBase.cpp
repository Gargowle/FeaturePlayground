// Fill out your copyright notice in the Description page of Project Settings.


#include "MyFooModuleActorBase.h"

// Sets default values
AMyFooModuleActorBase::AMyFooModuleActorBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyFooModuleActorBase::BeginPlay()
{
	Super::BeginPlay();
	GEngine->AddOnScreenDebugMessage(0, 5.0f, FColor::Red, TEXT("Hello, world! MyFooModuleActorBase speaking here!"));
}

// Called every frame
void AMyFooModuleActorBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

