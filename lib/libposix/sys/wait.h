

#ifndef __LIBPOSIX_WAIT_H
#define __LIBPOSIX_WAIT_H

#include <Macros.h>
#include "types.h"

/**
 * @addtogroup lib
 * @{
 *
 * @addtogroup libposix
 * @{
 */

/**
 * Returns the exit status of the child process
 *
 * @param st Contains the stat_loc value from waitpid()
 *
 * @return Exit status of the child process
 */
#define WEXITSTATUS(st) (st)

/**
 * @brief Wait for a child process to stop or terminate
 *
 * The wait() and waitpid() functions shall obtain status information
 * pertaining to one of the caller's child processes. Various options
 * permit status information to be obtained for child processes that
 * have terminated or stopped. If status information is available for
 * two or more child processes, the order in which their status is
 * reported is unspecified.
 *
 * @param pid Process ID of child to wait for.
 * @param stat_loc Points to an integer for storing the exit status.
 * @param options Optional flags.
 *
 * @return Process ID of the child on success or -1 on error
 */
extern C pid_t waitpid(pid_t pid, int *stat_loc, int options);

/**
 * @}
 * @}
 */

#endif /* __LIBPOSIX_WAIT_H */
