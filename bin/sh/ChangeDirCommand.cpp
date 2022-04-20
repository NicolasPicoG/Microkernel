
#include "ChangeDirCommand.h"
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <Log.h>

ChangeDirCommand::ChangeDirCommand()
    : ShellCommand("cd", 1)
{
    m_help = "Change the current working directory";
}

int ChangeDirCommand::execute(const Size nparams, const char **params)
{
    if (chdir(params[0]) != 0)
    {
        ERROR(getName() << ": failed to change directory to `" << params[0] << "': " << strerror(errno));
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
