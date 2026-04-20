#include "command_tone.h"

CommandResult CommandTone::SetTone(const std::string& toneFrequencyString) {
    ToneFrequency::ToneFrequencyEnum toneEnum =
        ToneFrequency::StringToToneFrequency(toneFrequencyString);
    if (toneEnum != ToneFrequency::ToneFrequencyEnum::UNKNOWN) {
        toneFrequency = toneEnum;
        return OK();
    }
    return Error("INVALID_TONE_FREQUENCY",
                 "Invalid tone frequency: " + toneFrequencyString);
}

std::string CommandTone::ToCommand() {
    std::string command = CommandPrefix::CommandToString(commandPrefix);
    int bufferLength = CommandPrefix::COMMAND_LENGTH;

    std::string toneString =
        ToneFrequency::ToneFrequencyToIntString(toneFrequency);
    bufferLength += ToneFrequency::MAX_TONE_LENGTH;

    return Command(bufferLength, command, toneString).ToString();
}
