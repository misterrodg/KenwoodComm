#include "tn.h"

TN::TN() : CommandTone(CommandPrefix::CommandPrefixEnum::TN) {};

bool TN::supportsSet() const {
    return true;
}
