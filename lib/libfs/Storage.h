

#ifndef __LIB_LIBFS_STORAGE_H
#define __LIB_LIBFS_STORAGE_H

#include <Types.h>
#include "FileSystem.h"

/**
 * @addtogroup lib
 * @{
 *
 * @addtogroup libfs
 * @{
 */

/**
 * Provides a storage device to build filesystems on top.
 */
class Storage
{
  public:

    /**
     * Constructor function.
     */
    Storage();

    /**
     * Destructor function.
     */
    virtual ~Storage();

    /**
     * Initialize the Storage device
     *
     * @return Result code
     */
    virtual FileSystem::Result initialize() = 0;

    /**
     * Read a contiguous set of data.
     *
     * @param offset Offset to start reading from.
     * @param buffer Output buffer.
     * @param size Number of bytes to copied.
     *
     * @return Result code
     */
    virtual FileSystem::Result read(const u64 offset, void *buffer, const Size size) const = 0;

    /**
     * Write a contiguous set of data.
     *
     * @param offset Offset to start writing to.
     * @param buffer Input buffer.
     * @param size Number of bytes to written.
     *
     * @return Result code
     */
    virtual FileSystem::Result write(const u64 offset, void *buffer, const Size size);

    /**
     * Retrieve maximum storage capacity.
     *
     * @return Storage capacity.
     */
    virtual u64 capacity() const = 0;
};

/**
 * @}
 * @}
 */

#endif /* __LIB_LIBFS_STORAGE_H */
