#ifndef RADIO_PROFILE_H
#define RADIO_PROFILE_H

#include "command/command_prefix.h"
#include "core/radio.h"
#include "commandset.h"
#include <vector>

class RadioProfile {
private:
    Radios radioType;
    Commandset availableCommands;
    Radios modelNumber;

public:
    RadioProfile(Radios modelNumber);
    Radios GetRadioType() const;
    Radios GetModelNumber() const;
    bool IsCommandAvailable(CommandPrefix::CommandPrefixEnum cmd) const;
    void PrintAvailableCommands(bool expanded = false) const;
    bool VerifyCommand(const std::string& commandStr) const;
};

#endif
