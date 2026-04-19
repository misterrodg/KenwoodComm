#ifndef RADIO_PROFILE_H
#define RADIO_PROFILE_H

#include "command/command_prefix.h"
#include "commandset.h"
#include "parameter/model_number.h"
#include <vector>

class RadioProfile {
private:
    Radios radioType;
    Commandset availableCommands;
    ModelNumber modelNumber;

public:
    RadioProfile(ModelNumber modelNumber);
    Radios GetRadioType() const;
    const ModelNumber& GetModelNumber() const;
    bool IsCommandAvailable(CommandPrefix::CommandPrefixEnum cmd) const;
    void PrintAvailableCommands(bool expanded = false) const;
    bool VerifyCommand(const std::string& commandStr) const;
};

#endif
