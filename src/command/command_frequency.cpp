#include "command_frequency.h"

bool CommandFrequency::SetFrequency(const std::string &frequencyString)
{
    bool result = false;
    if (frequency.setFrequency(frequencyString))
    {
        result = true;
    }
    return result;
}

std::string CommandFrequency::ToCommand(bool readStatus)
{
    std::string command = CommandPrefix::CommandToString(commandPrefix);
    int bufferLength = CommandPrefix::COMMAND_LENGTH;

    if (readStatus)
    {
        return Command(bufferLength, command).ToString();
    }

    std::string frequencyString = frequency.getFrequencyString();
    bufferLength += Frequency::MAX_FREQUENCY_LENGTH;

    return Command(bufferLength, command, frequencyString).ToString();
}
