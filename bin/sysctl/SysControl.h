

#ifndef __BIN_SYSCTL_SYSCONTROL_H
#define __BIN_SYSCTL_SYSCONTROL_H

#include <Types.h>
#include <POSIXApplication.h>

/**
 * @addtogroup bin
 * @{
 */

/**
 * Control program for various system services.
 */
class SysControl : public POSIXApplication
{
  public:

    /**
     * Constructor
     *
     * @param argc Argument count
     * @param argv Argument values
     */
    SysControl(int argc, char **argv);

    /**
     * Destructor
     */
    virtual ~SysControl();

    /**
     * Execute the application.
     *
     * @return Result code
     */
    virtual Result exec();

  private:

    /**
     * Stop the given process by its ID.
     *
     * @param pid Process ID
     *
     * @return Result code
     */
    Result stopProcess(const ProcessID pid) const;

    /**
     * Resume the given process by its ID.
     *
     * @param pid Process ID
     *
     * @return Result code
     */
    Result resumeProcess(const ProcessID pid) const;

    /**
     * Restart the given process by its ID.
     *
     * @param pid Process ID
     *
     * @return Result code
     */
    Result restartProcess(const ProcessID pid) const;
};

/**
 * @}
 */

#endif /* __BIN_SYSCTL_SYSCONTROL_H */
