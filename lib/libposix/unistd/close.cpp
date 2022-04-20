

#include <FileSystemClient.h>
#include "errno.h"
#include "unistd.h"

int close(int fildes)
{
    const FileSystemClient fs;

    const FileSystem::Result result = fs.closeFile(fildes);
    if (result != FileSystem::Success)
    {
        errno = ENOENT;
        return -1;
    }

    return 0;
}
