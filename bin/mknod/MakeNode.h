

#ifndef __BIN_MKNOD_MAKENODE_H
#define __BIN_MKNOD_MAKENODE_H

#include <POSIXApplication.h>

/**
 * @addtogroup bin
 * @{
 */

/**
 * Create new device file node.
 */
class MakeNode : public POSIXApplication
{
  public:

    /**
     * Constructor
     *
     * @param argc Argument count
     * @param argv Argument values
     */
    MakeNode(int argc, char **argv);

    /**
     * Destructor
     */
    virtual ~MakeNode();

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

#endif /* __BIN_MKNOD_MAKENODE_H */
