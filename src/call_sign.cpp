#include "call_sign.h"
#include <regex>
#include <stdexcept>

CallSign::CallSign() : callSign(0) {}

void CallSign::setCallSign(const std::string &input)
{
    std::regex regex(R"(^[a-zA-Z0-9]{3,6}$)");
    std::smatch match;

    if (std::regex_match(input, regex))
    {
        callSign = input;
    }
    else
    {
        throw std::invalid_argument("Invalid call sign format");
    }
}

std::string CallSign::getCallSignString()
{
    return callSign;
}