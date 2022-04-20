

#include <Nicoos/User.h>
#include <stdio.h>
#include "Shutdown.h"

Shutdown::Shutdown(int argc, char **argv)
    : POSIXApplication(argc, argv)
{
    parser().setDescription("Power off or restart the system");
    parser().registerFlag('p', "poweroff", "Power off the system (the default)");
    parser().registerFlag('r', "reboot", "Restart the system");
}

Shutdown::~Shutdown()
{
}

Shutdown::Result Shutdown::exec()
{
    // If no arguments given, power off the system. */
    if (arguments().getFlags().count() == 0)
    {
        printf("Power off\r\n");
        PrivExec(ShutdownSystem);
    }
    // Print everything?
    else if (arguments().get("reboot"))
    {
        printf("Reboot\r\n");
        PrivExec(RebootSystem);
    }

    return Success;
}
