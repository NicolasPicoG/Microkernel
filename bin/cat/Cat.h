

#ifndef __BIN_CAT_CAT_H
#define __BIN_CAT_CAT_H

#include <POSIXApplication.h>

/**
 * @addtogroup bin
 * @{
 */

/**
 * Concatenate files to standard output.
 */
class Cat : public POSIXApplication
{
  public:

    /**
     * Constructor
     *
     * @param argc Argument count
     * @param argv Argument values
     */
    Cat(int argc, char **argv);

    /**
     * Destructor
     */
    virtual ~Cat();

    /**
     * Initialize the application.
     *
     * @return Result code
     */
    virtual Result initialize();

    /**
     * Execute the application.
     *
     * @return Result code
     */
    virtual Result exec();

  private:

    /**
     * Concatenate a file
     *
     * @param file Name of file to concatenate
     *
     * @return Result code
     */
    Result cat(const char *file) const;
};

/**
 * @}
 */

#endif /* __BIN_CAT_CAT_H */
