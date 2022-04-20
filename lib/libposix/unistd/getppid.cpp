

#include <ProcessClient.h>
#include "unistd.h"

pid_t getppid()
{
    const ProcessClient proc;
    return proc.getParentID();
}
