#ifndef SM_H
#define SM_H

#include "command_base.h"

class SM : public CommandBase {
public:
    SM();
    bool supportsRead() const override;
    bool supportsAnswer() const override;
};

#endif