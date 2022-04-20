

#include <FileSystemClient.h>
#include "errno.h"
#include "unistd.h"

ssize_t read(int fildes, void *buf, size_t nbyte)
{
    // Read the file.
    const FileSystemClient filesystem;
    const FileSystem::Result result = filesystem.readFile(fildes,
                                                         (char *)buf,
                                                          &nbyte);
    // Did the read succeed?
    if (result != FileSystem::Success)
    {
        errno = ENOENT;
        return -1;
    }

    return nbyte;
}
