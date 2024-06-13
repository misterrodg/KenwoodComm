#include "session.h"

Session::Session(bool inSafeMode, bool inLocalMode, ModelNumber modelNumberEnum)
{
    safeMode = inSafeMode;
    localMode = inLocalMode;
    sessionOpen = true;
    modelNumber = modelNumberEnum;
    Commandset commands(modelNumber.getModelNumber());
    availableCommands = commands;
    availableCommands.printAvailableCommands();

    if (localMode == false)
    {
        serialConnection.Open();
    }
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
        serialConnection.Close();
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
    std::string commandString = "";

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
                commandString = ai.ToCommand();
                write(commandString);
            }
        }
        break;
    case (CommandPrefix::CommandPrefixEnum::AT):
        if (parameter != "")
        {
            parameterWarning(commandPrefixString, parameter);
        }
        commandString = at.ToCommand();
        write(commandString);
        break;
    case (CommandPrefix::CommandPrefixEnum::DI):
        if (parameter != "")
        {
            parameterWarning(commandPrefixString, parameter);
        }
        commandString = di.ToCommand();
        write(commandString);
        break;
    case (CommandPrefix::CommandPrefixEnum::DS):
        if (parameter == "")
        {
            commandString = ds.ToCommand(true);
            write(commandString, true);
        }
        else
        {
            if (ds.SetSwitch(parameter))
            {
                commandString = ds.ToCommand();
                write(commandString);
            }
        }
        break;
    case (CommandPrefix::CommandPrefixEnum::DN):
        if (parameter != "")
        {
            parameterWarning(commandPrefixString, parameter);
        }
        commandString = dn.ToCommand();
        write(commandString);
        break;
    case (CommandPrefix::CommandPrefixEnum::FA):
        if (parameter == "")
        {
            commandString = fa.ToCommand(true);
            write(commandString, true);
        }
        else
        {
            if (fa.SetFrequency(parameter))
            {
                commandString = fa.ToCommand();
                write(commandString);
            }
        }
        break;
    case (CommandPrefix::CommandPrefixEnum::FB):
        if (parameter == "")
        {
            commandString = fb.ToCommand(true);
            write(commandString, true);
        }
        else
        {
            if (fb.SetFrequency(parameter))
            {
                commandString = fb.ToCommand();
                write(commandString);
            }
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
                commandString = fn.ToCommand();
                write(commandString);
            }
        }
        break;
    case (CommandPrefix::CommandPrefixEnum::HD):
        if (parameter == "")
        {
            commandString = hd.ToCommand(true);
            write(commandString, true);
        }
        else
        {
            if (hd.SetSwitch(parameter))
            {
                commandString = hd.ToCommand();
                write(commandString);
            }
        }
        break;
    case (CommandPrefix::CommandPrefixEnum::ID):
        if (parameter != "")
        {
            parameterWarning(commandPrefixString, parameter);
        }
        commandString = id.ToCommand();
        write(commandString);
        break;
    case (CommandPrefix::CommandPrefixEnum::IF):
        if (parameter != "")
        {
            parameterWarning(commandPrefixString, parameter);
        }
        commandString = information.ToCommand();
        write(commandString, true);
        break;
    case (CommandPrefix::CommandPrefixEnum::LK):
        if (parameter == "")
        {
            commandString = lk.ToCommand(true);
            write(commandString, true);
        }
        else
        {
            if (lk.SetSwitch(parameter))
            {
                commandString = lk.ToCommand();
                write(commandString);
            }
        }
        break;
    case (CommandPrefix::CommandPrefixEnum::LO):
        if (parameter != "")
        {
            parameterWarning(commandPrefixString, parameter);
        }
        commandString = lo.ToCommand();
        write(commandString);
        break;
    case (CommandPrefix::CommandPrefixEnum::MC):
        if (parameter == "")
        {
            printf("Command \"MC\" requires a parameter.\n");
        }
        else
        {
            if (mc.SetMemory(modelNumber, parameter))
            {
                commandString = mc.ToCommand();
                write(commandString);
            }
        }
        break;
    case (CommandPrefix::CommandPrefixEnum::MD):
        if (parameter == "")
        {
            printf("Command \"MD\" requires a parameter.\n");
        }
        else
        {
            if (md.SetMode(modelNumber, parameter))
            {
                commandString = md.ToCommand();
                write(commandString);
            }
        }
        break;
    case (CommandPrefix::CommandPrefixEnum::MS):
        if (parameter == "")
        {
            commandString = ms.ToCommand(true);
            write(commandString, true);
        }
        else
        {
            if (ms.SetSwitch(parameter))
            {
                commandString = ms.ToCommand();
                write(commandString);
            }
        }
        break;
    case (CommandPrefix::CommandPrefixEnum::RC):
        if (parameter != "")
        {
            parameterWarning(commandPrefixString, parameter);
        }
        commandString = rc.ToCommand();
        write(commandString);
        break;
    case (CommandPrefix::CommandPrefixEnum::RD):
        if (parameter != "")
        {
            parameterWarning(commandPrefixString, parameter);
        }
        commandString = rd.ToCommand();
        write(commandString);
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
                commandString = rt.ToCommand();
                write(commandString);
            }
        }
        break;
    case (CommandPrefix::CommandPrefixEnum::RU):
        if (parameter != "")
        {
            parameterWarning(commandPrefixString, parameter);
        }
        commandString = ru.ToCommand();
        write(commandString);
        break;
    case (CommandPrefix::CommandPrefixEnum::RX):
        if (parameter != "")
        {
            parameterWarning(commandPrefixString, parameter);
        }
        commandString = rx.ToCommand();
        write(commandString);
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
                commandString = sc.ToCommand();
                write(commandString);
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
                commandString = sp.ToCommand();
                write(commandString);
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
                commandString = st.ToCommand();
                write(commandString);
            }
        }
        break;
    case (CommandPrefix::CommandPrefixEnum::TN):
        if (parameter == "")
        {
            printf("Command \"TN\" requires a parameter.\n");
        }
        else
        {
            if (tn.SetTone(parameter))
            {
                commandString = tn.ToCommand();
                write(commandString);
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
                commandString = to.ToCommand();
                write(commandString);
            }
        }
        break;
    case (CommandPrefix::CommandPrefixEnum::VR):
        if (parameter != "")
        {
            parameterWarning(commandPrefixString, parameter);
        }
        commandString = vr.ToCommand();
        write(commandString);
        break;
    case (CommandPrefix::CommandPrefixEnum::TX):
        if (parameter != "")
        {
            parameterWarning(commandPrefixString, parameter);
        }
        if (safeMode)
        {
            printf("Command \"TX\" disabled in SAFE MODE.\n");
        }
        else
        {
            commandString = tx.ToCommand();
            write(commandString);
        }
        break;
    case (CommandPrefix::CommandPrefixEnum::UP):
        if (parameter != "")
        {
            parameterWarning(commandPrefixString, parameter);
        }
        commandString = up.ToCommand();
        write(commandString);
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
                commandString = xt.ToCommand();
                write(commandString);
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

void Session::write(const std::string &command, bool expectsResponse)
{
    printf("Sending: %s\n", command.c_str());
    if (serialConnection.GetEstablished())
    {
        serialConnection.Write(command);
        if (expectsResponse)
        {
            std::string response = serialConnection.Read();
            printf("%s\n", response.c_str());
        }
    }
}