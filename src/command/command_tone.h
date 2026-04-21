#ifndef COMMAND_TONE_H
#define COMMAND_TONE_H

#include "command_result.h"
#include "parameter/tone_frequency.h"
#include "command_base.h"

class CommandTone : public CommandBase {
protected:
    ToneFrequency::ToneFrequencyEnum toneFrequency;

public:
    CommandTone(CommandPrefix::CommandPrefixEnum prefix)
        : CommandBase(prefix) {};
    std::string ToCommand();
    CommandResult SetTone(const std::string& toneFrequencyString);
};

#endif
