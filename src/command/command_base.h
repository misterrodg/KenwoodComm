#ifndef COMMAND_BASE_H
#define COMMAND_BASE_H

#include "command_prefix.h"
#include "command_result.h"
#include "core/result.h"
#include "core/serial_command.h"
#include <string>

class CommandBase {
protected:
    CommandPrefix::CommandPrefixEnum commandPrefix;

public:
    enum class ParamPolicy { Forbidden, Optional, Required };

    virtual ~CommandBase() = default;
    CommandBase(CommandPrefix::CommandPrefixEnum prefix)
        : commandPrefix(prefix) {
    }

    virtual bool supportsSet() const;
    virtual bool supportsRead() const;
    virtual bool supportsAnswer() const;

    virtual ParamPolicy setParamPolicy() const;
    virtual ParamPolicy readParamPolicy() const;

    virtual CommandResult set(const std::string& param);
    virtual core::Result<std::string> buildSetCommand();
    virtual core::Result<std::string> buildReadCommand();
    virtual core::Result<std::string>
    buildReadCommand(const std::string& param);
    virtual CommandResult parseAnswer(const std::string& payload);
    virtual std::string getDisplayValue() const;

    std::string ToCommand();
};

#endif