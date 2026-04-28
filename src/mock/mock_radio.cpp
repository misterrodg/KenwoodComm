#include "mock_radio.h"
#include "parameter/communication_state.h"
#include "parameter/function.h"
#include "parameter/memory_bank.h"
#include "parameter/memory_channel.h"
#include "parameter/mode.h"
#include "parameter/offset.h"
#include "parameter/switch.h"
#include "parameter/tone_frequency.h"
#include <string>

MockRadio::MockRadio() : established(false), lastResponse("") {
    FrequencyA.setFrequency("144 MHz");
    FrequencyB.setFrequency("144 MHz");
    SMeter.setSMeter("0000");
    StepFrequency.setStepFrequency("5Hz");
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

    if (isRead) {
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
        } else if (prefix == "MR") {
            lastResponse =
                "MR" + MemoryBank::BankEnumToIntString(MemoryBank) +
                MemoryChannel::ChannelEnumToIntString(MemoryChannel) + ";";
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

    std::string stepFrequency = "     "; // 5 chars, blank if unknown
    if (StepStatus == Switch::SwitchEnum::ON) {
        stepFrequency = StepFrequency.getStepFrequencyString();
    }

    std::string bank =
        (MemoryBank == MemoryBank::MemoryBankEnum::UNKNOWN)
            ? " "
            : MemoryBank::BankEnumToIntString(MemoryBank); // 1 char
    std::string channel =
        (MemoryChannel == MemoryChannel::MemoryChannelEnum::UNKNOWN)
            ? "  "
            : MemoryChannel::ChannelEnumToIntString(MemoryChannel); // 2 chars

        return freq + stepFrequency +                  // Step frequency (5)
            "     " +                               // RIT frequency (5, blank)
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
    } else if (prefix == "MC") {
        if (params.length() >= 3) {
            MemoryBank::MemoryBankEnum b =
                MemoryBank::StringToBankEnum(params.substr(0, 1));
            if (b != MemoryBank::MemoryBankEnum::UNKNOWN)
                MemoryBank = b;
            MemoryChannel::MemoryChannelEnum ch =
                MemoryChannel::StringToChannelEnum(params.substr(1, 2));
            if (ch != MemoryChannel::MemoryChannelEnum::UNKNOWN)
                MemoryChannel = ch;
        } else {
            MemoryChannel::MemoryChannelEnum ch =
                MemoryChannel::StringToChannelEnum(params);
            if (ch != MemoryChannel::MemoryChannelEnum::UNKNOWN)
                MemoryChannel = ch;
        }
    }
}

std::string MockRadio::Read() {
    return lastResponse;
}

bool MockRadio::GetEstablished() {
    return established;
}
