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
    else
    {
        printf("Unrecognized option. Options are: ON, or OFF.\n");
    }
    return result;
}

std::string AutoInformation::ToCommand()
{
    std::string command = CommandPrefix::CommandToString(CommandPrefix::CommandPrefixEnum::AI);
    std::string enabledString = Switch::SwitchToBoolString(enabled);
    int bufferLength = CommandPrefix::COMMAND_LENGTH + Switch::MAX_SWITCH_LENGTH + Command::COMMAND_TERMINATOR_LENGTH + 1;

    return Command::CreateCommand(bufferLength, command, enabledString);
}