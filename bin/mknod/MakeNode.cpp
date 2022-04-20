
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include "MakeNode.h"

MakeNode::MakeNode(int argc, char **argv)
    : POSIXApplication(argc, argv)
{
    parser().setDescription("Create new device file node");
    parser().registerPositional("FILE", "Name of the device file to create");
    parser().registerPositional("TYPE", "Type of file to create (c=char,b=block)");
    parser().registerPositional("MAJOR", "Major number for the device node");
    parser().registerPositional("MINOR", "Minor number for the device node");
}

MakeNode::~MakeNode()
{
}

MakeNode::Result MakeNode::exec()
{
    dev_t dev;

    // Fill in major/minor numbers
    dev.major = atoi(arguments().get("MAJOR"));
    dev.minor = atoi(arguments().get("MINOR"));

    // Attempt to create the file
    if (mknod(arguments().get("FILE"), S_IFCHR, dev) < 0)
    {
        ERROR("failed to create '" << arguments().get("FILE") << "': " << strerror(errno));
        return IOError;
    }
    return Success;
}
