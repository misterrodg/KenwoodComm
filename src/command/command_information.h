#ifndef COMMAND_INFORMATION_H
#define COMMAND_INFORMATION_H

#include "command_base.h"
#include "parameter/communication_state.h"
#include "parameter/frequency.h"
#include "parameter/function.h"
#include "parameter/memory_bank.h"
#include "parameter/memory_channel.h"
#include "parameter/mode.h"
#include "parameter/offset.h"
#include "parameter/rit_frequency.h"
#include "parameter/step_frequency.h"
#include "parameter/switch.h"
#include "parameter/tone_frequency.h"

class CommandInformation : public CommandBase {
public:
    CommandInformation(CommandPrefix::CommandPrefixEnum prefix)
        : CommandBase(prefix) {};

    core::Result<std::string> buildReadCommand() override;
};

#endif