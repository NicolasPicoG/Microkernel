

#include <Nicoos/System.h>
#include <Nicoos/ProcessEvent.h>
#include <Nicoos/ProcessManager.h>
#include <MemoryBlock.h>
#include "VMShare.h"
#include "ProcessID.h"

API::Result VMShareHandler(const ProcessID procID,
                           const API::Operation op,
                           ProcessShares::MemoryShare *share)
{
    ProcessManager *procs = Kernel::instance()->getProcessManager();
    Process *proc = ZERO;
    API::Result ret = API::Success;

    DEBUG("");

    // Find the given process
    if (procID == SELF)
    {
        if (op != API::Read)
            return API::InvalidArgument;
        else
            proc = procs->current();
    }
    else if (op != API::Delete && !(proc = procs->get(procID)))
    {
        return API::NotFound;
    }

    switch (op)
    {
        case API::Create:
        {
            switch (procs->current()->getShares().createShare(proc->getShares(), share))
            {
                case ProcessShares::Success: return API::Success;
                case ProcessShares::AlreadyExists: return API::AlreadyExists;
                case ProcessShares::DetachInProgress: return API::TemporaryUnavailable;
                default: return API::IOError;
            }
            break;
        }

        case API::Read:
            if (procs->current()->getShares().readShare(share) != ProcessShares::Success)
            {
                ret = API::IOError;
            }
            break;

        case API::Delete:
            if (procs->current()->getShares().removeShares(procID) != ProcessShares::Success)
                ret = API::IOError;
            break;

        default:
            return API::InvalidArgument;
    }

    // Done
    return ret;
}
