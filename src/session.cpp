#include "session.h"

Session::Session(ModelNumber modelNumber)
{
    Commandset commands(modelNumber.getModelNumber());
    availableCommands = commands;
    availableCommands.printAvailableCommands();
}

void Session::CheckCommand(std::string command)
{
    bool validCommand = false;
    std::string commandUpper = Helpers::toUpper(command);

    if (commandUpper == "COMMANDS")
    {
        availableCommands.printAvailableCommands();
        validCommand = true;
    }

    if (commandUpper == "COMMANDHELP")
    {
        availableCommands.printAvailableCommands(true);
        validCommand = true;
    }

    if (startsWithCommand(commandUpper))
    {
        SendCommand(commandUpper);
        validCommand = true;
    }

    if (commandUpper == "EXIT")
    {
        printf("Closing the session.\n");
        validCommand = true;
        sessionOpen = false;
    }

    if (!validCommand)
    {
        printf("Invalid Command.\n");
    }
}

void Session::SendCommand(std::string command)
{
    printf("Sending: %s\n", command.c_str());
}

bool Session::startsWithCommand(const std::string &fullCommand)
{
    std::string commandChars = fullCommand.substr(0, CommandPrefix::COMMAND_LENGTH);
    return availableCommands.verifyCommand(commandChars);
}
