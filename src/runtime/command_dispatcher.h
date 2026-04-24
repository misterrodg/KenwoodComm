#ifndef COMMAND_DISPATCHER_H
#define COMMAND_DISPATCHER_H

#include "command/command_prefix.h"
#include "command/command_result.h"
#include "radio_profile.h"

#include <functional>
#include <map>
#include <memory>
#include <string>

#include "command/command_base.h"

// Forward declaration
class Session;
class RadioProfile;

class CommandDispatcher {
private:
    struct CommandMetaData {
        enum class SafeMode {
            ALLOWED,
            DISABLED
        };

        SafeMode safeMode;
        std::function<CommandBase*(Session*)> commandRef;
        std::function<CommandResult(Session*)> handler;
    };

    std::map<CommandPrefix::CommandPrefixEnum, CommandMetaData> registry;
    Session* session;
    RadioProfile* radioProfile;

    CommandResult dispatchSet(CommandBase& command,
                              const std::string& parameter);
    CommandResult dispatchRead(CommandBase& command);

public:
    CommandDispatcher(Session* session, RadioProfile* radioProfile);
    CommandResult Dispatch(CommandPrefix::CommandPrefixEnum cmd,
                           const std::string& parameter);
    CommandResult RouteAnswer(CommandPrefix::CommandPrefixEnum cmd,
                              const std::string& payload);
};

#endif
