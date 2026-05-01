#ifndef MOCK_RADIO_H
#define MOCK_RADIO_H

#include "parameter/busy.h"
#include "parameter/communication_state.h"
#include "parameter/destination_code.h"
#include "parameter/frequency.h"
#include "parameter/function.h"
#include "parameter/memory_bank.h"
#include "parameter/memory_channel.h"
#include "parameter/memory_slot.h"
#include "parameter/mode.h"
#include "parameter/model_number.h"
#include "parameter/offset.h"
#include "parameter/s_meter.h"
#include "parameter/step_frequency.h"
#include "parameter/switch.h"
#include "parameter/tone_frequency.h"
#include "runtime/serial_interface.h"

#include <map>
#include <string>

/**
 * Mock radio that responds to any command without needing actual hardware.
 * Used in local mode for testing command logic before committing.
 *
 * Strategy: Echo back received commands as responses, allowing the existing
 * command parsing and answer routing to work as if a real radio responded.
 * This avoids duplicating the command-to-response mapping logic.
 */
class MockRadio : public ISerialPort {
public:
    MockRadio();
    void Open() override;
    void Close() override;
    void Write(const std::string& command) override;
    std::string Read() override;
    bool GetEstablished() override;

private:
    std::map<int, std::map<int, MemorySlot>> memoryMap;
    Switch::SwitchEnum AutoInformationStatus = Switch::SwitchEnum::OFF;
    Busy::BusyEnum BusyIndicatorStatus = Busy::BusyEnum::OFF;
    CommunicationState::CommunicationStateEnum CommunicationState =
        CommunicationState::CommunicationStateEnum::RECEIVE;
    ToneFrequency::ToneFrequencyEnum CTCSSFrequency =
        ToneFrequency::ToneFrequencyEnum::TN01;
    Switch::SwitchEnum CTCSSStatus = Switch::SwitchEnum::OFF;
    DestinationCode::CodeEnum DestinationCode = DestinationCode::CodeEnum::MAIN;
    Frequency FrequencyA;
    Frequency FrequencyB;
    Function::FunctionEnum Function = Function::FunctionEnum::VFOA;
    Mode::ModeEnum Mode = Mode::ModeEnum::AM;
    ModelNumber::ModelNumberEnum ModelNumber =
        ModelNumber::ModelNumberEnum::UNRECOGNIZED;
    Switch::SwitchEnum LockStatus = Switch::SwitchEnum::OFF;
    Switch::SwitchEnum AutoLockTuneStatus = Switch::SwitchEnum::OFF;
    MemoryBank::MemoryBankEnum MemoryBank = MemoryBank::MemoryBankEnum::UNKNOWN;
    MemoryChannel::MemoryChannelEnum MemoryChannel =
        MemoryChannel::MemoryChannelEnum::MC00;
    Switch::SwitchEnum MuteStatus = Switch::SwitchEnum::OFF;
    Offset::OffsetEnum Offset = Offset::OffsetEnum::SIMPLEX;
    Switch::SwitchEnum RITStatus = Switch::SwitchEnum::OFF;
    Switch::SwitchEnum ScanStatus = Switch::SwitchEnum::OFF;
    SMeter SMeter;
    Switch::SwitchEnum SplitStatus = Switch::SwitchEnum::OFF;
    StepFrequency StepFrequency;
    Switch::SwitchEnum StepStatus = Switch::SwitchEnum::OFF;
    ToneFrequency::ToneFrequencyEnum ToneFrequency =
        ToneFrequency::ToneFrequencyEnum::TN01;
    Switch::SwitchEnum ToneStatus = Switch::SwitchEnum::OFF;
    Switch::SwitchEnum XITStatus = Switch::SwitchEnum::OFF;

    std::string buildIFPayload() const;
    std::string serializeMemorySlot(int bank, int channel,
                                    const MemorySlot& slot) const;
    void applyWriteToState(const std::string& prefix,
                           const std::string& params);

    bool established;
    std::string lastResponse;
};

#endif
