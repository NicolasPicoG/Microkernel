

#ifndef __BIN_INIT_INIT_H
#define __BIN_INIT_INIT_H

#include <POSIXApplication.h>

/**
 * @addtogroup bin
 * @{
 */

/**
 * Initialize system processes.
 */
class Init : public POSIXApplication
{
  public:

    /**
     * Constructor
     *
     * @param argc Argument count
     * @param argv Argument values
     */
    Init(int argc, char **argv);

    /**
     * Destructor
     */
    virtual ~Init();

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

#endif /* __BIN_INIT_INIT_H */
