

#include <Nicoos/Config.h>
#include <string.h>
#include "unistd.h"
#include "sys/utsname.h"

int uname(struct utsname *name)
{
    // Fill in the struct
    strlcpy(name->sysname, "Nicoos", UTSBUF);
    gethostname(name->nodename, UTSBUF);
    strlcpy(name->release, RELEASE, UTSBUF);
    strlcpy(name->version, COMPILER_VERSION " " DATETIME, UTSBUF);
    strlcpy(name->machine, ARCH "/" SYSTEM, UTSBUF);

    // Success
    return 0;
}
