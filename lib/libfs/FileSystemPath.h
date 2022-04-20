

#ifndef __LIB_LIBFS_FILESYSTEMPATH_H
#define __LIB_LIBFS_FILESYSTEMPATH_H

#include <List.h>
#include <ListIterator.h>
#include <Types.h>
#include <String.h>

/**
 * @addtogroup lib
 * @{
 *
 * @addtogroup libfs
 * @{
 */

/**
 * Simple filesystem path parser.
 */
class FileSystemPath
{
  private:

    /** The default path separator character */
    static const char DefaultSeparator = '/';

  public:

    /** Maximum length of a filesystem path in bytes */
    static const Size MaximumLength = 64u;

  public:

    /**
     * Constructor using char pointer.
     *
     * @param path The input path to parse.
     * @param separator Pathname separator.
     */
    FileSystemPath(const char *path,
                   const char separator = DefaultSeparator);

    /**
     * Retrieve the full path of our parent.
     *
     * @return Path of our parent.
     */
    const String & parent() const;

    /**
     * The name of the last element in the path.
     *
     * @return Name of the base.
     */
    const String & base() const;

    /**
     * Get the full path as a String
     *
     * @return String instance.
     */
    const String & full() const;

    /**
     * Returns a List of separate path elements.
     *
     * @return Pointer to a List.
     */
    const List<String> & split() const;

    /**
     * Get Length of our full path.
     *
     * @return Length.
     */
    Size length() const;

  private:

    /** Separator character. */
    const char m_separator;

    /** Full input path. */
    const String m_full;

    /** The path split in pieces by the separator. */
    const List<String> m_path;

    /** Last element in the full path. */
    const String m_base;

    /** Full path to our parent. */
    String m_parent;
};

/**
 * @}
 * @}
 */

#endif /* __LIB_LIBFS_FILESYSTEMPATH_H */
