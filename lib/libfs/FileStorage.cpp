

#include "FileDescriptor.h"
#include "FileStorage.h"

FileStorage::FileStorage(const char *path, const Size offset)
    : m_path(path)
    , m_fd(0)
    , m_offset(offset)
{
}

FileSystem::Result FileStorage::initialize()
{
    const FileSystem::Result statResult = m_file.statFile(m_path, &m_stat);
    if (statResult != FileSystem::Success)
    {
        return statResult;
    }

    return m_file.openFile(m_path, m_fd);
}

FileSystem::Result FileStorage::read(const u64 offset, void *buffer, const Size size) const
{
    Size sz = size;

    FileDescriptor::Entry *fd = FileDescriptor::instance()->getEntry(m_fd);
    if (!fd || !fd->open)
    {
        return FileSystem::IOError;
    }

    // Update the file position pointer
    fd->position = m_offset + offset;

    return m_file.readFile(m_fd, buffer, &sz);
}

FileSystem::Result FileStorage::write(const u64 offset, void *buffer, const Size size)
{
    Size sz = size;

    FileDescriptor::Entry *fd = FileDescriptor::instance()->getEntry(m_fd);
    if (!fd || !fd->open)
    {
        return FileSystem::IOError;
    }

    // Update the file position pointer
    fd->position = m_offset + offset;

    return m_file.writeFile(m_fd, buffer, &sz);
}

u64 FileStorage::capacity() const
{
    return m_stat.size;
}
