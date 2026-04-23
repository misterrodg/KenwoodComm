#include "lt.h"

LT::LT() : CommandSwitch(CommandPrefix::CommandPrefixEnum::LT) {
}

bool LT::supportsSet() const {
    return true;
}

bool LT::supportsRead() const {
    return true;
}

bool LT::supportsAnswer() const {
    return true;
}
