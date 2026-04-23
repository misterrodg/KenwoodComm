#include "command_mode.h"

void CommandMode::setModelNumber(const ModelNumber& modelNumberValue) {
    modelNumber = modelNumberValue;
}

CommandResult CommandMode::set(const std::string& modeString) {
    return SetMode(modeString);
}

core::Result<std::string> CommandMode::buildSetCommand() {
    if (!supportsSet()) {
        return core::Error{core::ErrorCode::CommandNotImplemented,
                           "Set command is not available for this command"};
    }

    return ToCommand();
}

CommandResult CommandMode::SetMode(const std::string& modeString) {
    Mode::ModeEnum modeEnum = Mode::StringToMode(modeString);
    if (modeEnum != Mode::ModeEnum::UNKNOWN) {
        if (allowedForModelNumber(modeEnum)) {
            mode = modeEnum;
            return OK();
        } else {
            std::string modeStr = Mode::ModeToString(modeEnum);
            return Error(core::ErrorCode::ModeNotAvailable,
                         modeStr + " not available for the " +
                             modelNumber.getModelNumberString());
        }
    }
    return Error(core::ErrorCode::InvalidMode,
                 "Invalid mode: '" + modeString +
                     "'. Options are: LSB, USB, CW, FM, AM, FSK, CWN (or "
                     "1-7)");
}

std::string CommandMode::ToCommand() {
    std::string command = CommandPrefix::CommandToString(commandPrefix);
    int bufferLength = CommandPrefix::COMMAND_LENGTH;

    std::string modeString = Mode::ModeToIntString(mode);
    bufferLength += Mode::MAX_MODE_LENGTH;

    return SerialCommand(bufferLength, command, modeString).ToString();
}

bool CommandMode::allowedForModelNumber(Mode::ModeEnum& modeEnum) {
    bool result = false;
    Radios radioEnum = modelNumber.getModelNumber();
    switch (modeEnum) {
    case Mode::ModeEnum::LSB:
        result = true;
        break;
    case Mode::ModeEnum::USB:
        result = true;
        break;
    case Mode::ModeEnum::CW:
        result = true;
        break;
    case Mode::ModeEnum::FM:
        result = true;
        break;
    case Mode::ModeEnum::AM:
        if (radioEnum == Radios::TS50S || radioEnum == Radios::TS60S ||
            radioEnum == Radios::TS140S || radioEnum == Radios::TS680S ||
            radioEnum == Radios::TS940S) {
            result = true;
        }
        break;
    case Mode::ModeEnum::FSK:
        if (radioEnum == Radios::TS940S) {
            result = true;
        }
        break;
    case Mode::ModeEnum::CWN:
        if (radioEnum == Radios::TS140S || radioEnum == Radios::TS680S) {
            result = true;
        }
        break;
    case Mode::ModeEnum::UNKNOWN:
        result = false;
        break;
    }
    return result;
}
