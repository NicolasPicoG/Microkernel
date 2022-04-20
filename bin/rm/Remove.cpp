
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "Remove.h"

Remove::Remove(int argc, char **argv)
    : POSIXApplication(argc, argv)
{
    parser().setDescription("Remove file from the filesystem");
    parser().registerPositional("FILE", "Name of the file(s) to remove", 0);
}

Remove::~Remove()
{
}

Remove::Result Remove::exec()
{
    const Vector<Argument *> & positionals = arguments().getPositionals();

    // Delete all given files
    for (Size i = 0; i < positionals.count(); i++)
    {
        const char *path = *(positionals[i]->getValue());

        // Attempt to remove the file
        if (unlink(path) < 0)
        {
            ERROR("failed to unlink '" << path << "': " << strerror(errno));
            return IOError;
        }
    }

    // Done
    return Success;
}
