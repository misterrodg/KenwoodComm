#include "mock_radio.h"
#include "parameter/communication_state.h"
#include "parameter/function.h"
#include "parameter/memory_bank.h"
#include "parameter/memory_channel.h"
#include "parameter/memory_channel_split.h"
#include "parameter/memory_lockout.h"
#include "parameter/memory_slot.h"
#include "parameter/mode.h"
#include "parameter/offset.h"
#include "parameter/switch.h"
#include "parameter/tone_frequency.h"
#include <cstdio>
#include <string>

MockRadio::MockRadio() : established(false), lastResponse("") {
    FrequencyA.setFrequency("144 MHz");
    FrequencyB.setFrequency("144 MHz");
    SMeter.setSMeter("0000");
    StepFrequency.setStepFrequency("5Hz");
    memoryMap[0][0] =
        MemorySlot{.occupied = true,
                   .split = MemoryChannelSplit::MemoryChannelSplitEnum::RECEIVE,
                   .hasFrequency = true,
                   .frequency = Frequency(),
                   .mode = Mode::ModeEnum::FM,
                   .lockout = MemoryLockout::MemoryLockoutEnum::NOT_LOCKED_OUT,
                   .toneStatus = Switch::SwitchEnum::ON,
                   .toneFrequency = ToneFrequency::ToneFrequencyEnum::TN22,
                   .offset = Offset::OffsetEnum::MINUS};
    memoryMap[0][0].frequency.setFrequency("146.730 MHz");
}

void MockRadio::Open() {
    established = true;
}

void MockRadio::Close() {
    established = false;
}

void MockRadio::Write(const std::string& command) {
    if (command.length() < 3 || command.back() != ';') {
        lastResponse = "";
        return;
    }

    std::string prefix = command.substr(0, 2);
    std::string params = command.substr(2, command.length() - 3);
    bool isRead = params.empty();

    if (prefix == "MR") {
        if (params.length() >= 3) {
            int bank = params[0] - '0';
            int channel = std::stoi(params.substr(1, 2));
            auto bankIt = memoryMap.find(bank);
            if (bankIt != memoryMap.end()) {
                auto chanIt = bankIt->second.find(channel);
                if (chanIt != bankIt->second.end() && chanIt->second.occupied) {
                    lastResponse =
                        "MR" +
                        serializeMemorySlot(bank, channel, chanIt->second) +
                        ";";
                    return;
                }
            }
        }
        lastResponse = "MR" + std::string(21, ' ') + ";";
    } else if (isRead) {
        if (prefix == "BY") {
            lastResponse =
                "BY" + Busy::BusyToBoolString(BusyIndicatorStatus) + ";";
        } else if (prefix == "CN") {
            lastResponse =
                "CN" +
                ToneFrequency::ToneFrequencyToFreqString(CTCSSFrequency) + ";";
        } else if (prefix == "CT") {
            lastResponse = "CT" + Switch::SwitchToBoolString(CTCSSStatus) + ";";
        } else if (prefix == "DC") {
            lastResponse =
                "DC" + DestinationCode::CodeToIntString(DestinationCode) + ";";
        } else if (prefix == "FA") {
            lastResponse = "FA" + FrequencyA.getFrequencyString() + ";";
        } else if (prefix == "FB") {
            lastResponse = "FB" + FrequencyB.getFrequencyString() + ";";
        } else if (prefix == "ID") {
            lastResponse =
                "ID" + ModelNumber::ModelNumberToString(ModelNumber) + ";";
        } else if (prefix == "IF") {
            lastResponse = prefix + buildIFPayload() + ";";
        } else if (prefix == "LK") {
            lastResponse = "LK" + Switch::SwitchToBoolString(LockStatus) + ";";
        } else if (prefix == "LT") {
            lastResponse =
                "LT" + Switch::SwitchToBoolString(AutoLockTuneStatus) + ";";
        } else if (prefix == "MN") {
            lastResponse =
                "MN" + ModelNumber::ModelNumberToIntString(ModelNumber) + ";";
        } else if (prefix == "MT") {
            lastResponse = "MT" + Switch::SwitchToBoolString(MuteStatus) + ";";
        } else if (prefix == "SM") {
            lastResponse = "SM" + SMeter.getSMeterString() + ";";
        } else {
            lastResponse = "";
        }
    } else {
        applyWriteToState(prefix, params);
        lastResponse = command;
    }
}

std::string MockRadio::buildIFPayload() const {
    std::string freq = "           "; // 11 chars, blank if unknown
    if (Function == Function::FunctionEnum::VFOA) {
        freq = FrequencyA.getFrequencyString();
    } else if (Function == Function::FunctionEnum::VFOB) {
        freq = FrequencyB.getFrequencyString();
    }

    std::string stepFreq = "     "; // 5 chars, blank if step not active
    if (StepStatus == Switch::SwitchEnum::ON) {
        stepFreq = StepFrequency.getStepFrequencyString();
    }

    std::string bank =
        (MemoryBank == MemoryBank::MemoryBankEnum::UNKNOWN)
            ? " "
            : MemoryBank::BankEnumToIntString(MemoryBank); // 1 char
    std::string channel =
        (MemoryChannel == MemoryChannel::MemoryChannelEnum::UNKNOWN)
            ? "  "
            : MemoryChannel::ChannelEnumToIntString(MemoryChannel); // 2 chars

    return freq + stepFreq +                       // freq(11) + step(5)
           "     " +                               // RIT freq (5, blank)
           Switch::SwitchToBoolString(RITStatus) + // rit status (1)
           Switch::SwitchToBoolString(XITStatus) + // xit status (1)
           bank +                                  // mem bank (1)
           channel +                               // mem channel (2)
           CommunicationState::StateToIntString(
               CommunicationState) +                 // com status (1)
           Mode::ModeToIntString(Mode) +             // mode (1)
           Function::FunctionToIntString(Function) + // function (1)
           Switch::SwitchToBoolString(ScanStatus) +  // scan (1)
           Switch::SwitchToBoolString(SplitStatus) + // split (1)
           Switch::SwitchToBoolString(ToneStatus) +  // tone status (1)
           ToneFrequency::ToneFrequencyToIntString(
               ToneFrequency) +               // tone freq (2)
           Offset::OffsetToIntString(Offset); // offset (1)
}

std::string MockRadio::serializeMemorySlot(int bank, int channel,
                                           const MemorySlot& slot) const {
    char bankBuf[2], chanBuf[3];
    snprintf(bankBuf, sizeof(bankBuf), "%d", bank);
    snprintf(chanBuf, sizeof(chanBuf), "%02d", channel);

    // Each UNKNOWN field renders as the correct number of spaces so the
    // response is always exactly 21 chars (matching a blank MR response).
    std::string freq =
        slot.hasFrequency
            ? slot.frequency.getFrequencyString()
            : std::string(Frequency::MAX_FREQUENCY_LENGTH, ' '); // 11 chars

    std::string split =
        (slot.split != MemoryChannelSplit::MemoryChannelSplitEnum::UNKNOWN)
            ? MemoryChannelSplit::MemoryChannelSplitToIntString(slot.split)
            : " ";

    std::string mode = (slot.mode != Mode::ModeEnum::UNKNOWN)
                           ? Mode::ModeToIntString(slot.mode)
                           : " ";

    std::string lockout =
        (slot.lockout != MemoryLockout::MemoryLockoutEnum::UNKNOWN)
            ? MemoryLockout::MemoryLockoutToIntString(slot.lockout)
            : " ";

    std::string toneStatus = (slot.toneStatus != Switch::SwitchEnum::UNKNOWN)
                                 ? Switch::SwitchToBoolString(slot.toneStatus)
                                 : " ";

    std::string toneFreq =
        (slot.toneFrequency != ToneFrequency::ToneFrequencyEnum::UNKNOWN)
            ? ToneFrequency::ToneFrequencyToIntString(slot.toneFrequency)
            : std::string(ToneFrequency::MAX_TONE_LENGTH, ' '); // 2 chars

    std::string offset = (slot.offset != Offset::OffsetEnum::UNKNOWN)
                             ? Offset::OffsetToIntString(slot.offset)
                             : " ";

    // Total: bank(1)+channel(2)+freq(11)+split(1)+mode(1)+lockout(1)
    //        +toneStatus(1)+toneFreq(2)+offset(1) = 21 chars
    return std::string(bankBuf) + chanBuf + freq + split + mode + lockout +
           toneStatus + toneFreq + offset;
}

void MockRadio::applyWriteToState(const std::string& prefix,
                                  const std::string& params) {
    if (prefix == "FA") {
        FrequencyA.setFrequency(params + "Hz");
    } else if (prefix == "FB") {
        FrequencyB.setFrequency(params + "Hz");
    } else if (prefix == "MD") {
        Mode::ModeEnum m = Mode::StringToMode(params);
        if (m != Mode::ModeEnum::UNKNOWN)
            Mode = m;
    } else if (prefix == "FN") {
        Function::FunctionEnum f = Function::StringToFunction(params);
        if (f != Function::FunctionEnum::UNKNOWN)
            Function = f;
    } else if (prefix == "RT") {
        Switch::SwitchEnum s = Switch::StringToSwitch(params);
        if (s != Switch::SwitchEnum::UNKNOWN)
            RITStatus = s;
    } else if (prefix == "XT") {
        Switch::SwitchEnum s = Switch::StringToSwitch(params);
        if (s != Switch::SwitchEnum::UNKNOWN)
            XITStatus = s;
    } else if (prefix == "SC") {
        Switch::SwitchEnum s = Switch::StringToSwitch(params);
        if (s != Switch::SwitchEnum::UNKNOWN)
            ScanStatus = s;
    } else if (prefix == "SP") {
        Switch::SwitchEnum s = Switch::StringToSwitch(params);
        if (s != Switch::SwitchEnum::UNKNOWN)
            SplitStatus = s;
    } else if (prefix == "TO") {
        Switch::SwitchEnum s = Switch::StringToSwitch(params);
        if (s != Switch::SwitchEnum::UNKNOWN)
            ToneStatus = s;
    } else if (prefix == "TN") {
        ToneFrequency::ToneFrequencyEnum tf =
            ToneFrequency::StringToToneFrequency(params);
        if (tf != ToneFrequency::ToneFrequencyEnum::UNKNOWN)
            ToneFrequency = tf;
    } else if (prefix == "MW") {
        // MW: [bank(1)][channel(2)][freq(11)][split(1)][mode(1)][lockout(1)]
        //     [toneStatus(1)][toneFreq(2)][offset(1)] = 21 chars total
        if (params.length() == 21) {
            int bank = params[0] - '0';
            int channel = std::stoi(params.substr(1, 2));
            MemorySlot& slot = memoryMap[bank][channel];
            slot.occupied = true;

            std::string freqStr = params.substr(3, 11);
            if (freqStr.find_first_not_of(' ') != std::string::npos) {
                slot.hasFrequency =
                    slot.frequency.setFrequency(freqStr + "Hz").OK();
            } else {
                slot.hasFrequency = false;
            }

            std::string splitStr = params.substr(14, 1);
            if (splitStr != " ")
                slot.split =
                    MemoryChannelSplit::StringToMemoryChannelSplit(splitStr);

            std::string modeStr = params.substr(15, 1);
            if (modeStr != " ")
                slot.mode = Mode::StringToMode(modeStr);

            std::string lockoutStr = params.substr(16, 1);
            if (lockoutStr != " ")
                slot.lockout = MemoryLockout::StringToMemoryLockout(lockoutStr);

            std::string toneStatusStr = params.substr(17, 1);
            if (toneStatusStr != " ")
                slot.toneStatus = Switch::StringToSwitch(toneStatusStr);

            std::string toneFreqStr = params.substr(18, 2);
            if (toneFreqStr.find_first_not_of(' ') != std::string::npos)
                slot.toneFrequency =
                    ToneFrequency::StringToToneFrequency(toneFreqStr);

            std::string offsetStr = params.substr(20, 1);
            if (offsetStr != " ")
                slot.offset = Offset::StringToOffset(offsetStr);
        }
    }
}

std::string MockRadio::Read() {
    return lastResponse;
}

bool MockRadio::GetEstablished() {
    return established;
}
