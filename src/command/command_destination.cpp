#include "command_destination.h"

CommandResult CommandDestinationCode::set(const std::string& codeString) {
    return SetDestinationCode(codeString);
}

CommandResult CommandDestinationCode::parseAnswer(const std::string& payload) {
    return SetDestinationCode(payload);
}

core::Result<std::string> CommandDestinationCode::buildSetCommand() {
    if (!supportsSet()) {
        return core::Error{core::ErrorCode::CommandNotImplemented,
                           "Set command is not available for this command"};
    }

    return ToCommand();
}

core::Result<std::string> CommandDestinationCode::buildReadCommand() {
    if (!supportsRead()) {
        return core::Error{core::ErrorCode::CommandNotImplemented,
                           "Read command is not available for this command"};
    }

    return ToCommand(true);
}

std::string CommandDestinationCode::getDisplayValue() const {
    return DestinationCode::CodeToFriendlyString(destination);
}

CommandResult
CommandDestinationCode::SetDestinationCode(const std::string& codeString) {
    DestinationCode::CodeEnum codeEnum =
        DestinationCode::StringToCode(codeString);
    if (codeEnum != DestinationCode::CodeEnum::UNKNOWN) {
        destination = codeEnum;
        return OK();
    }
    return Error(core::ErrorCode::InvalidDestinationCode,
                 "Invalid destination: '" + codeString +
                     "'. Options are: MAIN, SUB (or 0, 1)");
}

std::string CommandDestinationCode::ToCommand(bool readStatus) {
    std::string command = CommandPrefix::CommandToString(commandPrefix);
    int bufferLength = CommandPrefix::COMMAND_LENGTH;

    if (readStatus) {
        return SerialCommand(bufferLength, command).ToString();
    }

    std::string codeString = DestinationCode::CodeToIntString(destination);
    bufferLength += DestinationCode::MAX_CODE_LENGTH;

    return SerialCommand(bufferLength, command, codeString).ToString();
}
