#ifndef RITFREQUENCY_H
#define RITFREQUENCY_H

#include <string>
#include <cstdint>

class RITFrequency
{
public:
    RITFrequency();
    void setRITFrequency(const std::string &input);
    short int getRITFrequencyInHz() const;
    std::string getRITFrequencyString();

private:
    short int frequencyInHz;
};

#endif