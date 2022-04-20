
#include <unistd.h>
#include <fcntl.h>
#include "StdioCommand.h"

StdioCommand::StdioCommand() : ShellCommand("stdio", 2)
{
    m_help = "Change standard I/O of the shell";
}

int StdioCommand::execute(const Size nparams, const char **params)
{
    // Close current standard I/O
    close(0);
    close(1);
    close(2);

    // Reopen standard I/O
    open(params[0], O_RDWR);
    open(params[1], O_RDWR);
    open(params[1], O_RDWR);

    // Done
    return 0;
}
