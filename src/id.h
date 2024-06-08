#ifndef ID_H
#define ID_H

#include "command.h"
#include "command_prefix.h"
#include <string>

class Id
{
public:
    static std::string ToCommand();
};

#endif