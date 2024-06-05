#include "session.h"

Session::Session(ModelNumber modelNumber)
{
    Commandset commands(modelNumber.getModelNumber());
    availableCommands = commands;
    availableCommands.printAvailableCommands();
}

void Session::SendCommand(std::string command)
{
    std::string commandUpper = Helpers::toUpper(command);

    if (commandUpper == "COMMANDS")
    {
        availableCommands.printAvailableCommands();
    }

    if (commandUpper == "EXIT")
    {
        printf("Closing the session.\n");
        sessionOpen = false;
    }
    else
    {
        bool validCommand = availableCommands.verifyCommand(command);
        if (validCommand)
        {
            printf("Command Sent.\n");
        }
        else
        {
            printf("Invalid Command.\n");
        }
    }
}
