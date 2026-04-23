#include "mc.h"

MC::MC() : CommandMemory(CommandPrefix::CommandPrefixEnum::MC) {};

bool MC::supportsSet() const {
    return true;
}
