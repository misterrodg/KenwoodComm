#ifndef FA_H
#define FA_H

#include "command_frequency.h"

class FA : public CommandFrequency
{
public:
    FA();
    FA(const std::string &parameter);
};

#endif