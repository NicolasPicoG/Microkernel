

#include <Nicoos/User.h>
#include <Timer.h>
#include "unistd.h"
#include "errno.h"

unsigned int sleep(unsigned int seconds)
{
    Timer::Info info;

    // Get current kernel timer ticks
    if (ProcessCtl(SELF, InfoTimer, (Address) &info) != API::Success)
    {
        errno = EAGAIN;
        return seconds;
    }

    // Set time to wait
    info.ticks += (info.frequency * seconds);

    // Wait until the timer expires
    if (ProcessCtl(SELF, WaitTimer, (Address) &info) != API::Success)
    {
        errno = EIO;
        return seconds;
    }

    // Done
    return 0;
}
