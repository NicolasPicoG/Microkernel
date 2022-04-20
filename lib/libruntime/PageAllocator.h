

#ifndef __LIB_LIBRUNTIME_PAGEALLOCATOR_H
#define __LIB_LIBRUNTIME_PAGEALLOCATOR_H

#include <Nicoos/Constant.h>
#include <Types.h>
#include "Allocator.h"

/**
 * @addtogroup lib
 * @{
 *
 * @addtogroup libruntime
 * @{
 */

/**
 * Allocates virtual memory using the memory server.
 */
class PageAllocator : public Allocator
{
  private:

    /** Minimum size required for allocations */
    static const Size MinimumAllocationSize = PAGESIZE * 32U;

  public:

    /**
     * Class constructor.
     *
     * @param range Block of continguous memory to be managed.
     */
    PageAllocator(const Range range);

    /**
     * Get memory available.
     *
     * @return Size of memory available by the Allocator.
     */
    virtual Size available() const;

    /**
     * Allocate memory.
     *
     * @param args Contains the requested size and alignment on input.
     *             On output, contains the actual allocated address.
     *
     * @return Result value.
     */
    virtual Result allocate(Range & args);

    /**
     * Release memory.
     *
     * @param addr Points to memory previously returned by allocate().
     *
     * @return Result value.
     *
     * @see allocate
     *
     * @todo Currently this function does not actually release memory back to the system.
     *       A potential problem with the current implementation is that releasing memory
     *       may result in fragmented virtual memory that may break higher-level allocators.
     */
    virtual Result release(const Address addr);

  private:

    /** Total number of bytes allocated. */
    Size m_allocated;
};

/**
 * @}
 * @}
 */

#endif /* __LIB_LIBRUNTIME_PAGEALLOCATOR_H */
