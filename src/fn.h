#ifndef FN_H
#define FN_H

#include "command.h"
#include "command/command_prefix.h"
#include "function.h"
#include "model_number.h"
#include <string>

class Fn
{
public:
    Fn(ModelNumber &modelNumberEnum);
    bool SetFn(std::string &function);
    std::string ToCommand();

private:
    bool fnAllowedForModelNumber(Function::FunctionEnum &functionEnum);
    ModelNumber modelNumber;
    Function::FunctionEnum function;
    static const int FN_PARAMETER_LENGTH;
};

#endif