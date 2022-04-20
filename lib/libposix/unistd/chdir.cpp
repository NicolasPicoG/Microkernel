

#include <FileSystemClient.h>
#include <FileSystemPath.h>
#include <String.h>
#include <List.h>
#include "limits.h"
#include "string.h"
#include "sys/stat.h"
#include "unistd.h"

int chdir(const char *filepath)
{
    String last;
    List<String> lst;
    char cwd[PATH_MAX], buf[PATH_MAX], *path = ZERO;
    FileSystemClient filesystem;

    struct stat st;

    // What's the current working dir?
    getcwd(cwd, PATH_MAX);

    // Relative or absolute?
    if (filepath[0] != '/')
    {
        snprintf(buf, sizeof(buf), "%s/%s", cwd, filepath);
        FileSystemPath fspath(buf);

        // Process '..'
        for (ListIterator<String> i(fspath.split()); i.hasCurrent(); i++)
        {
            if ((*i.current())[0] != '.')
            {
                lst.append(i.current());
                last = i.current();
            }
            else if ((*i.current())[1] == '.' && last.length() > 0)
            {
                lst.remove(last);
            }
        }

        memset(buf, 0, sizeof(buf));

        // Construct final path
        for (ListIterator<String> i(&lst); i.hasCurrent(); i++)
        {
            strcat(buf, "/");
            strcat(buf, *i.current());
        }
        path = buf;
    }
    else
        path = (char *) filepath;

    // Fall back to slash?
    if (!path[0])
    {
        strcpy(buf, "/");
        path = buf;
    }

    // Stat the file
    if (stat(path, &st) != 0)
    {
        return -1;
    }

    // Must be a directory
    if (!S_ISDIR(st.st_mode))
    {
        errno = ENOTDIR;
        return -1;
    }

    // Set current directory
    filesystem.setCurrentDirectory(path);

    // Done
    errno = ZERO;
    return 0;
}
