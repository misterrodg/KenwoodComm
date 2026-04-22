#ifndef FREQUENCY_H
#define FREQUENCY_H

#include "core/result.h"
#include "frequency_unit.h"
#include <cinttypes>
#include <regex>
#include <string>

class Frequency
{
public:
    Frequency();
    core::Result<void> setFrequency(const std::string &input);
    uint64_t getFrequencyInHz() const;
    std::string getFrequencyString();
    static const int MAX_FREQUENCY_LENGTH;

private:
    uint64_t frequencyInHz;
};

#endif