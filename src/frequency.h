#ifndef FREQUENCY_H
#define FREQUENCY_H

#include <string>
#include <cstdint>

class Frequency
{
public:
    Frequency();
    void setFrequency(const std::string &input);
    uint64_t getFrequencyInHz() const;
    std::string getFrequencyString();

private:
    uint64_t frequencyInHz;
};

#endif