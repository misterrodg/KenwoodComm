#include "session.h"

#include "core/error_reporter.h"
#include "serial.h"

Session::Session(bool inSafeMode, bool inLocalMode, ModelNumber modelNumberEnum)
    : safeMode(inSafeMode), localMode(inLocalMode), sessionOpen(true) {

    radioProfile = std::make_unique<RadioProfile>(modelNumberEnum);
    radioProfile->PrintAvailableCommands();

    serialConnection = std::make_unique<Serial>();
    if (!localMode) {
        serialConnection->Open();
    }

    dispatcher = std::make_unique<CommandDispatcher>(this, radioProfile.get());
}

Session::Session(bool inSafeMode, ModelNumber modelNumberEnum,
                 std::unique_ptr<ISerialPort> serial)
    : safeMode(inSafeMode), localMode(true), sessionOpen(true),
      serialConnection(std::move(serial)) {

    radioProfile = std::make_unique<RadioProfile>(modelNumberEnum);
    dispatcher = std::make_unique<CommandDispatcher>(this, radioProfile.get());
}

void Session::CheckCommand(std::string command) {
    bool validCommand = false;
    std::string commandUpper = Helpers::toUpper(command);

    if (commandUpper == "COMMANDS") {
        radioProfile->PrintAvailableCommands();
        validCommand = true;
    }

    if (commandUpper == "COMMANDHELP") {
        radioProfile->PrintAvailableCommands(true);
        validCommand = true;
    }

    if (startsWithCommand(commandUpper)) {
        SendCommand(commandUpper);
        validCommand = true;
    }

    if (commandUpper == "EXIT") {
        serialConnection->Close();
        printf("Closing the session.\n");
        validCommand = true;
        sessionOpen = false;
    }

    if (!validCommand) {
        printf("Invalid SerialCommand.\n");
    }
}

void Session::SendCommand(std::string command) {
    std::string commandPrefixString = getCommand(command);
    CommandPrefix::CommandPrefixEnum commandPrefixEnum =
        CommandPrefix::StringToCommandPrefix(commandPrefixString);
    std::string parameter = getParameter(command);

    CommandResult result = dispatcher->Dispatch(commandPrefixEnum, parameter);

    if (!result.OK()) {
        printError(result.error());
    }
}

bool Session::startsWithCommand(const std::string& fullCommand) const {
    std::string commandChars = getCommand(fullCommand);
    return radioProfile->VerifyCommand(commandChars);
}

std::string Session::getCommand(const std::string& fullCommand) const {
    return fullCommand.substr(0, CommandPrefix::COMMAND_LENGTH);
}

std::string Session::getParameter(const std::string& fullCommand) const {
    std::string param = fullCommand.substr(CommandPrefix::COMMAND_LENGTH);
    size_t start = param.find_first_not_of(" \t\n\r\f\v");
    return (start == std::string::npos) ? "" : param.substr(start);
}

void Session::write(const std::string& command, bool expectsResponse) {
    printf("Sending: %s\n", command.c_str());
    if (serialConnection->GetEstablished()) {
        serialConnection->Write(command);
        if (expectsResponse) {
            std::string rawResponse = serialConnection->Read();
            Response response(rawResponse);

            if (response.IsValid()) {
                response.ToConsole();
            } else {
                printf("Error parsing response: %s\n",
                       response.GetValidationResult().error().message.c_str());
            }
        }
    }
}
