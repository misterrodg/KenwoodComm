#include "command_function.h"

bool CommandFunction::SetFunction(ModelNumber &modelNumber, const std::string &functionString)
{
    bool result = false;
    Function::FunctionEnum functionEnum = Function::StringToFunction(functionString);
    if (functionEnum != Function::FunctionEnum::UNKNOWN)
    {
        if (allowedForModelNumber(modelNumber, functionEnum))
        {
            function = functionEnum;
            result = true;
        }
        else
        {
            printf("COM function not available for the %s.\n", modelNumber.getModelNumberString().c_str());
        }
    }
    return result;
}

std::string CommandFunction::ToCommand()
{
    std::string command = CommandPrefix::CommandToString(commandPrefix);
    int bufferLength = CommandPrefix::COMMAND_LENGTH;

    std::string functionString = Function::FunctionToIntString(function);
    bufferLength += Function::MAX_FUNCTION_LENGTH;

    return Command(bufferLength, command, functionString).ToString();
}

bool CommandFunction::allowedForModelNumber(ModelNumber &modelNumber, Function::FunctionEnum &functionEnum)
{
    Radios radioEnum = modelNumber.getModelNumber();
    if ((radioEnum == Radios::TS711A || radioEnum == Radios::TS711E || radioEnum == Radios::TS790A || radioEnum == Radios::TS790E || radioEnum == Radios::TS811A || radioEnum == Radios::TS811B || radioEnum == Radios::TS811E) && functionEnum == Function::FunctionEnum::COM)
    {
        return true;
    }
    return false;
}