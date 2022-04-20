

#ifndef __BIN_NETSEND_NETSEND_H
#define __BIN_NETSEND_NETSEND_H

#include <NetworkClient.h>
#include <NetworkQueue.h>
#include <POSIXApplication.h>

/**
 * @addtogroup bin
 * @{
 */

/**
 * Diagnostic program for sending network packets
 */
class NetSend : public POSIXApplication
{
  private:

    /** Size of each packet to send in bytes */
    static const Size PacketSize = 1448;

    /** Number of packets to submit for transmission each iteration */
    static const Size QueueSize = NetworkQueue::MaxPackets;

  public:

    /**
     * Class constructor.
     *
     * @param argc Argument count
     * @param argv Argument values
     */
    NetSend(int argc,
            char **argv);

    /**
     * Class destructor.
     */
    virtual ~NetSend();

    /**
     * Initialize the application.
     *
     * @return Result code
     */
    virtual Result initialize();

    /**
     * Execute the application event loop.
     *
     * @return Result code
     */
    virtual Result exec();

  private:

    /**
     * Send multiple UDP packets
     *
     * @param vec I/O vector with multiple packets
     * @param count Number of entries in the I/O vector
     * @param addr The destination IP and port
     *
     * @return Result code
     */
    Result udpSendMultiple(const struct iovec *vec,
                           const Size count,
                           const struct sockaddr & addr) const;

  private:

    /** Network client */
    NetworkClient *m_client;

    /** UDP socket */
    int m_socket;
};

/**
 * @}
 */

#endif /* __BIN_NETSEND_NETSEND_H */
