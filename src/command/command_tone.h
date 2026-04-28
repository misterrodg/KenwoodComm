#ifndef COMMAND_TONE_H
#define COMMAND_TONE_H

#include "command_base.h"
#include "command_result.h"
#include "parameter/tone_frequency.h"

class CommandTone : public CommandBase {
protected:
    ToneFrequency::ToneFrequencyEnum toneFrequency;

public:
    CommandTone(CommandPrefix::CommandPrefixEnum prefix)
        : CommandBase(prefix) {};

    CommandResult set(const std::string& toneFrequencyString) override;
    CommandResult parseAnswer(const std::string& payload) override;
    core::Result<std::string> buildSetCommand() override;
    core::Result<std::string> buildReadCommand() override;
    std::string getDisplayValue() const override;

    std::string ToCommand(bool readStatus = false);
    CommandResult SetTone(const std::string& toneFrequencyString);
};

#endif
