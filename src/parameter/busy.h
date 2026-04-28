#ifndef BUSY_H
#define BUSY_H

#include <map>
#include <string>

// Kenwood Parameter #20: Busy (ON/OFF)

class Busy {
public:
    enum class BusyEnum { OFF = 0, ON = 1, UNKNOWN = -1 };
    static BusyEnum StringToBusy(const std::string& busyString);
    static std::string BusyToBoolString(const BusyEnum& busyEnum);
    static std::string BusyToString(const BusyEnum& busyEnum);
    static std::string BusyToFriendlyString(const BusyEnum& busyEnum);
    static constexpr int MAX_BUSY_LENGTH = 3;
};

#endif
