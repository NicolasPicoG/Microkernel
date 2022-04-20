

#include <FileSystemClient.h>
#include "errno.h"
#include "limits.h"
#include "stdio.h"
#include "string.h"
#include "sys/stat.h"

int mknod(const char *path, mode_t mode, dev_t)
{
    const FileSystemClient filesystem;

    // Ask FileSystem to create the file for us
    const FileSystem::Result result = filesystem.createFile(path,
                                                           (FileSystem::FileType) ((mode >> FILEMODE_BITS) & FILETYPE_MASK),
                                                           (FileSystem::FileModes) (mode & FILEMODE_MASK));
    // Set errno
    if (result == FileSystem::Success)
        errno = ESUCCESS;
    else
        errno = EIO;

    // Report result
    return errno == ESUCCESS ? 0 : -1;
}
