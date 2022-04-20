

#ifndef __BIN_LS_LS_H
#define __BIN_LS_LS_H

#include <POSIXApplication.h>

/**
 * @addtogroup bin
 * @{
 */

/**
 * List files on the filesystem.
 */
class ListFiles : public POSIXApplication
{
  public:

    /**
     * Constructor
     *
     * @param argc Argument count
     * @param argv Argument values
     */
    ListFiles(int argc, char **argv);

    /**
     * Destructor
     */
    virtual ~ListFiles();

    /**
     * Execute the application.
     *
     * @return Result code
     */
    virtual Result exec();

  private:

    /**
     * List files on the filesystem
     *
     * @param path Path to the file(s) to list
     *
     * @return Result code
     */
    Result printFiles(const String & path) const;

    /**
     * List single file on the filesystem
     *
     * @param path Path to the file to list
     * @param out String to write the output to
     *
     * @return Result code
     */
    Result printSingleFile(const String & path, String & out) const;
};

/**
 * @}
 */

#endif /* __BIN_LS_LS_H */
