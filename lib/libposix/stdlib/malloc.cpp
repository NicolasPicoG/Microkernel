

#include <sys/types.h>
#include "stdlib.h"
#include "errno.h"

extern C void * malloc(size_t size)
{
    void *buf = new char[size];
    if (buf == 0)
    {
        errno = ENOMEM;
    }

    return buf;
}
