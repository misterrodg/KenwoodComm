#ifndef StepFREQUENCY_H
#define StepFREQUENCY_H

#include <cstdint>
#include <regex>
#include <string>

class StepFrequency
{
public:
    StepFrequency();
    void setStepFrequency(const std::string &input);
    unsigned short int getStepFrequencyInHz() const;
    std::string getStepFrequencyString();

private:
    unsigned short int frequencyInHz;
};

#endif