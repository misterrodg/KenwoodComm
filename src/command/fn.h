#ifndef FN_H
#define FN_H

#include "command_function.h"

class FN : public CommandFunction
{
public:
    FN();
    FN(ModelNumber &modelNumberEnum, const std::string &parameter);
};

#endif