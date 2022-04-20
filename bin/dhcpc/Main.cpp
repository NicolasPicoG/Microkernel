

#include <Log.h>
#include "DhcpClient.h"

int main(int argc, char **argv)
{
    DhcpClient app(argc, argv);
    return app.run();
}
