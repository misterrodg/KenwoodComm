#include "session.h"

Session::Session(ModelNumber modelNumberEnum)
{
    sessionOpen = true;
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
        if (parameter == "")
        {
            printf("Command \"AI\" requires a parameter.\n");
        }
        else
        {
            if (ai.SetSwitch(parameter))
            {
                printf("Sending: %s\n", ai.ToCommand().c_str());
            }
        }
        break;
    case (CommandPrefix::CommandPrefixEnum::AT):
        if (parameter != "")
        {
            parameterWarning(commandPrefixString, parameter);
        }
        printf("Sending: %s\n", at.ToCommand().c_str());
        break;
    case (CommandPrefix::CommandPrefixEnum::DI):
        if (parameter != "")
        {
            parameterWarning(commandPrefixString, parameter);
        }
        printf("Sending: %s\n", di.ToCommand().c_str());
        break;
    case (CommandPrefix::CommandPrefixEnum::DS):
        if (parameter == "")
        {
            printf("Sending: %s\n", ds.ToCommand(true).c_str());
        }
        else
        {
            if (ds.SetSwitch(parameter))
            {
                printf("Sending: %s\n", ds.ToCommand().c_str());
            }
        }
        break;
    case (CommandPrefix::CommandPrefixEnum::DN):
        if (parameter != "")
        {
            parameterWarning(commandPrefixString, parameter);
        }
        printf("Sending: %s\n", dn.ToCommand().c_str());
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
            if (fn.SetFunction(modelNumber, parameter))
            {
                printf("Sending: %s\n", fn.ToCommand().c_str());
            }
        }
        break;
    case (CommandPrefix::CommandPrefixEnum::HD):
        if (parameter == "")
        {
            printf("Sending: %s\n", hd.ToCommand(true).c_str());
        }
        else
        {
            if (hd.SetSwitch(parameter))
            {
                printf("Sending: %s\n", hd.ToCommand().c_str());
            }
        }
        break;
    case (CommandPrefix::CommandPrefixEnum::ID):
        if (parameter != "")
        {
            parameterWarning(commandPrefixString, parameter);
        }
        printf("Sending: %s\n", id.ToCommand().c_str());
        break;
    case (CommandPrefix::CommandPrefixEnum::IF):
        if (parameter != "")
        {
            parameterWarning(commandPrefixString, parameter);
        }
        printf("Sending: %s\n", information.ToCommand().c_str());
        break;
    case (CommandPrefix::CommandPrefixEnum::LK):
        if (parameter == "")
        {
            printf("Sending: %s\n", lk.ToCommand(true).c_str());
        }
        else
        {
            if (lk.SetSwitch(parameter))
            {
                printf("Sending: %s\n", lk.ToCommand().c_str());
            }
        }
        break;
    case (CommandPrefix::CommandPrefixEnum::LO):
        if (parameter != "")
        {
            parameterWarning(commandPrefixString, parameter);
        }
        printf("Sending: %s\n", lo.ToCommand().c_str());
        break;
    case (CommandPrefix::CommandPrefixEnum::MS):
        if (parameter == "")
        {
            printf("Sending: %s\n", ms.ToCommand(true).c_str());
        }
        else
        {
            if (ms.SetSwitch(parameter))
            {
                printf("Sending: %s\n", ms.ToCommand().c_str());
            }
        }
        break;
    case (CommandPrefix::CommandPrefixEnum::RC):
        if (parameter != "")
        {
            parameterWarning(commandPrefixString, parameter);
        }
        printf("Sending: %s\n", rc.ToCommand().c_str());
        break;
    case (CommandPrefix::CommandPrefixEnum::RD):
        if (parameter != "")
        {
            parameterWarning(commandPrefixString, parameter);
        }
        printf("Sending: %s\n", rd.ToCommand().c_str());
        break;
    case (CommandPrefix::CommandPrefixEnum::RT):
        if (parameter == "")
        {
            printf("Command \"RT\" requires a parameter.\n");
        }
        else
        {
            if (rt.SetSwitch(parameter))
            {
                printf("Sending: %s\n", rt.ToCommand().c_str());
            }
        }
        break;
    case (CommandPrefix::CommandPrefixEnum::RU):
        if (parameter != "")
        {
            parameterWarning(commandPrefixString, parameter);
        }
        printf("Sending: %s\n", ru.ToCommand().c_str());
        break;
    case (CommandPrefix::CommandPrefixEnum::RX):
        if (parameter != "")
        {
            parameterWarning(commandPrefixString, parameter);
        }
        printf("Sending: %s\n", rx.ToCommand().c_str());
        break;
    case (CommandPrefix::CommandPrefixEnum::SC):
        if (parameter == "")
        {
            printf("Command \"SC\" requires a parameter.\n");
        }
        else
        {
            if (sc.SetSwitch(parameter))
            {
                printf("Sending: %s\n", sc.ToCommand().c_str());
            }
        }
        break;
    case (CommandPrefix::CommandPrefixEnum::SP):
        if (parameter == "")
        {
            printf("Command \"SP\" requires a parameter.\n");
        }
        else
        {
            if (sp.SetSwitch(parameter))
            {
                printf("Sending: %s\n", sp.ToCommand().c_str());
            }
        }
        break;
    case (CommandPrefix::CommandPrefixEnum::ST):
        if (parameter == "")
        {
            printf("Command \"ST\" requires a parameter.\n");
        }
        else
        {
            if (st.SetSwitch(parameter))
            {
                printf("Sending: %s\n", st.ToCommand().c_str());
            }
        }
        break;
    case (CommandPrefix::CommandPrefixEnum::TO):
        if (parameter == "")
        {
            printf("Command \"TO\" requires a parameter.\n");
        }
        else
        {
            if (to.SetSwitch(parameter))
            {
                printf("Sending: %s\n", to.ToCommand().c_str());
            }
        }
        break;
    case (CommandPrefix::CommandPrefixEnum::VR):
        if (parameter != "")
        {
            parameterWarning(commandPrefixString, parameter);
        }
        printf("Sending: %s\n", vr.ToCommand().c_str());
        break;
    case (CommandPrefix::CommandPrefixEnum::TX):
        if (parameter != "")
        {
            parameterWarning(commandPrefixString, parameter);
        }
        printf("Sending: %s\n", tx.ToCommand().c_str());
        break;
    case (CommandPrefix::CommandPrefixEnum::UP):
        if (parameter != "")
        {
            parameterWarning(commandPrefixString, parameter);
        }
        printf("Sending: %s\n", up.ToCommand().c_str());
        break;
    case (CommandPrefix::CommandPrefixEnum::XT):
        if (parameter == "")
        {
            printf("Command \"XT\" requires a parameter.\n");
        }
        else
        {
            if (xt.SetSwitch(parameter))
            {
                printf("Sending: %s\n", xt.ToCommand().c_str());
            }
        }
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