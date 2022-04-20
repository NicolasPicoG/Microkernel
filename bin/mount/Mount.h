
#ifndef __BIN_MOUNT_MOUNT_H
#define __BIN_MOUNT_MOUNT_H

#include <POSIXApplication.h>

/**
 * @addtogroup bin
 * @{
 */

/**
 * Mount filesystems on the system.
 */
class Mount : public POSIXApplication
{
  public:

    /**
     * Constructor
     *
     * @param argc Argument count
     * @param argv Argument values
     */
    Mount(int argc, char **argv);

    /**
     * Destructor
     */
    virtual ~Mount();

    /**
     * Execute the application.
     *
     * @return Result code
     */
    virtual Result exec();

  private:

    /**
     * Print currently mounted file systems.
     */
    void listMounts() const;

    /**
     * Blocking wait until the given path is mounted.
     *
     * @param path Absolute path to a file system mount point
     */
    void waitForMount(const char *path) const;
};

/**
 * @}
 */

#endif /* __BIN_MOUNT_MOUNT_H */
