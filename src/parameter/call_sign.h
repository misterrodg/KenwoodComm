#ifndef CALL_SIGN_H
#define CALL_SIGN_H

#include "../helpers.h"
#include <regex>
#include <string>

class CallSign
{
public:
    CallSign();
    bool setCallSign(const std::string &input);
    std::string getCallSignString();

private:
    std::string callSign = "";
};

#endif