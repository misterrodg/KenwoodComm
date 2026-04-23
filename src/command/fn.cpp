#include "fn.h"

FN::FN() : CommandFunction(CommandPrefix::CommandPrefixEnum::FN) {};

bool FN::supportsSet() const {
    return true;
}
