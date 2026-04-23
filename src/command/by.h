#ifndef BY_H
#define BY_H

#include "command_busy.h"

class BY : public CommandBusy {
public:
    BY();
    bool supportsRead() const override;
    bool supportsAnswer() const override;
};

#endif
