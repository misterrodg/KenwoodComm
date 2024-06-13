#ifndef RESPONSE_H
#define RESPONSE_H

#include <string>
#include "command/command_prefix.h"

class Response
{
public:
    Response(const std::string &responseString);
    void ToConsole();
    static const int MAX_RESPONSE_LENGTH = 39;

private:
    CommandPrefix::CommandPrefixEnum commandPrefix;
    std::string parameters;
};

#endif