#include "session.h"

Session::Session(ModelNumber modelNumberEnum)
{
    modelNumber = modelNumberEnum;
    Commandset commands(modelNumber.getModelNumber());
    availableCommands = commands;
    availableCommands.printAvailableCommands();
    vfoA.SetId(CommandPrefix::CommandPrefixEnum::FA);
    vfoB.SetId(CommandPrefix::CommandPrefixEnum::FB);
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
    case (CommandPrefix::CommandPrefixEnum::DS):
        if (parameter != "")
        {
            if (dcs.SetDcs(parameter))
            {
                printf("Sending: %s\n", dcs.ToCommand(true).c_str());
            }
        }
        else
        {
            printf("Sending: %s\n", dcs.ToCommand().c_str());
        }
        break;
    case (CommandPrefix::CommandPrefixEnum::DN):
        if (parameter != "")
        {
            parameterWarning(commandPrefixString, parameter);
        }
        printf("Sending: %s\n", DnUp(CommandPrefix::CommandPrefixEnum::DN).ToCommand().c_str());
        break;
    case (CommandPrefix::CommandPrefixEnum::FA):
        if (parameter != "")
        {
            if (vfoA.SetFrequency(parameter))
            {
                printf("Sending: %s\n", vfoA.ToCommand(true).c_str());
            }
        }
        else
        {
            printf("Sending: %s\n", vfoA.ToCommand().c_str());
        }
        break;
    case (CommandPrefix::CommandPrefixEnum::FB):
        if (parameter != "")
        {
            if (vfoB.SetFrequency(parameter))
            {
                printf("Sending: %s\n", vfoB.ToCommand(true).c_str());
            }
        }
        else
        {
            printf("Sending: %s\n", vfoB.ToCommand().c_str());
        }
        break;
    case (CommandPrefix::CommandPrefixEnum::FN):
        if (parameter == "")
        {
            printf("Command \"FN\" requires a parameter.\n");
        }
        else
        {
            Fn fn(modelNumber);
            if (fn.SetFn(parameter))
            {
                printf("Sending: %s\n", fn.ToCommand().c_str());
            }
        }
        break;
    case (CommandPrefix::CommandPrefixEnum::HD):
        if (parameter != "")
        {
            if (hold.SetHold(parameter))
            {
                printf("Sending: %s\n", hold.ToCommand(true).c_str());
            }
        }
        else
        {
            printf("Sending: %s\n", hold.ToCommand().c_str());
        }
        break;
    case (CommandPrefix::CommandPrefixEnum::ID):
        if (parameter != "")
        {
            parameterWarning(commandPrefixString, parameter);
        }
        printf("Sending: %s\n", Id::ToCommand().c_str());
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