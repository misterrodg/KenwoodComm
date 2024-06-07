#include "dcs_id.h"

std::string DcsId::ToCommand()
{
    std::string command = CommandPrefix::CommandToString(CommandPrefix::CommandPrefixEnum::DI);
    int bufferLength = CommandPrefix::COMMAND_LENGTH;

    return Command(bufferLength, command).ToString();
}