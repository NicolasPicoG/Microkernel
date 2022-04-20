

#ifndef __SH_EXITCOMMAND
#define __SH_EXITCOMMAND

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
 * Exit the Shell.
 */
class ExitCommand : public ShellCommand
{
  public:

    /**
     * Constructor function.
     */
    ExitCommand();

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

#endif /* __SH_EXITCOMMAND */
