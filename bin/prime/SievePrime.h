

#ifndef __BIN_PRIME_SIEVEPRIME_H
#define __BIN_PRIME_SIEVEPRIME_H

#include <POSIXApplication.h>

/**
 * @addtogroup bin
 * @{
 */

/**
 * Compute prime numbers using the Sieve of Eratosthenes algorithm
 */
class SievePrime : public POSIXApplication
{
  public:

    /**
     * Constructor
     *
     * @param argc Argument count
     * @param argv Argument values
     */
    SievePrime(int argc, char **argv);

    /**
     * Destructor
     */
    virtual ~SievePrime();

    /**
     * Execute the application.
     *
     * @return Result code
     */
    virtual Result exec();

  protected:

    /**
     * Report the calculated results
     *
     * @param n Maximum number to search for prime numbers
     * @param map Pointer to array with prime numbers
     * @param resultsWritten Number of results written to the output
     * @param offsetNumber Add this constant offset value to each result
     *
     * @return Result code
     */
    Result reportResult(const int n,
                        const u8 *map,
                        Size & resultsWritten,
                        const Size offsetNumber = 0) const;

    /**
     * Perform sequential search for prime numbers
     *
     * @param n Maximum number to search for prime numbers
     * @param map Pointer to array with prime numbers marked
     */
    Result searchSequential(const int n,
                            u8 *map) const;
};

/**
 * @}
 */

#endif /* __BIN_PRIME_SIEVEPRIME_H */
