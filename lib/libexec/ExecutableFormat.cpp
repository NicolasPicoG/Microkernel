

#include <Macros.h>
#include "ExecutableFormat.h"
#include "ELF.h"

ExecutableFormat::ExecutableFormat(const u8 *image, const Size size)
    : m_image(image)
    , m_size(size)
{
}

ExecutableFormat::~ExecutableFormat()
{
}

ExecutableFormat::Result ExecutableFormat::find(const u8 *image,
                                                const Size size,
                                                ExecutableFormat **fmt)
{
    return ELF::detect(image, size, fmt);
}
