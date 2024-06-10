#include "md.h"

MD::MD() : CommandMode(CommandPrefix::CommandPrefixEnum::MD){};

MD::MD(ModelNumber &modelNumberEnum, const std::string &parameter) : CommandMode(CommandPrefix::CommandPrefixEnum::MD)
{
    MD::SetMode(modelNumberEnum, parameter);
}
