#ifndef TONE_FREQUENCY_H
#define TONE_FREQUENCY_H

#include <map>
#include <string>

class ToneFrequency
{
public:
    enum class ToneFrequencyEnum
    {
        TN01 = 1,
        TN02,
        TN03,
        TN04,
        TN05,
        TN06,
        TN07,
        TN08,
        TN09,
        TN10,
        TN11,
        TN12,
        TN13,
        TN14,
        TN15,
        TN16,
        TN17,
        TN18,
        TN19,
        TN20,
        TN21,
        TN22,
        TN23,
        TN24,
        TN25,
        TN26,
        TN27,
        TN28,
        TN29,
        TN30,
        TN31,
        TN32,
        TN33,
        TN34,
        TN35,
        TN36,
        TN37,
        TN38,
        UNKNOWN
    };
    static ToneFrequencyEnum StringToToneFrequency(const std::string &toneString);
    static std::string ToneFrequencyToFreqString(const ToneFrequencyEnum &toneEnum);
    static std::string ToneFrequencyToIntString(const ToneFrequencyEnum &toneEnum);
    static const int MAX_TONE_LENGTH;
};

#endif