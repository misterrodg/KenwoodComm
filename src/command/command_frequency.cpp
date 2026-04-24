#include "command_frequency.h"

CommandResult CommandFrequency::set(const std::string& frequencyString) {
    return SetFrequency(frequencyString);
}

CommandResult CommandFrequency::parseAnswer(const std::string& payload) {
    return SetFrequency(payload + " Hz");
}

core::Result<std::string> CommandFrequency::buildSetCommand() {
    if (!supportsSet()) {
        return core::Error{core::ErrorCode::CommandNotImplemented,
                           "Set command is not available for this command"};
    }

    return ToCommand();
}

core::Result<std::string> CommandFrequency::buildReadCommand() {
    if (!supportsRead()) {
        return core::Error{core::ErrorCode::CommandNotImplemented,
                           "Read command is not available for this command"};
    }

    return ToCommand(true);
}

CommandResult
CommandFrequency::SetFrequency(const std::string& frequencyString) {
    core::Result<void> result = frequency.setFrequency(frequencyString);
    if (result.OK()) {
        return OK();
    }
    return result.error();
}

std::string CommandFrequency::ToCommand(bool readStatus) {
    std::string command = CommandPrefix::CommandToString(commandPrefix);
    int bufferLength = CommandPrefix::COMMAND_LENGTH;

    if (readStatus) {
        return SerialCommand(bufferLength, command).ToString();
    }

    std::string frequencyString = frequency.getFrequencyString();
    bufferLength += Frequency::MAX_FREQUENCY_LENGTH;

    return SerialCommand(bufferLength, command, frequencyString).ToString();
}
