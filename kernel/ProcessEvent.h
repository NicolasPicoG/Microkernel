
#ifndef __KERNEL_PROCESSEVENT_H
#define __KERNEL_PROCESSEVENT_H

#include <Types.h>
#include <Macros.h>
#include "ProcessShares.h"

/**
 * @addtogroup kernel
 * @{
 */

enum ProcessEventType
{
    InterruptEvent,
    ShareCreated,
    ProcessTerminated
};

/**
 * Represents a process which may run on the host.
 */
typedef struct ProcessEvent
{
    ProcessEventType type;
    Size number;
    ProcessShares::MemoryShare share;
}
ProcessEvent;

/**
 * @}
 */

#endif /* __KERNEL_PROCESSEVENT_H */
