#include "sc.h"

SC::SC() : CommandSwitch(CommandPrefix::CommandPrefixEnum::SC) {
}

bool SC::supportsSet() const {
    return true;
}
