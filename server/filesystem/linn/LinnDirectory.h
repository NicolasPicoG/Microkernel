

#ifndef __FILESYSTEM_LINN_DIRECTORY_H
#define __FILESYSTEM_LINN_DIRECTORY_H
#ifndef __HOST__

#include <Directory.h>
#include <Types.h>
#include "LinnDirectoryEntry.h"
#include "LinnFileSystem.h"
#include "LinnInode.h"
#include "IOBuffer.h"

/**
 * @addtogroup server
 * @{
 *
 * @addtogroup linnfs
 * @{
 */

/**
 * Represents an directory on a LinnFS filesystem.
 *
 * @see Directory
 * @see LinnDirectoryEntry
 * @see LinnFileSystem
 */
class LinnDirectory : public Directory
{
  public:

    /**
     * Constructor function.
     *
     * @param fs Filesystem pointer.
     * @param inode Inode number
     * @param inodeData Inode data pointer.
     *
     * @see LinnFileSystem
     * @see LinnInode
     */
    LinnDirectory(LinnFileSystem *fs,
                  const u32 inode,
                  LinnInode *inodeData);

    /**
     * Read directory entries
     *
     * @param buffer Input/Output buffer to output bytes to.
     * @param size Maximum number of bytes to read on input.
     *             On output, the actual number of bytes read.
     * @param offset Offset inside the file to start reading.
     *
     * @return Result code
     */
    virtual FileSystem::Result read(IOBuffer & buffer,
                                    Size & size,
                                    const Size offset);

    /**
     * @brief Retrieves a File pointer for the given entry name.
     *
     * This function reads a file from disk corresponding
     * to the LinnInode of the given entry name. It returns
     * an File object associated with that LinnInode.
     *
     * @param name Name of the entry to lookup.
     *
     * @return Pointer to a File if found, or ZERO otherwise.
     *
     * @see File
     * @see LinnInode
     */
    virtual File * lookup(const char *name);

  private:

    /**
     * Retrieve a directory entry.
     *
     * @param dent LinnDirectoryEntry buffer pointer.
     * @param name Unique name of the entry.
     *
     * @return True if successful, false otherwise.
     */
    bool getLinnDirectoryEntry(LinnDirectoryEntry *dent,
                               const char *name);

  private:

    /** Filesystem pointer. */
    LinnFileSystem *m_fs;

    /** Inode which describes the directory. */
    LinnInode *m_inodeData;
};

/**
 * @}
 * @}
 */

#endif /* __HOST__ */
#endif /* __FILESYSTEM_EXT2DIRECTORY_H */
