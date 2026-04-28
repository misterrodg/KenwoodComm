#ifndef FREQUENCY_H
#define FREQUENCY_H

#include "core/result.h"
#include "frequency_unit.h"
#include <cinttypes>
#include <regex>
#include <string>

// Kenwood Parameter #4: Frequency (in Hz, with 11 digits, e.g. 00144000000 for
// 144 MHz)

class Frequency {
public:
    Frequency();
    core::Result<void> setFrequency(const std::string& input);
    uint64_t getFrequencyInHz() const;
    std::string getFrequencyString() const;
    std::string getFrequencyDisplayString() const;
    static constexpr int MAX_FREQUENCY_LENGTH = 11;

private:
    uint64_t frequencyInHz;
};

#endif
