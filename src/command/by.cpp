#include "by.h"

BY::BY() : CommandBusy(CommandPrefix::CommandPrefixEnum::BY) {
}

bool BY::supportsRead() const {
    return true;
}

bool BY::supportsAnswer() const {
    return true;
}
