#ifndef SESSION_H
#define SESSION_H

#include "auto_information.h"
#include "antenna_tuner.h"
#include "commandset.h"
#include "dcs.h"
#include "dcs_id.h"
#include "fn.h"
#include "function.h"
#include "helpers.h"
#include "hold.h"
#include "model_number.h"
#include "vfo.h"

#include "command/commands.h"
#include <string>

class Session
{
public:
    Session(ModelNumber modelNumber);
    void CheckCommand(std::string command);
    void SendCommand(std::string command);
    bool sessionOpen;

private:
    void parameterWarning(const std::string &commandPrefixString, const std::string &parameter);
    bool startsWithCommand(const std::string &fullCommand);
    std::string getCommand(const std::string &fullCommand);
    std::string getParameter(const std::string &fullCommand);
    ModelNumber modelNumber;
    Commandset availableCommands;
    AntennaTuner antennaTuner;
    AutoInformation autoInformation;
    DcsId dcsId;
    Dcs dcs;
    Dn dn;
    Hold hold;
    Id id;
    If information;
    Lk lk;
    Lo lo;
    Ms ms;
    Rc rc;
    Rd rd;
    Rt rt;
    Ru ru;
    Rx rx;
    Sc sc;
    Sp sp;
    St st;
    To to;
    Tx tx;
    Up up;
    Vr vr;
    Xt xt;
    VFO vfoA;
    VFO vfoB;
};

#endif