#ifndef AUTO_INFORMATION_H
#define AUTO_INFORMATION_H

#include "command.h"
#include "command_prefix.h"
#include "switch.h"
#include <string>

class AutoInformation
{
public:
    AutoInformation();
    bool SetAutoInformation(std::string &status);
    std::string ToCommand();

private:
    Switch::SwitchEnum enabled;
};

#endif