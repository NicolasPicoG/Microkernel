

#include <Types.h>
#include "Storage.h"

Storage::Storage()
{
}

Storage::~Storage()
{
}

FileSystem::Result Storage::write(const u64 offset, void *buffer, const Size size)
{
    return FileSystem::NotSupported;
}
