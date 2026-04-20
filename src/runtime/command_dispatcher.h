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
    RadioProfile* radioProfile;

public:
    CommandDispatcher(Session* session, RadioProfile* radioProfile);
    CommandResult Dispatch(CommandPrefix::CommandPrefixEnum cmd,
                           const std::string& parameter);
};

#endif
