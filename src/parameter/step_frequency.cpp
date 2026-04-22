#include "step_frequency.h"

#include "core/error_code.h"

StepFrequency::StepFrequency() : frequencyInHz(0) {}

core::Result<void> StepFrequency::setStepFrequency(const std::string &input)
{
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
                return {};
            }

            return core::Error{core::ErrorCode::ValueOutOfRange, "Step frequency must be between 0 and " +
                                   std::to_string(MAX_STEP_FREQUENCY_VALUE) +
                                   "Hz."};
        }

        return core::Error{core::ErrorCode::InvalidFrequencyUnit, "Step frequency unit must be Hz or kHz."};
    }

    return core::Error{core::ErrorCode::InvalidStepFrequency, "Invalid step frequency format: '" + input +
                           "'. Expected <value><unit>, for example 5kHz."};
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