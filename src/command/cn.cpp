#include "cn.h"

CN::CN() : CommandTone(CommandPrefix::CommandPrefixEnum::CN) {};

bool CN::supportsSet() const {
    return true;
}

bool CN::supportsRead() const {
    return true;
}

bool CN::supportsAnswer() const {
    return true;
}
