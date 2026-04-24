#ifndef MEMORY_LOCKOUT_H
#define MEMORY_LOCKOUT_H

#include "core/result.h"

#include <map>
#include <string>

// Kenwood Parameter #10: Memory Lockout (NOT LOCKED OUT/LOCKED OUT)

class MemoryLockout {
public:
    enum class MemoryLockoutEnum {
        NOT_LOCKED_OUT = 0,
        LOCKED_OUT = 1,
        UNKNOWN = -1
    };
    static MemoryLockoutEnum
    StringToMemoryLockout(const std::string& memoryLockoutString);
    static std::string
    MemoryLockoutToIntString(const MemoryLockoutEnum& memoryLockoutEnum);
    static std::string
    MemoryLockoutToString(const MemoryLockoutEnum& memoryLockoutEnum);
    static constexpr int MAX_MEMORY_LOCKOUT_LENGTH = 13;
};

#endif