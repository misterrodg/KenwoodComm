#include "command_prefix.h"
#include <map>

CommandPrefix::CommandPrefixEnum
CommandPrefix::StringToCommandPrefix(const std::string_view commandString) {
    static const std::map<std::string_view, CommandPrefixEnum> enumMap = [] {
        std::map<std::string_view, CommandPrefixEnum> map;
        for (size_t i = 0; i < COMMAND_REGISTRY.size(); ++i) {
            map[COMMAND_REGISTRY[i].abbreviation] =
                static_cast<CommandPrefixEnum>(i);
        }
        return map;
    }();

    auto it = enumMap.find(commandString);
    if (it != enumMap.end()) {
        return it->second;
    }
    return CommandPrefixEnum::ZZ;
}

std::string CommandPrefix::CommandToString(const CommandPrefixEnum& command) {
    size_t i = static_cast<size_t>(command);
    if (i < COMMAND_REGISTRY.size()) {
        return std::string(COMMAND_REGISTRY[i].abbreviation);
    }
    return "";
}

std::string
CommandPrefix::CommandToStringExpanded(const CommandPrefixEnum& command) {
    size_t i = static_cast<size_t>(command);
    if (i < COMMAND_REGISTRY.size()) {
        return std::string(COMMAND_REGISTRY[i].expanded);
    }
    return "";
}
