#include "mr.h"

MR::MR() : CommandMemory(CommandPrefix::CommandPrefixEnum::MR) {};

bool MR::supportsRead() const {
    return true;
}

bool MR::supportsAnswer() const {
    return true;
}

CommandBase::ParamPolicy MR::readParamPolicy() const {
    return ParamPolicy::Required;
}

core::Result<std::string> MR::buildReadCommand(const std::string& param) {
    CommandResult result = SetMemory(param);
    if (!result.OK()) {
        return result.error();
    }

    return core::Result<std::string>(ToCommand());
}
