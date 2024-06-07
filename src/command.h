#ifndef COMMAND_H
#define COMMAND_H

#include <string>

class Command
{
public:
    Command();
    static std::string CreateCommand(int &bufferLength, std::string &commandPrefix, std::string &parameter);
    static const int COMMAND_TERMINATOR_LENGTH;
};

#endif