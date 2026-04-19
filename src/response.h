#ifndef RESPONSE_H
#define RESPONSE_H

#include "command/command_prefix.h"
#include "response_result.h"
#include <optional>
#include <string>

class Response {
public:
    Response(const std::string& responseString);
    CommandPrefix::CommandPrefixEnum GetCommandPrefix() const;
    std::string GetParameters() const;
    bool IsValid() const;
    ResponseResult GetValidationResult() const;
    void ToConsole() const;
    static const int MAX_RESPONSE_LENGTH = 39;
    static const int MIN_RESPONSE_LENGTH = 3;

private:
    CommandPrefix::CommandPrefixEnum commandPrefixEnum;
    std::string parameters;
    ResponseResult validationResult;
    ResponseResult Parse(const std::string& responseString);
};

#endif
