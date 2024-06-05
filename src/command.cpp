#include "command.h"

Command::CommandEnum Command::stringToCommand(const std::string &commandString)
{
    static const std::map<std::string, Command::CommandEnum> enumMap = {
        {"AI", Command::CommandEnum::AI},
        {"AT", Command::CommandEnum::AT},
        {"DI", Command::CommandEnum::DI},
        {"DN", Command::CommandEnum::DN},
        {"DS", Command::CommandEnum::DS},
        {"FA", Command::CommandEnum::FA},
        {"FB", Command::CommandEnum::FB},
        {"FN", Command::CommandEnum::FN},
        {"HD", Command::CommandEnum::HD},
        {"ID", Command::CommandEnum::ID},
        {"IF", Command::CommandEnum::IF},
        {"LK", Command::CommandEnum::LK},
        {"LO", Command::CommandEnum::LO},
        {"MC", Command::CommandEnum::MC},
        {"MD", Command::CommandEnum::MD},
        {"MR", Command::CommandEnum::MR},
        {"MS", Command::CommandEnum::MS},
        {"MW", Command::CommandEnum::MW},
        {"OS", Command::CommandEnum::OS},
        {"RC", Command::CommandEnum::RC},
        {"RD", Command::CommandEnum::RD},
        {"RU", Command::CommandEnum::RU},
        {"RT", Command::CommandEnum::RT},
        {"RX", Command::CommandEnum::RX},
        {"SC", Command::CommandEnum::SC},
        {"SH", Command::CommandEnum::SH},
        {"SL", Command::CommandEnum::SL},
        {"SP", Command::CommandEnum::SP},
        {"ST", Command::CommandEnum::ST},
        {"TN", Command::CommandEnum::TN},
        {"TO", Command::CommandEnum::TO},
        {"TX", Command::CommandEnum::TX},
        {"UP", Command::CommandEnum::UP},
        {"VB", Command::CommandEnum::VB},
        {"VR", Command::CommandEnum::VR},
        {"XT", Command::CommandEnum::XT},
    };

    auto it = enumMap.find(commandString);
    if (it != enumMap.end())
    {
        return it->second;
    }
    return CommandEnum::ZZ;
}

std::string Command::commandToString(const Command::CommandEnum &command)
{
    static const std::map<Command::CommandEnum, std::string> enumMap = {
        {Command::CommandEnum::AI, "AI"},
        {Command::CommandEnum::AT, "AT"},
        {Command::CommandEnum::DI, "DI"},
        {Command::CommandEnum::DN, "DN"},
        {Command::CommandEnum::DS, "DS"},
        {Command::CommandEnum::FA, "FA"},
        {Command::CommandEnum::FB, "FB"},
        {Command::CommandEnum::FN, "FN"},
        {Command::CommandEnum::HD, "HD"},
        {Command::CommandEnum::ID, "ID"},
        {Command::CommandEnum::IF, "IF"},
        {Command::CommandEnum::LK, "LK"},
        {Command::CommandEnum::LO, "LO"},
        {Command::CommandEnum::MC, "MC"},
        {Command::CommandEnum::MD, "MD"},
        {Command::CommandEnum::MR, "MR"},
        {Command::CommandEnum::MS, "MS"},
        {Command::CommandEnum::MW, "MW"},
        {Command::CommandEnum::OS, "OS"},
        {Command::CommandEnum::RC, "RC"},
        {Command::CommandEnum::RD, "RD"},
        {Command::CommandEnum::RU, "RU"},
        {Command::CommandEnum::RT, "RT"},
        {Command::CommandEnum::RX, "RX"},
        {Command::CommandEnum::SC, "SC"},
        {Command::CommandEnum::SH, "SH"},
        {Command::CommandEnum::SL, "SL"},
        {Command::CommandEnum::SP, "SP"},
        {Command::CommandEnum::ST, "ST"},
        {Command::CommandEnum::TN, "TN"},
        {Command::CommandEnum::TO, "TO"},
        {Command::CommandEnum::TX, "TX"},
        {Command::CommandEnum::UP, "UP"},
        {Command::CommandEnum::VB, "VB"},
        {Command::CommandEnum::VR, "VR"},
        {Command::CommandEnum::XT, "XT"},
    };

    auto it = enumMap.find(command);
    if (it != enumMap.end())
    {
        return it->second;
    }
    return "";
}
