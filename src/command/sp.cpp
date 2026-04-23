#include "sp.h"

SP::SP() : CommandSwitch(CommandPrefix::CommandPrefixEnum::SP) {
}

bool SP::supportsSet() const {
    return true;
}
