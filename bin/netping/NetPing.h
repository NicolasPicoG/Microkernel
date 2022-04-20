

#ifndef __BIN_NETPING_H
#define __BIN_NETPING_H

#include <IPV4.h>
#include <Ethernet.h>
#include <POSIXApplication.h>

/**
 * @addtogroup bin
 * @{
 */

/**
 * Network ping/pong application.
 */
class NetPing : public POSIXApplication
{
  public:

    /**
     * Class constructor.
     */
    NetPing(int argc, char **argv);

    /**
     * Class destructor.
     */
    virtual ~NetPing();

    /**
     * Execute the application event loop.
     */
    virtual Result exec();

  private:

    /**
     * Send ARP ping/pong.
     */
    Result arpPing(const char *dev, const char *host);

    /**
     * Send ICMP ping/pong.
     */
    Result icmpPing(const char *dev, const char *host);
};

/**
 * @}
 */

#endif /* __BIN_NETPING_H */
