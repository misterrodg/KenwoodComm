#include "memory_channel.h"

#include "core/error_code.h"


MemoryChannel::MemoryChannel() : memoryChannel(0) {}

core::Result<void> MemoryChannel::setMemoryChannel(const std::string &input)
{
    std::regex regex(R"((\d{1,2}))");
    std::smatch match;

    if (std::regex_match(input, regex))
    {
        int value = std::stoi(input);
        memoryChannel = value;
        return {};
    }

    return core::Error{core::ErrorCode::InvalidMemoryChannel, "Invalid memory channel format: '" + input +
                           "'. Expected a 1 or 2 digit channel number."};
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