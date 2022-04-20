

#include <KernelLog.h>
#include <DeviceServer.h>
#include "Keyboard.h"

int main(int argc, char **argv)
{
    KernelLog log;
    DeviceServer server("/dev/ps2");

    // Create a new keyboard object
    Keyboard *kb = new Keyboard(server.getNextInode());

    // Register it with the DeviceServer
    server.registerDevice(kb, "keyboard0");
    server.registerInterrupt(kb, PS2_IRQ);

    // Initialize
    const FileSystem::Result result = server.initialize();
    if (result != FileSystem::Success)
    {
        ERROR("failed to initialize: result = " << (int) result);
        return 1;
    }

    // Start processing requests
    return server.run();
}
