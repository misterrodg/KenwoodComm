#include "response_result.h"

ResponseResult::ResponseResult()
    : success(true), error(std::nullopt), errorMessage("") {
}

ResponseResult::ResponseResult(ResponseError err, const std::string& message)
    : success(false), error(err), errorMessage(message) {
}

bool ResponseResult::IsSuccess() const {
    return success;
}

bool ResponseResult::IsError() const {
    return !success;
}

ResponseError ResponseResult::GetError() const {
    return error.value_or(ResponseError::EMPTY_RESPONSE);
}

std::string ResponseResult::GetErrorMessage() const {
    return errorMessage;
}

ResponseResult ResponseResult::OK() {
    return ResponseResult();
}

ResponseResult ResponseResult::Error(ResponseError err,
                                     const std::string& msg) {
    return ResponseResult(err, msg);
}
