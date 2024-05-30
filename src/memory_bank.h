#ifndef MEMORY_BANK_H
#define MEMORY_BANK_H

#include <string>
#include <cstdint>

class MemoryBank
{
public:
    MemoryBank();
    void setMemoryBank(const std::string &input);
    unsigned short int getMemoryBank() const;
    std::string getMemoryBankString();

private:
    unsigned short int memoryBank;
};

#endif