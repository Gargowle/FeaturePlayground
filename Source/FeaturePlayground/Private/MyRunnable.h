// Copyright Gargowle. All Rights Reserved.

#pragma once

#include "HAL/Runnable.h"

class FMyRunnable : public FRunnable
{
public:
	// create the thread by calling the constructor
	FMyRunnable();

	virtual ~FMyRunnable() override;
	
	// no need to call these functions ourself; this happens automatically
	virtual bool Init() override; // for setup: allocate memory, etc.
	virtual uint32 Run() override; // the actual data processing happens here
	virtual void Stop() override; // signalize that an early termination of the thread is requested

	// in our case: no particular cleanup needs to be done, therefore no need to declare the Exit method
	virtual void Exit();

private:
	// Thread handle to be used for controlling the thread. Possible operators on this: Kill, Suspend
	FRunnableThread* Thread;

	// Signalize when the thread should exit by toggling this variable
	// by calling the Stop() method; value read out in Run
	bool bRunThread;
};
