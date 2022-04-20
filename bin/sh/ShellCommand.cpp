

#include "ShellCommand.h"

ShellCommand::ShellCommand(const char *name, const Size params)
    : m_name(name)
    , m_help("")
    , m_minParams(params)
{
}

ShellCommand::~ShellCommand()
{
}

const char * ShellCommand::getName() const
{
    return m_name;
}

const char * ShellCommand::getHelp() const
{
    return m_help;
}

Size ShellCommand::getMinimumParams() const
{
    return m_minParams;
}
