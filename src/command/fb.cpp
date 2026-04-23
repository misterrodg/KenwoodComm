#include "fb.h"

FB::FB() : CommandFrequency(CommandPrefix::CommandPrefixEnum::FB){};

FB::FB(const std::string &parameter) : CommandFrequency(CommandPrefix::CommandPrefixEnum::FB)
{
    static_cast<void>(FB::SetFrequency(parameter));
}

bool FB::supportsSet() const {
    return true;
}

bool FB::supportsRead() const {
    return true;
}

bool FB::supportsAnswer() const {
    return true;
}
