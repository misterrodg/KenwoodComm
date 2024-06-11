#include "frequency.h"

const int Frequency::MAX_FREQUENCY_LENGTH = 11;

Frequency::Frequency() : frequencyInHz(0) {}

bool Frequency::setFrequency(const std::string &input)
{
    bool result = false;
    std::regex regex(R"((\d+(\.\d+)?)([a-zA-Z]+))");
    std::smatch match;

    if (std::regex_match(input, match, regex))
    {
        double value = std::stod(match[1].str());
        std::string unit = match[3].str();

        FrequencyUnit::Unit frequencyUnit = FrequencyUnit::parseUnit(unit);
        if (frequencyUnit != FrequencyUnit::UNKNOWN)
        {
            frequencyInHz = FrequencyUnit::toHz(value, frequencyUnit);
            result = true;
        }
    }
    else
    {
        printf("Invalid frequency format.\n");
    }
    return result;
}

uint64_t Frequency::getFrequencyInHz() const
{
    return frequencyInHz;
}

std::string Frequency::getFrequencyString()
{
    char formattedFrequency[12];
    snprintf(formattedFrequency, sizeof(formattedFrequency), "%011lu", frequencyInHz);

    return formattedFrequency;
}