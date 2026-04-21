#include "command_frequency.h"

CommandResult
CommandFrequency::SetFrequency(const std::string& frequencyString) {
    if (frequency.setFrequency(frequencyString)) {
        return OK();
    }
    return Error("INVALID_FREQUENCY", "Invalid frequency: " + frequencyString);
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
