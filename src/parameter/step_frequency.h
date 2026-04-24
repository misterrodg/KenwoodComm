#ifndef STEP_FREQUENCY_H
#define STEP_FREQUENCY_H

#include "core/result.h"
#include "frequency_unit.h"
#include <cstdint>
#include <regex>
#include <string>

// Kenwood Parameter #6: Step Frequency (in Hz, with 5 digits, e.g. 00025 for 25
// Hz)

class StepFrequency {
public:
    StepFrequency();
    core::Result<void> setStepFrequency(const std::string& input);
    unsigned short int getStepFrequencyInHz() const;
    std::string getStepFrequencyString();
    static constexpr int MAX_STEP_FREQUENCY_LENGTH = 5;
    static const unsigned int MAX_STEP_FREQUENCY_VALUE = 99999;

private:
    unsigned int frequencyInHz;
};

#endif