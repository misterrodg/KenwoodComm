#include "lo.h"

std::string Lo::ToCommand()
{
    std::string command = CommandPrefix::CommandToString(CommandPrefix::CommandPrefixEnum::LO);
    int bufferLength = CommandPrefix::COMMAND_LENGTH;

    return Command(bufferLength, command).ToString();
}