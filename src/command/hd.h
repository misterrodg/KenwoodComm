#ifndef HD_H
#define HD_H

#include "command_switch.h"

class HD : public CommandSwitch {
public:
    HD();
    bool supportsSet() const override;
    bool supportsRead() const override;
};

#endif
