

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "Hostname.h"

Hostname::Hostname(int argc, char **argv)
    : POSIXApplication(argc, argv)
{
    parser().setDescription("Print the system hostname");
}

Hostname::~Hostname()
{
}

Hostname::Result Hostname::exec()
{
    char host[128];

    // Fetch hostname
    gethostname(host, sizeof(host));
    
    // Output our hostname
    printf("%s\r\n", host);
    
    // Done
    return Success;
}
