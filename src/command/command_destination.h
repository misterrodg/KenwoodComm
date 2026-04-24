#ifndef COMMAND_DESTINATION_H
#define COMMAND_DESTINATION_H

#include "command_base.h"
#include "command_result.h"
#include "parameter/destination_code.h"

class CommandDestinationCode : public CommandBase {
protected:
    DestinationCode::CodeEnum destination = DestinationCode::CodeEnum::MAIN;

public:
    CommandDestinationCode(CommandPrefix::CommandPrefixEnum prefix)
        : CommandBase(prefix) {};

    CommandResult set(const std::string& codeString) override;
    CommandResult parseAnswer(const std::string& payload) override;
    core::Result<std::string> buildSetCommand() override;
    core::Result<std::string> buildReadCommand() override;

    std::string ToCommand(bool readStatus = false);
    CommandResult SetDestinationCode(const std::string& codeString);
};

#endif
