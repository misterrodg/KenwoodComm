#ifndef RIT_FREQUENCY_H
#define RIT_FREQUENCY_H

#include "core/result.h"
#include "frequency_unit.h"
#include <cstdint>
#include <regex>
#include <string>

// Kenwood Parameter #5: RIT Frequency (in Hz, with a sign +/- and 4 digits,
// e.g. +5320 for +5.32 kHz)

class RITFrequency {
public:
    RITFrequency();
    core::Result<void> setRITFrequency(const std::string& input);
    short int getRITFrequencyInHz() const;
    std::string getRITFrequencyString();
    static constexpr int MAX_RIT_FREQUENCY_LENGTH = 5;
    static constexpr int MAX_RIT_FREQUENCY_VALUE = 9999;
    static const int MIN_RIT_FREQUENCY_VALUE = -9999;

private:
    short int frequencyInHz;
};

#endif