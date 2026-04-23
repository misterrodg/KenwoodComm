#include "id.h"

ID::ID() : CommandBase(CommandPrefix::CommandPrefixEnum::ID) {
}

bool ID::supportsRead() const {
    return true;
}

bool ID::supportsAnswer() const {
    return true;
}