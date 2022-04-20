

#include <MemoryBlock.h>
#include "ELF.h"

ELF::ELF(const u8 *image, const Size size)
    : ExecutableFormat(image, size)
{
}

ELF::~ELF()
{
}

ELF::Result ELF::detect(const u8 *image, const Size size, ExecutableFormat **fmt)
{
    const ELFHeader *header = (const ELFHeader *) image;

    // Verify ELF magic bytes
    if (header->ident[ELF_INDEX_MAGIC0] == ELF_MAGIC0 &&
        header->ident[ELF_INDEX_MAGIC1] == ELF_MAGIC1 &&
        header->ident[ELF_INDEX_MAGIC2] == ELF_MAGIC2 &&
        header->ident[ELF_INDEX_MAGIC3] == ELF_MAGIC3)
    {
        // Only accept current version, 32-bit ELF executable programs
        if (header->ident[ELF_INDEX_CLASS] == ELF_CLASS_32 &&
            header->version == ELF_VERSION_CURRENT &&
            header->type    == ELF_TYPE_EXEC)
        {
            (*fmt) = new ELF(image, size);
            return Success;
        }
    }
    return InvalidFormat;
}

ELF::Result ELF::regions(ELF::Region *regions, Size *count) const
{
    const ELFHeader *header = (const ELFHeader *) m_image;
    const ELFSegment *segments = (const ELFSegment *) (m_image + header->programHeaderOffset);
    const Size maxSegments = header->programHeaderEntryCount;
    const Size maxRegions = *count;
    Size numRegions = 0, numSegments = 0;

    // Must be of the same sizes
    if (!(header->programHeaderEntrySize == sizeof(ELFSegment) &&
          header->programHeaderEntryCount < 16))
    {
        return InvalidFormat;
    }

    // Fill in the memory regions
    for (;numRegions < maxRegions && numSegments < maxSegments; numSegments++)
    {
        // We are only interested in loadable segments
        if (segments[numSegments].type != ELF_SEGMENT_LOAD)
            continue;

        // Fill the region structure
        regions[numRegions].virt       = segments[numSegments].virtualAddress;
        regions[numRegions].dataOffset = segments[numSegments].offset;
        regions[numRegions].dataSize   = segments[numSegments].fileSize;
        regions[numRegions].memorySize = segments[numSegments].memorySize;
        regions[numRegions++].access   = Memory::User | Memory::Readable | Memory::Writable | Memory::Executable;
    }

    // All done
    (*count) = numRegions;
    return Success;
}

ELF::Result ELF::entry(Address *entry) const
{
    const ELFHeader *header = (const ELFHeader *) m_image;
    *entry = header->entry;
    return Success;
}
