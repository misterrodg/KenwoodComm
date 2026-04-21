#ifndef RESPONSE_H
#define RESPONSE_H

#include "command/command_prefix.h"
#include "core/result.h"
#include <string>

class Response {
public:
    Response(const std::string& responseString);
    CommandPrefix::CommandPrefixEnum GetCommandPrefix() const;
    std::string GetParameters() const;
    bool IsValid() const;
    core::Result<void> GetValidationResult() const;
    void ToConsole() const;
    static const int MAX_RESPONSE_LENGTH = 39;
    static const int MIN_RESPONSE_LENGTH = 3;

private:
    CommandPrefix::CommandPrefixEnum commandPrefixEnum;
    std::string parameters;
    core::Result<void> validationResult;
    core::Result<void> Parse(const std::string& responseString);
};

#endif
