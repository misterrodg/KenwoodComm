#include "function.h"

const int Function::MAX_FUNCTION_LENGTH = 6;

Function::FunctionEnum Function::StringToFunction(const std::string &functionString)
{
    static const std::map<std::string, Function::FunctionEnum> enumMap = {
        {"VFOA", Function::FunctionEnum::VFOA},
        {"0", Function::FunctionEnum::VFOA},
        {"A", Function::FunctionEnum::VFOA},
        {"VFOB", Function::FunctionEnum::VFOB},
        {"1", Function::FunctionEnum::VFOB},
        {"B", Function::FunctionEnum::VFOB},
        {"MEMORY", Function::FunctionEnum::MEMORY},
        {"2", Function::FunctionEnum::MEMORY},
        {"M", Function::FunctionEnum::MEMORY},
        {"COM", Function::FunctionEnum::COM},
        {"3", Function::FunctionEnum::COM},
        {"C", Function::FunctionEnum::COM},
    };

    auto it = enumMap.find(functionString);
    if (it != enumMap.end())
    {
        return it->second;
    }
    printf("Unrecognized option. Options are: VFOA, VFOB, MEMORY, or COM.\n");
    return FunctionEnum::UNKNOWN;
}

std::string Function::FunctionToIntString(const FunctionEnum &functionEnum)
{
    char result[2];
    snprintf(result, sizeof(result), "%i", static_cast<int>(functionEnum));
    return result;
}

std::string Function::FunctionToString(const FunctionEnum &functionEnum)
{
    static const std::map<Function::FunctionEnum, std::string> enumMap = {
        {Function::FunctionEnum::VFOA, "VFOA"},
        {Function::FunctionEnum::VFOB, "VFOB"},
        {Function::FunctionEnum::MEMORY, "MEMORY"},
        {Function::FunctionEnum::COM, "COM"}};

    auto it = enumMap.find(functionEnum);
    if (it != enumMap.end())
    {
        return it->second;
    }
    return "UNKNOWN";
}