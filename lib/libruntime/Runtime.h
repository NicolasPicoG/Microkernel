

#ifndef __LIB_LIBRUNTIME_RUNTIME_H
#define __LIB_LIBRUNTIME_RUNTIME_H

#include <Macros.h>
#include <Types.h>

/**
 * @addtogroup lib
 * @{
 *
 * @addtogroup libruntime
 * @{
 */

/** Maximum size of each argument. */
#define ARGV_SIZE  128

/** Number of arguments at maximum. */
#define ARGV_COUNT (PAGESIZE / ARGV_SIZE)

/**
 * Program entry point.
 *
 * @param argc Argument count.
 * @param argv Argument values.
 *
 * @return Exit status.
 */
int main(int argc, char **argv);

/**
 * @}
 * @}
 */

#endif /* __LIB_LIBRUNTIME_RUNTIME_H */
