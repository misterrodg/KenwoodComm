#include "command_switch.h"

CommandResult CommandSwitch::set(const std::string& status) {
    return SetSwitch(status);
}

core::Result<std::string> CommandSwitch::buildSetCommand() {
    if (!supportsSet()) {
        return core::Error{core::ErrorCode::CommandNotImplemented,
                           "Set command is not available for this command"};
    }

    return ToCommand();
}

core::Result<std::string> CommandSwitch::buildReadCommand() {
    if (!supportsRead()) {
        return core::Error{core::ErrorCode::CommandNotImplemented,
                           "Read command is not available for this command"};
    }

    return ToCommand(true);
}

CommandResult CommandSwitch::SetSwitch(const std::string& status) {
    Switch::SwitchEnum switchEnum = Switch::StringToSwitch(status);
    if (switchEnum != Switch::SwitchEnum::UNKNOWN) {
        enabled = switchEnum;
        return OK();
    }
    return Error(core::ErrorCode::InvalidSwitchParameter,
                 "Invalid switch parameter: " + status);
}

std::string CommandSwitch::ToCommand(bool readStatus) {
    std::string command = CommandPrefix::CommandToString(commandPrefix);
    int bufferLength = CommandPrefix::COMMAND_LENGTH;

    if (readStatus) {
        return SerialCommand(bufferLength, command).ToString();
    }

    std::string enabledString = Switch::SwitchToBoolString(enabled);
    bufferLength += Switch::MAX_SWITCH_LENGTH;

    return SerialCommand(bufferLength, command, enabledString).ToString();
}
