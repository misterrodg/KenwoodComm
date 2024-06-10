#include "fn.h"

FN::FN() : CommandFunction(CommandPrefix::CommandPrefixEnum::FN){};

FN::FN(ModelNumber &modelNumberEnum, const std::string &parameter) : CommandFunction(CommandPrefix::CommandPrefixEnum::FN)
{
    FN::SetFunction(modelNumberEnum, parameter);
}
