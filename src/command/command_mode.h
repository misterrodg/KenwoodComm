#ifndef COMMAND_MODE_H
#define COMMAND_MODE_H

#include "command_result.h"
#include "../parameter/mode.h"
#include "../parameter/model_number.h"
#include "command_base.h"

class CommandMode : public CommandBase {
protected:
    Mode::ModeEnum mode = Mode::ModeEnum::LSB;
    bool allowedForModelNumber(const ModelNumber& modelNumber,
                               Mode::ModeEnum& modeEnum);

public:
    CommandMode(CommandPrefix::CommandPrefixEnum prefix)
        : CommandBase(prefix) {};
    std::string ToCommand();
    CommandResult SetMode(const ModelNumber& modelNumber,
                          const std::string& modeString);
};

#endif
