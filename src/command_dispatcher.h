#ifndef COMMAND_DISPATCHER_H
#define COMMAND_DISPATCHER_H

#include "command/command_prefix.h"
#include "command_result.h"

#include <functional>
#include <map>
#include <string>

// Forward declaration to avoid circular dependency
class Session;

class CommandDispatcher {
private:
    struct CommandMetaData {
        enum ParameterMode {
            NO_PARAMETER,
            OPTIONAL_PARAMETER,
            REQUIRED_PARAMETER
        };

        ParameterMode parameterMode;
        bool expectsResponse;
        bool disabledInSafeMode;
        std::function<CommandResult(Session*)> handler;
    };

    std::map<CommandPrefix::CommandPrefixEnum, CommandMetaData> registry;
    Session* session;

public:
    CommandDispatcher(Session* session);
    CommandResult Dispatch(CommandPrefix::CommandPrefixEnum cmd,
                           const std::string& parameter);
};

#endif
