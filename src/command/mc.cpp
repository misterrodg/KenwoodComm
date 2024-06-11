#include "mc.h"

MC::MC() : CommandMemory(CommandPrefix::CommandPrefixEnum::MC){};

;
MC::MC(ModelNumber &modelNumberEnum, const std::string &parameter) : CommandMemory(CommandPrefix::CommandPrefixEnum::MC)
{
    MC::SetMemory(modelNumberEnum, parameter);
}
