

#ifndef __FILESYSTEM_TMPFILESYSTEM_H
#define __FILESYSTEM_TMPFILESYSTEM_H

#include <FileSystem.h>
#include <FileSystemServer.h>
#include <Types.h>

/**
 * @addtogroup server
 * @{
 *
 * @addtogroup tmpfs
 * @{
 */

/**
 * Temporary filesystem (TmpFS). Maps files into virtual memory.
 */
class TmpFileSystem : public FileSystemServer
{
  public:

    /**
     * Class constructor function.
     *
     * @param path Path to which we are mounted.
     */
    TmpFileSystem(const char *path);

    /**
     * @brief Creates a new TmpFile.
     *
     * @param type Describes the file type to create.
     *
     * @return Pointer to a new File on success, or ZERO on failure.
     *
     * @see File
     */
    virtual File * createFile(const FileSystem::FileType type);
};

/**
 * @}
 * @}
 */

#endif /* __FILESYSTEM_TMPFILESYSTEM_H */
