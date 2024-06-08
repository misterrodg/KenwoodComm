#include "dcs.h"

Dcs::Dcs() : enabled(Switch::SwitchEnum::OFF) {}

bool Dcs::SetDcs(std::string &status)
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

std::string Dcs::ToCommand(const bool &hasParam)
{
    std::string command = CommandPrefix::CommandToString(CommandPrefix::CommandPrefixEnum::DS);
    int bufferLength = CommandPrefix::COMMAND_LENGTH;

    if (hasParam)
    {
        std::string enabledString = Switch::SwitchToBoolString(enabled);
        bufferLength += Switch::MAX_SWITCH_LENGTH;

        return Command(bufferLength, command, enabledString).ToString();
    }

    return Command(bufferLength, command).ToString();
}