#ifndef DN_UP_H
#define DN_UP_H

#include "command.h"
#include "command_prefix.h"
#include <string>

class DnUp
{
public:
    DnUp(const CommandPrefix::CommandPrefixEnum &downUp);
    std::string ToCommand();

private:
    CommandPrefix::CommandPrefixEnum downUp;
};

#endif