#ifndef PASSBAND_H
#define PASSBAND_H

#include "core/result.h"

#include <cstdint>
#include <regex>
#include <string>

class Passband
{
public:
    Passband();
    core::Result<void> setPassband(const std::string &input);
    unsigned short int getPassband() const;
    std::string getPassbandString();

private:
    unsigned short int passband;
};

#endif