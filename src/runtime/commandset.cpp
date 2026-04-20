#include "commandset.h"
#include "commandset_metadata.h"

Commandset::Commandset(Radios radioType) {
    for (const auto& radioSet : RADIO_COMMANDSETS) {
        if (radioSet.radioType == radioType) {
            availableCommands = radioSet.commands;
            return;
        }
    }

    availableCommands = {};
}

std::vector<CommandPrefix::CommandPrefixEnum>
Commandset::getAvailableCommands() const {
    return availableCommands;
}

void Commandset::printAvailableCommands(bool expand) const {
    printf("Available commands are: ");
    if (expand) {
        printf("\n");
    }
    for (size_t i = 0; i < availableCommands.size(); ++i) {
        std::string value =
            CommandPrefix::CommandToString(availableCommands[i]);
        if (expand) {
            std::string expandedValue =
                CommandPrefix::CommandToStringExpanded(availableCommands[i]);
            printf("%s: %s\n", value.c_str(), expandedValue.c_str());
        } else {
            printf("%s ", value.c_str());
        }
    }
    printf("\n");
}

bool Commandset::verifyCommand(std::string command) const {
    bool result = false;
    std::string upperCommand = Helpers::toUpper(command);
    CommandPrefix::CommandPrefixEnum commandValue =
        CommandPrefix::StringToCommandPrefix(upperCommand);
    if (commandValue != CommandPrefix::CommandPrefixEnum::ZZ) {
        result = true;
    }
    return result;
}
