#pragma once

#include "Modules/ModuleInterface.h"

/**
 * A convenient interface that provides events when this module starts up or shuts down
 * All tools in this module need to implement this interface
 */
class IEditorExampleToolModuleListenerInterface
{
public:
	// pure virtual functions -> no implementations
	virtual void OnStartupModule() = 0;
	virtual void OnShutdownModule() = 0;
};

// TODO: find out if modules need a prefix such as "Fort" or "S", as they were project wide prefixes in Fortnite / Tom Looman project
// -> probably I should, at least splash damage is doing it
class IEditorExampleToolModuleInterface : public IModuleInterface
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	virtual void AddModuleListeners() {}; // empty implementation -> TODO: is this to be implemented by the module class itself? should it be marked pure_virtual then?

protected:
	// TODO: find out what this TSharedRef is. the add explanation here. I assume it is something like a shared pointer, but the Unreal version of it
	TArray<TSharedRef<IEditorExampleToolModuleListenerInterface>> ModuleListeners;
};
