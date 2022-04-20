

#ifndef __FILESYSTEM_FILESTORAGE_H
#define __FILESYSTEM_FILESTORAGE_H

#include <Types.h>
#include "FileSystemClient.h"
#include "Storage.h"

/**
 * @addtogroup lib
 * @{
 *
 * @addtogroup libfs
 * @{
 */

/**
 * Use a file as Storage provider.
 *
 * @see Storage
 */
class FileStorage : public Storage
{
  public:

    /**
     * Constructor function.
     *
     * @param path Full path to the file to use.
     * @param offset Offset in the file as a base for I/O.
     */
    FileStorage(const char *path, Size offset = ZERO);

    /**
     * Initialize the Storage device
     *
     * @return Result code
     */
    virtual FileSystem::Result initialize();

    /**
     * Read a contiguous set of data.
     *
     * @param offset Offset to start reading from.
     * @param buffer Output buffer.
     * @param size Number of bytes to copied.
     *
     * @return Result code
     */
    virtual FileSystem::Result read(const u64 offset, void *buffer, const Size size) const;

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
    virtual u64 capacity() const;

  private:

    /** Path to the file */
    const char *m_path;

    /** File descriptor of the file */
    Size m_fd;

    /** Client for file system I/O */
    FileSystemClient m_file;

    /** Status of the file for Storage I/O. */
    FileSystem::FileStat m_stat;

    /** Offset used as a base for I/O. */
    Size m_offset;
};

/**
 * @}
 * @}
 */

#endif /* __FILESYSTEM_STORAGE_H */
