#ifndef MC_H
#define MC_H

#include "command_memory.h"

class MC : public CommandMemory {
public:
    MC();
    bool supportsSet() const override;
};

#endif