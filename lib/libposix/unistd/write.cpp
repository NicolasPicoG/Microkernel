

#include <FileSystemClient.h>
#include "errno.h"
#include "unistd.h"

ssize_t write(int fildes, const void *buf, size_t nbyte)
{
    // Write the file.
    const FileSystemClient filesystem;
    const FileSystem::Result result = filesystem.writeFile(fildes,
                                                          (const char *)buf,
                                                          &nbyte);

    // Did the write succeed?
    if (result != FileSystem::Success)
    {
        errno = ENOENT;
        return -1;
    }

    return nbyte;
}
