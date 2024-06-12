#include "tn.h"

TN::TN() : CommandTone(CommandPrefix::CommandPrefixEnum::TN){};

TN::TN(const std::string &parameter) : CommandTone(CommandPrefix::CommandPrefixEnum::TN)
{
    TN::SetTone(parameter);
}
