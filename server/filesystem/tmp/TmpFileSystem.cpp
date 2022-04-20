

#include <Assert.h>
#include <File.h>
#include <PseudoFile.h>
#include <Directory.h>
#include "TmpFileSystem.h"

TmpFileSystem::TmpFileSystem(const char *path)
    : FileSystemServer(new Directory(1), path)
{
}

File * TmpFileSystem::createFile(const FileSystem::FileType type)
{
    // Create the appropriate file type
    switch (type)
    {
        case FileSystem::RegularFile: {
            PseudoFile *file = new PseudoFile(getNextInode());
            assert(file != NULL);
            return file;
        }

        case FileSystem::DirectoryFile: {
            Directory *dir = new Directory(getNextInode());
            assert(dir != NULL);
            return dir;
        }

        default:
            return ZERO;
    }
}
