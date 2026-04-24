#ifndef MEMORY_CHANNEL_SPLIT_H
#define MEMORY_CHANNEL_SPLIT_H

#include "core/result.h"

#include <map>
#include <string>

// Kenwood Parameter #9: Memory Channel Split (RECEIVE/TRANSMIT)

class MemoryChannelSplit {
public:
    enum class MemoryChannelSplitEnum {
        RECEIVE = 0,
        TRANSMIT = 1,
        UNKNOWN = -1
    };
    static MemoryChannelSplitEnum
    StringToMemoryChannelSplit(const std::string& memoryChannelSplitString);
    static std::string MemoryChannelSplitToString(
        const MemoryChannelSplitEnum& memoryChannelSplitEnum);
    static std::string MemoryChannelSplitToIntString(
        const MemoryChannelSplitEnum& memoryChannelSplitEnum);
    static constexpr int MAX_MEMORY_CHANNEL_SPLIT_LENGTH = 1;
};

#endif // MEMORY_CHANNEL_SPLIT_H