#ifndef COMMAND_SWITCH_H
#define COMMAND_SWITCH_H

#include "command_base.h"
#include "command_result.h"
#include "parameter/switch.h"

class CommandSwitch : public CommandBase {
protected:
    Switch::SwitchEnum enabled = Switch::SwitchEnum::OFF;

public:
    CommandSwitch(CommandPrefix::CommandPrefixEnum prefix)
        : CommandBase(prefix) {};

    CommandResult set(const std::string& status) override;
    CommandResult parseAnswer(const std::string& payload) override;
    core::Result<std::string> buildSetCommand() override;
    core::Result<std::string> buildReadCommand() override;
    std::string getDisplayValue() const override;

    std::string ToCommand(bool readStatus = false);
    CommandResult SetSwitch(const std::string& status);
};

#endif
