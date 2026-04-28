#ifndef COMMAND_MEMORY_H
#define COMMAND_MEMORY_H

#include "command_base.h"
#include "command_result.h"
#include "core/radio.h"
#include "parameter/memory_bank.h"
#include "parameter/memory_channel.h"

class CommandMemory : public CommandBase {
protected:
    Radios radioModel = Radios::UNRECOGNIZED;
    MemoryBank::MemoryBankEnum memoryBank = MemoryBank::MemoryBankEnum::MB0;
    MemoryChannel::MemoryChannelEnum memoryChannel =
        MemoryChannel::MemoryChannelEnum::MC00;

public:
    CommandMemory(CommandPrefix::CommandPrefixEnum prefix)
        : CommandBase(prefix) {};

    void setModelNumber(Radios modelNumberValue);
    CommandResult set(const std::string& param) override;
    core::Result<std::string> buildSetCommand() override;

    std::string ToCommand();
    CommandResult SetMemory(const std::string& parameter);
};

#endif
