#ifndef RADIO_H
#define RADIO_H

#include "core/result.h"

#include <string>

enum class Radios {
    TS50S,
    TS60S,
    TS140S,
    TS680S,
    TS711A,
    TS711E,
    TS790A,
    TS790E,
    TS811A,
    TS811B,
    TS811E,
    TS940S,
    UNRECOGNIZED
};

namespace Radio {

core::Result<Radios> parse(const std::string& modelStr);
std::string toString(Radios radio);
std::string toGeneric(Radios radio);
std::string allSupported();

} // namespace Radio

#endif