#include "memory_bank.h"

#include "core/error_code.h"


MemoryBank::MemoryBank() : memoryBank(0) {}

core::Result<void> MemoryBank::setMemoryBank(const std::string &input)
{
    std::regex regex(R"([1-4])");
    std::smatch match;

    if (std::regex_match(input, regex))
    {
        int value = std::stoi(input);
        memoryBank = value;
        return {};
    }

    return core::Error{core::ErrorCode::InvalidMemoryBank, "Invalid memory bank format: '" + input +
                           "'. Expected a bank number from 1 to 4."};
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