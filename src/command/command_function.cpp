#include "command_function.h"

CommandResult CommandFunction::SetFunction(const ModelNumber& modelNumber,
                                           const std::string& functionString) {
    Function::FunctionEnum functionEnum =
        Function::StringToFunction(functionString);
    if (functionEnum != Function::FunctionEnum::UNKNOWN) {
        if (allowedForModelNumber(modelNumber, functionEnum)) {
            function = functionEnum;
            return OK();
        } else {
            return Error("FUNCTION_NOT_AVAILABLE",
                         "COM function not available for the " +
                             modelNumber.getModelNumberString());
        }
    }
    return Error("INVALID_FUNCTION", "Invalid function: " + functionString);
}

std::string CommandFunction::ToCommand() {
    std::string command = CommandPrefix::CommandToString(commandPrefix);
    int bufferLength = CommandPrefix::COMMAND_LENGTH;

    std::string functionString = Function::FunctionToIntString(function);
    bufferLength += Function::MAX_FUNCTION_LENGTH;

    return SerialCommand(bufferLength, command, functionString).ToString();
}

bool CommandFunction::allowedForModelNumber(
    const ModelNumber& modelNumber, Function::FunctionEnum& functionEnum) {
    Radios radioEnum = modelNumber.getModelNumber();
    if ((radioEnum == Radios::TS711A || radioEnum == Radios::TS711E ||
         radioEnum == Radios::TS790A || radioEnum == Radios::TS790E ||
         radioEnum == Radios::TS811A || radioEnum == Radios::TS811B ||
         radioEnum == Radios::TS811E) &&
        functionEnum == Function::FunctionEnum::COM) {
        return true;
    }
    return false;
}
