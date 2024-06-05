#ifndef CALL_SIGN_H
#define CALL_SIGN_H

#include <string>
#include <cstdint>

class CallSign
{
public:
    CallSign();
    void setCallSign(const std::string &input);
    std::string getCallSignString();

private:
    std::string callSign = "";
};

#endif