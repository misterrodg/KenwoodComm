#ifndef COMMAND_MEMORY_H
#define COMMAND_MEMORY_H

#include "command_base.h"
#include "command_result.h"
#include "parameter/memory_bank.h"
#include "parameter/memory_channel.h"
#include "parameter/model_number.h"

class CommandMemory : public CommandBase {
protected:
    ModelNumber modelNumber;
    MemoryBank memoryBank;
    MemoryChannel memoryChannel;

public:
    CommandMemory(CommandPrefix::CommandPrefixEnum prefix)
        : CommandBase(prefix) {};

    void setModelNumber(const ModelNumber& modelNumberValue);
    CommandResult set(const std::string& param) override;
    core::Result<std::string> buildSetCommand() override;

    std::string ToCommand();
    CommandResult SetMemory(const std::string& parameter);
};

#endif
