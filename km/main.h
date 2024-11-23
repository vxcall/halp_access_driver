#ifndef MAIN_H
#define MAIN_H

#include <ntddk.h>
#include "halp_structs.h"

extern "C" PVOID get_kernel_base();
void driver_unload(PDRIVER_OBJECT driver_object);

constexpr int pHalpApicInterruptControllerOffset = 0xC50778;

#endif //MAIN_H
