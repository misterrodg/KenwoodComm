#include "response.h"

Response::Response(const std::string &response) : commandPrefix(CommandPrefix::CommandPrefixEnum::ZZ), parameters("")
{
    if (response.length() >= 3 && response.back() == ';')
    {
        commandPrefix = CommandPrefix::StringToCommandPrefix(response.substr(0, CommandPrefix::COMMAND_LENGTH));
        size_t endPos = response.find(';', CommandPrefix::COMMAND_LENGTH);
        if (endPos != std::string::npos)
        {
            parameters = response.substr(CommandPrefix::COMMAND_LENGTH, endPos - CommandPrefix::COMMAND_LENGTH);
        }
    }
    else
    {
        printf("Unrecognized response.\n");
    }
}

void Response::ToConsole()
{
    printf("Response: %s\nParameters: %s\n", CommandPrefix::CommandToStringExpanded(commandPrefix).c_str(), parameters.c_str());
}