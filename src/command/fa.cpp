#include "fa.h"

FA::FA() : CommandFrequency(CommandPrefix::CommandPrefixEnum::FA){};

FA::FA(const std::string &parameter) : CommandFrequency(CommandPrefix::CommandPrefixEnum::FA)
{
    FA::SetFrequency(parameter);
}
