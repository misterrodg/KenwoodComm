#include "vfo.h"

VFO::VFO() {}

bool VFO::SetId(const CommandPrefix::CommandPrefixEnum &vfoIdEnum)
{
    bool result = false;
    if (vfoIdEnum == CommandPrefix::CommandPrefixEnum::FA || vfoIdEnum == CommandPrefix::CommandPrefixEnum::FB)
    {
        vfoId = vfoIdEnum;
        result = true;
    }
    return result;
}

bool VFO::SetFrequency(std::string &parameter)
{
    return frequency.setFrequency(parameter);
}

std::string VFO::ToCommand(const bool &hasParam)
{
    std::string command = CommandPrefix::CommandToString(vfoId);
    int bufferLength = CommandPrefix::COMMAND_LENGTH;

    if (hasParam)
    {
        std::string frequencyString = frequency.getFrequencyString();
        bufferLength += Frequency::MAX_FREQUENCY_LENGTH;

        return Command(bufferLength, command, frequencyString).ToString();
    }

    return Command(bufferLength, command).ToString();
}