

#include <Nicoos/System.h>

int main(int argc, char **argv)
{
    PrivExec(Idle);
    ProcessCtl(SELF, Schedule);

    while (true)
    {
        idle();
    }
}
