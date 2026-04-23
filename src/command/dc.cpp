#include "dc.h"

DC::DC() : CommandDestinationCode(CommandPrefix::CommandPrefixEnum::DC) {
}

bool DC::supportsSet() const {
    return true;
}

bool DC::supportsRead() const {
    return true;
}

bool DC::supportsAnswer() const {
    return true;
}
