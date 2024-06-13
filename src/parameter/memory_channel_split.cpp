#include "memory_channel_split.h"

MemoryChannelSplit::MemoryChannelSplitEnum MemoryChannelSplit::StringToSplit(const std::string &splitString)
{
    static const std::map<std::string, MemoryChannelSplit::MemoryChannelSplitEnum> enumMap = {
        {"RECEIVE", MemoryChannelSplit::MemoryChannelSplitEnum::RECEIVE},
        {"0", MemoryChannelSplit::MemoryChannelSplitEnum::RECEIVE},
        {"TRANSMIT", MemoryChannelSplit::MemoryChannelSplitEnum::TRANSMIT},
        {"1", MemoryChannelSplit::MemoryChannelSplitEnum::TRANSMIT}};

    auto it = enumMap.find(splitString);
    if (it != enumMap.end())
    {
        return it->second;
    }
    printf("Unrecognized option. Options are: RECEIVE, or TRANSMIT.\n");
    return MemoryChannelSplit::MemoryChannelSplitEnum::UNKNOWN;
}

std::string MemoryChannelSplit::SplitToIntString(const MemoryChannelSplitEnum &splitEnum)
{
    static const std::map<MemoryChannelSplit::MemoryChannelSplitEnum, std::string> enumMap = {
        {MemoryChannelSplit::MemoryChannelSplitEnum::RECEIVE, "0"},
        {MemoryChannelSplit::MemoryChannelSplitEnum::TRANSMIT, "1"}};

    auto it = enumMap.find(splitEnum);
    if (it != enumMap.end())
    {
        return it->second;
    }
    return "UNKNOWN";
}

std::string MemoryChannelSplit::SplitToString(const MemoryChannelSplitEnum &splitEnum)
{
    static const std::map<MemoryChannelSplit::MemoryChannelSplitEnum, std::string> enumMap = {
        {MemoryChannelSplit::MemoryChannelSplitEnum::RECEIVE, "RECEIVE"},
        {MemoryChannelSplit::MemoryChannelSplitEnum::TRANSMIT, "TRANSMIT"}};

    auto it = enumMap.find(splitEnum);
    if (it != enumMap.end())
    {
        return it->second;
    }
    return "UNKNOWN";
}