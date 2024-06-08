#ifndef SESSION_H
#define SESSION_H

#include "auto_information.h"
#include "antenna_tuner.h"
#include "command_prefix.h"
#include "commandset.h"
#include "dcs.h"
#include "dcs_id.h"
#include "dn_up.h"
#include "fn.h"
#include "function.h"
#include "helpers.h"
#include "model_number.h"
#include "vfo.h"
#include <string>

class Session
{
public:
    Session(ModelNumber modelNumber);
    void CheckCommand(std::string command);
    void SendCommand(std::string command);
    bool sessionOpen = true;

private:
    void parameterWarning(const std::string &commandPrefixString, const std::string &parameter);
    bool startsWithCommand(const std::string &fullCommand);
    std::string getCommand(const std::string &fullCommand);
    std::string getParameter(const std::string &fullCommand);
    ModelNumber modelNumber;
    Commandset availableCommands = {};
    AutoInformation autoInformation;
    Dcs dcs;
    VFO vfoA;
    VFO vfoB;
};

#endif