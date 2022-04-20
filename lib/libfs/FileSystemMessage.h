

#ifndef __FILESYSTEM_FILE_SYSTEM_MESSAGE_H
#define __FILESYSTEM_FILE_SYSTEM_MESSAGE_H

#include <Types.h>
#include <Timer.h>
#include "ChannelMessage.h"
#include "FileSystem.h"

/**
 * @addtogroup lib
 * @{
 *
 * @addtogroup libfs
 * @{
 */

/**
 * FileSystem IPC message.
 */
typedef struct FileSystemMessage : public ChannelMessage
{
    FileSystem::Action action;     /**< Action to perform. */
    FileSystem::Result result;     /**< Result code. */
    char *buffer;                  /**< Points to a buffer for I/O. */
    Size size;                     /**< Size of the buffer. */
    Size offset;                   /**< Offset in the file for I/O. */
    u32 inode;                     /**< Inode number of the file */
    FileSystem::FileStat *stat;    /**< File Statistics. */
    Timer::Info timeout;           /**< Timeout value for the action */
    ProcessID pid;                 /**< Process identifier (used for redirection) */
    Size pathMountLength;          /**< Length of the mounted path (used for redirection) */
}
FileSystemMessage;

/**
 * @}
 * @}
 */

#endif /* __FILESYSTEM_FILE_SYSTEM_MESSAGE_H */
