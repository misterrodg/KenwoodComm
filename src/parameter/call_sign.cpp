#include "call_sign.h"

#include "core/error_code.h"

CallSign::CallSign() : callSign("") {}

core::Result<void> CallSign::setCallSign(const std::string &input)
{
    std::regex regex(R"(^[a-zA-Z0-9]{3,6}$)");
    std::smatch match;

    if (std::regex_match(input, regex))
    {
        callSign = Helpers::toUpper(input);
        return {};
    }

    return core::Error{core::ErrorCode::InvalidCallSign, "Invalid call sign format: '" + input +
                           "'. Expected 3 to 6 letters or digits."};
}

std::string CallSign::getCallSignString()
{
    return callSign;
}