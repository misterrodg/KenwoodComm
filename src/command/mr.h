#ifndef MR_H
#define MR_H

#include "command_memory.h"

class MR : public CommandMemory {
public:
    MR();

    bool supportsRead() const override;
    bool supportsAnswer() const override;

    ParamPolicy readParamPolicy() const override;
    core::Result<std::string>
    buildReadCommand(const std::string& param) override;
};

#endif