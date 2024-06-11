#include "command_memory.h"

bool CommandMemory::SetMemory(ModelNumber &modelNumberParam, const std::string &parameter)
{
    bool result = false;
    modelNumber = modelNumberParam;
    if (modelNumber.getModelNumber() == Radios::TS940S)
    {
        std::string bank = parameter.substr(0, MemoryBank::MAX_MEMORY_BANK_LENGTH);
        std::string channel = parameter.substr(MemoryBank::MAX_MEMORY_BANK_LENGTH);
        bool bankSet = memoryBank.setMemoryBank(bank);
        if (!bankSet)
        {
            printf("Unrecognized memory bank %s.\n", bank.c_str());
        }
        bool channelSet = memoryChannel.setMemoryChannel(channel);
        if (!channelSet)
        {
            printf("Unrecognized memory channel %s.\n", channel.c_str());
        }
        if (bankSet && channelSet)
        {
            result = true;
        }
    }
    else
    {
        if (memoryChannel.setMemoryChannel(parameter))
        {
            result = true;
        }
        else
        {
            printf("Unrecognized channel string %s.\n", parameter.c_str());
        }
    }
    return result;
}

std::string CommandMemory::ToCommand()
{
    std::string command = CommandPrefix::CommandToString(commandPrefix);
    int bufferLength = CommandPrefix::COMMAND_LENGTH;

    std::string resultString = "";
    std::string channelString = memoryChannel.getMemoryChannelString();

    if (modelNumber.getModelNumber() == Radios::TS940S)
    {
        std::string bankString = memoryBank.getMemoryBankString();
        resultString = bankString + channelString;
    }
    else
    {
        resultString = " " + channelString;
    }

    bufferLength += MemoryBank::MAX_MEMORY_BANK_LENGTH + MemoryChannel::MAX_MEMORY_CHANNEL_LENGTH;

    return Command(bufferLength, command, resultString).ToString();
}
