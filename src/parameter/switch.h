#ifndef SWITCH_H
#define SWITCH_H

#include <map>
#include <string>

// Kenwood Parameter #1: Switch (ON/OFF)

class Switch {
public:
    enum class SwitchEnum { OFF = 0, ON = 1, UNKNOWN = -1 };
    static SwitchEnum StringToSwitch(const std::string& switchString);
    static std::string SwitchToBoolString(const SwitchEnum& switchEnum);
    static std::string SwitchToString(const SwitchEnum& switchEnum);
    static std::string SwitchToFriendlyString(const SwitchEnum& switchEnum);
    static constexpr int MAX_SWITCH_LENGTH = 3;
};

#endif