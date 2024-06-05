#ifndef SESSION_H
#define SESSION_H

#include "commandset.h"
#include "helpers.h"
#include "model_number.h"
#include <string>

class Session
{
public:
    Session(ModelNumber modelNumber);
    void SendCommand(std::string command);
    bool sessionOpen = true;

private:
    Commandset availableCommands = {};
};

#endif