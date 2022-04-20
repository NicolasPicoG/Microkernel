

#ifndef __BIN_SH_CHANGE_DIR_COMMAND
#define __BIN_SH_CHANGE_DIR_COMMAND

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
 * Change the current working directory.
 */
class ChangeDirCommand : public ShellCommand
{
  public:

    /**
     * Constructor function.
     */
    ChangeDirCommand();

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

#endif /* __BIN_SH_CHANGE_DIR_COMMAND */
