#ifndef ERROR_H
#define ERROR_H

#include <optional>
#include <string>

// std::nullopt = success
// std::optional<std::string> = error message
using CommandResult = std::optional<std::string>;

inline CommandResult Error(const std::string& message) {
    return std::make_optional(message);
}

inline CommandResult OK() {
    return std::nullopt;
}

#endif

