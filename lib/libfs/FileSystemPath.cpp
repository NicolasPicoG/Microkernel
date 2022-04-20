

#include <String.h>
#include <MemoryBlock.h>
#include "FileSystemPath.h"

FileSystemPath::FileSystemPath(const char *path, const char separator)
    : m_separator(separator)
    , m_full(path)
    , m_path(m_full.split(m_separator))
    , m_base(m_path.count() > 0 ? m_path.last() : "")
    , m_parent()
{
    // Create parent, if any
    if (m_path.head() && m_path.head()->next)
    {
        const char tmp[] = { m_separator, ZERO };
        m_parent << tmp;

        // Construct parent path
        for (const List<String>::Node *l = m_path.head(); l && l->next; l = l->next)
        {
            m_parent << *l->data;

            if (l->next && l->next->next)
            {
                m_parent << tmp;
            }
        }
    }
}

const String & FileSystemPath::parent() const
{
    return m_parent;
}

const String & FileSystemPath::base() const
{
    return m_base;
}

const String & FileSystemPath::full() const
{
    return m_full;
}

const List<String> & FileSystemPath::split() const
{
    return m_path;
}

Size FileSystemPath::length() const
{
    return m_full.length();
}
