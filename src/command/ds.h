#ifndef DS_H
#define DS_H

#include "command_switch.h"

class DS : public CommandSwitch {
public:
    DS();
    bool supportsSet() const override;
    bool supportsRead() const override;
};

#endif