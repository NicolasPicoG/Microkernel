
#ifndef __BIN_SYSINFO_SYSINFO_H
#define __BIN_SYSINFO_SYSINFO_H

#include <POSIXApplication.h>

/**
 * @addtogroup bin
 * @{
 */

/**
 * Print global system information.
 *
 * @bug Running 'sysinfo' and 'ps' commands in turn on arm/sunxi-h3 shows a 4KiB memory leak
 */
class SysInfo : public POSIXApplication
{
  public:

    /**
     * Constructor
     *
     * @param argc Argument count
     * @param argv Argument values
     */
    SysInfo(int argc, char **argv);

    /**
     * Destructor
     */
    virtual ~SysInfo();

    /**
     * Execute the application.
     *
     * @return Result code
     */
    virtual Result exec();
};

/**
 * @}
 */

#endif /* __BIN_SYSINFO_SYSINFO_H */
