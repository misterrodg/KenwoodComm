#include "auto_information.h"

AutoInformation::AutoInformation() : enabled(Switch::SwitchEnum::OFF) {}

bool AutoInformation::SetAutoInformation(std::string &status)
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

std::string AutoInformation::ToCommand()
{
    std::string command = CommandPrefix::CommandToString(CommandPrefix::CommandPrefixEnum::AI);
    std::string enabledString = Switch::SwitchToBoolString(enabled);
    int bufferLength = CommandPrefix::COMMAND_LENGTH + Switch::MAX_SWITCH_LENGTH;

    return Command(bufferLength, command, enabledString).ToString();
}