#ifndef MODEL_NUMBER_H
#define MODEL_NUMBER_H

#include "core/helpers.h"
#include "core/result.h"
#include "radios.h"
#include <string>

class ModelNumber {
public:
    ModelNumber();
    core::Result<void> setModelNumber(const std::string& input);
    Radios getModelNumber() const;
    std::string getModelNumberString() const;
    std::string getGeneric();
    std::string getAll();

private:
    static Radios parseUnit(const std::string& unitStr);

    Radios modelNumber = Radios::UNRECOGNIZED;
};

#endif
