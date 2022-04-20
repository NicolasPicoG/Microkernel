
#ifndef __KERNEL_API_VMSHARE_H
#define __KERNEL_API_VMSHARE_H

#include <Nicoos/ProcessShares.h>
#include <Types.h>

/**
 * @addtogroup kernel
 * @{
 *
 * @addtogroup kernelapi
 * @{
 */

/**
 * Prototype for user applications. Creates and removes shared virtual memory mappings.
 *
 * @param pid Remote process.
 * @param op Determines which operation to perform.
 * @param share Pointer to the MemoryShare to use in the operation
 *
 * @return API::Success on success and other API::ErrorCode on failure.
 */
inline API::Result VMShare(const ProcessID pid,
                           const API::Operation op,
                           ProcessShares::MemoryShare *share)
{
    return (API::Result) trapKernel3(API::VMShareNumber, pid, op, (Address) share);
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
 * Kernel handler prototype. Creates and removes shared virtual memory mappings.
 *
 * @param pid Remote process.
 * @param op Determines which operation to perform.
 * @param share Pointer to the MemoryShare to use in the operation
 *
 * @return API::Success on success and other API::ErrorCode on failure.
 */
extern API::Result VMShareHandler(const ProcessID pid,
                                  const API::Operation op,
                                  ProcessShares::MemoryShare *share);

/**
 * @}
 */

#endif /* __KERNEL__ */

/**
 * @}
 */

#endif /* __KERNEL_API_VMSHARE_H */
