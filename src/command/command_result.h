#ifndef COMMAND_RESULT_H
#define COMMAND_RESULT_H

#include "core/result.h"

#include <string>

using CommandResult = core::Result<void>;

inline CommandResult Error(const std::string& code,
                           const std::string& message) {
    return core::Error{code, message};
}

inline CommandResult Error(const std::string& message) {
    return core::Error{"COMMAND_ERROR", message};
}

inline CommandResult OK() {
    return CommandResult();
}

#endif

