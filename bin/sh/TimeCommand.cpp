

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/wait.h>
#include <Log.h>
#include <SystemClock.h>
#include "Shell.h"
#include "TimeCommand.h"

TimeCommand::TimeCommand(Shell *shell)
    : ShellCommand("time", 1)
    , m_shell(shell)
{
    m_help = "Measure the execution time of a program";
}

int TimeCommand::execute(const Size nparams, const char **params)
{
    SystemClock t1, t2;

    // Get timestamp before
    t1.now();

    // Run command
    int result = m_shell->executeInput(nparams, params, false);
    if (result != EXIT_SUCCESS)
    {
        return result;
    }

    // Get timestamp after
    t2.now();

    // Print time measured
    printf("\r\nTime: ");
    t1.printDiff(t2);
    return result;
}
