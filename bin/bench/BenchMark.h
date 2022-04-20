
#ifndef __BIN_BENCH_BENCHMARK_H
#define __BIN_BENCH_BENCHMARK_H

#include <POSIXApplication.h>

/**
 * @addtogroup bin
 * @{
 */

/**
 * Perform system benchmarking tests.
 */
class BenchMark : public POSIXApplication
{
  public:

    /**
     * Constructor
     *
     * @param argc Argument count
     * @param argv Argument values
     */
    BenchMark(int argc, char **argv);

    /**
     * Destructor
     */
    virtual ~BenchMark();

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

#endif /* __BIN_BENCH_BENCHMARK_H */
