#include "command.h"

const int Command::COMMAND_TERMINATOR_LENGTH = 1;

std::string Command::CreateCommand(int &bufferLength, std::string &commandPrefix, std::string &parameter)
{
    char result[bufferLength];
    snprintf(result, sizeof(result), "%s%s;", commandPrefix.c_str(), parameter.c_str());
    return result;
}