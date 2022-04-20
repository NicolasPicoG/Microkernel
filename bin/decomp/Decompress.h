

#ifndef __BIN_DECOMP_DECOMPRESS_H
#define __BIN_DECOMP_DECOMPRESS_H

#include <POSIXApplication.h>

/**
 * @addtogroup bin
 * @{
 */

/**
 * Decompress a compressed file
 */
class Decompress : public POSIXApplication
{
  public:

    /**
     * Constructor
     *
     * @param argc Argument count
     * @param argv Argument values
     */
    Decompress(int argc, char **argv);

    /**
     * Destructor
     */
    virtual ~Decompress();

    /**
     * Execute the application.
     *
     * @return Result code
     */
    virtual Result exec();

  private:

    /**
     * Decompress the given file
     *
     * @param inputFilename Path to the file to decompress
     *
     * @return Result code
     */
    Result decompressFile(const String inputFilename) const;
};

/**
 * @}
 */

#endif /* __BIN_DECOMP_DECOMPRESS_H */
