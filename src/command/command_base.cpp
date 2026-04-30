#include "command_base.h"

bool CommandBase::supportsSet() const {
    return false;
}

bool CommandBase::supportsRead() const {
    return false;
}

bool CommandBase::supportsAnswer() const {
    return false;
}

CommandBase::ParamPolicy CommandBase::setParamPolicy() const {
    return supportsSet() ? ParamPolicy::Required : ParamPolicy::Forbidden;
}

CommandBase::ParamPolicy CommandBase::readParamPolicy() const {
    return ParamPolicy::Forbidden;
}

CommandResult CommandBase::set(const std::string& param) {
    static_cast<void>(param);
    return Error(core::ErrorCode::CommandNotImplemented,
                 "Set not supported for this command");
}

core::Result<std::string> CommandBase::buildSetCommand() {
    return core::Error{core::ErrorCode::CommandNotImplemented,
                       "Set command is not available for this command"};
}

core::Result<std::string> CommandBase::buildReadCommand() {
    return core::Error{core::ErrorCode::CommandNotImplemented,
                       "Read command is not available for this command"};
}

core::Result<std::string>
CommandBase::buildReadCommand(const std::string& param) {
    if (!param.empty() && readParamPolicy() == ParamPolicy::Forbidden) {
        return core::Error{core::ErrorCode::CommandNoParameterAllowed,
                           "Read does not accept parameters for this command"};
    }
    return buildReadCommand();
}

CommandResult CommandBase::parseAnswer(const std::string& payload) {
    static_cast<void>(payload);
    return Error(core::ErrorCode::CommandNotImplemented,
                 "Answer parsing not supported for this command");
}

std::string CommandBase::getDisplayValue() const {
    return "";
}

std::string CommandBase::ToCommand() {
    std::string command = CommandPrefix::CommandToString(commandPrefix);
    int bufferLength = CommandPrefix::COMMAND_LENGTH;

    return SerialCommand(bufferLength, command).ToString();
}