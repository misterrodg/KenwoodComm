#include "command_memory.h"

CommandResult CommandMemory::SetMemory(const ModelNumber& modelNumberParam,
                                       const std::string& parameter) {
    modelNumber = modelNumberParam;
    if (modelNumber.getModelNumber() == Radios::TS940S) {
        std::string bank =
            parameter.substr(0, MemoryBank::MAX_MEMORY_BANK_LENGTH);
        std::string channel =
            parameter.substr(MemoryBank::MAX_MEMORY_BANK_LENGTH);
        core::Result<void> bankResult = memoryBank.setMemoryBank(bank);
        core::Result<void> channelResult =
            memoryChannel.setMemoryChannel(channel);

        if (!bankResult.OK()) {
            return bankResult.error();
        }
        if (!channelResult.OK()) {
            return channelResult.error();
        }
        return OK();
    } else {
        core::Result<void> channelResult =
            memoryChannel.setMemoryChannel(parameter);
        if (channelResult.OK()) {
            return OK();
        }
        return channelResult.error();
    }
}

std::string CommandMemory::ToCommand() {
    std::string command = CommandPrefix::CommandToString(commandPrefix);
    int bufferLength = CommandPrefix::COMMAND_LENGTH;

    std::string resultString = "";
    std::string channelString = memoryChannel.getMemoryChannelString();

    if (modelNumber.getModelNumber() == Radios::TS940S) {
        std::string bankString = memoryBank.getMemoryBankString();
        resultString = bankString + channelString;
    } else {
        resultString = " " + channelString;
    }

    bufferLength += MemoryBank::MAX_MEMORY_BANK_LENGTH +
                    MemoryChannel::MAX_MEMORY_CHANNEL_LENGTH;

    return SerialCommand(bufferLength, command, resultString).ToString();
}
