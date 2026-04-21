#include "core/serial_command.h"

const int SerialCommand::COMMAND_TERMINATOR_LENGTH = 1;
const int SerialCommand::NULL_TERMINATOR_LENGTH = 1;

SerialCommand::SerialCommand(int& bufferLength, std::string& commandPrefix)
    : commandString("") {
    bufferLength += COMMAND_TERMINATOR_LENGTH + NULL_TERMINATOR_LENGTH;
    commandString = commandPrefix + ";";
}

SerialCommand::SerialCommand(int& bufferLength, std::string& commandPrefix,
                             std::string& parameter)
    : commandString("") {
    bufferLength += COMMAND_TERMINATOR_LENGTH + NULL_TERMINATOR_LENGTH;
    commandString = commandPrefix + parameter + ";";
}

std::string SerialCommand::ToString() {
    return commandString;
}