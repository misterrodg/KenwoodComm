#include "mode.h"

const int Mode::MAX_MODE_LENGTH = 3;

Mode::ModeEnum Mode::StringToMode(const std::string &modeString)
{
    static const std::map<std::string, Mode::ModeEnum> enumMap = {
        {"LSB", Mode::ModeEnum::LSB},
        {"1", Mode::ModeEnum::LSB},
        {"USB", Mode::ModeEnum::USB},
        {"2", Mode::ModeEnum::USB},
        {"CW", Mode::ModeEnum::CW},
        {"3", Mode::ModeEnum::CW},
        {"FM", Mode::ModeEnum::FM},
        {"4", Mode::ModeEnum::FM},
        {"AM", Mode::ModeEnum::AM},
        {"5", Mode::ModeEnum::AM},
        {"FSK", Mode::ModeEnum::FSK},
        {"6", Mode::ModeEnum::FSK},
        {"CWN", Mode::ModeEnum::CWN},
        {"7", Mode::ModeEnum::CWN},
    };

    auto it = enumMap.find(modeString);
    if (it != enumMap.end())
    {
        return it->second;
    }
    printf("Unrecognized option. Options are: LSB, USB, CW, FM, AM, FSK, or CWN.\n");
    return ModeEnum::UNKNOWN;
}

std::string Mode::ModeToIntString(const ModeEnum &modeEnum)
{
    char result[2];
    snprintf(result, sizeof(result), "%i", static_cast<int>(modeEnum));
    return result;
}

std::string Mode::ModeToString(const ModeEnum &modeEnum)
{
    static const std::map<Mode::ModeEnum, std::string> enumMap = {
        {Mode::ModeEnum::LSB, "LSB"},
        {Mode::ModeEnum::USB, "USB"},
        {Mode::ModeEnum::CW, "CW"},
        {Mode::ModeEnum::FM, "FM"},
        {Mode::ModeEnum::AM, "AM"},
        {Mode::ModeEnum::FSK, "FSK"},
        {Mode::ModeEnum::CWN, "CWN"},
    };

    auto it = enumMap.find(modeEnum);
    if (it != enumMap.end())
    {
        return it->second;
    }
    return "UNKNOWN";
}