#ifndef TN_H
#define TN_H

#include "command_tone.h"

class TN : public CommandTone {
public:
    TN();
    bool supportsSet() const override;
};

#endif