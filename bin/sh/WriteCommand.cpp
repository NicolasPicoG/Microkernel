
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <String.h>
#include <Log.h>
#include "WriteCommand.h"

WriteCommand::WriteCommand()
    : ShellCommand("write", 2)
{
    m_help = "Write data to a file";
}

int WriteCommand::execute(const Size nparams, const char **params)
{
    int fd;
    String buf;
    
    // Attempt to open the file first
    if ((fd = open(params[0], O_WRONLY)) < 0)
    {
        ERROR("failed to open `" << params[0] << "': " << strerror(errno));
        return EXIT_FAILURE;
    }
    // Fill write buffer
    for (Size i = 1; i < nparams; i++)
    {
        buf << params[i];
        buf << " ";
    }
    // Append newline
    buf << "\n";

    // Write buffer to the file
    if (write(fd, *buf, buf.length()) < 0)
    {
        ERROR("failed to write `" << params[0] << "': " << strerror(errno));
        return EXIT_FAILURE;
    }

    // Close the file
    close(fd);
    return 0;
}
