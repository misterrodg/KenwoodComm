#ifndef MS_H
#define MS_H

#include "command_switch.h"

class MS : public CommandSwitch {
public:
    MS();
    bool supportsSet() const override;
    bool supportsRead() const override;
};

#endif