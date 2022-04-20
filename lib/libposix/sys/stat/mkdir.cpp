

#include <FileSystemClient.h>
#include "errno.h"
#include "limits.h"
#include "stdio.h"
#include "string.h"
#include "sys/stat.h"

int mkdir(const char *path, mode_t mode)
{
    const FileSystemClient filesystem;

    // Ask FileSystem to create the file for us
    const FileSystem::Result result = filesystem.createFile(path,
                                                            FileSystem::DirectoryFile,
                                                           (FileSystem::FileModes) (mode & FILEMODE_MASK));
    // Set errno
    if (result == FileSystem::Success)
        errno = ESUCCESS;
    else
        errno = EIO;

    // Report result
    return errno == ESUCCESS ? 0 : -1;
}
