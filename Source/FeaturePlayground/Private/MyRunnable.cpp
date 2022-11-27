// Copyright Gargowle. All Rights Reserved.

#include "MyRunnable.h"

#include "HAL/ThreadManager.h"

/* -------- Code in this section is run on the thread that invokes this thread (for example the game thread) -------- */
FMyRunnable::FMyRunnable()
{
	// Create the actual thread object. It begins with the execution immediately.
	// possible further arguments: stack size, priority
	// It is possible to move the Create() command to another function so you can invoke when ready
	Thread = FRunnableThread::Create(this, TEXT("MyFirstUnrealThread"));
}

FMyRunnable::~FMyRunnable()
{
	if(Thread)
	{
		// Because we do not pass bShouldWait = false to the Kill method, we will have to wait for it to complete.
		// Hopefully this does not take too long. After all, the structors are run on the thread that invokes this
		// thread, so maybe the game thread.
		// This calls Stop() of our runnable.
		Thread->Kill();

		// Now the threat can safely be deleted.
		delete Thread;
	}
}

void FMyRunnable::Stop()
{
	// Clean up memory usage here, and make sure the Run() function stops soon
	// The main thread will be stopped until this finishes! :(

	// For this example, we just need to terminate the while loop
	// It will finish in <= 1 sec, due to the Sleep()
	FString ThreadName = FThreadManager::Get().GetThreadName(FPlatformTLS::GetCurrentThreadId());
	UE_LOG(LogTemp, Warning, TEXT("Stop Method; Thread Name: %s"), *ThreadName);
	bRunThread = false;
}

/* --------------------------------- Code in this section is run on the new thread ---------------------------------- */

bool FMyRunnable::Init()
{
	FString ThreadName = FThreadManager::Get().GetThreadName(FPlatformTLS::GetCurrentThreadId());
	UE_LOG(LogTemp, Warning, TEXT("Init Method; Thread Name: %s"), *ThreadName);

	bRunThread = true;
	
	// return true to signalize that the initialization was successful
	// Return false if you want to abort the thread because initialization was unsuccessful.
	return true;
}

uint32 FMyRunnable::Run()
{
	FString ThreadName = FThreadManager::Get().GetThreadName(FPlatformTLS::GetCurrentThreadId());
	UE_LOG(LogTemp, Warning, TEXT("Run Method; Thread Name: %s"), *ThreadName);
	
	// perform processor intensive task here!
	// In this example, a neverending task is created that only stops when Stop() is called
	while (bRunThread)
	{
		UE_LOG(LogTemp, Warning, TEXT("My custom thread is running!"))
		FPlatformProcess::Sleep(1.0f);
	}

	return 0;		
}

void FMyRunnable::Exit()
{
	FString ThreadName = FThreadManager::Get().GetThreadName(FPlatformTLS::GetCurrentThreadId());
	UE_LOG(LogTemp, Warning, TEXT("Exit method; Thread Name: %s"), *ThreadName);
	FRunnable::Exit();
}
