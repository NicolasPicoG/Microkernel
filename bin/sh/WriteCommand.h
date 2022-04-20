

#ifndef __SH_WRITECOMMAND
#define __SH_WRITECOMMAND

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
 * Write data to a file.
 */
class WriteCommand : public ShellCommand
{
  public:

    /**
     * Constructor function.
     */
    WriteCommand();

    /**
     * Executes the command.
     *
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

#endif /* __SH_WRITECOMMAND */
