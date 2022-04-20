

#include <ProcessClient.h>
#include "unistd.h"

pid_t getpid()
{
    const ProcessClient proc;
    return proc.getProcessID();
}
