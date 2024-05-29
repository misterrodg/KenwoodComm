#include "frequency_unit.h"
#include <algorithm>
#include <stdexcept>

std::string FrequencyUnit::toLower(const std::string &str)
{
    std::string lowerStr = str;
    std::transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
    return lowerStr;
}

FrequencyUnit::Unit FrequencyUnit::parseUnit(const std::string &unitStr)
{
    std::string lowerStr = toLower(unitStr);
    if (lowerStr == "hz")
        return HZ;
    if (lowerStr == "khz")
        return KHZ;
    if (lowerStr == "mhz")
        return MHZ;
    if (lowerStr == "ghz")
        return GHZ;
}

double FrequencyUnit::toHz(double value, Unit unit)
{
    switch (unit)
    {
    case HZ:
        return value;
    case KHZ:
        return value * 1e3;
    case MHZ:
        return value * 1e6;
    case GHZ:
        return value * 1e9;
    default:
        throw std::invalid_argument("Unknown frequency unit. Valid values are Hz, kHz, MHz or GHz.");
    }
}
