#include "antenna_tuner.h"

std::string AntennaTuner::ANTENNA_TUNER_PARAMETER = "1";
const int AntennaTuner::ANTENNA_TUNER_PARAMETER_LENGTH = 1;

std::string AntennaTuner::ToCommand()
{
    std::string command = CommandPrefix::CommandToString(CommandPrefix::CommandPrefixEnum::AT);
    int bufferLength = CommandPrefix::COMMAND_LENGTH + ANTENNA_TUNER_PARAMETER_LENGTH;

    return Command(bufferLength, command, ANTENNA_TUNER_PARAMETER).ToString();
}