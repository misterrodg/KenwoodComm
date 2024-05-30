#ifndef TONE_FREQUENCY_H
#define TONE_FREQUENCY_H

#include <string>
#include <cstdint>

class ToneFrequency
{
public:
    ToneFrequency();
    void setToneFrequency(const std::string &input);
    unsigned short int getToneFrequency() const;
    std::string getToneFrequencyString();

private:
    unsigned short int toneFrequency;
};

#endif