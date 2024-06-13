#ifndef CN_H
#define CN_H

#include "command_tone.h"

class CN : public CommandTone
{
public:
    CN();
    CN(const std::string &parameter);
};

#endif