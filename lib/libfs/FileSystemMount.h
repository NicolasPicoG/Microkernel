

#ifndef __LIB_LIBFS_FILESYSTEMMOUNT_H
#define __LIB_LIBFS_FILESYSTEMMOUNT_H

#include <Types.h>
#include "FileSystemPath.h"

/**
 * @addtogroup lib
 * @{
 *
 * @addtogroup libposix
 * @{
 */

/**
 * Represents a mounted filesystem.
 */
typedef struct FileSystemMount
{
    /** Path of the mount. */
    char path[FileSystemPath::MaximumLength];

    /** Server which is responsible for the mount. */
    ProcessID procID;

    /** Mount options. */
    ulong options;
}
FileSystemMount;

/**
 * @}
 * @}
 */

#endif /* __LIB_LIBFS_FILESYSTEMMOUNT_H */
