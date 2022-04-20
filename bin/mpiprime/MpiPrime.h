

#ifndef __BIN_MPIPRIME_MPIPRIME_H
#define __BIN_MPIPRIME_MPIPRIME_H

#include <POSIXApplication.h>
#include "SievePrime.h"

/**
 * @addtogroup bin
 * @{
 */

/**
 * Calculate prime numbers in parallel.
 */
class MpiPrime : public SievePrime
{
  private:

  public:

    /**
     * Constructor
     *
     * @param argc Argument count
     * @param argv Argument values
     */
    MpiPrime(int argc, char **argv);

    /**
     * Destructor
     */
    virtual ~MpiPrime();

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
     * Calculate prime numbers in parallel
     *
     * @param k Start number to search for primes
     * @param n Upper limit to search for primes
     * @param rootMap Pointer to the root primes array
     * @param map Pointer to results array
     *
     * @return Result code
     */
    Result searchParallel(int k, int n, u8 *rootMap, u8 *map);

    /**
     * Collect prime number results
     *
     * @param n Upper limit to search for primes
     * @param rootMap Pointer to the root primes array
     * @param map Pointer to results array
     *
     * @return Result code
     */
    Result collect(int n, u8 *rootMap, u8 *map);

  private:

    /** Result of MPI initialization */
    int m_mpiInitResult;

    /** MPI core identifier (rank) of the current process */
    int m_id;

    /** Total number of cores */
    Size m_cores;

    /** Prime numbers calculated per core */
    Size m_numbersPerCore;

    /** Prime numbers array range start for this core */
    Size m_numberStart;

    /** Prime numbers array range end for this core */
    Size m_numberEnd;
};

/**
 * @}
 */

#endif /* __BIN_MPIPRIME_MPIPRIME_H */
