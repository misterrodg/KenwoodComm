#include "command_base.h"

std::string CommandBase::ToCommand()
{
    std::string command = CommandPrefix::CommandToString(commandPrefix);
    int bufferLength = CommandPrefix::COMMAND_LENGTH;

    return Command(bufferLength, command).ToString();
}