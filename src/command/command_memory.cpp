#include "command_memory.h"

CommandResult CommandMemory::SetMemory(const ModelNumber& modelNumberParam,
                                       const std::string& parameter) {
    modelNumber = modelNumberParam;
    if (modelNumber.getModelNumber() == Radios::TS940S) {
        std::string bank =
            parameter.substr(0, MemoryBank::MAX_MEMORY_BANK_LENGTH);
        std::string channel =
            parameter.substr(MemoryBank::MAX_MEMORY_BANK_LENGTH);
        bool bankSet = memoryBank.setMemoryBank(bank);
        bool channelSet = memoryChannel.setMemoryChannel(channel);

        if (!bankSet) {
            return Error("INVALID_MEMORY_BANK",
                         "Unrecognized memory bank: " + bank);
        }
        if (!channelSet) {
            return Error("INVALID_MEMORY_CHANNEL",
                         "Unrecognized memory channel: " + channel);
        }
        return OK();
    } else {
        if (memoryChannel.setMemoryChannel(parameter)) {
            return OK();
        }
        return Error("INVALID_MEMORY_CHANNEL",
                     "Unrecognized channel: " + parameter);
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

    return Command(bufferLength, command, resultString).ToString();
}
