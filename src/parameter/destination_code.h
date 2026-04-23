#ifndef DESTINATION_CODE_H
#define DESTINATION_CODE_H

#include <map>
#include <string>

class DestinationCode {
public:
    enum class CodeEnum { MAIN, SUB, UNKNOWN };
    static CodeEnum StringToCode(const std::string& codeString);
    static std::string CodeToString(const CodeEnum& codeEnum);
    static std::string CodeToIntString(const CodeEnum& codeEnum);
    static const int MAX_CODE_LENGTH;
};

#endif
