#ifndef TONE_FREQUENCY_H
#define TONE_FREQUENCY_H

#include <map>
#include <string>

// Kenwood Parameter #14: Tone Frequency (01 to 39)

class ToneFrequency {
public:
    enum class ToneFrequencyEnum {
        TN01 = 1,
        TN02 = 2,
        TN03 = 3,
        TN04 = 4,
        TN05 = 5,
        TN06 = 6,
        TN07 = 7,
        TN08 = 8,
        TN09 = 9,
        TN10 = 10,
        TN11 = 11,
        TN12 = 12,
        TN13 = 13,
        TN14 = 14,
        TN15 = 15,
        TN16 = 16,
        TN17 = 17,
        TN18 = 18,
        TN19 = 19,
        TN20 = 20,
        TN21 = 21,
        TN22 = 22,
        TN23 = 23,
        TN24 = 24,
        TN25 = 25,
        TN26 = 26,
        TN27 = 27,
        TN28 = 28,
        TN29 = 29,
        TN30 = 30,
        TN31 = 31,
        TN32 = 32,
        TN33 = 33,
        TN34 = 34,
        TN35 = 35,
        TN36 = 36,
        TN37 = 37,
        TN38 = 38,
        TN39 = 39,
        UNKNOWN = -1,
    };
    static ToneFrequencyEnum
    StringToToneFrequency(const std::string& toneString);
    static std::string
    ToneFrequencyToFreqString(const ToneFrequencyEnum& toneEnum);
    static std::string
    ToneFrequencyToIntString(const ToneFrequencyEnum& toneEnum);
    static std::string
    ToneFrequencyToFriendlyString(const ToneFrequencyEnum& toneEnum);
    static constexpr int MAX_TONE_LENGTH = 2;
};

#endif