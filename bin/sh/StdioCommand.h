

#ifndef __SH_STDIOCOMMAND
#define __SH_STDIOCOMMAND

#include <Types.h>
#include "ShellCommand.h"

/**
 * @addtogroup bin
 * @{
 *
 * @addtogroup sh
 * @{
 */

/**
 * Change the standard Input/Output of the shell.
 */
class StdioCommand : public ShellCommand
{
  public:

    /**
     * Constructor function.
     */
    StdioCommand();

    /**
     * Executes the command.
     * @param nparams Number of parameters given.
     * @param params Array of parameters.
     * @return Error code or zero on success.
     */
    virtual int execute(const Size nparams, const char **params);
};

/**
 * @}
 * @}
 */

#endif /* __SH_STDIOCOMMAND */
