#include "step_frequency.h"

StepFrequency::StepFrequency() : frequencyInHz(0) {}

void StepFrequency::setStepFrequency(const std::string &input)
{
    std::regex regex(R"((\d{1,5}))");
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