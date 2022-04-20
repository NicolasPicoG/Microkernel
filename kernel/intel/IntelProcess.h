

#ifndef __INTEL_PROCESS_H
#define __INTEL_PROCESS_H

#include <Nicoos/Process.h>
#include <Types.h>

/**
 * @addtogroup kernel
 * @{
 *
 * @addtogroup kernel_intel
 * @{
 */

/**
 * Process which may execute on an Intel CPU.
 *
 * @todo IntelProcess currently has a per-process kernel stack, while the ARMProcess does not.
 *       The kernel stack should not be needed anymore, and can be removed to reduce overhead.
 */
class IntelProcess : public Process
{
  private:

    /** Size of the kernel stack */
    static const Size KernelStackSize = PAGESIZE;

  public:

    /**
     * Constructor function.
     *
     * @param id Process Identifier.
     * @param entry Initial EIP register value.
     * @param privileged If true, the Process has unlimited access to hardware.
     * @param map Virtual memory layout.
     */
    IntelProcess(ProcessID id, Address entry, bool privileged, const MemoryMap &map);

    /**
     * Destructor function.
     */
    virtual ~IntelProcess();

    /**
     * Initialize the Process.
     *
     * Allocates various (architecture specific) resources,
     * creates MMU context and stacks.
     *
     * @return Result code
     */
    virtual Result initialize();

    /**
     * Restart execution at the given entry point.
     *
     * @param entry Address to begin execution.
     */
    virtual void reset(const Address entry);

    /**
     * Execute the process.
     *
     * Saves and restores registers, then perform a context switch.
     */
    virtual void execute(Process *previous);

  private:

    /** Current kernel stack address (changes during execution). */
    Address m_kernelStack;

    /** Base kernel stack (fixed) */
    Address m_kernelStackBase;

};

namespace Arch
{
    typedef IntelProcess Process;
};

/**
 * @}
 * @}
 */

#endif /* __INTEL_PROCESS_H */
