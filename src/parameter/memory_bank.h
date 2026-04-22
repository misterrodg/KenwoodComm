#ifndef MEMORY_BANK_H
#define MEMORY_BANK_H

#include "core/result.h"

#include <cstdint>
#include <regex>
#include <string>

class MemoryBank
{
public:
    MemoryBank();
    core::Result<void> setMemoryBank(const std::string &input);
    unsigned short int getMemoryBank() const;
    std::string getMemoryBankString();
    static const int MAX_MEMORY_BANK_LENGTH;

private:
    unsigned short int memoryBank;
};

#endif