#ifndef ANTENNA_TUNER_H
#define ANTENNA_TUNER_H

#include "command.h"
#include "command_prefix.h"
#include <string>

class AntennaTuner
{
public:
    static std::string ToCommand();

private:
    static std::string ANTENNA_TUNER_PARAMETER;
    static const int ANTENNA_TUNER_PARAMETER_LENGTH;
};

#endif