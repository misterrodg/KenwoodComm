#include "command_memory.h"

void CommandMemory::setModelNumber(Radios modelNumberValue) {
    radioModel = modelNumberValue;
}

CommandResult CommandMemory::set(const std::string& memoryString) {
    return SetMemory(memoryString);
}

core::Result<std::string> CommandMemory::buildSetCommand() {
    if (!supportsSet()) {
        return core::Error{core::ErrorCode::CommandNotImplemented,
                           "Set command is not available for this command"};
    }

    return ToCommand();
}

CommandResult CommandMemory::SetMemory(const std::string& parameter) {
    if (radioModel == Radios::TS940S) {
        std::string bank =
            parameter.substr(0, MemoryBank::MAX_MEMORY_BANK_LENGTH);
        std::string channel =
            parameter.substr(MemoryBank::MAX_MEMORY_BANK_LENGTH);
        MemoryBank::MemoryBankEnum bankEnum =
            MemoryBank::StringToBankEnum(bank);
        MemoryChannel::MemoryChannelEnum channelEnum =
            MemoryChannel::StringToChannelEnum(channel);
        if (bankEnum == MemoryBank::MemoryBankEnum::UNKNOWN) {
            return Error(core::ErrorCode::InvalidMemoryBank,
                         "Invalid memory bank: " + bank);
        }
        if (channelEnum == MemoryChannel::MemoryChannelEnum::UNKNOWN) {
            return Error(core::ErrorCode::InvalidMemoryChannel,
                         "Invalid memory channel: " + channel);
        }
        memoryBank = bankEnum;
        memoryChannel = channelEnum;
        return OK();
    } else {
        MemoryChannel::MemoryChannelEnum channelEnum =
            MemoryChannel::StringToChannelEnum(parameter);
        if (channelEnum != MemoryChannel::MemoryChannelEnum::UNKNOWN) {
            memoryChannel = channelEnum;
            return OK();
        }
        return Error(core::ErrorCode::InvalidMemoryChannel,
                     "Invalid memory channel: " + parameter);
    }
}

std::string CommandMemory::ToCommand() {
    std::string command = CommandPrefix::CommandToString(commandPrefix);
    int bufferLength = CommandPrefix::COMMAND_LENGTH;

    std::string resultString = "";
    std::string channelString =
        MemoryChannel::ChannelEnumToIntString(memoryChannel);

    if (radioModel == Radios::TS940S) {
        std::string bankString = MemoryBank::BankEnumToIntString(memoryBank);
        resultString = bankString + channelString;
    } else {
        resultString = " " + channelString;
    }

    bufferLength += MemoryBank::MAX_MEMORY_BANK_LENGTH +
                    MemoryChannel::MAX_MEMORY_CHANNEL_LENGTH;

    return SerialCommand(bufferLength, command, resultString).ToString();
}
