#include "md.h"

MD::MD() : CommandMode(CommandPrefix::CommandPrefixEnum::MD) {};

bool MD::supportsSet() const {
    return true;
}
