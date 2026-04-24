#include "command_busy.h"

CommandResult CommandBusy::set(const std::string& status) {
    return SetBusy(status);
}

CommandResult CommandBusy::parseAnswer(const std::string& payload) {
    return SetBusy(payload);
}

core::Result<std::string> CommandBusy::buildSetCommand() {
    if (!supportsSet()) {
        return core::Error{core::ErrorCode::CommandNotImplemented,
                           "Set command is not available for this command"};
    }

    return ToCommand();
}

core::Result<std::string> CommandBusy::buildReadCommand() {
    if (!supportsRead()) {
        return core::Error{core::ErrorCode::CommandNotImplemented,
                           "Read command is not available for this command"};
    }

    return ToCommand(true);
}

CommandResult CommandBusy::SetBusy(const std::string& status) {
    Busy::BusyEnum busyEnum = Busy::StringToBusy(status);
    if (busyEnum != Busy::BusyEnum::UNKNOWN) {
        enabled = busyEnum;
        return OK();
    }
    return Error(core::ErrorCode::InvalidBusyParameter,
                 "Invalid busy parameter: " + status);
}

std::string CommandBusy::ToCommand(bool readStatus) {
    std::string command = CommandPrefix::CommandToString(commandPrefix);
    int bufferLength = CommandPrefix::COMMAND_LENGTH;

    if (readStatus) {
        return SerialCommand(bufferLength, command).ToString();
    }

    std::string enabledString = Busy::BusyToBoolString(enabled);
    bufferLength += Busy::MAX_BUSY_LENGTH;

    return SerialCommand(bufferLength, command, enabledString).ToString();
}
