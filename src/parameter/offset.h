#ifndef OFFSET_H
#define OFFSET_H

#include <map>
#include <string>

// Kenwood Parameter #13: Offset (SIMPLEX/PLUS/MINUS)

class Offset {
public:
    enum class OffsetEnum { SIMPLEX = 0, PLUS = 1, MINUS = 2, UNKNOWN = -1 };
    static OffsetEnum StringToOffset(const std::string& offsetString);
    static std::string OffsetToIntString(const OffsetEnum& offsetEnum);
    static std::string OffsetToString(const OffsetEnum& offsetEnum);
    static constexpr int MAX_OFFSET_LENGTH = 7;
};
#endif