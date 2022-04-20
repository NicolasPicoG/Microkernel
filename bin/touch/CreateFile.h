

#ifndef __BIN_TOUCH_CREATEFILE_H
#define __BIN_TOUCH_CREATEFILE_H

#include <POSIXApplication.h>

/**
 * @addtogroup bin
 * @{
 */

/**
 * Create new files on the filesystem
 */
class CreateFile : public POSIXApplication
{
  public:

    /**
     * Constructor
     *
     * @param argc Argument count
     * @param argv Argument values
     */
    CreateFile(int argc, char **argv);

    /**
     * Destructor
     */
    virtual ~CreateFile();

    /**
     * Execute the application.
     *
     * @return Result code
     */
    virtual Result exec();

  private:

    /**
     * Create a new empty file
     *
     * @param file Name of the file to create
     *
     * @return Result code
     */
    Result createFile(const String & file) const;
};

/**
 * @}
 */

#endif /* __BIN_TOUCH_CREATEFILE_H */
