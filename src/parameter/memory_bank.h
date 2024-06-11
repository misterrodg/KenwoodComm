#ifndef MEMORY_BANK_H
#define MEMORY_BANK_H

#include <string>
#include <cstdint>
#include <regex>

class MemoryBank
{
public:
    MemoryBank();
    bool setMemoryBank(const std::string &input);
    unsigned short int getMemoryBank() const;
    std::string getMemoryBankString();
    static const int MAX_MEMORY_BANK_LENGTH;

private:
    unsigned short int memoryBank;
};

#endif