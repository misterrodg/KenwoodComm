#include "if.h"

IF::IF() : CommandInformation(CommandPrefix::CommandPrefixEnum::IF) {
}

bool IF::supportsRead() const {
    return true;
}

bool IF::supportsAnswer() const {
    return true;
}
