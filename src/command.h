#ifndef COMMAND_H
#define COMMAND_H

#include <string>

class Command
{
public:
    Command(int &bufferLength, std::string &commandPrefix);
    Command(int &bufferLength, std::string &commandPrefix, std::string &parameter);
    std::string ToString();
    static const int MAX_COMMAND_LENGTH = 26;

private:
    std::string commandString;
    static const int COMMAND_TERMINATOR_LENGTH;
    static const int NULL_TERMINATOR_LENGTH;
};

#endif