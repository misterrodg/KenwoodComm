#ifndef IF_H
#define IF_H

#include "command_information.h"

class IF : public CommandInformation {
public:
    IF();
    bool supportsRead() const override;
    bool supportsAnswer() const override;
};

#endif