#ifndef COMMAND_RESULT_H
#define COMMAND_RESULT_H

#include "core/error_code.h"
#include "core/result.h"

#include <string>

using CommandResult = core::Result<void>;

inline CommandResult Error(const std::string& code,
                           const std::string& message) {
    return core::Error{code, message};
}

inline CommandResult Error(core::ErrorCode code, const std::string& message) {
    return core::Error{code, message};
}

inline CommandResult Error(const std::string& message) {
    return core::Error{core::ErrorCode::CommandError, message};
}

inline CommandResult OK() {
    return CommandResult();
}

#endif

