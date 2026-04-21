#ifndef COMMAND_FREQUENCY_H
#define COMMAND_FREQUENCY_H

#include "command_result.h"
#include "parameter/frequency.h"
#include "parameter/model_number.h"
#include "command_base.h"

class CommandFrequency : public CommandBase {
protected:
    Frequency frequency;

public:
    CommandFrequency(CommandPrefix::CommandPrefixEnum prefix)
        : CommandBase(prefix) {};
    std::string ToCommand(bool readStatus = false);
    CommandResult SetFrequency(const std::string& frequencyString);
};

#endif
