#ifndef SERIAL_COMMAND_H
#define SERIAL_COMMAND_H

#include <string_view>
#include <string>

class SerialCommand {
public:
    SerialCommand(int& bufferLength, std::string_view commandPrefix);
    SerialCommand(int& bufferLength, std::string_view commandPrefix,
                  std::string_view parameter);
    std::string ToString() const;
    static const int MAX_COMMAND_LENGTH = 26;

private:
    std::string commandString;
    static const int COMMAND_TERMINATOR_LENGTH;
    static const int NULL_TERMINATOR_LENGTH;
};

#endif