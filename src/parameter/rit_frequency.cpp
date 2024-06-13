#include "rit_frequency.h"

RITFrequency::RITFrequency() : frequencyInHz(0) {}

void RITFrequency::setRITFrequency(const std::string &input)
{
    std::regex regex(R"(([+-]?\d{1,4}))");
    std::smatch match;

    if (std::regex_match(input, regex))
    {
        int value = std::stoi(input);

        frequencyInHz = value;
    }
    else
    {
        printf("Invalid frequency format");
    }
}

short int RITFrequency::getRITFrequencyInHz() const
{
    return frequencyInHz;
}

std::string RITFrequency::getRITFrequencyString()
{
    char formattedFrequency[6];
    snprintf(formattedFrequency, sizeof(formattedFrequency), "%+05d", frequencyInHz);

    return formattedFrequency;
}