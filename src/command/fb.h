#ifndef FB_H
#define FB_H

#include "command_frequency.h"

class FB : public CommandFrequency
{
public:
    FB();
    FB(const std::string &parameter);
};

#endif