#ifndef LT_H
#define LT_H

#include "command_switch.h"

class LT : public CommandSwitch {
public:
    LT();
    bool supportsSet() const override;
    bool supportsRead() const override;
    bool supportsAnswer() const override;
};

#endif