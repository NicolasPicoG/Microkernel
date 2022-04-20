
#ifndef __BIN_RM_REMOVE_H
#define __BIN_RM_REMOVE_H

#include <POSIXApplication.h>

/**
 * @addtogroup bin
 * @{
 */

/**
 * Remove file from the filesystem
 */
class Remove : public POSIXApplication
{
  public:

    /**
     * Constructor
     *
     * @param argc Argument count
     * @param argv Argument values
     */
    Remove(int argc, char **argv);

    /**
     * Destructor
     */
    virtual ~Remove();

    /**
     * Execute the application.
     *
     * @return Result code
     */
    virtual Result exec();
};

/**
 * @}
 */

#endif /* __BIN_RM_REMOVE_H */
