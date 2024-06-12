#ifndef COMMAND_TONE_H
#define COMMAND_TONE_H

#include "command_base.h"
#include "../parameter/tone_frequency.h"

class CommandTone : public CommandBase
{
protected:
    ToneFrequency::ToneFrequencyEnum toneFrequency;

public:
    CommandTone(CommandPrefix::CommandPrefixEnum prefix) : CommandBase(prefix){};
    std::string ToCommand();
    bool SetTone(const std::string &toneFrequencyString);
};

#endif