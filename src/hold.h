#ifndef HOLD_H
#define HOLD_H

#include "command.h"
#include "command_prefix.h"
#include "switch.h"
#include <string>

class Hold
{
public:
    Hold();
    bool SetHold(std::string &status);
    std::string ToCommand(const bool &hasParam = false);

private:
    Switch::SwitchEnum enabled;
};

#endif
