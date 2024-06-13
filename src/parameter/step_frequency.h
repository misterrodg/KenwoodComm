#ifndef STEP_FREQUENCY_H
#define STEP_FREQUENCY_H

#include "frequency_unit.h"
#include <cstdint>
#include <regex>
#include <string>

class StepFrequency
{
public:
    StepFrequency();
    bool setStepFrequency(const std::string &input);
    unsigned short int getStepFrequencyInHz() const;
    std::string getStepFrequencyString();
    static const int MAX_STEP_FREQUENCY_LENGTH = 5;
    static const int MAX_STEP_FREQUENCY_VALUE = 99999;

private:
    unsigned short int frequencyInHz;
};

#endif