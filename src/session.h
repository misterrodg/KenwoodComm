#ifndef SESSION_H
#define SESSION_H

#include "command/commands.h"
#include "command_dispatcher.h"
#include "helpers.h"
#include "radio_profile.h"
#include "response.h"
#include "serial.h"
#include <memory>
#include <string>

class Session {
    friend class CommandDispatcher;

public:
    Session(bool inSafeMode, bool inLocalMode, ModelNumber modelNumber);
    void CheckCommand(std::string command);
    bool safeMode;
    bool localMode;
    bool sessionOpen;

private:
    void SendCommand(std::string command);
    bool startsWithCommand(const std::string& fullCommand) const;
    std::string getCommand(const std::string& fullCommand) const;
    std::string getParameter(const std::string& fullCommand) const;
    void write(const std::string& command, bool expectsResponse = false);

    Serial serialConnection;
    std::unique_ptr<RadioProfile> radioProfile;
    std::unique_ptr<CommandDispatcher> dispatcher;
    std::string lastParameter;

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
