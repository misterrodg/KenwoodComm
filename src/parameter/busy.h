#ifndef BUSY_H
#define BUSY_H

#include <map>
#include <string>

class Busy {
public:
    enum class BusyEnum { OFF, ON, UNKNOWN };
    static BusyEnum StringToBusy(const std::string& busyString);
    static std::string BusyToBoolString(const BusyEnum& busyEnum);
    static std::string BusyToString(const BusyEnum& busyEnum);
    static const int MAX_BUSY_LENGTH;
};

#endif
