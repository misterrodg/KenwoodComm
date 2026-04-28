#include "command_information.h"

CommandResult CommandInformation::parseAnswer(const std::string& payload) {
    // IF answers are fixed-width packed fields (cols per Kenwood IF-10 docs,
    // ';' at col 38): Frequency(11, cols 3-13), Step(5, cols 14-18), RIT
    // Freq(5, cols 19-23), RIT Status(1, col 24), XIT Status(1, col 25), Memory
    // Bank(1, col 26), Memory Channel(2, cols 27-28), Com Status(1, col 29),
    // Mode(1, col 30), Function(1, col 31), Scan Status(1, col 32), Split
    // Status(1, col 33), Tone Status(1, col 34), Tone Frequency(2, cols 35-36),
    // Offset(1, col 37)
    size_t pos = 0;
    auto takeField = [&](size_t length,
                         const char* name) -> core::Result<std::string> {
        if (payload.size() < pos + length) {
            return core::Error{
                core::ErrorCode::InvalidFormat,
                std::string("IF answer too short while reading ") + name};
        }

        std::string value = payload.substr(pos, length);
        pos += length;
        return value;
    };

    core::Result<std::string> frequencyField =
        takeField(Frequency::MAX_FREQUENCY_LENGTH, "frequency");
    if (!frequencyField.OK()) {
        return frequencyField.error();
    }

    core::Result<std::string> stepField =
        takeField(StepFrequency::MAX_STEP_FREQUENCY_LENGTH, "step frequency");
    if (!stepField.OK()) {
        return stepField.error();
    }

    core::Result<std::string> ritField =
        takeField(RITFrequency::MAX_RIT_FREQUENCY_LENGTH, "RIT frequency");
    if (!ritField.OK()) {
        return ritField.error();
    }

    core::Result<std::string> ritStatusField = takeField(1, "RIT status");
    if (!ritStatusField.OK()) {
        return ritStatusField.error();
    }

    core::Result<std::string> xitStatusField = takeField(1, "XIT status");
    if (!xitStatusField.OK()) {
        return xitStatusField.error();
    }

    core::Result<std::string> memoryBankField =
        takeField(MemoryBank::MAX_MEMORY_BANK_LENGTH, "memory bank");
    if (!memoryBankField.OK()) {
        return memoryBankField.error();
    }

    core::Result<std::string> memoryChannelField =
        takeField(MemoryChannel::MAX_MEMORY_CHANNEL_LENGTH, "memory channel");
    if (!memoryChannelField.OK()) {
        return memoryChannelField.error();
    }

    core::Result<std::string> communicationStateField =
        takeField(1, "communication state");
    if (!communicationStateField.OK()) {
        return communicationStateField.error();
    }

    core::Result<std::string> modeField = takeField(1, "mode");
    if (!modeField.OK()) {
        return modeField.error();
    }

    core::Result<std::string> functionField = takeField(1, "function");
    if (!functionField.OK()) {
        return functionField.error();
    }

    core::Result<std::string> scanStatusField = takeField(1, "scan status");
    if (!scanStatusField.OK()) {
        return scanStatusField.error();
    }

    core::Result<std::string> splitStatusField = takeField(1, "split status");
    if (!splitStatusField.OK()) {
        return splitStatusField.error();
    }

    core::Result<std::string> toneStatusField = takeField(1, "tone status");
    if (!toneStatusField.OK()) {
        return toneStatusField.error();
    }

    core::Result<std::string> toneFrequencyField =
        takeField(ToneFrequency::MAX_TONE_LENGTH, "tone frequency");
    if (!toneFrequencyField.OK()) {
        return toneFrequencyField.error();
    }

    core::Result<std::string> offsetField = takeField(1, "offset");
    if (!offsetField.OK()) {
        return offsetField.error();
    }

    if (pos != payload.size()) {
        return Error(core::ErrorCode::InvalidFormat,
                     "IF answer has trailing data after fixed-width fields");
    }

    auto isBlank = [](const std::string& s) {
        return s.find_first_not_of(' ') == std::string::npos;
    };

    hasFrequency = false;
    hasStepFrequency = false;
    hasRITFrequency = false;
    hasRITStatus = false;
    hasXITStatus = false;
    hasMemoryBank = false;
    hasMemoryChannel = false;
    hasCommunicationState = false;
    hasMode = false;
    hasFunction = false;
    hasScanStatus = false;
    hasSplitStatus = false;
    hasToneStatus = false;
    hasToneFrequency = false;
    hasOffset = false;

    CommandResult result;

    if (!isBlank(frequencyField.value())) {
        result = SetFrequency(frequencyField.value() + "Hz");
        if (!result.OK())
            return result;
    }

    if (!isBlank(stepField.value())) {
        result = SetStepFrequency(stepField.value() + "Hz");
        if (!result.OK())
            return result;
    }

    if (!isBlank(ritField.value())) {
        result = SetRITFrequency(ritField.value() + "Hz");
        if (!result.OK())
            return result;
    }

    if (!isBlank(ritStatusField.value())) {
        result = SetRITStatus(ritStatusField.value());
        if (!result.OK())
            return result;
    }

    if (!isBlank(xitStatusField.value())) {
        result = SetXITStatus(xitStatusField.value());
        if (!result.OK())
            return result;
    }

    if (!isBlank(memoryBankField.value())) {
        result = SetMemoryBank(memoryBankField.value());
        if (!result.OK())
            return result;
    }

    if (!isBlank(memoryChannelField.value())) {
        result = SetMemoryChannel(memoryChannelField.value());
        if (!result.OK())
            return result;
    }

    if (!isBlank(communicationStateField.value())) {
        result = SetCommunicationState(communicationStateField.value());
        if (!result.OK())
            return result;
    }

    if (!isBlank(modeField.value())) {
        result = SetMode(modeField.value());
        if (!result.OK())
            return result;
    }

    if (!isBlank(functionField.value())) {
        result = SetFunction(functionField.value());
        if (!result.OK())
            return result;
    }

    if (!isBlank(scanStatusField.value())) {
        result = SetScanStatus(scanStatusField.value());
        if (!result.OK())
            return result;
    }

    if (!isBlank(splitStatusField.value())) {
        result = SetSplitStatus(splitStatusField.value());
        if (!result.OK())
            return result;
    }

    if (!isBlank(toneStatusField.value())) {
        result = SetToneStatus(toneStatusField.value());
        if (!result.OK())
            return result;
    }

    if (!isBlank(toneFrequencyField.value())) {
        result = SetToneFrequency(toneFrequencyField.value());
        if (!result.OK())
            return result;
    }

    if (!isBlank(offsetField.value())) {
        result = SetOffset(offsetField.value());
        if (!result.OK())
            return result;
    }

    return OK();
}

std::string CommandInformation::getDisplayValue() const {
    std::string result;
    auto append = [&](const std::string& field) {
        if (!result.empty())
            result += ", ";
        result += field;
    };
    if (hasFrequency)
        append("freq=" + frequency.getFrequencyDisplayString());
    if (hasMode)
        append("mode=" + Mode::ModeToString(mode));
    if (hasFunction)
        append("function=" + Function::FunctionToString(function));
    if (hasToneStatus)
        append("tone=" + Switch::SwitchToFriendlyString(toneStatus));
    return result;
}

core::Result<std::string> CommandInformation::buildReadCommand() {
    if (!supportsRead()) {
        return core::Error{core::ErrorCode::CommandNotImplemented,
                           "Read command is not available for this command"};
    }

    return ToCommand();
}

CommandResult
CommandInformation::SetFrequency(const std::string& frequencyString) {
    core::Result<void> result = frequency.setFrequency(frequencyString);
    if (result.OK()) {
        hasFrequency = true;
        return OK();
    }
    return result.error();
}

CommandResult
CommandInformation::SetStepFrequency(const std::string& stepFrequencyString) {
    core::Result<void> result =
        stepFrequency.setStepFrequency(stepFrequencyString);
    if (result.OK()) {
        hasStepFrequency = true;
        return OK();
    }
    return result.error();
}

CommandResult
CommandInformation::SetRITFrequency(const std::string& ritFrequencyString) {
    core::Result<void> result =
        ritFrequency.setRITFrequency(ritFrequencyString);
    if (result.OK()) {
        hasRITFrequency = true;
        return OK();
    }
    return result.error();
}

CommandResult
CommandInformation::SetRITStatus(const std::string& ritStatusString) {
    Switch::SwitchEnum ritStatusEnum = Switch::StringToSwitch(ritStatusString);
    if (ritStatusEnum != Switch::SwitchEnum::UNKNOWN) {
        ritStatus = ritStatusEnum;
        hasRITStatus = true;
        return OK();
    }
    return Error(core::ErrorCode::InvalidSwitchParameter,
                 "Invalid RIT status: " + ritStatusString);
}

CommandResult
CommandInformation::SetXITStatus(const std::string& xitStatusString) {
    Switch::SwitchEnum xitStatusEnum = Switch::StringToSwitch(xitStatusString);
    if (xitStatusEnum != Switch::SwitchEnum::UNKNOWN) {
        xitStatus = xitStatusEnum;
        hasXITStatus = true;
        return OK();
    }
    return Error(core::ErrorCode::InvalidSwitchParameter,
                 "Invalid XIT status: " + xitStatusString);
}

CommandResult
CommandInformation::SetMemoryBank(const std::string& memoryBankString) {
    MemoryBank::MemoryBankEnum bankEnum =
        MemoryBank::StringToBankEnum(memoryBankString);
    if (bankEnum != MemoryBank::MemoryBankEnum::UNKNOWN) {
        memoryBank = bankEnum;
        hasMemoryBank = true;
        return OK();
    }
    return Error(core::ErrorCode::InvalidMemoryBank,
                 "Invalid memory bank: " + memoryBankString);
}

CommandResult
CommandInformation::SetMemoryChannel(const std::string& memoryChannelString) {
    MemoryChannel::MemoryChannelEnum channelEnum =
        MemoryChannel::StringToChannelEnum(memoryChannelString);
    if (channelEnum != MemoryChannel::MemoryChannelEnum::UNKNOWN) {
        memoryChannel = channelEnum;
        hasMemoryChannel = true;
        return OK();
    }
    return Error(core::ErrorCode::InvalidMemoryChannel,
                 "Invalid memory channel: " + memoryChannelString);
}

CommandResult CommandInformation::SetCommunicationState(
    const std::string& communicationStateString) {
    CommunicationState::CommunicationStateEnum communicationStateEnum =
        CommunicationState::StringToState(communicationStateString);
    if (communicationStateEnum !=
        CommunicationState::CommunicationStateEnum::UNKNOWN) {
        communicationState = communicationStateEnum;
        hasCommunicationState = true;
        return OK();
    }
    return Error(core::ErrorCode::InvalidSwitchParameter,
                 "Invalid communication state: " + communicationStateString);
}

CommandResult CommandInformation::SetMode(const std::string& modeString) {
    Mode::ModeEnum modeEnum = Mode::StringToMode(modeString);
    if (modeEnum != Mode::ModeEnum::UNKNOWN) {
        mode = modeEnum;
        hasMode = true;
        return OK();
    }
    return Error(core::ErrorCode::InvalidMode, "Invalid mode: " + modeString);
}

CommandResult
CommandInformation::SetFunction(const std::string& functionString) {
    Function::FunctionEnum functionEnum =
        Function::StringToFunction(functionString);
    if (functionEnum != Function::FunctionEnum::UNKNOWN) {
        function = functionEnum;
        hasFunction = true;
        return OK();
    }
    return Error(core::ErrorCode::InvalidFunction,
                 "Invalid function: " + functionString);
}

CommandResult
CommandInformation::SetScanStatus(const std::string& scanStatusString) {
    Switch::SwitchEnum scanStatusEnum =
        Switch::StringToSwitch(scanStatusString);
    if (scanStatusEnum != Switch::SwitchEnum::UNKNOWN) {
        scanStatus = scanStatusEnum;
        hasScanStatus = true;
        return OK();
    }
    return Error(core::ErrorCode::InvalidSwitchParameter,
                 "Invalid scan status: " + scanStatusString);
}

CommandResult
CommandInformation::SetSplitStatus(const std::string& splitStatusString) {
    Switch::SwitchEnum splitStatusEnum =
        Switch::StringToSwitch(splitStatusString);
    if (splitStatusEnum != Switch::SwitchEnum::UNKNOWN) {
        splitStatus = splitStatusEnum;
        hasSplitStatus = true;
        return OK();
    }
    return Error(core::ErrorCode::InvalidSwitchParameter,
                 "Invalid split status: " + splitStatusString);
}

CommandResult
CommandInformation::SetToneStatus(const std::string& toneStatusString) {
    Switch::SwitchEnum toneStatusEnum =
        Switch::StringToSwitch(toneStatusString);
    if (toneStatusEnum != Switch::SwitchEnum::UNKNOWN) {
        toneStatus = toneStatusEnum;
        hasToneStatus = true;
        return OK();
    }
    return Error(core::ErrorCode::InvalidSwitchParameter,
                 "Invalid tone status: " + toneStatusString);
}

CommandResult
CommandInformation::SetToneFrequency(const std::string& toneFrequencyString) {
    ToneFrequency::ToneFrequencyEnum toneFrequencyEnum =
        ToneFrequency::StringToToneFrequency(toneFrequencyString);
    if (toneFrequencyEnum != ToneFrequency::ToneFrequencyEnum::UNKNOWN) {
        toneFrequency = toneFrequencyEnum;
        hasToneFrequency = true;
        return OK();
    }
    return Error(core::ErrorCode::InvalidToneFrequency,
                 "Invalid tone frequency: " + toneFrequencyString);
}

CommandResult CommandInformation::SetOffset(const std::string& offsetString) {
    Offset::OffsetEnum offsetEnum = Offset::StringToOffset(offsetString);
    if (offsetEnum != Offset::OffsetEnum::UNKNOWN) {
        offset = offsetEnum;
        hasOffset = true;
        return OK();
    }
    return Error(core::ErrorCode::InvalidOffset,
                 "Invalid offset: " + offsetString);
}