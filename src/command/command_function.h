#ifndef COMMAND_FUNCTION_H
#define COMMAND_FUNCTION_H

#include "command_base.h"
#include "command_result.h"
#include "core/radio.h"
#include "parameter/function.h"

class CommandFunction : public CommandBase {
protected:
    Function::FunctionEnum function = Function::FunctionEnum::VFOA;
    Radios radioModel = Radios::UNRECOGNIZED;
    bool allowedForModelNumber(Radios radioModel,
                               Function::FunctionEnum& functionEnum);

public:
    CommandFunction(CommandPrefix::CommandPrefixEnum prefix)
        : CommandBase(prefix) {};

    void setModelNumber(Radios modelNumber);
    CommandResult set(const std::string& functionString) override;
    core::Result<std::string> buildSetCommand() override;

    std::string ToCommand();
    CommandResult SetFunction(Radios modelNumber,
                              const std::string& functionString);
};

#endif
