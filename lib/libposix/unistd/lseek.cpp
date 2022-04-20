

#include <FileDescriptor.h>
#include "errno.h"
#include "unistd.h"

off_t lseek(int fildes, off_t offset, int whence)
{
    // Do we have this file descriptor?
    FileDescriptor::Entry *fd = FileDescriptor::instance()->getEntry(fildes);
    if (!fd || !fd->open)
    {
        errno = ENOENT;
        return -1;
    }

    // Update the file position pointer
    fd->position = offset;

    // Done
    return 0;
}
