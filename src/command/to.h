#ifndef TO_H
#define TO_H

#include "command_switch.h"

class TO : public CommandSwitch {
public:
    TO();
    bool supportsSet() const override;
};

#endif