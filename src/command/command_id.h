#ifndef COMMAND_ID_H
#define COMMAND_ID_H

#include "command_base.h"
#include "command_result.h"
#include "parameter/model_number.h"

class CommandID : public CommandBase {
protected:
    ModelNumber::ModelNumberEnum modelNumber =
        ModelNumber::ModelNumberEnum::UNRECOGNIZED;

public:
    CommandID() : CommandBase(CommandPrefix::CommandPrefixEnum::ID) {};

    CommandResult parseAnswer(const std::string& payload) override;
    core::Result<std::string> buildReadCommand() override;
    std::string getDisplayValue() const override;

    CommandResult SetModelNumber(const std::string& modelNumberString);
};

#endif