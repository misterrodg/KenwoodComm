#include "command_tone.h"

CommandResult CommandTone::set(const std::string& toneFrequencyString) {
    return SetTone(toneFrequencyString);
}

CommandResult CommandTone::parseAnswer(const std::string& payload) {
    return SetTone(payload);
}

core::Result<std::string> CommandTone::buildSetCommand() {
    if (!supportsSet()) {
        return core::Error{core::ErrorCode::CommandNotImplemented,
                           "Set command is not available for this command"};
    }

    return ToCommand();
}

core::Result<std::string> CommandTone::buildReadCommand() {
    if (!supportsRead()) {
        return core::Error{core::ErrorCode::CommandNotImplemented,
                           "Read command is not available for this command"};
    }

    return ToCommand(true);
}

CommandResult CommandTone::SetTone(const std::string& toneFrequencyString) {
    ToneFrequency::ToneFrequencyEnum toneEnum =
        ToneFrequency::StringToToneFrequency(toneFrequencyString);
    if (toneEnum != ToneFrequency::ToneFrequencyEnum::UNKNOWN) {
        toneFrequency = toneEnum;
        return OK();
    }
    return Error(core::ErrorCode::InvalidToneFrequency,
                 "Invalid tone frequency: " + toneFrequencyString);
}

std::string CommandTone::ToCommand(bool readStatus) {
    std::string command = CommandPrefix::CommandToString(commandPrefix);
    int bufferLength = CommandPrefix::COMMAND_LENGTH;

    if (readStatus) {
        return SerialCommand(bufferLength, command).ToString();
    }

    std::string toneString =
        ToneFrequency::ToneFrequencyToIntString(toneFrequency);
    bufferLength += ToneFrequency::MAX_TONE_LENGTH;

    return SerialCommand(bufferLength, command, toneString).ToString();
}
