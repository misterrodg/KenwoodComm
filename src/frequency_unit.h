#ifndef FREQUENCY_UNIT_H
#define FREQUENCY_UNIT_H

#include "helpers.h"
#include <string>

class FrequencyUnit
{
public:
    enum Unit
    {
        HZ,
        KHZ,
        MHZ,
        GHZ,
        UNKNOWN
    };
    static Unit parseUnit(const std::string &unitStr);
    static double toHz(double value, Unit unit);
};

#endif
