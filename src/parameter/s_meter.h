#ifndef S_METER_H
#define S_METER_H

#include "core/result.h"

#include <regex>
#include <string>

// Kenwood Parameter #22: S-Meter (0000 to 0015, with 0000 = S0, 0001 = S1, ...,
// 0015 = S9+60dB)

class SMeter {
public:
    SMeter();
    core::Result<void> setSMeter(const std::string& input);
    short int getSMeter() const;
    std::string getSMeterString();
    static constexpr int MAX_S_METER_LENGTH = 4;

private:
    short int sMeter;
};

#endif