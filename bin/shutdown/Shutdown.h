

#ifndef __BIN_SHUTDOWN_SHUTDOWN_H
#define __BIN_SHUTDOWN_SHUTDOWN_H

#include <POSIXApplication.h>

/**
 * @addtogroup bin
 * @{
 */

/**
 * Turn off or restart the system.
 */
class Shutdown : public POSIXApplication
{
  public:

    /**
     * Constructor
     *
     * @param argc Argument count
     * @param argv Argument values
     */
    Shutdown(int argc, char **argv);

    /**
     * Destructor
     */
    virtual ~Shutdown();

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

#endif /* __BIN_SHUTDOWN_SHUTDOWN_H */
