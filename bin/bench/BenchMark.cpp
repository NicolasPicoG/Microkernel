

#include <Nicoos/System.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include "BenchMark.h"

BenchMark::BenchMark(int argc, char **argv)
    : POSIXApplication(argc, argv)
{
    parser().setDescription("Perform system benchmark tests");
}

BenchMark::~BenchMark()
{
}

BenchMark::Result BenchMark::exec()
{
    u64 t1 = 0, t2 = 0;
    ProcessInfo info;
    Memory::Range range;
    char *foo[128];
    struct stat st;

    // Retrieve current process ID with kernel trap
    t1 = timestamp();
    ProcessCtl(SELF, GetPID);
    t2 = timestamp();
    printf("SystemCall (GetPID) Ticks: %u\r\n", t2 - t1);

    // Retrieve current process information
    t1 = timestamp();
    ProcessCtl(SELF, InfoPID, (Address) &info);
    t2 = timestamp();
    printf("SystemCall (InfoPID) Ticks: %u\r\n", t2 - t1);

    // Perform task schedule
    t1 = timestamp();
    ProcessCtl(SELF, Schedule);
    t2 = timestamp();
    printf("SystemCall (Schedule) Ticks: %u\r\n", t2 - t1);

    // Translate virtual memory address to physical memory address
    range.virt = 0x80000000;
    range.size = PAGESIZE;    
    t1 = timestamp();
    VMCtl(SELF, LookupVirtual, &range);
    t2 = timestamp();
    printf("SystemCall (VMCtl) Ticks: %u\r\n", t2 - t1);

    // Perform inter-process communication call
    t1 = timestamp();
    stat("/etc", &st);
    t2 = timestamp();
    printf("IPC (stat) Ticks: %u\r\n", t2 - t1);

    // Allocate heap memory
    t1 = timestamp();
    for (int i = 0; i < 128; i++)
        foo[i] = new char[16];
    t2 = timestamp();
    printf("allocate() Ticks: %u (%u AVG)\r\n",
            (u32)(t2 - t1), (u32)(t2 - t1) / 128);

    // Release heap memory
    t1 = timestamp();
    for (int i = 0; i < 128; i++)
        delete foo[i];
    t2 = timestamp();
    printf("release() Ticks: %u (%u AVG)\r\n",
            (u32)(t2 - t1), (u32)(t2 - t1) / 128);

    // Done
    return Success;
}
