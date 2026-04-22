#include "response.h"

#include "core/error_code.h"
#include "core/error_reporter.h"
#include "core/result.h"
#include <cstring>

Response::Response(const std::string& responseString)
    : commandPrefixEnum(CommandPrefix::CommandPrefixEnum::ZZ), parameters(""),
      validationResult(core::Error{core::ErrorCode::EmptyResponse, "Empty response"}) {
    validationResult = Parse(responseString);
}

core::Result<void> Response::Parse(const std::string& responseString) {
    if (responseString.empty()) {
        return core::Error{core::ErrorCode::EmptyResponse, "Response is empty"};
    }

    if (responseString.length() < MIN_RESPONSE_LENGTH) {
        return core::Error{core::ErrorCode::InvalidFormat, "Response too short"};
    }

    if (responseString.back() != ';') {
        return core::Error{core::ErrorCode::MissingTerminator, "Response missing terminator"};
    }

    std::string prefixStr =
        responseString.substr(0, CommandPrefix::COMMAND_LENGTH);
    CommandPrefix::CommandPrefixEnum prefix =
        CommandPrefix::StringToCommandPrefix(prefixStr);

    if (prefix == CommandPrefix::CommandPrefixEnum::ZZ) {
        return core::Error{core::ErrorCode::InvalidCommandPrefix, "Unknown command prefix: " + prefixStr};
    }

    size_t endPos = responseString.find(';');
    if (endPos == std::string::npos) {
        return core::Error{core::ErrorCode::MissingTerminator, "Malformed response: terminator not found"};
    }

    commandPrefixEnum = prefix;
    parameters = responseString.substr(CommandPrefix::COMMAND_LENGTH,
                                       endPos - CommandPrefix::COMMAND_LENGTH);

    return core::Result<void>();
}

CommandPrefix::CommandPrefixEnum Response::GetCommandPrefix() const {
    return commandPrefixEnum;
}

std::string Response::GetParameters() const {
    return parameters;
}

bool Response::IsValid() const {
    return validationResult.OK();
}

core::Result<void> Response::GetValidationResult() const {
    return validationResult;
}

void Response::ToConsole() const {
    if (IsValid()) {
        printf(
            "Response: %s\nParameters: %s\n",
            CommandPrefix::CommandToStringExpanded(commandPrefixEnum).c_str(),
            parameters.c_str());
    } else {
        printError(validationResult.error());
    }
}

