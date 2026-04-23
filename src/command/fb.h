#ifndef FB_H
#define FB_H

#include "command_frequency.h"

class FB : public CommandFrequency
{
public:
    FB();
    FB(const std::string &parameter);
    bool supportsSet() const override;
    bool supportsRead() const override;
    bool supportsAnswer() const override;
};

#endif