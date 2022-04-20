

#ifndef __SERVER_FILESYSTEM_LINN_LINNFILE_H
#define __SERVER_FILESYSTEM_LINN_LINNFILE_H

#include <File.h>
#include <Types.h>
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
 * Represents a file on a mounted LinnFS filesystem.
 */
class LinnFile : public File
{
  public:

    /**
     * Constructor function.
     *
     * @param fs LinnFS filesystem pointer.
     * @param inode Inode number
     * @param inodeData Inode data pointer.
     */
    LinnFile(LinnFileSystem *fs,
             const u32 inode,
             LinnInode *inodeData);

    /**
     * Destructor function.
     */
    virtual ~LinnFile();

    /**
     * @brief Read bytes from the file.
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

  private:

    /** Filesystem pointer. */
    LinnFileSystem *m_fs;

    /** Inode pointer. */
    LinnInode *m_inodeData;
};

/**
 * @}
 * @}
 */

#endif /* __SERVER_FILESYSTEM_LINN_LINNFILE_H */
