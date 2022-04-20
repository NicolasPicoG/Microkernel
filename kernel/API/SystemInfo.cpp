

#include <Nicoos/System.h>
#include <Nicoos/Config.h>
#include <Nicoos/Kernel.h>
#include <SplitAllocator.h>
#include <CoreInfo.h>

API::Result SystemInfoHandler(SystemInformation *info)
{
    SplitAllocator *memory = Kernel::instance()->getAllocator();
    CoreInfo *core = Kernel::instance()->getCoreInfo();

    DEBUG("");

    // Fill in our current information
    info->version          = VERSIONCODE;
    info->kernelAddress    = core->kernel.phys;
    info->kernelSize       = core->kernel.size;
    info->memorySize       = memory->size();
    info->memoryAvail      = memory->available();
    info->coreId           = core->coreId;

    info->bootImageAddress = core->bootImageAddress;
    info->bootImageSize    = core->bootImageSize;
    info->timerCounter     = core->timerCounter;
    info->coreChannelAddress = core->coreChannelAddress;
    info->coreChannelSize    = core->coreChannelSize;

    MemoryBlock::copy(info->cmdline, coreInfo.kernelCommand, 64);
    return API::Success;
}
