#include "if.h"

std::string If::ToCommand()
{
    std::string command = CommandPrefix::CommandToString(CommandPrefix::CommandPrefixEnum::IF);
    int bufferLength = CommandPrefix::COMMAND_LENGTH;

    return Command(bufferLength, command).ToString();
}