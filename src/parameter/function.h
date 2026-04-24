#ifndef FUNCTION_H
#define FUNCTION_H

#include <map>
#include <string>

// Kenwood Parameter #3: Function (VFOA/VFOB/MEMORY/COM)

class Function {
public:
    enum class FunctionEnum {
        VFOA = 0,
        VFOB = 1,
        MEMORY = 2,
        COM = 3, // TS711A/711E/811A/811B/811E only
        UNKNOWN = -1
    };
    static FunctionEnum StringToFunction(const std::string& functionString);
    static std::string FunctionToString(const FunctionEnum& functionEnum);
    static std::string FunctionToIntString(const FunctionEnum& FunctionEnum);
    static constexpr int MAX_FUNCTION_LENGTH = 6;
};

#endif