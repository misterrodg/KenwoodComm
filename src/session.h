#ifndef SESSION_H
#define SESSION_H

#include "commandset.h"
#include "helpers.h"
#include "response.h"
#include "serial.h"
#include "command/commands.h"
#include "parameter/function.h"
#include "parameter/model_number.h"
#include <string>

class Session
{
public:
    Session(bool inSafeMode, bool inLocalMode, ModelNumber modelNumber);
    void CheckCommand(std::string command);
    void SendCommand(std::string command);
    bool safeMode;
    bool localMode;
    bool sessionOpen;

private:
    void parameterWarning(const std::string &commandPrefixString, const std::string &parameter);
    bool startsWithCommand(const std::string &fullCommand);
    std::string getCommand(const std::string &fullCommand);
    std::string getParameter(const std::string &fullCommand);
    void write(const std::string &command, bool expectsResponse = false);
    Serial serialConnection;
    ModelNumber modelNumber;
    Commandset availableCommands;
    AI ai;
    AT at;
    BY by;
    CN cn;
    CT ct;
    DI di;
    DS ds;
    DN dn;
    FA fa;
    FB fb;
    FN fn;
    HD hd;
    ID id;
    IF information;
    LK lk;
    LO lo;
    LT lt;
    MC mc;
    MD md;
    MS ms;
    MT mt;
    RC rc;
    RD rd;
    RT rt;
    RU ru;
    RX rx;
    SC sc;
    SP sp;
    ST st;
    TN tn;
    TO to;
    TX tx;
    UP up;
    VR vr;
    XT xt;
};

#endif