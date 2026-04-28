#include "frequency.h"

#include "core/error_code.h"
#include <cstdint>
#include <cstdio>

Frequency::Frequency() : frequencyInHz(0) {
}

core::Result<void> Frequency::setFrequency(const std::string& input) {
    std::regex regex(R"((\d+(\.\d+)?)\s*([a-zA-Z]+))");
    std::smatch match;

    if (std::regex_match(input, match, regex)) {
        double value = std::stod(match[1].str());
        std::string unit = match[3].str();

        FrequencyUnit::Unit frequencyUnit = FrequencyUnit::parseUnit(unit);
        if (frequencyUnit != FrequencyUnit::UNKNOWN) {
            frequencyInHz = FrequencyUnit::toHz(value, frequencyUnit);
            return {};
        }

        return core::Error{core::ErrorCode::InvalidFrequencyUnit,
                           "Unknown frequency unit '" + unit +
                               "'. Valid values are Hz, kHz, MHz or GHz."};
    }

    return core::Error{core::ErrorCode::InvalidFrequency,
                       "Invalid frequency format: '" + input +
                           "'. Expected <value><unit>, for example 145.5MHz."};
}

uint64_t Frequency::getFrequencyInHz() const {
    return frequencyInHz;
}

std::string Frequency::getFrequencyString() const {
    char formattedFrequency[12];
    snprintf(formattedFrequency, sizeof(formattedFrequency), "%011" PRIu64,
             frequencyInHz);

    return formattedFrequency;
}

std::string Frequency::getFrequencyDisplayString() const {
    double value = static_cast<double>(frequencyInHz);
    const char* unit = "Hz";

    if (frequencyInHz >= 1'000'000'000ULL) {
        value /= 1'000'000'000.0;
        unit = "GHz";
    } else if (frequencyInHz >= 1'000'000ULL) {
        value /= 1'000'000.0;
        unit = "MHz";
    } else if (frequencyInHz >= 1'000ULL) {
        value /= 1'000.0;
        unit = "kHz";
    }

    char formatted[32];
    snprintf(formatted, sizeof(formatted), "%.3f %s", value, unit);
    return formatted;
}
