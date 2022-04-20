
#ifndef __BIN_LOGIN_LOGIN_H
#define __BIN_LOGIN_LOGIN_H

#include <POSIXApplication.h>

/**
 * @addtogroup bin
 * @{
 */

/**
 * Login program which starts the user shell.
 */
class Login : public POSIXApplication
{
  public:

    /**
     * Constructor
     *
     * @param argc Argument count
     * @param argv Argument values
     */
    Login(int argc, char **argv);

    /**
     * Destructor
     */
    virtual ~Login();

    /**
     * Execute the application.
     *
     * @return Result code
     */
    virtual Result exec();

  private:

    /**
     * Read username from standard input
     *
     * @return Username of the user.
     */
    const char * getUsername() const;

    /**
     * Print the login program prompt
     */
    void printPrompt() const;
};

/**
 * @}
 */

#endif /* __BIN_LOGIN_LOGIN_H */
