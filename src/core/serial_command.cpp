#include "core/serial_command.h"

const int SerialCommand::COMMAND_TERMINATOR_LENGTH = 1;
const int SerialCommand::NULL_TERMINATOR_LENGTH = 1;

SerialCommand::SerialCommand(int& bufferLength, std::string_view commandPrefix)
    : commandString("") {
    bufferLength += COMMAND_TERMINATOR_LENGTH + NULL_TERMINATOR_LENGTH;
    commandString = std::string(commandPrefix) + ";";
}

SerialCommand::SerialCommand(int& bufferLength, std::string_view commandPrefix,
                             std::string_view parameter)
    : commandString("") {
    bufferLength += COMMAND_TERMINATOR_LENGTH + NULL_TERMINATOR_LENGTH;
    commandString = std::string(commandPrefix) + std::string(parameter) + ";";
}

std::string SerialCommand::ToString() const {
    return commandString;
}