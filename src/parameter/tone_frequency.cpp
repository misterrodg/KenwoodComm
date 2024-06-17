#include "tone_frequency.h"

const int ToneFrequency::MAX_TONE_LENGTH = 2;

ToneFrequency::ToneFrequencyEnum ToneFrequency::StringToToneFrequency(const std::string &toneString)
{
    static const std::map<std::string, ToneFrequency::ToneFrequencyEnum> enumMap = {
        {"01", ToneFrequency::ToneFrequencyEnum::TN01},
        {"67.0", ToneFrequency::ToneFrequencyEnum::TN01},
        {"02", ToneFrequency::ToneFrequencyEnum::TN02},
        {"71.9", ToneFrequency::ToneFrequencyEnum::TN02},
        {"03", ToneFrequency::ToneFrequencyEnum::TN03},
        {"74.4", ToneFrequency::ToneFrequencyEnum::TN03},
        {"04", ToneFrequency::ToneFrequencyEnum::TN04},
        {"77.0", ToneFrequency::ToneFrequencyEnum::TN04},
        {"05", ToneFrequency::ToneFrequencyEnum::TN05},
        {"79.7", ToneFrequency::ToneFrequencyEnum::TN05},
        {"06", ToneFrequency::ToneFrequencyEnum::TN06},
        {"82.5", ToneFrequency::ToneFrequencyEnum::TN06},
        {"07", ToneFrequency::ToneFrequencyEnum::TN07},
        {"85.4", ToneFrequency::ToneFrequencyEnum::TN07},
        {"08", ToneFrequency::ToneFrequencyEnum::TN08},
        {"88.5", ToneFrequency::ToneFrequencyEnum::TN08},
        {"09", ToneFrequency::ToneFrequencyEnum::TN09},
        {"91.5", ToneFrequency::ToneFrequencyEnum::TN09},
        {"10", ToneFrequency::ToneFrequencyEnum::TN10},
        {"94.8", ToneFrequency::ToneFrequencyEnum::TN10},
        {"11", ToneFrequency::ToneFrequencyEnum::TN11},
        {"97.4", ToneFrequency::ToneFrequencyEnum::TN11},
        {"12", ToneFrequency::ToneFrequencyEnum::TN12},
        {"100.0", ToneFrequency::ToneFrequencyEnum::TN12},
        {"13", ToneFrequency::ToneFrequencyEnum::TN13},
        {"103.5", ToneFrequency::ToneFrequencyEnum::TN13},
        {"14", ToneFrequency::ToneFrequencyEnum::TN14},
        {"107.2", ToneFrequency::ToneFrequencyEnum::TN14},
        {"15", ToneFrequency::ToneFrequencyEnum::TN15},
        {"110.9", ToneFrequency::ToneFrequencyEnum::TN15},
        {"16", ToneFrequency::ToneFrequencyEnum::TN16},
        {"114.8", ToneFrequency::ToneFrequencyEnum::TN16},
        {"17", ToneFrequency::ToneFrequencyEnum::TN17},
        {"118.8", ToneFrequency::ToneFrequencyEnum::TN17},
        {"18", ToneFrequency::ToneFrequencyEnum::TN18},
        {"123.0", ToneFrequency::ToneFrequencyEnum::TN18},
        {"19", ToneFrequency::ToneFrequencyEnum::TN19},
        {"127.3", ToneFrequency::ToneFrequencyEnum::TN19},
        {"20", ToneFrequency::ToneFrequencyEnum::TN20},
        {"131.8", ToneFrequency::ToneFrequencyEnum::TN20},
        {"21", ToneFrequency::ToneFrequencyEnum::TN21},
        {"136.5", ToneFrequency::ToneFrequencyEnum::TN21},
        {"22", ToneFrequency::ToneFrequencyEnum::TN22},
        {"141.3", ToneFrequency::ToneFrequencyEnum::TN22},
        {"23", ToneFrequency::ToneFrequencyEnum::TN23},
        {"146.2", ToneFrequency::ToneFrequencyEnum::TN23},
        {"24", ToneFrequency::ToneFrequencyEnum::TN24},
        {"151.4", ToneFrequency::ToneFrequencyEnum::TN24},
        {"25", ToneFrequency::ToneFrequencyEnum::TN25},
        {"156.7", ToneFrequency::ToneFrequencyEnum::TN25},
        {"26", ToneFrequency::ToneFrequencyEnum::TN26},
        {"162.2", ToneFrequency::ToneFrequencyEnum::TN26},
        {"27", ToneFrequency::ToneFrequencyEnum::TN27},
        {"167.9", ToneFrequency::ToneFrequencyEnum::TN27},
        {"28", ToneFrequency::ToneFrequencyEnum::TN28},
        {"173.8", ToneFrequency::ToneFrequencyEnum::TN28},
        {"29", ToneFrequency::ToneFrequencyEnum::TN29},
        {"179.9", ToneFrequency::ToneFrequencyEnum::TN29},
        {"30", ToneFrequency::ToneFrequencyEnum::TN30},
        {"186.2", ToneFrequency::ToneFrequencyEnum::TN30},
        {"31", ToneFrequency::ToneFrequencyEnum::TN31},
        {"192.8", ToneFrequency::ToneFrequencyEnum::TN31},
        {"32", ToneFrequency::ToneFrequencyEnum::TN32},
        {"203.5", ToneFrequency::ToneFrequencyEnum::TN32},
        {"33", ToneFrequency::ToneFrequencyEnum::TN33},
        {"210.7", ToneFrequency::ToneFrequencyEnum::TN33},
        {"34", ToneFrequency::ToneFrequencyEnum::TN34},
        {"218.1", ToneFrequency::ToneFrequencyEnum::TN34},
        {"35", ToneFrequency::ToneFrequencyEnum::TN35},
        {"225.7", ToneFrequency::ToneFrequencyEnum::TN35},
        {"36", ToneFrequency::ToneFrequencyEnum::TN36},
        {"233.6", ToneFrequency::ToneFrequencyEnum::TN36},
        {"37", ToneFrequency::ToneFrequencyEnum::TN37},
        {"241.8", ToneFrequency::ToneFrequencyEnum::TN37},
        {"38", ToneFrequency::ToneFrequencyEnum::TN38},
        {"250.3", ToneFrequency::ToneFrequencyEnum::TN38},
        {"399", ToneFrequency::ToneFrequencyEnum::TN39},
        {"1750.0", ToneFrequency::ToneFrequencyEnum::TN39},
    };

    auto it = enumMap.find(toneString);
    if (it != enumMap.end())
    {
        return it->second;
    }
    printf("Unrecognized tone. Tones are: 01-38.\n");
    return ToneFrequencyEnum::UNKNOWN;
}

std::string ToneFrequency::ToneFrequencyToIntString(const ToneFrequencyEnum &toneEnum)
{
    char result[3];
    snprintf(result, sizeof(result), "%02d", static_cast<int>(toneEnum));
    return result;
}

std::string ToneFrequency::ToneFrequencyToFreqString(const ToneFrequencyEnum &toneEnum)
{
    static const std::map<ToneFrequency::ToneFrequencyEnum, std::string> enumMap = {
        {ToneFrequency::ToneFrequencyEnum::TN01, "67.0"},
        {ToneFrequency::ToneFrequencyEnum::TN02, "71.9"},
        {ToneFrequency::ToneFrequencyEnum::TN03, "74.4"},
        {ToneFrequency::ToneFrequencyEnum::TN04, "77.0"},
        {ToneFrequency::ToneFrequencyEnum::TN05, "79.7"},
        {ToneFrequency::ToneFrequencyEnum::TN06, "82.5"},
        {ToneFrequency::ToneFrequencyEnum::TN07, "85.4"},
        {ToneFrequency::ToneFrequencyEnum::TN08, "88.5"},
        {ToneFrequency::ToneFrequencyEnum::TN09, "91.5"},
        {ToneFrequency::ToneFrequencyEnum::TN10, "94.8"},
        {ToneFrequency::ToneFrequencyEnum::TN11, "97.4"},
        {ToneFrequency::ToneFrequencyEnum::TN12, "100.0"},
        {ToneFrequency::ToneFrequencyEnum::TN13, "103.5"},
        {ToneFrequency::ToneFrequencyEnum::TN14, "107.2"},
        {ToneFrequency::ToneFrequencyEnum::TN15, "110.9"},
        {ToneFrequency::ToneFrequencyEnum::TN16, "114.8"},
        {ToneFrequency::ToneFrequencyEnum::TN17, "118.8"},
        {ToneFrequency::ToneFrequencyEnum::TN18, "123.0"},
        {ToneFrequency::ToneFrequencyEnum::TN19, "127.3"},
        {ToneFrequency::ToneFrequencyEnum::TN20, "131.8"},
        {ToneFrequency::ToneFrequencyEnum::TN21, "136.5"},
        {ToneFrequency::ToneFrequencyEnum::TN22, "141.3"},
        {ToneFrequency::ToneFrequencyEnum::TN23, "146.2"},
        {ToneFrequency::ToneFrequencyEnum::TN24, "151.4"},
        {ToneFrequency::ToneFrequencyEnum::TN25, "156.7"},
        {ToneFrequency::ToneFrequencyEnum::TN26, "162.2"},
        {ToneFrequency::ToneFrequencyEnum::TN27, "167.9"},
        {ToneFrequency::ToneFrequencyEnum::TN28, "173.8"},
        {ToneFrequency::ToneFrequencyEnum::TN29, "179.9"},
        {ToneFrequency::ToneFrequencyEnum::TN30, "186.2"},
        {ToneFrequency::ToneFrequencyEnum::TN31, "192.8"},
        {ToneFrequency::ToneFrequencyEnum::TN32, "203.5"},
        {ToneFrequency::ToneFrequencyEnum::TN33, "210.7"},
        {ToneFrequency::ToneFrequencyEnum::TN34, "218.1"},
        {ToneFrequency::ToneFrequencyEnum::TN35, "225.7"},
        {ToneFrequency::ToneFrequencyEnum::TN36, "233.6"},
        {ToneFrequency::ToneFrequencyEnum::TN37, "241.8"},
        {ToneFrequency::ToneFrequencyEnum::TN38, "250.3"},
        {ToneFrequency::ToneFrequencyEnum::TN39, "1750.0"},
    };

    auto it = enumMap.find(toneEnum);
    if (it != enumMap.end())
    {
        return it->second;
    }
    return "UNKNOWN";
}