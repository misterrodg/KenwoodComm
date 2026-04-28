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
#include <cstdio>

class CommandInformation : public CommandBase {
protected:
    Frequency frequency;
    StepFrequency stepFrequency;
    RITFrequency ritFrequency;
    Switch::SwitchEnum ritStatus = Switch::SwitchEnum::UNKNOWN;
    Switch::SwitchEnum xitStatus = Switch::SwitchEnum::UNKNOWN;
    MemoryBank::MemoryBankEnum memoryBank = MemoryBank::MemoryBankEnum::UNKNOWN;
    MemoryChannel::MemoryChannelEnum memoryChannel =
        MemoryChannel::MemoryChannelEnum::UNKNOWN;
    CommunicationState::CommunicationStateEnum communicationState =
        CommunicationState::CommunicationStateEnum::UNKNOWN;
    Mode::ModeEnum mode = Mode::ModeEnum::UNKNOWN;
    Function::FunctionEnum function = Function::FunctionEnum::UNKNOWN;
    Switch::SwitchEnum scanStatus = Switch::SwitchEnum::UNKNOWN;
    Switch::SwitchEnum splitStatus = Switch::SwitchEnum::UNKNOWN;
    Switch::SwitchEnum toneStatus = Switch::SwitchEnum::UNKNOWN;
    ToneFrequency::ToneFrequencyEnum toneFrequency =
        ToneFrequency::ToneFrequencyEnum::UNKNOWN;
    Offset::OffsetEnum offset = Offset::OffsetEnum::UNKNOWN;

    bool hasFrequency = false;
    bool hasStepFrequency = false;
    bool hasRITFrequency = false;
    bool hasRITStatus = false;
    bool hasXITStatus = false;
    bool hasMemoryBank = false;
    bool hasMemoryChannel = false;
    bool hasCommunicationState = false;
    bool hasMode = false;
    bool hasFunction = false;
    bool hasScanStatus = false;
    bool hasSplitStatus = false;
    bool hasToneStatus = false;
    bool hasToneFrequency = false;
    bool hasOffset = false;

public:
    CommandInformation(CommandPrefix::CommandPrefixEnum prefix)
        : CommandBase(prefix) {};

    CommandResult parseAnswer(const std::string& payload) override;
    core::Result<std::string> buildReadCommand() override;
    std::string getDisplayValue() const override;

    CommandResult SetFrequency(const std::string& frequencyString);
    CommandResult SetStepFrequency(const std::string& stepFrequencyString);
    CommandResult SetRITFrequency(const std::string& ritFrequencyString);
    CommandResult SetRITStatus(const std::string& ritStatusString);
    CommandResult SetXITStatus(const std::string& xitStatusString);
    CommandResult SetMemoryBank(const std::string& memoryBankString);
    CommandResult SetMemoryChannel(const std::string& memoryChannelString);
    CommandResult
    SetCommunicationState(const std::string& communicationStateString);
    CommandResult SetMode(const std::string& modeString);
    CommandResult SetFunction(const std::string& functionString);
    CommandResult SetScanStatus(const std::string& scanStatusString);
    CommandResult SetSplitStatus(const std::string& splitStatusString);
    CommandResult SetToneStatus(const std::string& toneStatusString);
    CommandResult SetToneFrequency(const std::string& toneFrequencyString);
    CommandResult SetOffset(const std::string& offsetString);
};

#endif