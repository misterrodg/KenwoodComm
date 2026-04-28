#include "memory_bank.h"

#include "core/error_code.h"

MemoryBank::MemoryBankEnum
MemoryBank::StringToBankEnum(const std::string& memoryBank) {
    if (memoryBank == "0" || memoryBank == "MB0") {
        return MemoryBankEnum::MB0;
    } else if (memoryBank == "1" || memoryBank == "MB1") {
        return MemoryBankEnum::MB1;
    } else if (memoryBank == "2" || memoryBank == "MB2") {
        return MemoryBankEnum::MB2;
    }
    return MemoryBankEnum::UNKNOWN;
}

std::string MemoryBank::BankEnumToIntString(const MemoryBankEnum& memoryBank) {
    switch (memoryBank) {
    case MemoryBankEnum::MB0:
        return "0";
    case MemoryBankEnum::MB1:
        return "1";
    case MemoryBankEnum::MB2:
        return "2";
    default:
        return "UNKNOWN";
    }
}

std::string MemoryBank::BankEnumToString(const MemoryBankEnum& memoryBank) {
    switch (memoryBank) {
    case MemoryBankEnum::MB0:
        return "MB0";
    case MemoryBankEnum::MB1:
        return "MB1";
    case MemoryBankEnum::MB2:
        return "MB2";
    default:
        return "UNKNOWN";
    }
}

std::string
MemoryBank::BankEnumToFriendlyString(const MemoryBankEnum& memoryBank) {
    switch (memoryBank) {
    case MemoryBankEnum::MB0:
        return "Memory Bank 0";
    case MemoryBankEnum::MB1:
        return "Memory Bank 1";
    case MemoryBankEnum::MB2:
        return "Memory Bank 2";
    default:
        return "Unknown Memory Bank";
    }
}
