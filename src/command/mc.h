#ifndef MC_H
#define MC_H

#include "command_memory.h"

class MC : public CommandMemory
{
public:
    MC();
    MC(ModelNumber &modelNumberEnum, const std::string &parameter);
};

#endif