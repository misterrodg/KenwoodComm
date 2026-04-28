#include "session.h"

#include "core/error_reporter.h"
#include "serial.h"
#include "mock/mock_radio.h"

Session::Session(bool inSafeMode, bool inLocalMode, Radios modelNumberEnum,
                 bool inFriendlyMode)
    : safeMode(inSafeMode), localMode(inLocalMode),
      friendlyMode(inFriendlyMode), sessionOpen(true) {

    radioProfile = std::make_unique<RadioProfile>(modelNumberEnum);
    radioProfile->PrintAvailableCommands();

    if (localMode) {
        serialConnection = std::make_unique<MockRadio>();
        serialConnection->Open();
    } else {
        serialConnection = std::make_unique<Serial>();
        serialConnection->Open();
    }

    dispatcher = std::make_unique<CommandDispatcher>(this, radioProfile.get());
}

Session::Session(bool inSafeMode, Radios modelNumberEnum,
                 std::unique_ptr<ISerialPort> serial, bool inFriendlyMode)
    : safeMode(inSafeMode), localMode(true), friendlyMode(inFriendlyMode),
      sessionOpen(true), serialConnection(std::move(serial)) {

    radioProfile = std::make_unique<RadioProfile>(modelNumberEnum);
    dispatcher = std::make_unique<CommandDispatcher>(this, radioProfile.get());
}

void Session::CheckCommand(const std::string& command) {
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
        printError(core::Error{core::ErrorCode::InvalidCommand,
                               "Invalid SerialCommand."});
    }
}

void Session::SendCommand(const std::string& command) {
    std::string commandPrefixString = getCommand(command);
    CommandPrefix::CommandPrefixEnum commandPrefixEnum =
        CommandPrefix::StringToCommandPrefix(commandPrefixString);
    std::string parameter = getParameter(command);

    CommandResult result = dispatcher->Dispatch(commandPrefixEnum, parameter);

    if (!result.OK()) {
        printError(result.error());
    }
}

bool Session::startsWithCommand(std::string_view fullCommand) const {
    std::string commandChars = getCommand(fullCommand);
    return radioProfile->VerifyCommand(commandChars);
}

std::string Session::getCommand(std::string_view fullCommand) const {
    return std::string(fullCommand.substr(0, CommandPrefix::COMMAND_LENGTH));
}

std::string Session::getParameter(std::string_view fullCommand) const {
    std::string param(fullCommand.substr(CommandPrefix::COMMAND_LENGTH));
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
                if (friendlyMode) {
                    response.ToConsole();
                } else {
                    printf("Response: %s\n", rawResponse.c_str());
                }

                CommandResult answerResult = dispatcher->RouteAnswer(
                    response.GetCommandPrefix(), response.GetParameters());
                if (!answerResult.OK()) {
                    printError(answerResult.error());
                } else if (friendlyMode) {
                    std::string decoded = dispatcher->GetAnswerDisplayValue(
                        response.GetCommandPrefix());
                    if (!decoded.empty()) {
                        printf("Decoded: %s\n", decoded.c_str());
                    }
                }
            } else {
                printError(response.GetValidationResult().error());
            }
        }
    }
}
