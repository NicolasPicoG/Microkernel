

#include <Nicoos/User.h>
#include "Init.h"

int main(int argc, char **argv)
{
    SystemInformation info;

    // Only run on core0
    if (info.coreId != 0)
        return 0;

    Init app(argc, argv);
    return app.run();
}
