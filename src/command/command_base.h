#ifndef COMMAND_BASE_H
#define COMMAND_BASE_H

#include "../command.h"
#include "command_prefix.h"
#include <string>

class CommandBase
{
protected:
    CommandPrefix::CommandPrefixEnum commandPrefix;

public:
    CommandBase(CommandPrefix::CommandPrefixEnum prefix) : commandPrefix(prefix) {}
    std::string ToCommand();
};

#endif