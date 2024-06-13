#include "offset.h"

Offset::OffsetEnum Offset::StringToOffset(const std::string &offsetString)
{
    static const std::map<std::string, Offset::OffsetEnum> enumMap = {
        {"SIMPLEX", Offset::OffsetEnum::SIMPLEX},
        {"0", Offset::OffsetEnum::SIMPLEX},
        {"PLUS", Offset::OffsetEnum::PLUS},
        {"1", Offset::OffsetEnum::PLUS},
        {"MINUS", Offset::OffsetEnum::MINUS},
        {"2", Offset::OffsetEnum::MINUS}};

    auto it = enumMap.find(offsetString);
    if (it != enumMap.end())
    {
        return it->second;
    }
    printf("Unrecognized option. Options are: SIMPLEX, PLUS, or MINUS.\n");
    return Offset::OffsetEnum::UNKNOWN;
}

std::string Offset::OffsetToIntString(const OffsetEnum &offsetEnum)
{
    static const std::map<Offset::OffsetEnum, std::string> enumMap = {
        {Offset::OffsetEnum::SIMPLEX, "0"},
        {Offset::OffsetEnum::PLUS, "1"},
        {Offset::OffsetEnum::MINUS, "2"}};

    auto it = enumMap.find(offsetEnum);
    if (it != enumMap.end())
    {
        return it->second;
    }
    return "UNKNOWN";
}

std::string Offset::OffsetToString(const OffsetEnum &offsetEnum)
{
    static const std::map<Offset::OffsetEnum, std::string> enumMap = {
        {Offset::OffsetEnum::SIMPLEX, "SIMPLEX"},
        {Offset::OffsetEnum::PLUS, "PLUS"},
        {Offset::OffsetEnum::MINUS, "MINUS"}};

    auto it = enumMap.find(offsetEnum);
    if (it != enumMap.end())
    {
        return it->second;
    }
    return "UNKNOWN";
}