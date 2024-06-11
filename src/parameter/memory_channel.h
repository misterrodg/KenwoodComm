#ifndef MEMORY_CHANNEL_H
#define MEMORY_CHANNEL_H

#include <string>
#include <cstdint>
#include <regex>

class MemoryChannel
{
public:
    MemoryChannel();
    bool setMemoryChannel(const std::string &input);
    short int getMemoryChannel() const;
    std::string getMemoryChannelString();
    static const int MAX_MEMORY_CHANNEL_LENGTH;

private:
    short int memoryChannel;
};

#endif