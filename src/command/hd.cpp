#include "hd.h"

HD::HD() : CommandSwitch(CommandPrefix::CommandPrefixEnum::HD) {
}

bool HD::supportsSet() const {
    return true;
}

bool HD::supportsRead() const {
    return true;
}
