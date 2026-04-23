#ifndef CN_H
#define CN_H

#include "command_tone.h"

class CN : public CommandTone {
public:
    CN();
    bool supportsSet() const override;
    bool supportsRead() const override;
    bool supportsAnswer() const override;
};

#endif
