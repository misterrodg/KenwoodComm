#include "response.h"
#include <cstring>

Response::Response(const std::string& responseString)
    : commandPrefixEnum(CommandPrefix::CommandPrefixEnum::ZZ), parameters(""),
      validationResult(ResponseError::EMPTY_RESPONSE, "Empty response") {
    validationResult = Parse(responseString);
}

ResponseResult Response::Parse(const std::string& responseString) {
    if (responseString.empty()) {
        return ResponseResult::Error(ResponseError::EMPTY_RESPONSE,
                                     "Response is empty");
    }

    if (responseString.length() < MIN_RESPONSE_LENGTH) {
        return ResponseResult::Error(ResponseError::INVALID_FORMAT,
                                     "Response too short");
    }

    if (responseString.back() != ';') {
        return ResponseResult::Error(ResponseError::MISSING_TERMINATOR,
                                     "Response missing terminator");
    }

    std::string prefixStr =
        responseString.substr(0, CommandPrefix::COMMAND_LENGTH);
    CommandPrefix::CommandPrefixEnum prefix =
        CommandPrefix::StringToCommandPrefix(prefixStr);

    if (prefix == CommandPrefix::CommandPrefixEnum::ZZ) {
        return ResponseResult::Error(ResponseError::INVALID_COMMAND_PREFIX,
                                     "Unknown command prefix: " + prefixStr);
    }

    size_t endPos = responseString.find(';');
    if (endPos == std::string::npos) {
        return ResponseResult::Error(
            ResponseError::MISSING_TERMINATOR,
            "Malformed response: terminator not found");
    }

    commandPrefixEnum = prefix;
    parameters = responseString.substr(CommandPrefix::COMMAND_LENGTH,
                                       endPos - CommandPrefix::COMMAND_LENGTH);

    return ResponseResult::OK();
}

CommandPrefix::CommandPrefixEnum Response::GetCommandPrefix() const {
    return commandPrefixEnum;
}

std::string Response::GetParameters() const {
    return parameters;
}

bool Response::IsValid() const {
    return validationResult.IsSuccess();
}

ResponseResult Response::GetValidationResult() const {
    return validationResult;
}

void Response::ToConsole() const {
    if (IsValid()) {
        printf(
            "Response: %s\nParameters: %s\n",
            CommandPrefix::CommandToStringExpanded(commandPrefixEnum).c_str(),
            parameters.c_str());
    } else {
        printf("Invalid Response: %s\n",
               validationResult.GetErrorMessage().c_str());
    }
}

