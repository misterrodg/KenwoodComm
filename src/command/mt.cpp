#include "mt.h"

MT::MT() : CommandSwitch(CommandPrefix::CommandPrefixEnum::MT) {
}

bool MT::supportsSet() const {
    return true;
}

bool MT::supportsRead() const {
    return true;
}

bool MT::supportsAnswer() const {
    return true;
}
