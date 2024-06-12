#include "command_tone.h"

bool CommandTone::SetTone(const std::string &toneFrequencyString)
{
    bool result = false;
    ToneFrequency::ToneFrequencyEnum toneEnum = ToneFrequency::StringToToneFrequency(toneFrequencyString);
    if (toneEnum != ToneFrequency::ToneFrequencyEnum::UNKNOWN)
    {
        toneFrequency = toneEnum;
        result = true;
    }
    return result;
}

std::string CommandTone::ToCommand()
{
    std::string command = CommandPrefix::CommandToString(commandPrefix);
    int bufferLength = CommandPrefix::COMMAND_LENGTH;

    std::string toneString = ToneFrequency::ToneFrequencyToIntString(toneFrequency);
    bufferLength += ToneFrequency::MAX_TONE_LENGTH;

    return Command(bufferLength, command, toneString).ToString();
}
