
#ifndef __BIN_MPIPING_MPIPING_H
#define __BIN_MPIPING_MPIPING_H

#include <POSIXApplication.h>

/**
 * @addtogroup bin
 * @{
 */

/**
 * Send a ping message via MPI to all available nodes.
 */
class MpiPing : public POSIXApplication
{
  private:

    /** Magic number to send as ping message */
    static const int PingMagicNumber = 0xaabbccdd;

    /** Magic number send for the pong message */
    static const int PongMagicNumber = 0x12345678;

  public:

    /**
     * Constructor
     *
     * @param argc Argument count
     * @param argv Argument values
     */
    MpiPing(int argc, char **argv);

    /**
     * Destructor
     */
    virtual ~MpiPing();

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
     * Send a message containing a number
     *
     * @param coreId Core identifier to send the message to
     * @param number Number value to send
     *
     * @return Result code
     */
    Result sendNumber(const Size coreId,
                      const int number) const;

    /**
     * Receive a message containing a number
     *
     * @param coreId Core identifier to receive the message from
     * @param expectedNumber The expected number value to receive
     *
     * @return Result code
     */
    Result receiveNumber(const Size coreId,
                         const int expectedNumber) const;

  private:

    /** Result of MPI initialization */
    int m_mpiInitResult;

    /** MPI core identifier (rank) of the current process */
    int m_id;
};

/**
 * @}
 */

#endif /* __BIN_MPIPING_MPIPING_H */
