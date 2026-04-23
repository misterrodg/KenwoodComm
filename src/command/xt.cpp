#include "xt.h"

XT::XT() : CommandSwitch(CommandPrefix::CommandPrefixEnum::XT) {
}

bool XT::supportsSet() const {
    return true;
}
