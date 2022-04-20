

#ifndef __BIN_HOSTNAME_HOSTNAME_H
#define __BIN_HOSTNAME_HOSTNAME_H

#include <POSIXApplication.h>

/**
 * @addtogroup bin
 * @{
 */

/**
 * Print the system hostname.
 */
class Hostname : public POSIXApplication
{
  public:

    /**
     * Constructor
     *
     * @param argc Argument count
     * @param argv Argument values
     */
    Hostname(int argc, char **argv);

    /**
     * Destructor
     */
    virtual ~Hostname();

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

#endif /* __BIN_HOSTNAME_HOSTNAME_H */
