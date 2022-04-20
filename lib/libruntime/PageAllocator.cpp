

#include <Nicoos/System.h>
#include "PageAllocator.h"

PageAllocator::PageAllocator(const Allocator::Range range)
    : Allocator(range)
    , m_allocated(PAGESIZE)
{
}

Size PageAllocator::available() const
{
    return size() - m_allocated;
}

Allocator::Result PageAllocator::allocate(Allocator::Range & args)
{
    Arch::MemoryMap map;
    Memory::Range heapRange = map.range(MemoryMap::UserHeap);
    Memory::Range range;
    Size bytes  = args.size > MinimumAllocationSize ?
                  args.size : MinimumAllocationSize;

    // Check for heap overflow
    if (m_allocated + bytes >= heapRange.size)
    {
        ERROR("cannot allocate beyond maximum heap size " << heapRange.size);
        return Allocator::OutOfMemory;
    }

    // Set return address
    args.address = base() + m_allocated;

    // Align to pagesize
    bytes = aligned(bytes, PAGESIZE * 32U);

    // Fill in the message
    range.size   = bytes;
    range.access = Memory::User | Memory::Readable | Memory::Writable;
    range.virt   = base() + m_allocated;
    range.phys   = ZERO;
    const API::Result r = VMCtl(SELF, MapSparse, &range);
    if (r != API::Success)
    {
        ERROR("failed to allocate memory using VMCtl(): " << (int)r);
        return Allocator::OutOfMemory;
    }

    // Update count
    m_allocated += range.size;

    // Success
    args.size = range.size;
    return Success;
}

Allocator::Result PageAllocator::release(const Address addr)
{
    return InvalidAddress;
}
