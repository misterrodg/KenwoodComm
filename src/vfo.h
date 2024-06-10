#ifndef VFO_H
#define VFO_H

#include "command.h"
#include "command/command_prefix.h"
#include "frequency.h"
#include <string>

class VFO
{
public:
    VFO();
    bool SetId(const CommandPrefix::CommandPrefixEnum &vfoIdEnum);
    bool SetFrequency(std::string &parameter);
    std::string ToCommand(const bool &hasParam = false);

private:
    CommandPrefix::CommandPrefixEnum vfoId;
    Frequency frequency;
};

#endif