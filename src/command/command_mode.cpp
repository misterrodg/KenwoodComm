#include "command_mode.h"

CommandResult CommandMode::SetMode(const ModelNumber& modelNumber,
                                   const std::string& modeString) {
    Mode::ModeEnum modeEnum = Mode::StringToMode(modeString);
    if (modeEnum != Mode::ModeEnum::UNKNOWN) {
        if (allowedForModelNumber(modelNumber, modeEnum)) {
            mode = modeEnum;
            return OK();
        } else {
            std::string modeStr = Mode::ModeToString(modeEnum);
            return Error(modeStr + " not available for the " +
                         modelNumber.getModelNumberString());
        }
    }
    return Error("Invalid mode: " + modeString);
}

std::string CommandMode::ToCommand() {
    std::string command = CommandPrefix::CommandToString(commandPrefix);
    int bufferLength = CommandPrefix::COMMAND_LENGTH;

    std::string modeString = Mode::ModeToIntString(mode);
    bufferLength += Mode::MAX_MODE_LENGTH;

    return Command(bufferLength, command, modeString).ToString();
}

bool CommandMode::allowedForModelNumber(const ModelNumber& modelNumber,
                                        Mode::ModeEnum& modeEnum) {
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
