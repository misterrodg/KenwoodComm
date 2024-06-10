#ifndef MEMORY_CHANNEL_H
#define MEMORY_CHANNEL_H

#include <string>
#include <cstdint>

class MemoryChannel
{
public:
    MemoryChannel();
    void setMemoryChannel(const std::string &input);
    short int getMemoryChannel() const;
    std::string getMemoryChannelString();

private:
    short int memoryChannel;
};

#endif