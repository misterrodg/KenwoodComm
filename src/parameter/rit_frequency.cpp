#include "rit_frequency.h"

RITFrequency::RITFrequency() : frequencyInHz(0) {}

bool RITFrequency::setRITFrequency(const std::string &input)
{
    bool result = false;
    std::regex regex(R"(([+-]?\d+(\.\d+)?)([a-zA-Z]+))");
    std::smatch match;

    if (std::regex_match(input, match, regex))
    {
        std::string sign = match[1].str();
        double value = std::stod(match[2].str());
        std::string unit = match[4].str();

        FrequencyUnit::Unit frequencyUnit = FrequencyUnit::parseUnit(unit);
        if (frequencyUnit != FrequencyUnit::UNKNOWN && frequencyUnit != FrequencyUnit::MHZ && frequencyUnit != FrequencyUnit::GHZ)
        {
            frequencyInHz = FrequencyUnit::toHz(value, frequencyUnit);
            if (frequencyInHz <= MAX_RIT_FREQUENCY_VALUE && frequencyInHz >= MIN_RIT_FREQUENCY_VALUE)
            {
                result = true;
            }
            else
            {
                printf("RIT frequency must be between %dHz and %dHz.\n", MAX_RIT_FREQUENCY_VALUE, MIN_RIT_FREQUENCY_VALUE);
            }
        }
        else
        {
            printf("RIT frequency unit must be kHz or Hz.\n");
        }
    }
    else
    {
        printf("Invalid RIT frequency format.\n");
    }
    return result;
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