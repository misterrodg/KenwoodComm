#include "antenna_tuner.h"

AntennaTuner::AntennaTuner() : CommandSwitch(CommandPrefix::CommandPrefixEnum::AT)
{
    AntennaTuner::SetSwitch("ON");
}