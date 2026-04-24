#include "memory_lockout.h"

#include "core/error_code.h"

MemoryLockout::MemoryLockoutEnum
MemoryLockout::StringToMemoryLockout(const std::string& memoryLockoutString) {
    static const std::map<std::string, MemoryLockoutEnum> enumMap = {
        {"UNLOCKED", MemoryLockoutEnum::NOT_LOCKED_OUT},
        {"U", MemoryLockoutEnum::NOT_LOCKED_OUT},
        {"0", MemoryLockoutEnum::NOT_LOCKED_OUT},
        {"LOCKED", MemoryLockoutEnum::LOCKED_OUT},
        {"L", MemoryLockoutEnum::LOCKED_OUT},
        {"1", MemoryLockoutEnum::LOCKED_OUT},
    };
    auto it = enumMap.find(memoryLockoutString);
    if (it != enumMap.end()) {
        return it->second;
    }
    return MemoryLockoutEnum::UNKNOWN;
}

std::string MemoryLockout::MemoryLockoutToIntString(
    const MemoryLockoutEnum& memoryLockoutEnum) {
    char result[2];
    snprintf(result, sizeof(result), "%i", static_cast<int>(memoryLockoutEnum));
    return result;
}

std::string MemoryLockout::MemoryLockoutToString(
    const MemoryLockoutEnum& memoryLockoutEnum) {
    static const std::map<MemoryLockoutEnum, std::string> enumMap = {
        {MemoryLockoutEnum::NOT_LOCKED_OUT, "UNLOCKED"},
        {MemoryLockoutEnum::LOCKED_OUT, "LOCKED"},
        {MemoryLockoutEnum::UNKNOWN, "UNKNOWN"}};

    auto it = enumMap.find(memoryLockoutEnum);
    if (it != enumMap.end()) {
        return it->second;
    }
    return "UNKNOWN";
}