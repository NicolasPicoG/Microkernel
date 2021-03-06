

#ifndef __LIBSTD_COMPARABLE_H
#define __LIBSTD_COMPARABLE_H

#include "Types.h"

/**
 * @addtogroup lib
 * @{
 *
 * @addtogroup libstd
 * @{
 */

/**
 * Objects which can be compared to each other.
 */
template <class T> class Comparable
{
  public:

    /**
     * Class destructor.
     */
    virtual ~Comparable() {}

    /**
     * Test if an object is equal to an other object.
     *
     * @param t Object instance.
     *
     * @return True if equal, false otherwise.
     */
    virtual bool equals(const T &t) const = 0;

    /**
     * Compares this Comparable to the given Comparable.
     *
     * This function checks whether this Comparable is equal to,
     * less, or greater then the given Comparable.
     *
     * @param t The Comparable to compare us to.
     *
     * @return an int < 0, 0, > 0 if we are respectively less then,
     *         equal to or greater then the given Comparable.
     */
    virtual int compareTo(const T &t) const = 0;
};

/**
 * @}
 * @}
 */

#endif /* __LIBSTD_COMPARABLE_H */
