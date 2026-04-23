#ifndef ERROR_MESSAGE_H
#define ERROR_MESSAGE_H

#include <string>

class ErrorMessage {
public:
    ErrorMessage(const std::string& errorString, const bool& verbose);

private:
    void explain();
    std::string errorIdentifier;
};

#endif