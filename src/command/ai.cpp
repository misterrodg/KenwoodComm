#include "ai.h"

AI::AI() : CommandSwitch(CommandPrefix::CommandPrefixEnum::AI) {
}

bool AI::supportsSet() const {
    return true;
}

bool AI::supportsAnswer() const {
    return true;
}
