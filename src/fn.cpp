#include "fn.h"

const int Fn::FN_PARAMETER_LENGTH = 1;

Fn::Fn(ModelNumber &modelNumberEnum) : modelNumber(modelNumberEnum), function(Function::FunctionEnum::VFOA) {}

bool Fn::SetFn(std::string &functionString)
{
    bool result = false;
    Function::FunctionEnum functionEnum = Function::StringToFunction(functionString);
    if (!fnAllowedForModelNumber(functionEnum))
    {
        printf("COM function not available for the %s.\n", modelNumber.getModelNumberString().c_str());
        return false;
    }
    if (functionEnum != Function::FunctionEnum::UNKNOWN)
    {
        function = functionEnum;
        result = true;
    }
    else
    {
        printf("Unrecognized option. Options are: VFOA, VFOB, MEMORY, or COM.\n");
    }
    return result;
}

std::string Fn::ToCommand()
{
    std::string command = CommandPrefix::CommandToString(CommandPrefix::CommandPrefixEnum::FN);
    std::string functionString = Function::FunctionToIntString(function);
    int bufferLength = CommandPrefix::COMMAND_LENGTH + FN_PARAMETER_LENGTH;

    return Command(bufferLength, command, functionString).ToString();
}

bool Fn::fnAllowedForModelNumber(Function::FunctionEnum &functionEnum)
{
    Radios radioEnum = modelNumber.getModelNumber();
    if ((radioEnum == Radios::TS140S || radioEnum == Radios::TS680S || radioEnum == Radios::TS940S) && functionEnum == Function::FunctionEnum::COM)
    {
        return false;
    }
    return true;
}