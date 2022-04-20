

#ifndef __LIB_LIBPOSIX_TIME_H
#define __LIB_LIBPOSIX_TIME_H

#include <Macros.h>
#include "sys/types.h"

/**
 * @addtogroup lib
 * @{
 *
 * @addtogroup libposix
 * @{
 */

/**
 * The <time.h> header shall declare the timespec structure.
 */
struct timespec
{
    /** Seconds. */
    time_t tv_sec;

    /** Nanoseconds. */
    long tv_nsec;
};

/**
 * Convert given time values to UNIX timestamp (seconds since epoch)
 *
 * @param year Year value
 * @param month Month value
 * @param day Day value
 * @param hour Hour value (0-23)
 * @param min Minute value (0-59)
 * @param sec Second value (0-59)
 *
 * @return Converted timestamp in seconds since epoch (UNIX time)
 *
 * @note This code is based on the linux source in kernel/time.c
 */
extern C unsigned long mktime(const unsigned int year, const unsigned int month,
                              const unsigned int day, const unsigned int hour,
                              const unsigned int min, const unsigned int sec);
/**
 * @}
 * @}
 */

#endif /* __LIB_LIBPOSIX_TIME_H */
