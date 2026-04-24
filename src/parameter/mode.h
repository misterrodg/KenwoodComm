#ifndef MODE_H
#define MODE_H

#include <map>
#include <string>

// Kenwood Parameter #2: Mode (LSB/USB/CW/FM/AM/FSK/CWN)

class Mode {
public:
    enum class ModeEnum {
        LSB = 1,
        USB = 2,
        CW = 3,
        FM = 4,
        AM = 5,  // TS140S/680S/940S only
        FSK = 6, // TS940 only
        CWN = 7, // TS140S/680S only
        UNKNOWN = -1
    };
    static ModeEnum StringToMode(const std::string& modeString);
    static std::string ModeToString(const ModeEnum& modeEnum);
    static std::string ModeToIntString(const ModeEnum& ModeEnum);
    static constexpr int MAX_MODE_LENGTH = 3;
};

#endif