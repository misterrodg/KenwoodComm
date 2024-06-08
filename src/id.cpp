#include "id.h"

std::string Id::ToCommand()
{
    std::string command = CommandPrefix::CommandToString(CommandPrefix::CommandPrefixEnum::ID);
    int bufferLength = CommandPrefix::COMMAND_LENGTH;

    return Command(bufferLength, command).ToString();
}