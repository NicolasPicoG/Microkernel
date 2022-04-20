

#include <unistd.h>
#include <sys/types.h>
#include "stdio.h"
#include "stdlib.h"
#include "errno.h"

size_t fread(void *ptr, size_t size,
             size_t nitems, FILE *stream)
{
    size_t i;
    char *buf = (char *) ptr;

    // Read items
    for (i = 0; i < nitems; i++)
    {
        ssize_t num = read(stream->fd, buf, size);
        if (num < 0 || (size_t)num != size)
            break;

        buf += size;
    }

    // Done
    return i;
}
