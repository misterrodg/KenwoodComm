#ifndef CALL_SIGN_H
#define CALL_SIGN_H

#include "core/helpers.h"
#include "core/result.h"
#include <regex>
#include <string>

// Kenwood Parameter #15: Call Sign (with up to 8 characters, e.g. N0CALL)

class CallSign {
public:
    CallSign();
    core::Result<void> setCallSign(const std::string& input);
    std::string getCallSignString();

private:
    std::string callSign = "";
};

#endif