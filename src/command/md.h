#ifndef MD_H
#define MD_H

#include "command_mode.h"

class MD : public CommandMode {
public:
    MD();
    bool supportsSet() const override;
};

#endif