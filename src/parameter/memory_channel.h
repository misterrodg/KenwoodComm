#ifndef MEMORY_CHANNEL_H
#define MEMORY_CHANNEL_H

#include "core/result.h"

#include <cstdint>
#include <regex>
#include <string>

class MemoryChannel
{
public:
    MemoryChannel();
    core::Result<void> setMemoryChannel(const std::string &input);
    short int getMemoryChannel() const;
    std::string getMemoryChannelString();
    static const int MAX_MEMORY_CHANNEL_LENGTH;

private:
    short int memoryChannel;
};

#endif