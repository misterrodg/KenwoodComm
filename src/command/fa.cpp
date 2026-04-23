#include "fa.h"

FA::FA() : CommandFrequency(CommandPrefix::CommandPrefixEnum::FA){};

FA::FA(const std::string &parameter) : CommandFrequency(CommandPrefix::CommandPrefixEnum::FA)
{
    static_cast<void>(FA::SetFrequency(parameter));
}

bool FA::supportsSet() const {
    return true;
}

bool FA::supportsRead() const {
    return true;
}

bool FA::supportsAnswer() const {
    return true;
}
