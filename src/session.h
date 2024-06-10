#ifndef SESSION_H
#define SESSION_H

#include "commandset.h"
#include "fn.h"
#include "helpers.h"
#include "vfo.h"
#include "parameter/function.h"
#include "parameter/model_number.h"

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
    AI ai;
    AT at;
    DI di;
    DS ds;
    DN dn;
    HD hd;
    ID id;
    IF information;
    LK lk;
    LO lo;
    MS ms;
    RC rc;
    RD rd;
    RT rt;
    RU ru;
    RX rx;
    SC sc;
    SP sp;
    ST st;
    TO to;
    TX tx;
    UP up;
    VR vr;
    XT xt;
    VFO vfoA;
    VFO vfoB;
};

#endif