#include "dn_up.h"

DnUp::DnUp(const CommandPrefix::CommandPrefixEnum &downUpEnum) : downUp(downUpEnum) {}

std::string DnUp::ToCommand()
{
    std::string command = CommandPrefix::CommandToString(downUp);
    int bufferLength = CommandPrefix::COMMAND_LENGTH;

    return Command(bufferLength, command).ToString();
}