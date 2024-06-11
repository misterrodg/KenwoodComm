#ifndef COMMAND_MEMORY_H
#define COMMAND_MEMORY_H

#include "command_base.h"
#include "../parameter/memory_bank.h"
#include "../parameter/memory_channel.h"
#include "../parameter/model_number.h"

class CommandMemory : public CommandBase
{
protected:
    ModelNumber modelNumber;
    MemoryBank memoryBank;
    MemoryChannel memoryChannel;

public:
    CommandMemory(CommandPrefix::CommandPrefixEnum prefix) : CommandBase(prefix){};
    std::string ToCommand();
    bool SetMemory(ModelNumber &modelNumberParam, const std::string &parameter);
};

#endif