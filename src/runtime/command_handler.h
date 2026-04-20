#ifndef COMMAND_HANDLER_H
#define COMMAND_HANDLER_H

#include "command/command_prefix.h"
#include "command/command_result.h"
#include <string>

// Forward declaration
class Session;

class CommandHandler {
public:
    virtual ~CommandHandler() = default;
    virtual CommandResult Execute(Session* session,
                                  const std::string& parameter) = 0;
    virtual std::string GetCommandName() const = 0;
};

#endif
