#include "memory_channel_split.h"

#include "core/error_code.h"


MemoryChannelSplit::MemoryChannelSplitEnum
MemoryChannelSplit::StringToMemoryChannelSplit(
    const std::string& memoryChannelSplitString) {
    static const std::map<std::string, MemoryChannelSplitEnum> enumMap = {
        {"RECEIVE", MemoryChannelSplitEnum::RECEIVE},
        {"RX", MemoryChannelSplitEnum::RECEIVE},
        {"0", MemoryChannelSplitEnum::RECEIVE},
        {"TRANSMIT", MemoryChannelSplitEnum::TRANSMIT},
        {"TX", MemoryChannelSplitEnum::TRANSMIT},
        {"1", MemoryChannelSplitEnum::TRANSMIT},
    };

    auto it = enumMap.find(memoryChannelSplitString);
    if (it != enumMap.end()) {
        return it->second;
    }
    return MemoryChannelSplitEnum::UNKNOWN;
}

std::string MemoryChannelSplit::MemoryChannelSplitToIntString(
    const MemoryChannelSplitEnum& memoryChannelSplitEnum) {
    char result[2];
    snprintf(result, sizeof(result), "%i",
             static_cast<int>(memoryChannelSplitEnum));
    return result;
}

std::string MemoryChannelSplit::MemoryChannelSplitToString(
    const MemoryChannelSplitEnum& memoryChannelSplitEnum) {
    static const std::map<MemoryChannelSplitEnum, std::string> enumMap = {
        {MemoryChannelSplitEnum::RECEIVE, "RECEIVE"},
        {MemoryChannelSplitEnum::TRANSMIT, "TRANSMIT"},
        {MemoryChannelSplitEnum::UNKNOWN, "UNKNOWN"}};

    auto it = enumMap.find(memoryChannelSplitEnum);
    if (it != enumMap.end()) {
        return it->second;
    }
    return "UNKNOWN";
}