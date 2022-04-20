

#include <Nicoos/User.h>
#include <MemoryBlock.h>
#include "BootSymbolStorage.h"

BootSymbolStorage::BootSymbolStorage(const BootImageStorage &bootImage,
                                     const char *symbolName)
    : m_bootImage(bootImage)
    , m_symbol(loadSymbol(symbolName))
    , m_segment(loadSegment(m_symbol))
{
}

FileSystem::Result BootSymbolStorage::initialize()
{
    if (m_symbol.segmentsTotalSize != 0 && m_segment.offset != 0)
    {
        return FileSystem::Success;
    }
    else
    {
        return FileSystem::IOError;
    }
}

FileSystem::Result BootSymbolStorage::read(const u64 offset, void *buffer, const Size size) const
{
    return m_bootImage.read(offset + m_segment.offset, buffer, size);
}

u64 BootSymbolStorage::capacity() const
{
    return m_symbol.segmentsTotalSize;
}

const BootSymbol BootSymbolStorage::loadSymbol(const char *name) const
{
    const String symbolName(name);
    const BootImage image = m_bootImage.bootImage();
    BootSymbol symbol;

    // Clear symbol first
    MemoryBlock::set(&symbol, 0, sizeof(symbol));

    // Search for the given BootSymbol
    for (uint i = 0; i < image.symbolTableCount; i++)
    {
        const FileSystem::Result result = m_bootImage.read(image.symbolTableOffset + (i * sizeof(BootSymbol)),
                                                          &symbol, sizeof(BootSymbol));
        if (result != FileSystem::Success)
        {
            ERROR("failed to read BootSymbol: result = " << (int) result);
            return symbol;
        }

        if (symbolName.equals(symbol.name))
        {
            return symbol;
        }
    }

    // No match, return empty symbol
    MemoryBlock::set(&symbol, 0, sizeof(symbol));
    return symbol;
}

const BootSegment BootSymbolStorage::loadSegment(const BootSymbol &symbol) const
{
    const BootImage image = m_bootImage.bootImage();
    BootSegment segment;

    // Clear segment first
    MemoryBlock::set(&segment, 0, sizeof(segment));

    if (symbol.segmentsTotalSize > 0)
    {
        const FileSystem::Result result = m_bootImage.read(
            image.segmentsTableOffset + (symbol.segmentsOffset * sizeof(BootSegment)),
            &segment,
            sizeof(BootSegment)
        );

        if (result != FileSystem::Success)
        {
            ERROR("failed to read BootSegment: result = " << (int) result);
            MemoryBlock::set(&segment, 0, sizeof(segment));
        }
    }

    return segment;
}
