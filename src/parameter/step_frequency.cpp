#include "step_frequency.h"

StepFrequency::StepFrequency() : frequencyInHz(0) {}

bool StepFrequency::setStepFrequency(const std::string &input)
{
    bool result = false;
    std::regex regex(R"((\d+(\.\d+)?)([a-zA-Z]+))");
    std::smatch match;

    if (std::regex_match(input, match, regex))
    {
        double value = std::stod(match[1].str());
        std::string unit = match[3].str();

        FrequencyUnit::Unit frequencyUnit = FrequencyUnit::parseUnit(unit);
        if (frequencyUnit != FrequencyUnit::UNKNOWN && frequencyUnit != FrequencyUnit::MHZ && frequencyUnit != FrequencyUnit::GHZ)
        {
            frequencyInHz = FrequencyUnit::toHz(value, frequencyUnit);
            if (frequencyInHz <= MAX_STEP_FREQUENCY_VALUE)
            {
                result = true;
            }
            else
            {
                printf("Step frequency must be between 0 and %dHz.\n", MAX_STEP_FREQUENCY_VALUE);
            }
        }
        else
        {
            printf("Step frequency unit must be kHz or Hz.\n");
        }
    }
    else
    {
        printf("Invalid Step frequency format.\n");
    }
    return result;
}

unsigned short int StepFrequency::getStepFrequencyInHz() const
{
    return frequencyInHz;
}

std::string StepFrequency::getStepFrequencyString()
{
    char formattedFrequency[6];
    snprintf(formattedFrequency, sizeof(formattedFrequency), "%05d", frequencyInHz);

    return formattedFrequency;
}