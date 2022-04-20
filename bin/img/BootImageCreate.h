

#ifndef __BIN_IMG_BOOTIMAGECREATE_H
#define __BIN_IMG_BOOTIMAGECREATE_H

#include <Application.h>
#include <ExecutableFormat.h>
#include <BootImage.h>

/**
 * @addtogroup bin
 * @{
 */

/** Maximum memory regions. */
#define BOOTENTRY_MAX_REGIONS 16

/**
 * Executable entry for use inside a boot image.
 */
typedef struct BootEntry
{
    /** BootSymbol definition */
    BootSymbol symbol;

    /** Input data buffer read from the original file */
    u8 *data;

    /** Memory regions for this symbol */
    ExecutableFormat::Region regions[BOOTENTRY_MAX_REGIONS];

    /** Number of memory regions. */
    Size numRegions;
}
BootEntry;

/**
 * Create system boot image
 */
class BootImageCreate : public Application
{
  private:

    /** Size of memory pages as supported by this program. */
    static const Size PageSize = 4096U;

  public:

    /**
     * Constructor
     *
     * @param argc Argument count
     * @param argv Argument values
     */
    BootImageCreate(int argc, char **argv);

    /**
     * Destructor
     */
    virtual ~BootImageCreate();

    /**
     * Execute the application.
     *
     * @return Result code
     */
    virtual Result exec();

  protected:

    /**
     * Print text to output.
     *
     * @param string Text to print to program output.
     * @return Result code.
     */
    virtual Result output(const char *string) const;

  private:

    /**
     * Read boot symbols using a configuration file.
     *
     * @param file Name of the boot configuration file.
     * @param prefix Prefix each entry from the config file with the given path or NULL
     * @param entries Pointer to Vector with BootEntry's
     *
     * @return Number of bytes read
     */
    Size readBootSymbols(const char *file,
                         const char *prefix,
                         Vector<BootEntry *> *entries);
};

/**
 * @}
 */

#endif /* __BIN_IMG_BOOTIMAGECREATE_H */
