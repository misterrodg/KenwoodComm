#ifndef MODE_H
#define MODE_H

#include <map>
#include <string>

class Mode
{
public:
    enum class ModeEnum
    {
        LSB = 1,
        USB,
        CW,
        FM,
        AM,  // TS140S/680S/940S only
        FSK, // TS940 only
        CWN, // TS140S/680S only
        UNKNOWN
    };
    static ModeEnum StringToMode(const std::string &modeString);
    static std::string ModeToString(const ModeEnum &modeEnum);
    static std::string ModeToIntString(const ModeEnum &ModeEnum);
    static const int MAX_MODE_LENGTH;
};

#endif