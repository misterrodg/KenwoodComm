#ifndef COMMAND_FUNCTION_H
#define COMMAND_FUNCTION_H

#include "../command_result.h"
#include "../parameter/function.h"
#include "../parameter/model_number.h"
#include "command_base.h"

class CommandFunction : public CommandBase {
protected:
    Function::FunctionEnum function = Function::FunctionEnum::VFOA;
    bool allowedForModelNumber(ModelNumber& modelNumber,
                               Function::FunctionEnum& functionEnum);

public:
    CommandFunction(CommandPrefix::CommandPrefixEnum prefix)
        : CommandBase(prefix) {};
    std::string ToCommand();
    CommandResult SetFunction(ModelNumber& modelNumber,
                              const std::string& functionString);
};

#endif
