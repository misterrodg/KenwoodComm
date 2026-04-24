#ifndef MEMORY_BANK_H
#define MEMORY_BANK_H

#include "core/result.h"

#include <cstdint>
#include <regex>
#include <string>

// Kenwood Parameter #8: Memory Bank (with 1 digit, e.g. 2 for Bank 2)

class MemoryBank {
public:
    MemoryBank();
    core::Result<void> setMemoryBank(const std::string& input);
    unsigned short int getMemoryBank() const;
    std::string getMemoryBankString();
    static constexpr int MAX_MEMORY_BANK_LENGTH = 1;

private:
    unsigned short int memoryBank;
};

#endif