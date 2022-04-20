

#include <Macros.h>
#include "Support.h"
#include "Kernel.h"

extern C void constructors()
{
    for (void (**ctor)() = &CTOR_LIST; *ctor; ctor++)
    {
        (*ctor)();
    }
}

extern C void destructors()
{
    for (void (**dtor)() = &DTOR_LIST; *dtor; dtor++)
    {
        (*dtor)();
    }
}

extern C void __cxa_pure_virtual()
{
}

extern C void __dso_handle()
{
}

extern C void __stack_chk_fail(void)
{
}

extern C int __cxa_atexit(void (*func) (void *), void * arg, void * dso_handle)
{
    return (0);
}

extern C int raise(int sig)
{
    return 0;
}
