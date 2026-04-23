#include "destination_code.h"

const int DestinationCode::MAX_CODE_LENGTH = 4;

DestinationCode::CodeEnum
DestinationCode::StringToCode(const std::string& codeString) {
    static const std::map<std::string, CodeEnum> enumMap = {
        {"MAIN", CodeEnum::MAIN},
        {"0", CodeEnum::MAIN},
        {"SUB", CodeEnum::SUB},
        {"1", CodeEnum::SUB},
    };

    auto it = enumMap.find(codeString);
    if (it != enumMap.end()) {
        return it->second;
    }
    return CodeEnum::UNKNOWN;
}

std::string DestinationCode::CodeToIntString(const CodeEnum& codeEnum) {
    char result[2];
    snprintf(result, sizeof(result), "%i", static_cast<int>(codeEnum));
    return result;
}

std::string DestinationCode::CodeToString(const CodeEnum& codeEnum) {
    static const std::map<CodeEnum, std::string> enumMap = {
        {CodeEnum::MAIN, "MAIN"},
        {CodeEnum::SUB, "SUB"},
    };

    auto it = enumMap.find(codeEnum);
    if (it != enumMap.end()) {
        return it->second;
    }
    return "UNKNOWN";
}
