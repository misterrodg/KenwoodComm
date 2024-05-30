#include "memory_channel.h"
#include <regex>
#include <stdexcept>

MemoryChannel::MemoryChannel() : memoryChannel(0) {}

void MemoryChannel::setMemoryChannel(const std::string &input)
{
    std::regex regex(R"((\d{1,2}))");
    std::smatch match;

    if (std::regex_match(input, regex))
    {
        int value = std::stoi(input);

        memoryChannel = value;
    }
    else
    {
        throw std::invalid_argument("Invalid channel format");
    }
}

short int MemoryChannel::getMemoryChannel() const
{
    return memoryChannel;
}

std::string MemoryChannel::getMemoryChannelString()
{
    char formattedChannel[3];
    std::sprintf(formattedChannel, "%02d", memoryChannel);

    return formattedChannel;
}