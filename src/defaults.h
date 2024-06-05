#ifndef DEFAULTS_H
#define DEFAULTS_H

#include "call_sign.h"
#include "model_number.h"
#include <iostream>
#include <fstream>
#include <string>

class Defaults
{
public:
    Defaults(const std::string filePath);
    std::string getCallSign();
    bool setCallSign(const std::string newCallSign);
    ModelNumber getModelNumber();
    std::string getModelNumberString();
    bool setModelNumber(const std::string newModelNumber);
    void save();

private:
    void readDefaults();
    const std::string CALLSIGN_KEY = "CALLSIGN=";
    const std::string MODEL_NUMBER_KEY = "MODEL_NUMBER=";
    const std::string filePath;
    bool defaultsChanged = false;
    ModelNumber modelNumber;
    CallSign callSign;
};

#endif