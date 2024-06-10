#include "frequency_unit.h"

FrequencyUnit::Unit FrequencyUnit::parseUnit(const std::string &unitStr)
{
    std::string lowerStr = Helpers::toLower(unitStr);
    if (lowerStr == "hz")
        return HZ;
    if (lowerStr == "khz")
        return KHZ;
    if (lowerStr == "mhz")
        return MHZ;
    if (lowerStr == "ghz")
        return GHZ;
    printf("Unknown frequency unit. Valid values are Hz, kHz, MHz or GHz.\n");
    return UNKNOWN;
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
        return 0;
    }
}
