#ifndef COMMAND_MODE_H
#define COMMAND_MODE_H

#include "command_base.h"
#include "command_result.h"
#include "parameter/mode.h"
#include "parameter/model_number.h"

class CommandMode : public CommandBase {
protected:
    ModelNumber modelNumber;
    Mode::ModeEnum mode = Mode::ModeEnum::LSB;
    bool allowedForModelNumber(Mode::ModeEnum& modeEnum);

public:
    CommandMode(CommandPrefix::CommandPrefixEnum prefix)
        : CommandBase(prefix) {};

    void setModelNumber(const ModelNumber& modelNumberValue);
    CommandResult set(const std::string& modeString) override;
    core::Result<std::string> buildSetCommand() override;

    std::string ToCommand();
    CommandResult SetMode(const std::string& modeString);
};

#endif
