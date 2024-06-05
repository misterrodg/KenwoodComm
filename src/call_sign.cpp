#include "call_sign.h"
#include <regex>

CallSign::CallSign() : callSign(0) {}

bool CallSign::setCallSign(const std::string &input)
{
    bool result = false;

    std::regex regex(R"(^[a-zA-Z0-9]{3,6}$)");
    std::smatch match;

    if (std::regex_match(input, regex))
    {
        result = true;
    }
    else
    {
        printf("Invalid call sign format.\n");
    }

    return result;
}

std::string CallSign::getCallSignString()
{
    return callSign;
}