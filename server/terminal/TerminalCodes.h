

#ifndef __TERMINAL_CODES_H
#define __TERMINAL_CODES_H

/**
 * @addtogroup server
 * @{
 *
 * @addtogroup terminal
 * @{
 */

/** Set Graphic Rendition. */
#define _SGR(x) "\033[" #x "m"

/**
 * @name Terminal Colors
 * @see http://en.wikipedia.org/wiki/ANSI_escape_code
 * @{
 */

#define BLACK   _SGR(30)
#define RED     _SGR(31)
#define GREEN   _SGR(32)
#define YELLOW  _SGR(33)
#define BLUE    _SGR(34)
#define MAGENTA _SGR(35)
#define CYAN    _SGR(36)
#define WHITE   _SGR(37)
#define RESET   _SGR(39)

/**
 * @}
 */

/**
 * @}
 * @}
 */

#endif /* __TERMINAL_CODES_H */
