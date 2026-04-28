#include <cstdio>

#include "core/error_code.h"
#include "memory_channel.h"

MemoryChannel::MemoryChannelEnum
MemoryChannel::StringToChannelEnum(const std::string& memoryChannel) {
    std::string s = memoryChannel;

    // Strip optional "CH" or "MC" prefix
    if (s.size() >= 2 && (s.substr(0, 2) == "CH" || s.substr(0, 2) == "MC")) {
        s = s.substr(2);
    }

    if (s.empty() || s.find_first_not_of("0123456789") != std::string::npos) {
        return MemoryChannelEnum::UNKNOWN;
    }

    int value = std::stoi(s);
    if (value >= 0 && value <= 99) {
        return static_cast<MemoryChannelEnum>(value);
    }
    return MemoryChannelEnum::UNKNOWN;
}

std::string
MemoryChannel::ChannelEnumToIntString(const MemoryChannelEnum& memoryChannel) {
    int value = static_cast<int>(memoryChannel);
    if (value < 0 || value > 99) {
        return "UNKNOWN";
    }
    char buf[3];
    snprintf(buf, sizeof(buf), "%02d", value);
    return buf;
}

std::string
MemoryChannel::ChannelEnumToString(const MemoryChannelEnum& memoryChannel) {
    int value = static_cast<int>(memoryChannel);
    if (value < 0 || value > 99) {
        return "UNKNOWN";
    }
    char buf[5];
    snprintf(buf, sizeof(buf), "MC%02d", value);
    return buf;
}

std::string MemoryChannel::ChannelEnumToFriendlyString(
    const MemoryChannelEnum& memoryChannel) {
    return ChannelEnumToString(memoryChannel);
}