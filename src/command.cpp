#include "command.h"

const int Command::COMMAND_TERMINATOR_LENGTH = 1;
const int Command::NULL_TERMINATOR_LENGTH = 1;

Command::Command(int &bufferLength, std::string &commandPrefix, std::string &parameter) : commandString("")
{
    bufferLength += COMMAND_TERMINATOR_LENGTH + NULL_TERMINATOR_LENGTH;
    char result[bufferLength];
    snprintf(result, sizeof(result), "%s%s;", commandPrefix.c_str(), parameter.c_str());
    commandString = result;
}

std::string Command::ToString()
{
    return commandString;
}