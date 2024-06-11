#include "memory_channel.h"

const int MemoryChannel::MAX_MEMORY_CHANNEL_LENGTH = 2;

MemoryChannel::MemoryChannel() : memoryChannel(0) {}

bool MemoryChannel::setMemoryChannel(const std::string &input)
{
    bool result = false;
    std::regex regex(R"((\d{1,2}))");
    std::smatch match;

    if (std::regex_match(input, regex))
    {
        int value = std::stoi(input);
        memoryChannel = value;
        result = true;
    }
    else
    {
        printf("Invalid channel format: ");
    }
    return result;
}

short int MemoryChannel::getMemoryChannel() const
{
    return memoryChannel;
}

std::string MemoryChannel::getMemoryChannelString()
{
    char formattedChannel[3];
    snprintf(formattedChannel, sizeof(formattedChannel), "%02d", memoryChannel);

    return formattedChannel;
}