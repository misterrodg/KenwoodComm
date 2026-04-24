#ifndef MEMORY_CHANNEL_H
#define MEMORY_CHANNEL_H

#include "core/result.h"

#include <cstdint>
#include <regex>
#include <string>

// Kenwood Parameter #7: Memory Channel (with 2 digits, e.g. 02 for CH2)

class MemoryChannel {
public:
    MemoryChannel();
    core::Result<void> setMemoryChannel(const std::string& input);
    short int getMemoryChannel() const;
    std::string getMemoryChannelString();
    static constexpr int MAX_MEMORY_CHANNEL_LENGTH = 2;

private:
    short int memoryChannel;
};

#endif