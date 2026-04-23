#include "sm.h"

SM::SM() : CommandBase(CommandPrefix::CommandPrefixEnum::SM) {
}

bool SM::supportsRead() const {
    return true;
}

bool SM::supportsAnswer() const {
    return true;
}