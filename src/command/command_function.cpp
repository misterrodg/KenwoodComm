#include "command_function.h"

void CommandFunction::setModelNumber(Radios modelNumberValue) {
    radioModel = modelNumberValue;
}

CommandResult CommandFunction::set(const std::string& functionString) {
    return SetFunction(radioModel, functionString);
}

core::Result<std::string> CommandFunction::buildSetCommand() {
    if (!supportsSet()) {
        return core::Error{core::ErrorCode::CommandNotImplemented,
                           "Set command is not available for this command"};
    }

    return ToCommand();
}

CommandResult CommandFunction::SetFunction(Radios modelNumber,
                                           const std::string& functionString) {
    Function::FunctionEnum functionEnum =
        Function::StringToFunction(functionString);
    if (functionEnum != Function::FunctionEnum::UNKNOWN) {
        if (allowedForModelNumber(modelNumber, functionEnum)) {
            function = functionEnum;
            return OK();
        } else {
            return Error(core::ErrorCode::FunctionNotAvailable,
                         "COM function not available for the " +
                             Radio::toString(modelNumber));
        }
    }
    return Error(core::ErrorCode::InvalidFunction,
                 "Invalid function: " + functionString);
}

std::string CommandFunction::ToCommand() {
    std::string command = CommandPrefix::CommandToString(commandPrefix);
    int bufferLength = CommandPrefix::COMMAND_LENGTH;

    std::string functionString = Function::FunctionToIntString(function);
    bufferLength += Function::MAX_FUNCTION_LENGTH;

    return SerialCommand(bufferLength, command, functionString).ToString();
}

bool CommandFunction::allowedForModelNumber(
    Radios radioEnum, Function::FunctionEnum& functionEnum) {
    if (functionEnum == Function::FunctionEnum::COM) {
        return (radioEnum == Radios::TS711A || radioEnum == Radios::TS711E ||
                radioEnum == Radios::TS811A || radioEnum == Radios::TS811B ||
                radioEnum == Radios::TS811E);
    }
    return true;
}
