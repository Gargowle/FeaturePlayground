// Fill out your copyright notice in the Description page of Project Settings.


#include "FPMyFooModuleTestingActor.h"
#include "MyFooModuleActorBase.h"

// Sets default values
AFPMyFooModuleTestingActor::AFPMyFooModuleTestingActor(): MyFooModuleActorBasePointer(nullptr)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AFPMyFooModuleTestingActor::BeginPlay()
{
	Super::BeginPlay();

	// Spawn instance MyFooModuleActorBase with empty spawn parameters
	// because nothing matters and the actor just prints a debug message)
	MyFooModuleActorBasePointer = GetWorld()->SpawnActor<AMyFooModuleActorBase>(FActorSpawnParameters());	
}

// Called every frame
void AFPMyFooModuleTestingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

