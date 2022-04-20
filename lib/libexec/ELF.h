

#ifndef __LIBEXEC_ELF_H
#define __LIBEXEC_ELF_H

#include <Types.h>
#include <Factory.h>
#include "ExecutableFormat.h"
#include "ELFHeader.h"

/**
 * @addtogroup lib
 * @{
 *
 * @addtogroup libexec
 * @{
 */

/**
 * Executable and Linkable Format (ELF).
 */
class ELF : public ExecutableFormat
{
  public:

    /**
     * Class constructor.
     *
     * @param image Pointer to raw input image data
     * @param size Number of bytes of input image data
     */
    ELF(const u8 *image, const Size size);

    /**
     * Class destructor.
     */
    virtual ~ELF();

    /**
     * Reads out segments from the ELF program table.
     *
     * @param regions Memory regions to fill.
     * @param count Maximum number of memory regions on input.
     *              Actual number of memory regions on output.
     *
     * @return Result code.
     *
     * @todo Rework executables to avoid giving all mapped regions read, write and execute permissions.
     */
    virtual Result regions(Region *regions, Size *count) const;

    /**
     * Lookup the program entry point.
     *
     * @param entry Program entry point on output.
     *
     * @return Result code.
     */
    virtual Result entry(Address *entry) const;

    /**
     * Read ELF header from memory.
     *
     * @param image Pointer to raw input image data
     * @param size Number of bytes of input image data
     * @param fmt Outputs a pointer to an ELF instance
     *
     * @return Result code
     */
    static Result detect(const u8 *image, const Size size, ExecutableFormat **fmt);
};

/**
 * @}
 * @}
 */

#endif /* __LIBEXEC_ELF_H */
