#ifndef HALP_STRUCTS_H
#define HALP_STRUCTS_H
#include <ntddk.h>
#include "kprcb.h"

using VOID_FUNC_PTR = void(*)();
using INT64_FUNC_PTR = INT64(*)();
using KPRCB_FUNC_PTR = _KPRCB*(*)(INT64, UINT32);
using INIT_LOCAL_UNIT_PTR = INT64(*)(INT64, INT64, INT32, INT32, UINT32, UINT32*);
using INIT_IO_UNIT_PTR = INT64(*)(INT64);
using SET_LOGICAL_ID_PTR = INT64(*)(INT64, INT64);
using SET_LINE_STATE_PTR = INT64(*)(INT64, UINT32*, INT64);
using REQUEST_INTERRUPT_PTR = INT64(*)(INT64, INT64, void*, UINT32, UINT32*);
using START_PROCESSOR_PTR = INT64(*)(INT64, UINT32, INT64, INT32);
using GENERATE_MESSAGE_PTR = INT64(*)(INT64, UINT32*, UINT64*, UINT64*);
using SAVE_LOCAL_INTERRUPTS_PTR = INT64(*)(INT64, INT64);
using QUERY_GET_SOURCE_PTR = INT64(*)(INT64, INT64, UINT32*, UINT8*);

// I only reversed it up to 25th index because the rest looks like not part of it.
// I don't guarantee.
struct _HALP_INTERRUPT_CONTROLLER {
    void* unknown_ptr1;
    void** HalpRegisteredInterruptControllers;
    void* unknown_ptr2;
    INT64 unknown_value1;
    INIT_LOCAL_UNIT_PTR HalpApicInitializeLocalUnit;
    INIT_IO_UNIT_PTR HalpApicInitializeIoUnit;
    KPRCB_FUNC_PTR HalpApicSetPriority;
    INT64_FUNC_PTR HalpApicGetLocalUnitError;
    INT64_FUNC_PTR HalpApicClearLocalUnitError;
    INT64 unknown_value2;
    SET_LOGICAL_ID_PTR HalpApicSetLogicalId;
    INT64 unknown_value3;
    INT64_FUNC_PTR HalpApicWriteEndOfInterrupt;
    VOID_FUNC_PTR HalpApic1EndOfInterrupt;
    SET_LINE_STATE_PTR HalpApicSetLineState;
    REQUEST_INTERRUPT_PTR HalpApicRequestInterrupt;
    START_PROCESSOR_PTR HalpApicStartProcessor;
    GENERATE_MESSAGE_PTR HalpApicGenerateMessage;
    INT64 unknown_value4;
    SAVE_LOCAL_INTERRUPTS_PTR HalpApicSaveLocalInterrupts;
    SAVE_LOCAL_INTERRUPTS_PTR HalpApicReplayLocalInterrupts;
    INT64_FUNC_PTR HalpApicDeinitializeLocalUnit;
    INT64 unknown_value5;
    QUERY_GET_SOURCE_PTR HalpApicQueryAndGetSource;
};

#endif //HALP_STRUCTS_H
