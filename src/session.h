#ifndef SESSION_H
#define SESSION_H

#include "command_prefix.h"
#include "commandset.h"
#include "helpers.h"
#include "model_number.h"
#include <string>

class Session
{
public:
    Session(ModelNumber modelNumber);
    void CheckCommand(std::string command);
    void SendCommand(std::string command);
    bool sessionOpen = true;

private:
    bool startsWithCommand(const std::string &fullCommand);
    std::string getCommand(const std::string &fullCommand);
    std::string getParameter(const std::string &fullCommand);
    Commandset availableCommands = {};
};

#endif