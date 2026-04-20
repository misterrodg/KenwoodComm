#include "serial_command.h"

const int Command::COMMAND_TERMINATOR_LENGTH = 1;
const int Command::NULL_TERMINATOR_LENGTH = 1;

Command::Command(int &bufferLength, std::string &commandPrefix) : commandString("")
{
    bufferLength += COMMAND_TERMINATOR_LENGTH + NULL_TERMINATOR_LENGTH;
    commandString = commandPrefix + ";";
}

Command::Command(int &bufferLength, std::string &commandPrefix, std::string &parameter) : commandString("")
{
    bufferLength += COMMAND_TERMINATOR_LENGTH + NULL_TERMINATOR_LENGTH;
    commandString = commandPrefix + parameter + ";";
}

std::string Command::ToString()
{
    return commandString;
}