#ifndef MODEL_NUMBER_H
#define MODEL_NUMBER_H

#include "helpers.h"
#include "radios.h"
#include <string>

class ModelNumber
{
public:
    ModelNumber();
    bool setModelNumber(const std::string &input);
    Radios getModelNumber();
    std::string getModelNumberString();
    std::string getGeneric();

private:
    static Radios parseUnit(const std::string &unitStr);

    Radios modelNumber = Radios::UNRECOGNIZED;
};

#endif
