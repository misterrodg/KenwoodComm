#ifndef SESSION_H
#define SESSION_H

#include "command/commands.h"
#include "command_dispatcher.h"
#include "core/helpers.h"
#include "radio_profile.h"
#include "response.h"
#include "serial_interface.h"
#include <memory>
#include <string>
#include <string_view>

class Session {
    friend class CommandDispatcher;

public:
    Session(bool inSafeMode, bool inLocalMode, Radios modelNumber,
            bool inFriendlyMode = false);
    Session(bool inSafeMode, Radios modelNumber,
            std::unique_ptr<ISerialPort> serial, bool inFriendlyMode = false);
    void CheckCommand(const std::string& command);
    bool safeMode;
    bool localMode;
    bool friendlyMode;
    bool sessionOpen;

private:
    void SendCommand(const std::string& command);
    bool startsWithCommand(std::string_view fullCommand) const;
    std::string getCommand(std::string_view fullCommand) const;
    std::string getParameter(std::string_view fullCommand) const;
    void write(const std::string& command, bool expectsResponse = false);

    std::unique_ptr<ISerialPort> serialConnection;
    std::unique_ptr<RadioProfile> radioProfile;
    std::unique_ptr<CommandDispatcher> dispatcher;
    std::string lastParameter;

    AI ai;
    AT at;
    BY by;
    CN cn;
    CT ct;
    DC dc;
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
