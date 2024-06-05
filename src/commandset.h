#ifndef COMMANDSET_H
#define COMMANDSET_H

#include <string>
#include <vector>
#include "command.h"
#include "helpers.h"
#include "radios.h"

class Commandset
{
private:
    std::vector<Command::CommandEnum> availableCommands;

public:
    Commandset(Radios radioType = Radios::UNRECOGNIZED);
    std::vector<Command::CommandEnum> getAvailableCommands();
    void printAvailableCommands();
    bool verifyCommand(std::string command);
};

#endif
