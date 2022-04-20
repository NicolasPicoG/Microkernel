

#include <Nicoos/User.h>
#include <KernelLog.h>
#include <stdlib.h>
#include "TmpFileSystem.h"

int main(int argc, char **argv)
{
    KernelLog log;
    SystemInformation info;
    const char *path = "/tmp";

    // Only run on core0
    if (info.coreId != 0)
        return EXIT_SUCCESS;

    if (argc > 1)
        path = argv[1];

    TmpFileSystem server(path);

    // Mount, then start serving requests.
    server.mount();
    return server.run();
}
