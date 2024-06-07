#ifndef DCS_ID_H
#define DCS_ID_H

#include "command.h"
#include "command_prefix.h"
#include <string>

class DcsId
{
public:
    static std::string ToCommand();
};

#endif