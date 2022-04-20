

#include <KernelLog.h>
#include <DeviceServer.h>
#include "VGA.h"

int main(int argc, char **argv)
{
    KernelLog log;
    DeviceServer server("/dev/video");

    server.registerDevice(new VGA(server.getNextInode()), "vga0");

    // Initialize
    const FileSystem::Result result = server.initialize();
    if (result != FileSystem::Success)
    {
        ERROR("failed to initialize: result = " << (int) result);
        return 1;
    }

    // Start serving requests.
    return server.run();
}
