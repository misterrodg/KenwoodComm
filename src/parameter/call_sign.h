#ifndef CALL_SIGN_H
#define CALL_SIGN_H

#include "core/helpers.h"
#include "core/result.h"
#include <regex>
#include <string>

class CallSign
{
public:
    CallSign();
    core::Result<void> setCallSign(const std::string &input);
    std::string getCallSignString();

private:
    std::string callSign = "";
};

#endif