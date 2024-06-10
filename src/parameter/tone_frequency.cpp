#include "tone_frequency.h"
#include <regex>
#include <stdexcept>

ToneFrequency::ToneFrequency() : toneFrequency(0) {}

void ToneFrequency::setToneFrequency(const std::string &input)
{
    std::regex regex(R"((0[0-9]|1[0-9]|2[0-9]|3[0-7]))");
    std::smatch match;

    if (std::regex_match(input, regex))
    {
        int value = std::stoi(input);

        toneFrequency = value;
    }
    else
    {
        throw std::invalid_argument("Invalid tone frequency format");
    }
}

unsigned short int ToneFrequency::getToneFrequency() const
{
    return toneFrequency;
}

std::string ToneFrequency::getToneFrequencyString()
{
    char formattedToneFrequency[3];
    snprintf(formattedToneFrequency, sizeof(formattedToneFrequency), "%02d", toneFrequency);

    return formattedToneFrequency;
}