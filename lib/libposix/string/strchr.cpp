

#include "string.h"

char * strchr(const char *s, int c)
{
    while (*s && *s != c)
    {
        s++;
    }
    return (char *) (*s ? s : NULL);
}
