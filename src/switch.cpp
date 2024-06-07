#include "switch.h"

const int Switch::MAX_SWITCH_LENGTH = 3;

Switch::SwitchEnum Switch::StringToSwitch(const std::string &switchString)
{
    static const std::map<std::string, Switch::SwitchEnum> enumMap = {
        {"OFF", Switch::SwitchEnum::OFF},
        {"ON", Switch::SwitchEnum::ON}};

    auto it = enumMap.find(switchString);
    if (it != enumMap.end())
    {
        return it->second;
    }
    return SwitchEnum::UNKNOWN;
}

std::string Switch::SwitchToBoolString(const SwitchEnum &switchEnum)
{
    static const std::map<Switch::SwitchEnum, std::string> enumMap = {
        {Switch::SwitchEnum::OFF, "0"},
        {Switch::SwitchEnum::ON, "1"}};

    auto it = enumMap.find(switchEnum);
    if (it != enumMap.end())
    {
        return it->second;
    }
    return "UNKNOWN";
}

std::string Switch::SwitchToString(const SwitchEnum &switchEnum)
{
    static const std::map<Switch::SwitchEnum, std::string> enumMap = {
        {Switch::SwitchEnum::OFF, "OFF"},
        {Switch::SwitchEnum::ON, "ON"}};

    auto it = enumMap.find(switchEnum);
    if (it != enumMap.end())
    {
        return it->second;
    }
    return "UNKNOWN";
}