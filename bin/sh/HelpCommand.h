

#ifndef __SH_HELPCOMMAND
#define __SH_HELPCOMMAND

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
 * Prints the help info for all known ShellCommands.
 */
class HelpCommand : public ShellCommand
{
  public:

    /**
     * Constructor.
     */
    HelpCommand(Shell *shell);

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

#endif /* __SH_HELPCOMMAND */
