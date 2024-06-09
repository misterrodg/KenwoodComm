#ifndef LK_H
#define LK_H

#include "command.h"
#include "command_prefix.h"
#include "switch.h"
#include <string>

class Lk
{
public:
    Lk();
    bool SetLk(std::string &status);
    std::string ToCommand(const bool &hasParam = false);

private:
    Switch::SwitchEnum enabled;
};

#endif