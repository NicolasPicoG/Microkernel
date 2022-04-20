

#ifndef __KERNEL_API_SYSTEMINFO_H
#define __KERNEL_API_SYSTEMINFO_H

#include <Types.h>

struct SystemInformation;

/**
 * @addtogroup kernel
 * @{
 *
 * @addtogroup kernelapi
 * @{
 */

/**
 * Prototype for user applications. Retrieves system information.
 *
 * @param info Pointer to SystemInformation output buffer.
 *
 * @return API::Success on success and other API::ErrorCode on failure.
 */
inline API::Result SystemInfo(SystemInformation *info)
{
    return (API::Result) trapKernel1(API::SystemInfoNumber, (Address) info);
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
 * Kernel prototype. Retrieves system information.
 *
 * @param info Pointer to SystemInformation output buffer.
 *
 * @return API::Success on success and other API::ErrorCode on failure.
 */
extern API::Result SystemInfoHandler(SystemInformation *info);

/**
 * @}
 */

#endif /* __KERNEL__ */

/**
 * @addtogroup kernelapi
 * @{
 */

/**
 * System information structure.
 */
typedef struct SystemInformation
{
    /**
     * Constructor function.
     */
    SystemInformation()
    {
        SystemInfo(this);
    }

    /** System version. */
    ulong version;

    /** Boot commandline. */
    char cmdline[64];

    /** Physical start address of the kernel program */
    Address kernelAddress;

    /** Size of the kernel program in bytes */
    Size kernelSize;

    /** Total and available memory in bytes. */
    Size memorySize, memoryAvail;

    /** Core Identifier */
    uint coreId;

    /** BootImage physical address */
    Address bootImageAddress;

    /** BootImage size */
    Size bootImageSize;

    Address coreChannelAddress;
    Size coreChannelSize;

    /** Timer counter */
    uint timerCounter;
}
SystemInformation;

/**
 * @}
 * @}
 */

#endif /* __KERNEL_API_SYSTEMINFO_H */
