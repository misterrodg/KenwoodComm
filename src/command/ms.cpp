#include "ms.h"

MS::MS() : CommandSwitch(CommandPrefix::CommandPrefixEnum::MS) {
}

bool MS::supportsSet() const {
    return true;
}

bool MS::supportsRead() const {
    return true;
}
