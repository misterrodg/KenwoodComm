#ifndef SWITCH_H
#define SWITCH_H

#include <map>
#include <string>

class Switch
{
public:
    enum class SwitchEnum
    {
        OFF,
        ON,
        UNKNOWN
    };
    static SwitchEnum StringToSwitch(const std::string &switchString);
    static std::string SwitchToString(const SwitchEnum &switchEnum);
    static const int MAX_SWITCH_LENGTH;
};

#endif