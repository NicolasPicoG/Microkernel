
#include <Nicoos/System.h>
#include <FileSystemClient.h>
#include <FileSystemMount.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "Mount.h"

Mount::Mount(int argc, char **argv)
    : POSIXApplication(argc, argv)
{
    parser().setDescription("Mount filesystems on the system");
    parser().registerFlag('w', "wait", "Blocking wait until given filesystem path is mounted");
}

Mount::~Mount()
{
}

void Mount::listMounts() const
{
    const FileSystemClient filesystem;
    const FileSystemMount *mounts;
    const Arch::MemoryMap map;
    const Memory::Range range = map.range(MemoryMap::UserArgs);
    char cmd[PAGESIZE];
    Size numberOfMounts = 0;

    // Get mounted filesystems
    mounts = filesystem.getFileSystems(numberOfMounts);
    assert(mounts != NULL);

    // Print header
    printf("PATH                 FILESYSTEM\r\n");

    // Print out
    for (Size i = 0; i < numberOfMounts; i++)
    {
        if (mounts[i].path[0])
        {
            // Get the command
            const API::Result result = VMCopy(mounts[i].procID, API::Read, (Address) cmd, range.virt, PAGESIZE);
            if (result != API::Success)
            {
                ERROR("VMCopy failed for PID " << mounts[i].procID << ": result = " << (int) result);
                MemoryBlock::copy(cmd, "???", sizeof(cmd));
            }

            printf("%20s %s\r\n", mounts[i].path, cmd);
        }
    }
}

void Mount::waitForMount(const char *path) const
{
    const FileSystemClient filesystem;
    const FileSystem::Result result = filesystem.waitFileSystem(path);

    if (result != FileSystem::Success)
    {
        ERROR("failed to wait for filesystem at " << path << ": result = " << (int) result);
        exit(1);
    }

    assert(result == FileSystem::Success);
}

Mount::Result Mount::exec()
{
    const char *waitPath = arguments().get("wait") ?
                           arguments().get("wait") : ZERO;

    if (waitPath != ZERO)
        waitForMount(waitPath);
    else
        listMounts();

    return Success;
}
