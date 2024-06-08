#include "hold.h"

Hold::Hold() : enabled(Switch::SwitchEnum::OFF) {}

bool Hold::SetHold(std::string &status)
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

std::string Hold::ToCommand(const bool &hasParam)
{
    std::string command = CommandPrefix::CommandToString(CommandPrefix::CommandPrefixEnum::HD);
    int bufferLength = CommandPrefix::COMMAND_LENGTH;

    if (hasParam)
    {
        std::string enabledString = Switch::SwitchToBoolString(enabled);
        bufferLength += Switch::MAX_SWITCH_LENGTH;

        return Command(bufferLength, command, enabledString).ToString();
    }

    return Command(bufferLength, command).ToString();
}