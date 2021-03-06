

#ifndef __KERNEL_SUPPORT_H
#define __KERNEL_SUPPORT_H

#include <Macros.h>

/**
 * @addtogroup kernel
 * @{
 */

/**
 * Invokes all function pointers inside the .ctors section.
 */
extern C void constructors();

/**
 * Invokes function pointers inside the .dtors section.
 */
extern C void destructors();

/**
 * Unknown function, required by g++.
 */
extern C void __cxa_pure_virtual();

/**
 * Constructor list.
 */
extern void (*CTOR_LIST)();

/**
 * Destructor list.
 */
extern void (*DTOR_LIST)();

/**
 * @}
 */

#endif /* __KERNEL_SUPPORT_H */
