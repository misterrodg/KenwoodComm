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
    std::string commandPrefixString = getCommand(command);
    CommandPrefix::CommandPrefixEnum commandPrefixEnum = CommandPrefix::StringToCommandPrefix(commandPrefixString);
    std::string parameter = getParameter(command);

    switch (commandPrefixEnum)
    {
    case (CommandPrefix::CommandPrefixEnum::AI):
        if (autoInformation.SetAutoInformation(parameter))
        {
            printf("Sending: %s\n", autoInformation.ToCommand().c_str());
        }
        break;
    case (CommandPrefix::CommandPrefixEnum::AT):
        if (parameter != "")
        {
            parameterWarning(commandPrefixString, parameter);
        }
        printf("Sending: %s\n", AntennaTuner::ToCommand().c_str());
        break;
    case (CommandPrefix::CommandPrefixEnum::DI):
        if (parameter != "")
        {
            parameterWarning(commandPrefixString, parameter);
        }
        printf("Sending: %s\n", DcsId::ToCommand().c_str());
        break;
    case (CommandPrefix::CommandPrefixEnum::DN):
        if (parameter != "")
        {
            parameterWarning(commandPrefixString, parameter);
        }
        printf("Sending: %s\n", DnUp(CommandPrefix::CommandPrefixEnum::DN).ToCommand().c_str());
        break;
    case (CommandPrefix::CommandPrefixEnum::UP):
        if (parameter != "")
        {
            parameterWarning(commandPrefixString, parameter);
        }
        printf("Sending: %s\n", DnUp(CommandPrefix::CommandPrefixEnum::UP).ToCommand().c_str());
        break;
    default:
        printf("Command \"%s\" Not Implemented.\n", command.c_str());
    }
}

void Session::parameterWarning(const std::string &commandPrefixString, const std::string &parameter)
{
    printf("%s accepts no parameters. Ignoring \"%s\" and sending standard %s command.\n", commandPrefixString.c_str(), parameter.c_str(), commandPrefixString.c_str());
}

bool Session::startsWithCommand(const std::string &fullCommand)
{
    std::string commandChars = getCommand(fullCommand);
    return availableCommands.verifyCommand(commandChars);
}

std::string Session::getCommand(const std::string &fullCommand)
{
    return fullCommand.substr(0, CommandPrefix::COMMAND_LENGTH);
}

std::string Session::getParameter(const std::string &fullCommand)
{
    return fullCommand.substr(CommandPrefix::COMMAND_LENGTH);
}