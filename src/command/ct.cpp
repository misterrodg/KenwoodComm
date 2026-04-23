#include "ct.h"

CT::CT() : CommandSwitch(CommandPrefix::CommandPrefixEnum::CT) {
}

bool CT::supportsSet() const {
    return true;
}

bool CT::supportsRead() const {
    return true;
}

bool CT::supportsAnswer() const {
    return true;
}
