#ifndef LK_H
#define LK_H

#include "command_switch.h"

class LK : public CommandSwitch {
public:
    LK();
    bool supportsSet() const override;
    bool supportsRead() const override;
    bool supportsAnswer() const override;
};

#endif