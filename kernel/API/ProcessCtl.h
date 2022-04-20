

#ifndef __KERNEL_API_PROCESSCTL_H
#define __KERNEL_API_PROCESSCTL_H

#include <Nicoos/Process.h>
#include <Types.h>

/**
 * @addtogroup kernel
 * @{
 *
 * @addtogroup kernelapi
 * @{
 */

/**
 * Available operation to perform using ProcessCtl.
 *
 * @see ProcessCtl
 */
typedef enum ProcessOperation
{
    Spawn = 0,
    KillPID,
    GetPID,
    GetParent,
    WatchIRQ,
    EnableIRQ,
    DisableIRQ,
    SendIRQ,
    InfoPID,
    WaitPID,
    InfoTimer,
    WaitTimer,
    EnterSleep,
    Schedule,
    Wakeup,
    Stop,
    Resume,
    Reset
}
ProcessOperation;

/**
 * Process information structure, used for Info.
 */
typedef struct ProcessInfo
{
    /** Process Identity number. Must be unique. */
    ProcessID id;

    /** Parent process id. */
    ProcessID parent;

    /** Defines the current state of the Process. */
    Process::State state;
}
ProcessInfo;

/** Operator to print a ProcessOperation to a Log */
Log & operator << (Log &log, ProcessOperation op);

/**
 * Prototype for user applications. Process management related operations.
 *
 * @param proc Target Process' ID.
 * @param op The operation to perform.
 * @param addr Input argument address, used for program entry point for Spawn,
 *             ProcessInfo pointer for Info.
 * @param output Output argument address (optional).
 *
 * @return API::Success on success and other API::ErrorCode on failure.
 *         For WaitPID, the process exit status is stored in the upper 16-bits
 *         of this return value on success. For Spawn, the new PID is stored in
 *         the upper 16-bits.
 */
inline API::Result ProcessCtl(const ProcessID proc,
                              const ProcessOperation op,
                              const Address addr = 0,
                              const Address output = 0)
{
    return (API::Result) trapKernel4(API::ProcessCtlNumber, proc, op, addr, output);
}

/**
 * @}
 */

#ifdef __KERNEL__

/**
 * @addtogroup kernelapi_handler
 * @{
 */

/**
 * Kernel handler prototype. Process management related operations.
 *
 * @param proc Target Process' ID.
 * @param op The operation to perform.
 * @param addr Input argument address, used for program entry point for Spawn,
 *             ProcessInfo pointer for Info.
 * @param output Output argument address (optional).
 *
 * @return API::Success on success and other API::ErrorCode on failure.
 *         For WaitPID, the process exit status is stored in the upper 16-bits
 *         of this return value on success. For Spawn, the new PID is stored in
 *         the upper 16-bits.
 */
extern API::Result ProcessCtlHandler(const ProcessID proc,
                                     const ProcessOperation op,
                                     const Address addr,
                                     const Address output);

/**
 * @}
 */

#endif /* __KERNEL__ */

/**
 * @}
 */

#endif /* __KERNEL_API_PROCESSCTL_H */
