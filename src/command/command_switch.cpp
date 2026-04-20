#include "command_switch.h"

CommandResult CommandSwitch::SetSwitch(const std::string& status) {
    Switch::SwitchEnum switchEnum = Switch::StringToSwitch(status);
    if (switchEnum != Switch::SwitchEnum::UNKNOWN) {
        enabled = switchEnum;
        return OK();
    }
    return Error("INVALID_SWITCH_PARAMETER",
                 "Invalid switch parameter: " + status);
}

std::string CommandSwitch::ToCommand(bool readStatus) {
    std::string command = CommandPrefix::CommandToString(commandPrefix);
    int bufferLength = CommandPrefix::COMMAND_LENGTH;

    if (readStatus) {
        return Command(bufferLength, command).ToString();
    }

    std::string enabledString = Switch::SwitchToBoolString(enabled);
    bufferLength += Switch::MAX_SWITCH_LENGTH;

    return Command(bufferLength, command, enabledString).ToString();
}
