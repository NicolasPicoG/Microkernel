

#ifndef __LIBSTD_FACTORY_H
#define __LIBSTD_FACTORY_H

/**
 * @addtogroup lib
 * @{
 *
 * @addtogroup libstd
 * @{
 */

/**
 * Factory design pattern providing a standard creation function.
 */
template <class T> class Factory
{
  public:

    /**
     * Create an instance of T.
     *
     * @return Pointer to T.
     */
    static T * create()
    {
        return new T();
    }
};

/**
 * Abstract Factory pattern providing a creation function declaration.
 */
template <class T> class AbstractFactory
{
  public:

    /**
     * Abstract function to create an instance of T.
     *
     * @return Pointer to T.
     */
    static T * create();
};

/**
 * @}
 * @}
 */

#endif /* __LIBSTD_FACTORY_H */
