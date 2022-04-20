

#include <FileSystemClient.h>
#include <Log.h>
#include "errno.h"
#include "limits.h"
#include "string.h"
#include "sys/stat.h"

int stat(const char *path, struct stat *buf)
{
    const FileSystemClient filesystem;
    FileSystem::FileStat st;

    DEBUG("path = " << path);

    // Ask the FileSystem for the information
    const FileSystem::Result result = filesystem.statFile(path, &st);

    // Copy information into buf
    switch (result)
    {
        case FileSystem::Success:
            buf->fromFileStat(&st);
            errno = ESUCCESS;
            break;
        case FileSystem::NotFound:
            errno = ENOENT;
            break;
        default:
            errno = EIO;
            break;
    }

    // Success
    return errno == ESUCCESS ? 0 : -1;
}
