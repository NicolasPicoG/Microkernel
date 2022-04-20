

#ifndef __LIBC_LIMITS_H
#define __LIBC_LIMITS_H

#include <Macros.h>
#include <sys/types.h>
#include <FileSystemPath.h>

/**
 * @addtogroup lib
 * @{
 *
 * @addtogroup libposix
 * @{
 */

/** Number of bits in a type char. */
#define CHAR_BIT  8

/** Maximum file path length. */
#define PATH_MAX  FileSystemPath::MaximumLength

/**
 * @}
 * @}
 */

#endif /* __LIBC_LIMITS_H */
