

#include <Runtime.h>
#include <KernelLog.h>
#include <DeviceServer.h>
#include <FileSystemClient.h>
#include "Terminal.h"

int main(int argc, char **argv)
{
    KernelLog log;

    // Wait for the input/output devices to become available
    const FileSystemClient filesystem;
    filesystem.waitFileSystem("/dev/ps2");
    filesystem.waitFileSystem("/dev/video");

    // Register our device
    DeviceServer server("/console");
    server.registerDevice(new Terminal(server.getNextInode(),
                                       "/dev/ps2/keyboard0",
                                       "/dev/video/vga0"), "tty0");

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
