#include "command_switch.h"

bool CommandSwitch::SetSwitch(const std::string &status)
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

std::string CommandSwitch::ToCommand(bool readStatus)
{
    std::string command = CommandPrefix::CommandToString(commandPrefix);
    int bufferLength = CommandPrefix::COMMAND_LENGTH;

    if (readStatus)
    {
        return Command(bufferLength, command).ToString();
    }

    std::string enabledString = Switch::SwitchToBoolString(enabled);
    bufferLength += Switch::MAX_SWITCH_LENGTH;

    return Command(bufferLength, command, enabledString).ToString();
}