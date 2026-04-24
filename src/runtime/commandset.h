#ifndef COMMANDSET_H
#define COMMANDSET_H

#include "command/command_prefix.h"
#include "core/helpers.h"
#include "core/radio.h"
#include <string>
#include <vector>

class Commandset {
private:
    std::vector<CommandPrefix::CommandPrefixEnum> availableCommands;

public:
    Commandset(Radios radioType = Radios::UNRECOGNIZED);
    std::vector<CommandPrefix::CommandPrefixEnum> getAvailableCommands() const;
    void printAvailableCommands(bool expand = false) const;
    bool verifyCommand(std::string command) const;
};

#endif
