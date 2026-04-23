#ifndef CT_H
#define CT_H

#include "command_switch.h"

class CT : public CommandSwitch {
public:
    CT();
    bool supportsSet() const override;
    bool supportsRead() const override;
    bool supportsAnswer() const override;
};

#endif