#ifndef DI_H
#define DI_H

#include "command_base.h"

class DI : public CommandBase {
public:
    DI();
    bool supportsRead() const override;
    bool supportsAnswer() const override;
};

#endif