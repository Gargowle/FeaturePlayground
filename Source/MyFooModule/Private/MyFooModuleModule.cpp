#include "Modules/ModuleManager.h"

// Default implementation of loader, resulting in default loading and unloading behavior
// This is only here by convention - it could be in any cpp file of this module
IMPLEMENT_MODULE(FDefaultModuleImpl, MyFooModule);
