#ifndef COMMAND_BUSY_H
#define COMMAND_BUSY_H

#include "command_base.h"
#include "command_result.h"
#include "parameter/busy.h"

class CommandBusy : public CommandBase {
protected:
    Busy::BusyEnum enabled = Busy::BusyEnum::OFF;

public:
    CommandBusy(CommandPrefix::CommandPrefixEnum prefix)
        : CommandBase(prefix) {};

    CommandResult set(const std::string& status) override;
    core::Result<std::string> buildSetCommand() override;
    core::Result<std::string> buildReadCommand() override;

    std::string ToCommand(bool readStatus = false);
    CommandResult SetBusy(const std::string& status);
};

#endif
