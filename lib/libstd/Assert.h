

#ifndef __LIB_LIBSTD_ASSERT_H
#define __LIB_LIBSTD_ASSERT_H

/**
 * @addtogroup lib
 * @{
 *
 * @addtogroup libstd
 * @{
 */

#if defined(__ASSERT__)

#include "Log.h"

/**
 * @name Preprocessor assertion
 * @{
 */

/**
 * Verify that a given expression evaluates to true.
 *
 * @param exp Boolean expression.
 */
#define assert(exp) \
    if (!(exp)) \
    { \
        FATAL("*** Assertion `" << QUOTE(#exp) << "' failed ***"); \
    }

/**
 * @}
 */

#else

/**
 * @name Dummy preprocessor macros
 * @{
 */

/**
 * Dummy assertion function which does not perform any check.
 *
 * @param exp Expression is ignored.
 */
#define assert(exp)

/**
 * @}
 */

#endif /* defined(__ASSERT__) */

/**
 * @}
 * @}
 */

#endif /* __LIB_LIBSTD_ASSERT_H */
