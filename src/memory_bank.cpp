#include "memory_bank.h"
#include <regex>
#include <stdexcept>

MemoryBank::MemoryBank() : memoryBank(0) {}

void MemoryBank::setMemoryBank(const std::string &input)
{
    std::regex regex(R"([1-4])");
    std::smatch match;

    if (std::regex_match(input, regex))
    {
        int value = std::stoi(input);

        memoryBank = value;
    }
    else
    {
        throw std::invalid_argument("Invalid channel format");
    }
}

unsigned short int MemoryBank::getMemoryBank() const
{
    return memoryBank;
}

std::string MemoryBank::getMemoryBankString()
{
    char formattedBank[2];
    std::sprintf(formattedBank, "%1d", memoryBank);

    return formattedBank;
}