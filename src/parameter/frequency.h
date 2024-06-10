#ifndef FREQUENCY_H
#define FREQUENCY_H

#include "frequency_unit.h"
#include <string>
#include <cstdint>
#include <regex>

class Frequency
{
public:
    Frequency();
    bool setFrequency(const std::string &input);
    uint64_t getFrequencyInHz() const;
    std::string getFrequencyString();
    static const int MAX_FREQUENCY_LENGTH;

private:
    uint64_t frequencyInHz;
};

#endif