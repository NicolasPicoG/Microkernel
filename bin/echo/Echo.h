

#ifndef __BIN_ECHO_ECHO_H
#define __BIN_ECHO_ECHO_H

#include <POSIXApplication.h>

/**
 * @addtogroup bin
 * @{
 */

/**
 * Echo standard input to output.
 */
class Echo : public POSIXApplication
{
  public:

    /**
     * Constructor
     *
     * @param argc Argument count
     * @param argv Argument values
     */
    Echo(int argc, char **argv);

    /**
     * Destructor
     */
    virtual ~Echo();

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

#endif /* __BIN_ECHO_ECHO_H */
