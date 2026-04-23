#include "di.h"

DI::DI() : CommandBase(CommandPrefix::CommandPrefixEnum::DI) {
}

bool DI::supportsRead() const {
    return true;
}

bool DI::supportsAnswer() const {
    return true;
}