

#include <Nicoos/User.h>
#include <FileSystemClient.h>
#include "limits.h"
#include "string.h"
#include "errno.h"
#include "fcntl.h"
#include "sys/stat.h"

int open(const char *path, int oflag, ...)
{
    const FileSystemClient filesystem;
    Size fd = 0;

    // Attempt to open the file
    const FileSystem::Result result = filesystem.openFile(path, fd);
    if (result == FileSystem::Success)
    {
        errno = ESUCCESS;
        return (int) fd;
    }
    else
    {
        // File not found
        errno = ENOENT;
        return -1;
    }
}
