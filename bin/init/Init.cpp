
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>
#include "Init.h"

Init::Init(int argc, char **argv)
    : POSIXApplication(argc, argv)
{
    parser().setDescription("Initialize system processes");
    parser().registerFlag('s', "script", "Set shell startup script");
}

Init::~Init()
{
}

Init::Result Init::exec()
{
    const char *script = arguments().get("script") ?
                         arguments().get("script") : "/etc/init.sh";
    const char *av[] = { "/bin/sh", script, ZERO };
    int pid, status;

    NOTICE("Starting init script: " << script);

    // Execute the run commands file
    if ((pid = runProgram("/bin/sh", av)) == -1)
    {
        ERROR("failed to execute /bin/sh: " <<
              strerror(errno));
        return IOError;
    }

    // Wait for the command to finish before terminating
    waitpid(pid, &status, 0);
    return Success;
}
