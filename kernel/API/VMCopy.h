

#ifndef __KERNEL_API_VMCOPY_H
#define __KERNEL_API_VMCOPY_H

#include <Types.h>

/**
 * @addtogroup kernel
 * @{
 *
 * @addtogroup kernelapi
 * @{
 */

/**
 * Prototype for user applications. Copies virtual memory between two processes.
 *
 * @param proc Remote process.
 * @param how Read or Write.
 * @param ours Virtual address of the buffer of this process.
 * @param theirs Virtual address of the remote process' buffer.
 * @param sz Amount of memory to copy.
 *
 * @return API::Success on success and any other value on error.
 */
inline API::Result VMCopy(const ProcessID proc,
                          const API::Operation how,
                          const Address ours,
                          const Address theirs,
                          const Size sz)
{
    return (API::Result) trapKernel5(API::VMCopyNumber, proc, how, ours, theirs, sz);
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
 * Kernel handler prototype. Copies virtual memory between two processes.
 *
 * @param proc Remote process.
 * @param how Read or Write.
 * @param ours Virtual address of the buffer of this process.
 * @param theirs Virtual address of the remote process' buffer.
 * @param sz Amount of memory to copy.
 *
 * @return API::Success on success and any other value on error.
 *
 * @bug VMCopyHandler assumes the theirs parameter points to memory mapped as a small page (PAGESIZE, 4KiB)
 *      When that memory is actually a large mapping (for example 1MiB on ARM), the internal pageOff variable will be zero.
 */
extern API::Result VMCopyHandler(const ProcessID proc,
                                 const API::Operation how,
                                 const Address ours,
                                 const Address theirs,
                                 const Size sz);

/**
 * @}
 */

#endif /* __KERNEL__ */

/**
 * @}
 */

#endif /* __KERNEL_API_VMCOPY_H */
