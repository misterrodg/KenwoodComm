#ifndef IF_H
#define IF_H

#include "command_base.h"

class IF : public CommandBase {
public:
    IF();
    bool supportsRead() const override;
    bool supportsAnswer() const override;
};

#endif