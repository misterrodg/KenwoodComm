#ifndef MEMORY_BANK_H
#define MEMORY_BANK_H

#include "core/result.h"

#include <cstdint>
#include <regex>
#include <string>

// Kenwood Parameter #8: Memory Bank (with 1 digit, e.g. 2 for Bank 2)

class MemoryBank {
public:
    enum class MemoryBankEnum { MB0 = 0, MB1 = 1, MB2 = 2, UNKNOWN = -1 };

    static MemoryBankEnum StringToBankEnum(const std::string& memoryBank);
    static std::string BankEnumToIntString(const MemoryBankEnum& memoryBank);
    static std::string BankEnumToString(const MemoryBankEnum& memoryBank);
    static std::string
    BankEnumToFriendlyString(const MemoryBankEnum& memoryBank);
    static constexpr int MAX_MEMORY_BANK_LENGTH = 1;
};

#endif