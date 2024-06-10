#ifndef FUNCTION_H
#define FUNCTION_H

#include <map>
#include <string>

class Function
{
public:
    enum class FunctionEnum
    {
        VFOA,
        VFOB,
        MEMORY,
        COM, // TS711A/711E/811A/811B/811E only
        UNKNOWN
    };
    static FunctionEnum StringToFunction(const std::string &functionString);
    static std::string FunctionToString(const FunctionEnum &functionEnum);
    static std::string FunctionToIntString(const FunctionEnum &FunctionEnum);
    static const int MAX_FUNCTION_LENGTH;
};

#endif