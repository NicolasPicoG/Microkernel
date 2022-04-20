
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Echo.h"

Echo::Echo(int argc, char **argv)
    : POSIXApplication(argc, argv)
{
    parser().setDescription("Echo standard input to output");
    parser().registerPositional("STRING", "text string to echo", 0);
    parser().registerFlag('n', "no-newline", "If set, do not print new line character");
}

Echo::~Echo()
{
}

Echo::Result Echo::exec()
{
    const Vector<Argument *> & positionals = arguments().getPositionals();
    const char *no_newline = arguments().get("no-newline");
    
    // Loop positional arguments
    for (Size i = 0; i < positionals.count(); i++)
        printf("%s ", *(positionals[i]->getValue()));

    // Print newline
    if (no_newline == NULL)
        printf("\n");

    return Success;
}
