#ifndef COMMAND_PREFIX_H
#define COMMAND_PREFIX_H

#include "command_metadata.h"
#include <string>

class CommandPrefix {
public:
    using CommandPrefixEnum = ::CommandPrefixEnum;

    static CommandPrefixEnum
    StringToCommandPrefix(std::string_view commandString);
    static std::string CommandToString(const CommandPrefixEnum& command);
    static std::string
    CommandToStringExpanded(const CommandPrefixEnum& command);
    static constexpr int COMMAND_LENGTH = 2;
};

#endif
