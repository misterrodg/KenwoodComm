#include "rit_frequency.h"

#include "core/error_code.h"

RITFrequency::RITFrequency() : frequencyInHz(0) {}

core::Result<void> RITFrequency::setRITFrequency(const std::string &input)
{
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
                return {};
            }

            return core::Error{core::ErrorCode::ValueOutOfRange, "RIT frequency must be between " +
                                   std::to_string(MIN_RIT_FREQUENCY_VALUE) +
                                   "Hz and " +
                                   std::to_string(MAX_RIT_FREQUENCY_VALUE) +
                                   "Hz."};
        }

        return core::Error{core::ErrorCode::InvalidFrequencyUnit, "RIT frequency unit must be Hz or kHz."};
    }

    return core::Error{core::ErrorCode::InvalidRitFrequency, "Invalid RIT frequency format: '" + input +
                           "'. Expected <signed value><unit>, for example +1.2kHz."};
}

short int RITFrequency::getRITFrequencyInHz() const
{
    return frequencyInHz;
}

std::string RITFrequency::getRITFrequencyString()
{
    char formattedFrequency[7];
    snprintf(formattedFrequency, sizeof(formattedFrequency), "%+05d", frequencyInHz);

    return formattedFrequency;
}