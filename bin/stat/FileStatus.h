

#ifndef __BIN_STAT_FILESTATUS_H
#define __BIN_STAT_FILESTATUS_H

#include <POSIXApplication.h>

/**
 * @addtogroup bin
 * @{
 */

/**
 * Retrieve file status from the filesystem
 */
class FileStatus : public POSIXApplication
{
  public:

    /**
     * Constructor
     *
     * @param argc Argument count
     * @param argv Argument values
     */
    FileStatus(int argc, char **argv);

    /**
     * Destructor
     */
    virtual ~FileStatus();

    /**
     * Execute the application.
     *
     * @return Result code
     */
    virtual Result exec();

  private:

    /**
     * Concatenate a file
     *
     * @param file Name of file to concatenate
     *
     * @return Result code
     */
    Result printStatus(const String & file) const;
};

/**
 * @}
 */

#endif /* __BIN_STAT_FILESTATUS_H */
