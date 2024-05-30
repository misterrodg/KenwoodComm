#ifndef COMMANDSET_H
#define COMMANDSET_H

#include <string>
#include <vector>
#include "commands.h"
#include "radios.h"

class Commandset
{
private:
    std::vector<Commands> availableCommands;

public:
    Commandset(Radios radioType);
    std::vector<Commands> getAvailableCommands();
};

#endif
