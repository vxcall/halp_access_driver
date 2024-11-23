#include <ntddk.h>
#include "main.h"

extern "C" PVOID get_kernel_base();

void driver_unload(PDRIVER_OBJECT driver_object);

extern "C"
NTSTATUS DriverEntry(PDRIVER_OBJECT driver_object, PUNICODE_STRING registry_path)
{
    UNREFERENCED_PARAMETER(registry_path);
    driver_object->DriverUnload = driver_unload;

    PVOID kernel_base = get_kernel_base();
    if (!kernel_base) {
        DbgPrint("[vxdrv] Failed to get kernel base address.\n");
        return STATUS_UNSUCCESSFUL;
    }

    DbgPrint("[vxdrv] Kernel base address: %p\n", kernel_base);

    _HALP_INTERRUPT_CONTROLLER** p_halp_interrupt_controller =
        reinterpret_cast<_HALP_INTERRUPT_CONTROLLER**>((PUCHAR)kernel_base + pHalpApicInterruptControllerOffset);

    DbgPrint("[vxdrv] pHalpInterruptController address: %p\n", p_halp_interrupt_controller);

    REQUEST_INTERRUPT_PTR p_halp_apic_request_interrupt = (*p_halp_interrupt_controller)->HalpApicRequestInterrupt;

    DbgPrint("[vxdrv] Function pointer at index 15: %p\n", p_halp_apic_request_interrupt);

    return STATUS_SUCCESS;
}

void driver_unload(PDRIVER_OBJECT driver_object)
{
    UNREFERENCED_PARAMETER(driver_object);
    DbgPrint("[vxdrv] Driver unloaded\n");
}