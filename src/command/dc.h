#ifndef DC_H
#define DC_H

#include "command_destination.h"

class DC : public CommandDestinationCode {
public:
    DC();
    bool supportsSet() const override;
    bool supportsRead() const override;
    bool supportsAnswer() const override;
};

#endif
