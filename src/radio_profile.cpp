#include "radio_profile.h"

RadioProfile::RadioProfile(ModelNumber modelNumber)
    : radioType(modelNumber.getModelNumber()), availableCommands(radioType),
      modelNumber(modelNumber) {
}

Radios RadioProfile::GetRadioType() const {
    return radioType;
}

const ModelNumber& RadioProfile::GetModelNumber() const {
    return modelNumber;
}

bool RadioProfile::IsCommandAvailable(
    CommandPrefix::CommandPrefixEnum cmd) const {
    auto available = availableCommands.getAvailableCommands();
    return std::find(available.begin(), available.end(), cmd) !=
           available.end();
}

void RadioProfile::PrintAvailableCommands(bool expanded) const {
    availableCommands.printAvailableCommands(expanded);
}

bool RadioProfile::VerifyCommand(const std::string& commandStr) const {
    return availableCommands.verifyCommand(commandStr);
}
