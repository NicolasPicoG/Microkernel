
#ifndef __BIN_SH_TIMECOMMAND
#define __BIN_SH_TIMECOMMAND

#include <Types.h>
#include "ShellCommand.h"

class Shell;

/**
 * @addtogroup bin
 * @{
 *
 * @addtogroup sh
 * @{
 */

/**
 * Measure the execution time of a program.
 */
class TimeCommand : public ShellCommand
{
  public:

    /**
     * Constructor function.
     */
    TimeCommand(Shell *shell);

    /**
     * Executes the command.
     *
     * @param nparams Number of parameters given.
     * @param params Array of parameters.
     * @return Error code or zero on success.
     */
    virtual int execute(const Size nparams, const char **params);

  private:

    /** Shell object */
    Shell *m_shell;
};

/**
 * @}
 * @}
 */

#endif /* __BIN_SH_TIMECOMMAND */
