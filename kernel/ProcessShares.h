
#ifndef __KERNEL_PROCESSSHARES_H
#define __KERNEL_PROCESSSHARES_H

#include <Types.h>
#include <Macros.h>
#include <List.h>
#include <MemoryMap.h>
#include <Index.h>

class MemoryChannel;
class MemoryContext;
class Process;

/**
 * @addtogroup kernel
 * @{
 */

/**
 * Manages memory shares for a Process.
 */
class ProcessShares
{
  private:

    /** Maximum number of memory shares that a single process can have. */
    static const Size MaximumMemoryShares = 32u;

  public:

    struct MemoryShare
    {
        /** Remote process id for this share */
        ProcessID pid;

        /** CoreId for the other process */
        Size coreId;

        /** Share tag id is defined by the application */
        Size tagId;

        /** Physical memory address range. */
        Memory::Range range;

        /** True if the share is attached (used by both processes) */
        bool attached;
    };

    enum Result
    {
        Success,
        InvalidArgument,
        MemoryMapError,
        OutOfMemory,
        AlreadyExists,
        DetachInProgress,
        NotFound
    };

    /**
     * Constructor.
     */
    ProcessShares(ProcessID pid);

    /**
     * Destructor function.
     */
    virtual ~ProcessShares();

    /**
     * Get process.
     */
    const ProcessID getProcessID() const;

    /**
     * Get MemoryContext object.
     *
     * @return MemoryContext object pointer.
     */
    MemoryContext * getMemoryContext();

    /**
     * Set MemoryContext.
     *
     * @param context MemoryContext object
     *
     * @return Result code.
     */
    Result setMemoryContext(MemoryContext *context);

    /**
     *
     */
    Result createShare(ProcessShares & instance,
                       MemoryShare *share);

    /**
     * Create memory share.
     *
     * @param pid ProcessID for the share.
     * @param coreId CoreID for the share.
     * @param tagId TagID for the share.
     * @param virt Virtual address of the share.
     * @param size Size of the share.
     *
     * @return Result code.
     */
    Result createShare(ProcessID pid,
                       Size coreId,
                       Size tagId,
                       Address virt,
                       Size size);

    /**
     * Read memory share by Process, Core and Tag IDs.
     *
     * @param share MemoryShare buffer (input/output).
     *
     * @return Result code.
     */
    Result readShare(MemoryShare *share);

    /**
     * Remove all shares for the given ProcessID
     *
     * @param pid ProcessID to remove all shares for
     *
     * @return Result code
     */
    Result removeShares(ProcessID pid);

  private:

    /**
     * Release one memory share
     *
     * @param share MemoryShare object pointer
     * @param idx Index position of the object
     *
     * @return Result code
     */
    Result releaseShare(MemoryShare *share, Size idx);

    /**
     * Retrieve MemoryShare object.
     *
     * @param pid ProcessID value to match
     * @param coreId CoreID value to match
     * @param tagId TagID value to match
     *
     * @return MemoryShare pointer if found or ZERO if not
     */
    MemoryShare * findShare(const ProcessID pid,
                            const Size coreId,
                            const Size tagId);

  private:

    /** ProcessID associated to these shares */
    ProcessID m_pid;

    /** MemoryContext instance */
    MemoryContext *m_memory;

    /** Contains all memory shares */
    Index<MemoryShare, MaximumMemoryShares> m_shares;
};

/**
 * @}
 */

#endif /* __KERNEL_PROCESSSHARES_H */
