#include "s_meter.h"

#include "core/error_code.h"

SMeter::SMeter() : sMeter(0) {
}

core::Result<void> SMeter::setSMeter(const std::string& input) {
    std::regex regex(R"((\d{4}))");
    std::smatch match;

    if (std::regex_match(input, regex)) {
        int value = std::stoi(input);
        if (value >= 0 && value <= 15) {
            sMeter = value;
            return {};
        }
    }

    return core::Error{
        core::ErrorCode::InvalidSMeter,
        "Invalid S-Meter format: '" + input +
            "'. Expected a 4 digit number between 0000 and 0015."};
}

short int SMeter::getSMeter() const {
    return sMeter;
}

std::string SMeter::getSMeterString() {
    char formattedSMeter[5];
    snprintf(formattedSMeter, sizeof(formattedSMeter), "%04d", sMeter);

    return formattedSMeter;
}