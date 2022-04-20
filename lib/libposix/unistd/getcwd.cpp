

#include <Assert.h>
#include <FileSystemClient.h>
#include <string.h>
#include <errno.h>
#include "unistd.h"

char *getcwd(char *buf, size_t size)
{
    const FileSystemClient filesystem;
    const String *currentDirectory = filesystem.getCurrentDirectory();

    // Copy our current working directory
    assert(currentDirectory != NULL);
    memcpy(buf, **currentDirectory, size);

    // Set errno
    errno = ESUCCESS;

    // Done
    return buf;
}
