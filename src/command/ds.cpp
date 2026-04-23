#include "ds.h"

DS::DS() : CommandSwitch(CommandPrefix::CommandPrefixEnum::DS) {
}

bool DS::supportsSet() const {
    return true;
}

bool DS::supportsRead() const {
    return true;
}
