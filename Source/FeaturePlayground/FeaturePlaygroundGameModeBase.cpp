// Copyright Epic Games, Inc. All Rights Reserved.


#include "FeaturePlaygroundGameModeBase.h"

#include "HAL/ThreadManager.h"
#include "MyRunnable.h"

void AFeaturePlaygroundGameModeBase::StartPlay()
{
	Super::StartPlay();

	FString ThreadName = FThreadManager::Get().GetThreadName(FPlatformTLS::GetCurrentThreadId());
	UE_LOG(LogTemp, Warning, TEXT("Start Play; Thread Name: %s"), *ThreadName);
	
	AsyncTask(ENamedThreads::AnyNormalThreadNormalTask,[]()
	{
		FString ThreadName = FThreadManager::Get().GetThreadName(FPlatformTLS::GetCurrentThreadId());
		UE_LOG(LogTemp, Warning, TEXT("Somewhere in the TaskGraph; Thread Name: %s"), *ThreadName);
	});

	MyRunnable = new FMyRunnable();
}

AFeaturePlaygroundGameModeBase::~AFeaturePlaygroundGameModeBase()
{
	if(MyRunnable)
	{
		FString ThreadName = FThreadManager::Get().GetThreadName(FPlatformTLS::GetCurrentThreadId());
		UE_LOG(LogTemp, Warning, TEXT("GameMode destructor; Thread Name: %s"), *ThreadName);
		delete MyRunnable;		
	}
}
