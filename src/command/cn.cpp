#include "cn.h"

CN::CN() : CommandTone(CommandPrefix::CommandPrefixEnum::CN){};

CN::CN(const std::string &parameter) : CommandTone(CommandPrefix::CommandPrefixEnum::CN)
{
    CN::SetTone(parameter);
}
