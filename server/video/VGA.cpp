

#include <Nicoos/User.h>
#include <Types.h>
#include <MemoryBlock.h>
#include "VGA.h"

VGA::VGA(const u32 inode,
         const Size w,
         const Size h)
    : Device(inode, FileSystem::BlockDeviceFile)
    , width(w)
    , height(h)
{
    m_identifier << "vga0";
}

FileSystem::Result VGA::initialize()
{
    Memory::Range range;

    // Request VGA memory
    range.size   = PAGESIZE;
    range.access = Memory::User     |
                   Memory::Readable |
                   Memory::Writable;
    range.virt   = ZERO;
    range.phys   = VGA_PADDR;
    VMCtl(SELF, MapContiguous, &range);

    // Point to the VGA mapping
    vga = (u16 *) range.virt;

    // Clear screen
    for (uint i = 0; i < width * height; i++)
    {
        vga[i] = VGA_CHAR(' ', LIGHTGREY, BLACK);
    }

    // Disable hardware cursor
    m_io.outb(VGA_IOADDR, 0x0a);
    m_io.outb(VGA_IODATA, 1 << 5);

    // Successfull
    return FileSystem::Success;
}

FileSystem::Result VGA::read(IOBuffer & buffer,
                             Size & size,
                             const Size offset)
{
    if (offset + size > width * height * sizeof(u16))
    {
        return FileSystem::InvalidArgument;
    }

    buffer.write(vga + (offset / sizeof(u16)), size);
    return FileSystem::Success;
}

FileSystem::Result VGA::write(IOBuffer & buffer,
                              Size & size,
                              const Size offset)
{
    if (offset + size > width * height * sizeof(u16))
    {
        return FileSystem::InvalidArgument;
    }

    MemoryBlock::copy(vga + (offset / sizeof(u16)), buffer.getBuffer(), size);
    return FileSystem::Success;
}
