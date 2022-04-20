

#ifndef __KERNEL_API_PROCESSID_H
#define __KERNEL_API_PROCESSID_H

/**
 * @addtogroup kernel
 * @{
 *
 * @addtogroup kernelapi
 * @{
 */

/**
 * @name Static Process IDs
 * @{
 */

#define ANY             65535
#define SELF            65534
#define KERNEL_PID      65533

#define CORESRV_PID     0
#define DATASTORE_PID   1
#define RECOVERY_PID    2
#define ROOTFS_PID      3

/**
 * @}
 * @}
 * @}
 */

#endif /* __KERNEL_API_PROCESSID_H */
