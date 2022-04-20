

#ifndef __BIN_UNAME_UNIXNAME_H
#define __BIN_UNAME_UNIXNAME_H

#include <POSIXApplication.h>

/**
 * @addtogroup bin
 * @{
 */

/**
 * Print the operating system name.
 */
class UnixName : public POSIXApplication
{
  public:

    /**
     * Constructor
     *
     * @param argc Argument count
     * @param argv Argument values
     */
    UnixName(int argc, char **argv);

    /**
     * Destructor
     */
    virtual ~UnixName();

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

#endif /* __BIN_UNAME_UNIXNAME_H */
