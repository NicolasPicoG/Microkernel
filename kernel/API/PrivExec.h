

#ifndef __KERNEL_API_PRIVEXEC_H
#define __KERNEL_API_PRIVEXEC_H

/**
 * @addtogroup kernel
 * @{
 *
 * @addtogroup kernelapi
 * @{
 */

/**
 * Available operations to perform using PrivExec().
 *
 * @see PrivExec
 */
typedef enum PrivOperation
{
    Idle           = 0,
    RebootSystem   = 1,
    ShutdownSystem = 2,
    WriteConsole   = 3,
    Panic          = 4
}
PrivOperation;

/**
 * Prototype for user applications. Performs various privileged operations.
 *
 * @param op The operation to perform.
 * @param param Optional parameter value for the given operation
 *
 * @return API::Success on success and other API::ErrorCode on failure.
 */
inline API::Result PrivExec(const PrivOperation op,
                            const Address param = 0)
{
    return (API::Result) trapKernel2(API::PrivExecNumber, op, param);
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
 * Prototype for kernel handler. Performs various privileged operations.
 *
 * @param op The operation to perform.
 * @param param Optional parameter value for the given operation
 *
 * @return API::Success on success and other API::ErrorCode on failure.
 */
extern API::Result PrivExecHandler(const PrivOperation op,
                                   const Address param);

/**
 * @}
 */

#endif /* __KERNEL__ */

/**
 * @}
 */

#endif /* __KERNEL_API_PRIVEXEC_H */
