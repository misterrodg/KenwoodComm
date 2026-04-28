#ifndef DESTINATION_CODE_H
#define DESTINATION_CODE_H

#include <map>
#include <string>

// Kenwood Parameter #21: Destination Code (MAIN/SUB)

class DestinationCode {
public:
    enum class CodeEnum { MAIN = 0, SUB = 1, UNKNOWN = -1 };
    static CodeEnum StringToCode(const std::string& codeString);
    static std::string CodeToString(const CodeEnum& codeEnum);
    static std::string CodeToFriendlyString(const CodeEnum& codeEnum);
    static std::string CodeToIntString(const CodeEnum& codeEnum);
    static constexpr int MAX_CODE_LENGTH = 4;
};

#endif
