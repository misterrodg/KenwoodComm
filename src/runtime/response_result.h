#ifndef RESPONSE_RESULT_H
#define RESPONSE_RESULT_H

#include <optional>
#include <string>

enum class ResponseError {
    INVALID_FORMAT,
    INVALID_COMMAND_PREFIX,
    MISSING_TERMINATOR,
    EMPTY_RESPONSE,
    TIMEOUT
};

class ResponseResult {
private:
    bool success;
    std::optional<ResponseError> error;
    std::string errorMessage;

public:
    ResponseResult();
    explicit ResponseResult(ResponseError err, const std::string& message);
    bool IsSuccess() const;
    bool IsError() const;
    ResponseError GetError() const;
    std::string GetErrorMessage() const;
    static ResponseResult OK();
    static ResponseResult Error(ResponseError err, const std::string& msg);
};

#endif
