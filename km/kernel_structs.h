#ifndef KPRCB_STRUCT_H
#define KPRCB_STRUCT_H

struct _KTHREAD;
struct _KNODE;
struct _KDPC;
struct _REQUEST_MAILBOX;

struct _KPRCBFLAG {
    unsigned __int64 flags;
};

struct _KPROCESSOR_STATE {
    unsigned __int8 data[512];
};

struct _PP_LOOKASIDE_LIST {
    unsigned __int8 data[32];
};

struct _KSTATIC_AFFINITY_BLOCK {
    unsigned __int8 data[32];
};

struct _RTL_HASH_TABLE {
    unsigned __int8 data[64];
};

struct _KDPC_DATA {
    unsigned __int8 data[64];
};

struct _KTIMER_TABLE {
    unsigned __int8 data[1024];
};

struct _RTL_RB_TREE {
    void* Root;
    void* Min;
};

struct _PROCESSOR_POWER_STATE {
    unsigned __int8 data[128];
};

struct _KAFFINITY_EX {
    unsigned __int8 data[32];
};

struct _KSHARED_READY_QUEUE {
    unsigned __int8 data[64];
};

struct _PROCESSOR_PROFILE_CONTROL_AREA {
    unsigned __int8 data[64];
};

struct _SYNCH_COUNTERS {
    unsigned __int8 data[64];
};

struct _FILESYSTEM_DISK_COUNTERS {
    unsigned __int8 data[64];
};

struct _KENTROPY_TIMING_STATE {
    unsigned __int8 data[128];
};

struct _IOP_IRP_STACK_PROFILER {
    unsigned __int8 data[64];
};

struct _KSECURE_FAULT_INFORMATION {
    unsigned __int8 data[32];
};

struct _MACHINE_CHECK_CONTEXT {
    unsigned __int8 data[1024];
};

struct _KTIMER_EXPIRATION_TRACE {
    unsigned __int8 data[32];
};

#endif //KPRCB_STRUCT_H
