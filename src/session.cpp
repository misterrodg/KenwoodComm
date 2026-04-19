#include "session.h"

Session::Session(bool inSafeMode, bool inLocalMode,
                 ModelNumber modelNumberEnum) {
    safeMode = inSafeMode;
    localMode = inLocalMode;
    sessionOpen = true;
    modelNumber = modelNumberEnum;
    Commandset commands(modelNumber.getModelNumber());
    availableCommands = commands;
    availableCommands.printAvailableCommands();

    if (localMode == false) {
        serialConnection.Open();
    }

    dispatcher = std::make_unique<CommandDispatcher>(this);
}

void Session::CheckCommand(std::string command) {
    bool validCommand = false;
    std::string commandUpper = Helpers::toUpper(command);

    if (commandUpper == "COMMANDS") {
        availableCommands.printAvailableCommands();
        validCommand = true;
    }

    if (commandUpper == "COMMANDHELP") {
        availableCommands.printAvailableCommands(true);
        validCommand = true;
    }

    if (startsWithCommand(commandUpper)) {
        SendCommand(commandUpper);
        validCommand = true;
    }

    if (commandUpper == "EXIT") {
        serialConnection.Close();
        printf("Closing the session.\n");
        validCommand = true;
        sessionOpen = false;
    }

    if (!validCommand) {
        printf("Invalid Command.\n");
    }
}

void Session::SendCommand(std::string command) {
    std::string commandPrefixString = getCommand(command);
    CommandPrefix::CommandPrefixEnum commandPrefixEnum =
        CommandPrefix::StringToCommandPrefix(commandPrefixString);
    std::string parameter = getParameter(command);

    CommandResult result = dispatcher->Dispatch(commandPrefixEnum, parameter);

    if (result) {
        printf("Error: %s\n", result.value().c_str());
    }
}

bool Session::startsWithCommand(const std::string& fullCommand) {
    std::string commandChars = getCommand(fullCommand);
    return availableCommands.verifyCommand(commandChars);
}

std::string Session::getCommand(const std::string& fullCommand) {
    return fullCommand.substr(0, CommandPrefix::COMMAND_LENGTH);
}

std::string Session::getParameter(const std::string& fullCommand) {
    std::string param = fullCommand.substr(CommandPrefix::COMMAND_LENGTH);
    size_t start = param.find_first_not_of(" \t\n\r\f\v");
    return (start == std::string::npos) ? "" : param.substr(start);
}

void Session::write(const std::string& command, bool expectsResponse) {
    printf("Sending: %s\n", command.c_str());
    if (serialConnection.GetEstablished()) {
        serialConnection.Write(command);
        if (expectsResponse) {
            std::string response = serialConnection.Read();
            Response(response).ToConsole();
        }
    }
}
