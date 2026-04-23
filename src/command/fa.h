#ifndef FA_H
#define FA_H

#include "command_frequency.h"

class FA : public CommandFrequency
{
public:
    FA();
    FA(const std::string &parameter);
    bool supportsSet() const override;
    bool supportsRead() const override;
    bool supportsAnswer() const override;
};

#endif