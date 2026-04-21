#ifndef SERIAL_COMMAND_H
#define SERIAL_COMMAND_H

#include <string>

class SerialCommand {
public:
    SerialCommand(int& bufferLength, std::string& commandPrefix);
    SerialCommand(int& bufferLength, std::string& commandPrefix,
                  std::string& parameter);
    std::string ToString();
    static const int MAX_COMMAND_LENGTH = 26;

private:
    std::string commandString;
    static const int COMMAND_TERMINATOR_LENGTH;
    static const int NULL_TERMINATOR_LENGTH;
};

#endif