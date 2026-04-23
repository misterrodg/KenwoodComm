#ifndef MT_H
#define MT_H

#include "command_switch.h"

class MT : public CommandSwitch {
public:
    MT();
    bool supportsSet() const override;
    bool supportsRead() const override;
    bool supportsAnswer() const override;
};

#endif