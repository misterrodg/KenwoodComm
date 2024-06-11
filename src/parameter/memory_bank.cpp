#include "memory_bank.h"

const int MemoryBank::MAX_MEMORY_BANK_LENGTH = 1;

MemoryBank::MemoryBank() : memoryBank(0) {}

bool MemoryBank::setMemoryBank(const std::string &input)
{
    bool result = false;
    std::regex regex(R"([1-4])");
    std::smatch match;

    if (std::regex_match(input, regex))
    {
        int value = std::stoi(input);
        memoryBank = value;
        result = true;
    }
    else
    {
        printf("Invalid bank format: ");
    }
    return result;
}

unsigned short int MemoryBank::getMemoryBank() const
{
    return memoryBank;
}

std::string MemoryBank::getMemoryBankString()
{
    char formattedBank[2];
    snprintf(formattedBank, sizeof(formattedBank), "%1d", memoryBank);

    return formattedBank;
}