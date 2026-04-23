#include "busy.h"

const int Busy::MAX_BUSY_LENGTH = 3;

Busy::BusyEnum Busy::StringToBusy(const std::string& busyString) {
    static const std::map<std::string, Busy::BusyEnum> enumMap = {
        {"OFF", Busy::BusyEnum::OFF},
        {"0", Busy::BusyEnum::OFF},
        {"ON", Busy::BusyEnum::ON},
        {"1", Busy::BusyEnum::ON}};

    auto it = enumMap.find(busyString);
    if (it != enumMap.end()) {
        return it->second;
    }
    return BusyEnum::UNKNOWN;
}

std::string Busy::BusyToBoolString(const BusyEnum& busyEnum) {
    static const std::map<Busy::BusyEnum, std::string> enumMap = {
        {Busy::BusyEnum::OFF, "0"}, {Busy::BusyEnum::ON, "1"}};

    auto it = enumMap.find(busyEnum);
    if (it != enumMap.end()) {
        return it->second;
    }
    return "UNKNOWN";
}

std::string Busy::BusyToString(const BusyEnum& busyEnum) {
    static const std::map<Busy::BusyEnum, std::string> enumMap = {
        {Busy::BusyEnum::OFF, "OFF"}, {Busy::BusyEnum::ON, "ON"}};

    auto it = enumMap.find(busyEnum);
    if (it != enumMap.end()) {
        return it->second;
    }
    return "UNKNOWN";
}
