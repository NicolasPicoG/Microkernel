

#ifndef __SH_SHELLCOMMAND
#define __SH_SHELLCOMMAND

#include <String.h>
#include <HashTable.h>
#include <Types.h>

/**
 * @addtogroup bin
 * @{
 *
 * @addtogroup sh
 * @{
 */

/**
 * Builtin command for the Shell.
 *
 * @see Shell
 */
class ShellCommand
{
  public:

    /**
     * Constructor.
     *
     * @param name Unique name of the command.
     * @param minParams Minimum number of parameters required by this command.
     */
    ShellCommand(const char *name, const Size minParams = 0);

    /**
     * Destructor.
     */
    virtual ~ShellCommand();

    /**
     * Get command name.
     *
     * @return Command name
     */
    const char * getName() const;

    /**
     * Get command help.
     *
     * @return Command help
     */
    const char * getHelp() const;

    /**
     * Get the minimum number of parameters required.
     *
     * @return Minimum number of parameters required.
     */
    Size getMinimumParams() const;

    /**
     * Executes the command.
     *
     * @param nparams Number of parameters given.
     * @param params Array of parameters.
     * @return Error code or zero on success.
     */
    virtual int execute(const Size nparams, const char **params) = 0;

  protected:

    /** Unique name of the command. */
    const char *m_name;

    /** Command help text. */
    const char *m_help;

    /** Minimum number of parameters required. */
    const Size m_minParams;
};

/**
 * @}
 * @}
 */

#endif /* __SH_SHELLCOMMAND */
