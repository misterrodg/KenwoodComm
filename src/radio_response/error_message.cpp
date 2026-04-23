#include "error_message.h"

#include "core/error_code.h"
#include "core/error_reporter.h"

ErrorMessage::ErrorMessage(const std::string& errorString,
                           const bool& verbose) {
    errorIdentifier = errorString;
    if (verbose) {
        explain();
    } else {
        printError(core::Error{core::ErrorCode::RadioError, errorString});
    }
};

void ErrorMessage::explain() {
    std::string result = "";
    if (strcmp(errorIdentifier.c_str(), "?;") == 0) {
        result = "Command syntax incorrect, system busy.";
    }
    if (strcmp(errorIdentifier.c_str(), "E;") == 0) {
        result = "Overrun or framing error.";
    }
    if (strcmp(errorIdentifier.c_str(), "O;") == 0) {
        result = "Message received but processing could not complete.";
    }
    printError(core::Error{core::ErrorCode::RadioError, result});
}