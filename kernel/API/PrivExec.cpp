

#include <Nicoos/System.h>
#include <Nicoos/ProcessManager.h>
#include <Log.h>
#include "PrivExec.h"

API::Result PrivExecHandler(const PrivOperation op,
                            const Address param)
{
    DEBUG("");

    switch (op)
    {
    case Idle: {
        ProcessManager *procs = Kernel::instance()->getProcessManager();
        procs->setIdle(procs->current());
        return API::Success;
    }

    case RebootSystem:
        cpu_reboot();
        while (true) ;

    case ShutdownSystem:
        cpu_shutdown();
        return API::Success;

    case WriteConsole:
        assert(Log::instance() != ZERO);
        (*Log::instance()) << (char *) param;
        return API::Success;

    case Panic:
        FATAL("panic in PID " << Kernel::instance()->getProcessManager()->current()->getID());
        return API::Success;

    default:
        ;
    }
    return API::InvalidArgument;
}
