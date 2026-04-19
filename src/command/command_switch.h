#ifndef COMMAND_SWITCH_H
#define COMMAND_SWITCH_H

#include "../command_result.h"
#include "../parameter/switch.h"
#include "command_base.h"

class CommandSwitch : public CommandBase {
protected:
    Switch::SwitchEnum enabled = Switch::SwitchEnum::OFF;

public:
    CommandSwitch(CommandPrefix::CommandPrefixEnum prefix)
        : CommandBase(prefix) {};
    std::string ToCommand(bool readStatus = false);
    CommandResult SetSwitch(const std::string& status);
};

#endif
