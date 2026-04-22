#include "fb.h"

FB::FB() : CommandFrequency(CommandPrefix::CommandPrefixEnum::FB){};

FB::FB(const std::string &parameter) : CommandFrequency(CommandPrefix::CommandPrefixEnum::FB)
{
    static_cast<void>(FB::SetFrequency(parameter));
}
