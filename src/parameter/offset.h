#ifndef OFFSET_H
#define OFFSET_H

#include <map>
#include <string>

class Offset
{
public:
    enum class OffsetEnum
    {
        SIMPLEX,
        PLUS,
        MINUS,
        UNKNOWN
    };
    static OffsetEnum StringToOffset(const std::string &offsetString);
    static std::string OffsetToIntString(const OffsetEnum &offsetEnum);
    static std::string OffsetToString(const OffsetEnum &offsetEnum);
    static const int MAX_OFFSET_LENGTH = 7;
};
#endif