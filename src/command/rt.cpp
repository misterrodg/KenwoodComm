#include "rt.h"

RT::RT() : CommandSwitch(CommandPrefix::CommandPrefixEnum::RT) {
}

bool RT::supportsSet() const {
    return true;
}
