

#ifndef __KERNEL_API_VMCTL_H
#define __KERNEL_API_VMCTL_H

#include <Types.h>
#include <Memory.h>

/**
 * @addtogroup kernel
 * @{
 *
 * @addtogroup kernelapi
 * @{
 */

/**
 * Memory operations which may be used as an argument to VMCtl().
 */
typedef enum MemoryOperation
{
    MapContiguous = 0,
    MapSparse,
    UnMap,
    Release,
    ReleaseSections,
    LookupVirtual,
    Access,
    ReserveMem,
    AddMem,
    CacheClean,
    CacheInvalidate,
    CacheCleanInvalidate
}
MemoryOperation;

/**
 * Prototype for user applications. Examines and modifies virtual memory pages.
 *
 * @param procID Remote process.
 * @param op Determines which operation to perform.
 * @param range Describes the memory pages to operate on.
 *
 * @return API::Success on success and other API::ErrorCode on failure.
 */
inline API::Result VMCtl(const ProcessID procID,
                         const MemoryOperation op,
                         Memory::Range *range = ZERO)
{
    return (API::Result) trapKernel3(API::VMCtlNumber, procID, op, (Address) range);
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
 * Kernel handler prototype. Examines and modifies virtual memory pages.
 *
 * @param procID Remote process.
 * @param op Determines which operation to perform.
 * @param range Describes the memory pages to operate on.
 *
 * @return API::Success on success and other API::ErrorCode on failure.
 */
extern API::Result VMCtlHandler(const ProcessID procID,
                                const MemoryOperation op,
                                Memory::Range *range);

/**
 * @}
 */

#endif /* __KERNEL__ */

/**
 * @}
 */

#endif /* __KERNEL_API_VMCTL_H */
