#ifndef PARAMETER_VALIDATOR_H
#define PARAMETER_VALIDATOR_H

#include "error_code.h"
#include "result.h"

#include <initializer_list>
#include <string>

class ParameterValidator {
public:
    static core::Result<void> validateNotEmpty(const std::string& param,
                                               const std::string& paramName) {
        if (param.empty()) {
            return core::Error{core::ErrorCode::ParameterEmpty, "Parameter '" + paramName +
                                   "' must not be empty"};
        }
        return {};
    }

    static core::Result<void>
    validateOneOf(const std::string& param, const std::string& paramName,
                  std::initializer_list<const char*> allowed) {
        for (const char* option : allowed) {
            if (param == option) {
                return {};
            }
        }
        std::string options;
        for (const char* option : allowed) {
            if (!options.empty())
                options += ", ";
            options += option;
        }
        return core::Error{core::ErrorCode::ParameterInvalid, "'" + param + "' is not a valid " + paramName +
                               ". Options are: " + options};
    }
};

#endif
