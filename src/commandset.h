#ifndef COMMANDSET_H
#define COMMANDSET_H

#include <string>
#include <vector>
#include "command/command_prefix.h"
#include "helpers.h"
#include "radios.h"

class Commandset
{
private:
    std::vector<CommandPrefix::CommandPrefixEnum> availableCommands;

public:
    Commandset(Radios radioType = Radios::UNRECOGNIZED);
    std::vector<CommandPrefix::CommandPrefixEnum> getAvailableCommands();
    void printAvailableCommands(bool expand = false);
    bool verifyCommand(std::string command);
};

#endif
