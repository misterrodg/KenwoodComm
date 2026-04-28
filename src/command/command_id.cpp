#include "command_id.h"

CommandResult CommandID::parseAnswer(const std::string& payload) {
    return SetModelNumber(payload);
}

core::Result<std::string> CommandID::buildReadCommand() {
    if (!supportsRead()) {
        return core::Error{core::ErrorCode::CommandNotImplemented,
                           "Read command is not available for this command"};
    }

    return ToCommand();
}

std::string CommandID::getDisplayValue() const {
    return ModelNumber::ModelNumberToFriendlyString(modelNumber);
}

CommandResult CommandID::SetModelNumber(const std::string& modelNumberString) {
    ModelNumber::ModelNumberEnum modelEnum =
        ModelNumber::StringToModelNumber(modelNumberString);
    if (modelEnum != ModelNumber::ModelNumberEnum::UNRECOGNIZED) {
        modelNumber = modelEnum;
        return OK();
    }
    return Error(core::ErrorCode::InvalidModelNumber,
                 "Invalid model number: '" + modelNumberString +
                     "'. Options are: TS711, TS811, TS940, TS140/680 (or 001, "
                     "002, 003, 006)");
}
