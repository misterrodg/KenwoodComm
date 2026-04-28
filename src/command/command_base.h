#ifndef COMMAND_BASE_H
#define COMMAND_BASE_H

#include "command_result.h"
#include "core/result.h"
#include "core/serial_command.h"
#include "command_prefix.h"
#include <string>

class CommandBase
{
protected:
    CommandPrefix::CommandPrefixEnum commandPrefix;

public:
    virtual ~CommandBase() = default;
    CommandBase(CommandPrefix::CommandPrefixEnum prefix) : commandPrefix(prefix) {}

    virtual bool supportsSet() const;
    virtual bool supportsRead() const;
    virtual bool supportsAnswer() const;

    virtual CommandResult set(const std::string& param);
    virtual core::Result<std::string> buildSetCommand();
    virtual core::Result<std::string> buildReadCommand();
    virtual CommandResult parseAnswer(const std::string& payload);
    virtual std::string getDisplayValue() const;

    std::string ToCommand();
};

#endif