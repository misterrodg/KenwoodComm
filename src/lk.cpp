#include "lk.h"

Lk::Lk() : enabled(Switch::SwitchEnum::OFF) {}

bool Lk::SetLk(std::string &status)
{
    bool result = false;
    Switch::SwitchEnum switchEnum = Switch::StringToSwitch(status);
    if (switchEnum != Switch::SwitchEnum::UNKNOWN)
    {
        enabled = switchEnum;
        result = true;
    }
    return result;
}

std::string Lk::ToCommand(const bool &hasParam)
{
    std::string command = CommandPrefix::CommandToString(CommandPrefix::CommandPrefixEnum::LK);
    int bufferLength = CommandPrefix::COMMAND_LENGTH;

    if (hasParam)
    {
        std::string enabledString = Switch::SwitchToBoolString(enabled);
        bufferLength += Switch::MAX_SWITCH_LENGTH;

        return Command(bufferLength, command, enabledString).ToString();
    }

    return Command(bufferLength, command).ToString();
}