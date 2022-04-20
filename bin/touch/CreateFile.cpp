

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <Log.h>
#include "CreateFile.h"

CreateFile::CreateFile(int argc, char **argv)
    : POSIXApplication(argc, argv)
{
    parser().setDescription("Create new files the filesystem");
    parser().registerPositional("FILE", "Name of the file(s) to create", 0);
}

CreateFile::~CreateFile()
{
}

CreateFile::Result CreateFile::exec()
{
    const Vector<Argument *> & positionals = arguments().getPositionals();
    Result result = Success;
    Result ret = Success;

    // Perform a stat for each file
    for (Size i = 0; i < positionals.count(); i++)
    {
        // Create the file immediately
        result = createFile(positionals[i]->getValue());

        // Update exit status, if needed
        if (result != Success)
        {
            ret = result;
        }
    }

    // Done
    return ret;
}

CreateFile::Result CreateFile::createFile(const String & file) const
{
    // Attempt to create the file. */
    if (creat(*file, S_IRUSR|S_IWUSR) < 0)
    {
        ERROR("failed to create file `" << *file << "': " << strerror(errno));
        return IOError;
    }

    // Done
    return Success;
}
