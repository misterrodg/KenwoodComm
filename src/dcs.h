#ifndef DCS_H
#define DCS_H

#include "command.h"
#include "command_prefix.h"
#include "switch.h"
#include <string>

class Dcs
{
public:
    Dcs();
    bool SetDcs(std::string &status);
    std::string ToCommand(const bool &hasParam = false);

private:
    Switch::SwitchEnum enabled;
};

#endif