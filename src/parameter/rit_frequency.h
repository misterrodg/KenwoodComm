#ifndef RIT_FREQUENCY_H
#define RIT_FREQUENCY_H

#include "frequency_unit.h"
#include <cstdint>
#include <regex>
#include <string>

class RITFrequency
{
public:
    RITFrequency();
    bool setRITFrequency(const std::string &input);
    short int getRITFrequencyInHz() const;
    std::string getRITFrequencyString();
    static const int MAX_RIT_FREQUENCY_LENGTH = 5;
    static const int MAX_RIT_FREQUENCY_VALUE = 9999;
    static const int MIN_RIT_FREQUENCY_VALUE = -9999;

private:
    short int frequencyInHz;
};

#endif