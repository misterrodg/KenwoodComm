#ifndef FREQUENCY_UNIT_H
#define FREQUENCY_UNIT_H

#include <string>

class FrequencyUnit
{
public:
    enum Unit
    {
        HZ,
        KHZ,
        MHZ,
        GHZ
    };
    static Unit parseUnit(const std::string &unitStr);
    static double toHz(double value, Unit unit);

private:
    static std::string toLower(const std::string &str);
};

#endif
