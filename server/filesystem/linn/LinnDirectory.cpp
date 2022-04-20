

#include <Nicoos/User.h>
#include <Assert.h>
#include <MemoryBlock.h>
#include <String.h>
#include "LinnDirectory.h"
#include "LinnFile.h"

LinnDirectory::LinnDirectory(LinnFileSystem *fs,
                             const u32 inode,
                             LinnInode *inodeData)
    : Directory(inode)
    , m_fs(fs)
    , m_inodeData(inodeData)
{
    m_size   = m_inodeData->size;
    m_access = m_inodeData->mode;
}

FileSystem::Result LinnDirectory::read(IOBuffer & buffer,
                                       Size & size,
                                       const Size offset)
{
    LinnSuperBlock *sb = m_fs->getSuperBlock();
    LinnDirectoryEntry dent;
    LinnInode *dInode;
    Size bytes = ZERO, blk;
    Dirent tmp;

    // Read directory entries
    for (u32 ent = 0; ent < m_inodeData->size / sizeof(LinnDirectoryEntry); ent++)
    {
        // Point to correct (direct) block
        if ((blk = (ent * sizeof(LinnDirectoryEntry)) / sb->blockSize)
             >= LINN_INODE_DIR_BLOCKS)
        {
            break;
        }

        // Calculate offset to read.
        u64 off = (m_inodeData->block[blk] * sb->blockSize) +
                      (ent * sizeof(LinnDirectoryEntry));

        // Get the next entry.
        if (m_fs->getStorage()->read(off, &dent,
                                   sizeof(LinnDirectoryEntry)) != FileSystem::Success)
        {
            return FileSystem::PermissionDenied;
        }

        // Can we read another entry?
        if (bytes + sizeof(Dirent) > size)
        {
            return FileSystem::InvalidArgument;
        }

        // Fill in the Dirent.
        if (!(dInode = m_fs->getInode(dent.inode)))
        {
            return FileSystem::NotFound;
        }
        MemoryBlock::copy(tmp.name, dent.name, LINN_DIRENT_NAME_LEN);
        tmp.type = (FileSystem::FileType) dInode->type;

        // Copy to the buffer.
        const FileSystem::Result result = buffer.write(&tmp, sizeof(Dirent), bytes);
        if (result != FileSystem::Success)
        {
            return result;
        }

        bytes += sizeof(Dirent);
    }

    // All done.
    size = bytes;
    return FileSystem::Success;
}

File * LinnDirectory::lookup(const char *name)
{
    LinnDirectoryEntry entry;
    LinnInode *inode;

    // Try to find the given LinnDirectoryEntry.
    if (!getLinnDirectoryEntry(&entry, name))
        return ZERO;

    // Then retrieve it's LinnInode.
    if (!(inode = m_fs->getInode(entry.inode)))
        return ZERO;

    // Create the appropriate in-memory file.
    switch ((FileSystem::FileType) inode->type)
    {
        case FileSystem::DirectoryFile: {
            LinnDirectory *dir = new LinnDirectory(m_fs, entry.inode, inode);
            assert(dir != NULL);
            return dir;
        }

        case FileSystem::RegularFile: {
            LinnFile *file = new LinnFile(m_fs, entry.inode, inode);
            assert(file != NULL);
            return file;
        }

        default:
            return ZERO;
    }
}

bool LinnDirectory::getLinnDirectoryEntry(LinnDirectoryEntry *dent,
                                          const char *name)
{
    const String nameStr(name, false);
    LinnSuperBlock *sb = m_fs->getSuperBlock();
    u64 offset;

    // Loop all blocks.
    for (u32 blk = 0; blk < LINN_INODE_NUM_BLOCKS(sb, m_inodeData); blk++)
    {
        // Read directory entries.
        for (u32 ent = 0; ent < LINN_DIRENT_PER_BLOCK(sb); ent++)
        {
            // Calculate offset to read.
            offset = (m_inodeData->block[blk] * sb->blockSize) +
                     (sizeof(LinnDirectoryEntry) * ent);

            // Get the next entry.
            if (m_fs->getStorage()->read(offset, dent,
                                         sizeof(LinnDirectoryEntry)) != FileSystem::Success)
            {
                return false;
            }

            // Is it the entry we are looking for?
            if (nameStr.equals(dent->name))
            {
                return true;
            }
        }
    }

    // Not found.
    return false;
}
