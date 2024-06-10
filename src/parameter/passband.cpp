#include "passband.h"
#include <regex>
#include <stdexcept>

Passband::Passband() : passband(0) {}

void Passband::setPassband(const std::string &input)
{
    std::regex regex(R"((0[0-9]|1[0-9]|2[0-9]|3[0-1]))");
    std::smatch match;

    if (std::regex_match(input, regex))
    {
        int value = std::stoi(input);

        passband = value;
    }
    else
    {
        throw std::invalid_argument("Invalid passband format");
    }
}

unsigned short int Passband::getPassband() const
{
    return passband;
}

std::string Passband::getPassbandString()
{
    char formattedPassband[3];
    snprintf(formattedPassband, sizeof(formattedPassband), "%02d", passband);

    return formattedPassband;
}