#ifndef MEMORY_CHANNEL_SPLIT_H
#define MEMORY_CHANNEL_SPLIT_H

#include <map>
#include <string>

class MemoryChannelSplit
{
public:
    enum class MemoryChannelSplitEnum
    {
        // TS140S/680S/711A/711E/811A/811B/811E only
        RECEIVE,
        TRANSMIT,
        UNKNOWN
    };
    static MemoryChannelSplitEnum StringToSplit(const std::string &splitString);
    static std::string SplitToIntString(const MemoryChannelSplitEnum &splitEnum);
    static std::string SplitToString(const MemoryChannelSplitEnum &splitEnum);
    static const int MAX_SPLIT_LENGTH = 8;
};

#endif