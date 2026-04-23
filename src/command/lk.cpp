#include "lk.h"

LK::LK() : CommandSwitch(CommandPrefix::CommandPrefixEnum::LK) {
}

bool LK::supportsSet() const {
    return true;
}

bool LK::supportsRead() const {
    return true;
}

bool LK::supportsAnswer() const {
    return true;
}
