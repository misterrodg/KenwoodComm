#ifndef COMMAND_DISPATCHER_H
#define COMMAND_DISPATCHER_H

#include "command/command_prefix.h"
#include "command/command_result.h"
#include "radio_profile.h"

#include <functional>
#include <map>
#include <memory>
#include <string>

// Forward declaration
class Session;
class RadioProfile;

class CommandDispatcher {
private:
    struct CommandMetaData {
        enum class Parameter {
            NONE,
            OPTIONAL,
            REQUIRED
        };

        enum class SafeMode {
            ALLOWED,
            DISABLED
        };

        Parameter parameter;
        SafeMode safeMode;
        std::function<CommandResult(Session*)> handler;
    };

    std::map<CommandPrefix::CommandPrefixEnum, CommandMetaData> registry;
    Session* session;
    RadioProfile* radioProfile;

public:
    CommandDispatcher(Session* session, RadioProfile* radioProfile);
    CommandResult Dispatch(CommandPrefix::CommandPrefixEnum cmd,
                           const std::string& parameter);
};

#endif
