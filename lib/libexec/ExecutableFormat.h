

#ifndef __LIBEXEC_EXECUTABLEFORMAT_H
#define __LIBEXEC_EXECUTABLEFORMAT_H
#ifndef __ASSEMBLER__

#include <Memory.h>
#include <Types.h>

/**
 * @addtogroup lib
 * @{
 *
 * @addtogroup libexec
 * @{
 */

/** Entry point of a program. */
typedef Address EntryPoint;

/** Forward declaration. */
class ExecutableFormat;

/**
 * Confirms if we understand the given format.
 * @return true on success and false on failure.
 */
typedef ExecutableFormat * FormatDetector(u8 *image, Size size);

/**
 * Abstraction class of various executable formats.
 */
class ExecutableFormat
{
  public:

    /**
     * Memory region.
     */
    typedef struct Region
    {
        Address virt;
        Address dataOffset;
        Size dataSize;
        Size memorySize;
        Memory::Access access;
    }
    Region;

    /**
     * Result code
     */
    enum Result
    {
        Success,
        NotFound,
        InvalidFormat,
        OutOfMemory
    };

  public:

    /**
     * Class constructor.
     *
     * @param image Pointer to program image.
     * @param size Size of the program image.
     */
    ExecutableFormat(const u8 *image, const Size size);

    /**
     * Class destructor.
     */
    virtual ~ExecutableFormat();

    /**
     * Memory regions a program needs at runtime.
     *
     * @param regions Memory regions to fill.
     * @param count On input, the maximum number of regions to read.
     *              On output, the actual number of regions read.
     *
     * @return Result code.
     */
    virtual Result regions(Region *regions, Size *count) const = 0;

    /**
     * Lookup the program entry point.
     *
     * @param entry Entry point on output.
     * @return Result code.
     */
    virtual Result entry(Address *entry) const = 0;

    /**
     * Find a ExecutableFormat which can handle the given format.
     *
     * @param image Program image to read.
     * @param size Program image size.
     * @param fmt ExecutableFormat object pointer on output.
     *
     * @return Result code.
     *
     * @todo Invoke Lz4Decompressor inside this function so that the various callers do not need to anymore
     */
    static Result find(const u8 *image, const Size size, ExecutableFormat **fmt);

  protected:

    /** Input image raw data */
    const u8 *m_image;

    /** Input image size in bytes */
    const Size m_size;
};

/**
 * @}
 * @}
 */

#endif /* __ASSEMBLER__ */
#endif /* __LIBEXEC_EXECUTABLEFORMAT_H */
