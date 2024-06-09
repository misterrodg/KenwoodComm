#ifndef SESSION_H
#define SESSION_H

#include "auto_information.h"
#include "antenna_tuner.h"
#include "command_prefix.h"
#include "commandset.h"
#include "dcs.h"
#include "dcs_id.h"
#include "dn.h"
#include "fn.h"
#include "function.h"
#include "helpers.h"
#include "hold.h"
#include "id.h"
#include "if.h"
#include "lk.h"
#include "lo.h"
#include "ms.h"
#include "rc.h"
#include "rd.h"
#include "rt.h"
#include "ru.h"
#include "rx.h"
#include "sc.h"
#include "model_number.h"
#include "tx.h"
#include "up.h"
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
    Tx tx;
    Up up;
    VFO vfoA;
    VFO vfoB;
};

#endif