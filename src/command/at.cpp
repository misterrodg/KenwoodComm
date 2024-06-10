#include "at.h"

AT::AT() : CommandSwitch(CommandPrefix::CommandPrefixEnum::AT)
{
    AT::SetSwitch("ON");
}