#include "command_prefix.h"

const int CommandPrefix::COMMAND_LENGTH = 2;

CommandPrefix::CommandPrefixEnum CommandPrefix::StringToCommandPrefix(const std::string &commandString)
{
    static const std::map<std::string, CommandPrefix::CommandPrefixEnum> enumMap = {
        {"AI", CommandPrefix::CommandPrefixEnum::AI},
        {"AT", CommandPrefix::CommandPrefixEnum::AT},
        {"DI", CommandPrefix::CommandPrefixEnum::DI},
        {"DN", CommandPrefix::CommandPrefixEnum::DN},
        {"DS", CommandPrefix::CommandPrefixEnum::DS},
        {"FA", CommandPrefix::CommandPrefixEnum::FA},
        {"FB", CommandPrefix::CommandPrefixEnum::FB},
        {"FN", CommandPrefix::CommandPrefixEnum::FN},
        {"HD", CommandPrefix::CommandPrefixEnum::HD},
        {"ID", CommandPrefix::CommandPrefixEnum::ID},
        {"IF", CommandPrefix::CommandPrefixEnum::IF},
        {"LK", CommandPrefix::CommandPrefixEnum::LK},
        {"LO", CommandPrefix::CommandPrefixEnum::LO},
        {"MC", CommandPrefix::CommandPrefixEnum::MC},
        {"MD", CommandPrefix::CommandPrefixEnum::MD},
        {"MR", CommandPrefix::CommandPrefixEnum::MR},
        {"MS", CommandPrefix::CommandPrefixEnum::MS},
        {"MW", CommandPrefix::CommandPrefixEnum::MW},
        {"OS", CommandPrefix::CommandPrefixEnum::OS},
        {"RC", CommandPrefix::CommandPrefixEnum::RC},
        {"RD", CommandPrefix::CommandPrefixEnum::RD},
        {"RU", CommandPrefix::CommandPrefixEnum::RU},
        {"RT", CommandPrefix::CommandPrefixEnum::RT},
        {"RX", CommandPrefix::CommandPrefixEnum::RX},
        {"SC", CommandPrefix::CommandPrefixEnum::SC},
        {"SH", CommandPrefix::CommandPrefixEnum::SH},
        {"SL", CommandPrefix::CommandPrefixEnum::SL},
        {"SP", CommandPrefix::CommandPrefixEnum::SP},
        {"ST", CommandPrefix::CommandPrefixEnum::ST},
        {"TN", CommandPrefix::CommandPrefixEnum::TN},
        {"TO", CommandPrefix::CommandPrefixEnum::TO},
        {"TX", CommandPrefix::CommandPrefixEnum::TX},
        {"UP", CommandPrefix::CommandPrefixEnum::UP},
        {"VB", CommandPrefix::CommandPrefixEnum::VB},
        {"VR", CommandPrefix::CommandPrefixEnum::VR},
        {"XT", CommandPrefix::CommandPrefixEnum::XT},
    };

    auto it = enumMap.find(commandString);
    if (it != enumMap.end())
    {
        return it->second;
    }
    return CommandPrefixEnum::ZZ;
}

std::string CommandPrefix::CommandToString(const CommandPrefix::CommandPrefixEnum &command)
{
    static const std::map<CommandPrefix::CommandPrefixEnum, std::string> enumMap = {
        {CommandPrefix::CommandPrefixEnum::AI, "AI"},
        {CommandPrefix::CommandPrefixEnum::AT, "AT"},
        {CommandPrefix::CommandPrefixEnum::DI, "DI"},
        {CommandPrefix::CommandPrefixEnum::DN, "DN"},
        {CommandPrefix::CommandPrefixEnum::DS, "DS"},
        {CommandPrefix::CommandPrefixEnum::FA, "FA"},
        {CommandPrefix::CommandPrefixEnum::FB, "FB"},
        {CommandPrefix::CommandPrefixEnum::FN, "FN"},
        {CommandPrefix::CommandPrefixEnum::HD, "HD"},
        {CommandPrefix::CommandPrefixEnum::ID, "ID"},
        {CommandPrefix::CommandPrefixEnum::IF, "IF"},
        {CommandPrefix::CommandPrefixEnum::LK, "LK"},
        {CommandPrefix::CommandPrefixEnum::LO, "LO"},
        {CommandPrefix::CommandPrefixEnum::MC, "MC"},
        {CommandPrefix::CommandPrefixEnum::MD, "MD"},
        {CommandPrefix::CommandPrefixEnum::MR, "MR"},
        {CommandPrefix::CommandPrefixEnum::MS, "MS"},
        {CommandPrefix::CommandPrefixEnum::MW, "MW"},
        {CommandPrefix::CommandPrefixEnum::OS, "OS"},
        {CommandPrefix::CommandPrefixEnum::RC, "RC"},
        {CommandPrefix::CommandPrefixEnum::RD, "RD"},
        {CommandPrefix::CommandPrefixEnum::RU, "RU"},
        {CommandPrefix::CommandPrefixEnum::RT, "RT"},
        {CommandPrefix::CommandPrefixEnum::RX, "RX"},
        {CommandPrefix::CommandPrefixEnum::SC, "SC"},
        {CommandPrefix::CommandPrefixEnum::SH, "SH"},
        {CommandPrefix::CommandPrefixEnum::SL, "SL"},
        {CommandPrefix::CommandPrefixEnum::SP, "SP"},
        {CommandPrefix::CommandPrefixEnum::ST, "ST"},
        {CommandPrefix::CommandPrefixEnum::TN, "TN"},
        {CommandPrefix::CommandPrefixEnum::TO, "TO"},
        {CommandPrefix::CommandPrefixEnum::TX, "TX"},
        {CommandPrefix::CommandPrefixEnum::UP, "UP"},
        {CommandPrefix::CommandPrefixEnum::VB, "VB"},
        {CommandPrefix::CommandPrefixEnum::VR, "VR"},
        {CommandPrefix::CommandPrefixEnum::XT, "XT"},
    };

    auto it = enumMap.find(command);
    if (it != enumMap.end())
    {
        return it->second;
    }
    return "";
}

std::string CommandPrefix::CommandToStringExpanded(const CommandPrefix::CommandPrefixEnum &command)
{
    static const std::map<CommandPrefix::CommandPrefixEnum, std::string> enumMap = {
        {CommandPrefix::CommandPrefixEnum::AI, "AUTO INFORMATION"},
        {CommandPrefix::CommandPrefixEnum::AT, "ANTENNA TUNER"},
        {CommandPrefix::CommandPrefixEnum::DI, "DCS ID"},
        {CommandPrefix::CommandPrefixEnum::DN, "DOWN"},
        {CommandPrefix::CommandPrefixEnum::DS, "DCS"},
        {CommandPrefix::CommandPrefixEnum::FA, "FREQUENCY VFO A"},
        {CommandPrefix::CommandPrefixEnum::FB, "FREQUENCY VFO B"},
        {CommandPrefix::CommandPrefixEnum::FN, "FUNCTION"},
        {CommandPrefix::CommandPrefixEnum::HD, "SCAN HOLD"},
        {CommandPrefix::CommandPrefixEnum::ID, "ID"},
        {CommandPrefix::CommandPrefixEnum::IF, "INFORMATION"},
        {CommandPrefix::CommandPrefixEnum::LK, "LOCK"},
        {CommandPrefix::CommandPrefixEnum::LO, "LOCAL"},
        {CommandPrefix::CommandPrefixEnum::MC, "MEMORY CHANNEL"},
        {CommandPrefix::CommandPrefixEnum::MD, "MODE"},
        {CommandPrefix::CommandPrefixEnum::MR, "MEMORY READ"},
        {CommandPrefix::CommandPrefixEnum::MS, "MEMORY SCAN"},
        {CommandPrefix::CommandPrefixEnum::MW, "MEMORY WRITE"},
        {CommandPrefix::CommandPrefixEnum::OS, "OFFSET"},
        {CommandPrefix::CommandPrefixEnum::RC, "RIT CLEAR"},
        {CommandPrefix::CommandPrefixEnum::RD, "RIT DOWN"},
        {CommandPrefix::CommandPrefixEnum::RU, "RIT UP"},
        {CommandPrefix::CommandPrefixEnum::RT, "RIT"},
        {CommandPrefix::CommandPrefixEnum::RX, "RX"},
        {CommandPrefix::CommandPrefixEnum::SC, "SCAN"},
        {CommandPrefix::CommandPrefixEnum::SH, "SLOPE TUNE HIGH"},
        {CommandPrefix::CommandPrefixEnum::SL, "SLOPE TUNE LOW"},
        {CommandPrefix::CommandPrefixEnum::SP, "SPLIT"},
        {CommandPrefix::CommandPrefixEnum::ST, "STEP"},
        {CommandPrefix::CommandPrefixEnum::TN, "TONE NUMBER"},
        {CommandPrefix::CommandPrefixEnum::TO, "TONE"},
        {CommandPrefix::CommandPrefixEnum::TX, "TX"},
        {CommandPrefix::CommandPrefixEnum::UP, "UP"},
        {CommandPrefix::CommandPrefixEnum::VB, "VBT"},
        {CommandPrefix::CommandPrefixEnum::VR, "VOICE RECALL"},
        {CommandPrefix::CommandPrefixEnum::XT, "XIT"},
    };

    auto it = enumMap.find(command);
    if (it != enumMap.end())
    {
        return it->second;
    }
    return "";
}