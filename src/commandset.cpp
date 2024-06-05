#include "commandset.h"

Commandset::Commandset(Radios radioType)
{
    switch (radioType)
    {
    case Radios::TS140S:
        availableCommands = {
            Command::CommandEnum::AI,
            Command::CommandEnum::DN,
            Command::CommandEnum::FA,
            Command::CommandEnum::FB,
            Command::CommandEnum::FN,
            Command::CommandEnum::ID,
            Command::CommandEnum::IF,
            Command::CommandEnum::LK,
            Command::CommandEnum::MC,
            Command::CommandEnum::MD,
            Command::CommandEnum::MR,
            Command::CommandEnum::MW,
            Command::CommandEnum::RC,
            Command::CommandEnum::RD,
            Command::CommandEnum::RT,
            Command::CommandEnum::RU,
            Command::CommandEnum::RX,
            Command::CommandEnum::SC,
            Command::CommandEnum::SP,
            Command::CommandEnum::TX,
            Command::CommandEnum::UP};
        break;
    case Radios::TS680S:
        availableCommands = {
            Command::CommandEnum::AI,
            Command::CommandEnum::DN,
            Command::CommandEnum::FA,
            Command::CommandEnum::FB,
            Command::CommandEnum::FN,
            Command::CommandEnum::ID,
            Command::CommandEnum::IF,
            Command::CommandEnum::LK,
            Command::CommandEnum::MC,
            Command::CommandEnum::MD,
            Command::CommandEnum::MR,
            Command::CommandEnum::MW,
            Command::CommandEnum::RC,
            Command::CommandEnum::RD,
            Command::CommandEnum::RT,
            Command::CommandEnum::RU,
            Command::CommandEnum::RX,
            Command::CommandEnum::SC,
            Command::CommandEnum::SP,
            Command::CommandEnum::TX,
            Command::CommandEnum::UP};
        break;
    case Radios::TS711A:
        availableCommands = {
            Command::CommandEnum::AI,
            Command::CommandEnum::DI,
            Command::CommandEnum::DN,
            Command::CommandEnum::DS,
            Command::CommandEnum::FA,
            Command::CommandEnum::FB,
            Command::CommandEnum::FN,
            Command::CommandEnum::ID,
            Command::CommandEnum::IF,
            Command::CommandEnum::LK,
            Command::CommandEnum::MC,
            Command::CommandEnum::MD,
            Command::CommandEnum::MR,
            Command::CommandEnum::MW,
            Command::CommandEnum::OS,
            Command::CommandEnum::RC,
            Command::CommandEnum::RD,
            Command::CommandEnum::RT,
            Command::CommandEnum::RU,
            Command::CommandEnum::RX,
            Command::CommandEnum::SC,
            Command::CommandEnum::SP,
            Command::CommandEnum::ST,
            Command::CommandEnum::TN,
            Command::CommandEnum::TO,
            Command::CommandEnum::TX,
            Command::CommandEnum::UP,
            Command::CommandEnum::VR};
        break;
    case Radios::TS711E:
        availableCommands = {
            Command::CommandEnum::AI,
            Command::CommandEnum::DI,
            Command::CommandEnum::DN,
            Command::CommandEnum::DS,
            Command::CommandEnum::FA,
            Command::CommandEnum::FB,
            Command::CommandEnum::FN,
            Command::CommandEnum::ID,
            Command::CommandEnum::IF,
            Command::CommandEnum::LK,
            Command::CommandEnum::MC,
            Command::CommandEnum::MD,
            Command::CommandEnum::MR,
            Command::CommandEnum::MW,
            Command::CommandEnum::OS,
            Command::CommandEnum::RC,
            Command::CommandEnum::RD,
            Command::CommandEnum::RT,
            Command::CommandEnum::RU,
            Command::CommandEnum::RX,
            Command::CommandEnum::SC,
            Command::CommandEnum::SP,
            Command::CommandEnum::ST,
            Command::CommandEnum::TO,
            Command::CommandEnum::TX,
            Command::CommandEnum::UP,
            Command::CommandEnum::VR};
        break;
    case Radios::TS811A:
        availableCommands = {
            Command::CommandEnum::AI,
            Command::CommandEnum::DI,
            Command::CommandEnum::DN,
            Command::CommandEnum::DS,
            Command::CommandEnum::FA,
            Command::CommandEnum::FB,
            Command::CommandEnum::FN,
            Command::CommandEnum::ID,
            Command::CommandEnum::IF,
            Command::CommandEnum::LK,
            Command::CommandEnum::MC,
            Command::CommandEnum::MD,
            Command::CommandEnum::MR,
            Command::CommandEnum::MW,
            Command::CommandEnum::OS,
            Command::CommandEnum::RC,
            Command::CommandEnum::RD,
            Command::CommandEnum::RT,
            Command::CommandEnum::RU,
            Command::CommandEnum::RX,
            Command::CommandEnum::SC,
            Command::CommandEnum::SP,
            Command::CommandEnum::ST,
            Command::CommandEnum::TN,
            Command::CommandEnum::TO,
            Command::CommandEnum::TX,
            Command::CommandEnum::UP,
            Command::CommandEnum::VR};
        break;
    case Radios::TS811B:
        availableCommands = {
            Command::CommandEnum::AI,
            Command::CommandEnum::DI,
            Command::CommandEnum::DN,
            Command::CommandEnum::DS,
            Command::CommandEnum::FA,
            Command::CommandEnum::FB,
            Command::CommandEnum::FN,
            Command::CommandEnum::ID,
            Command::CommandEnum::IF,
            Command::CommandEnum::LK,
            Command::CommandEnum::MC,
            Command::CommandEnum::MD,
            Command::CommandEnum::MR,
            Command::CommandEnum::MW,
            Command::CommandEnum::OS,
            Command::CommandEnum::RC,
            Command::CommandEnum::RD,
            Command::CommandEnum::RT,
            Command::CommandEnum::RU,
            Command::CommandEnum::RX,
            Command::CommandEnum::SC,
            Command::CommandEnum::SP,
            Command::CommandEnum::ST,
            Command::CommandEnum::TN,
            Command::CommandEnum::TO,
            Command::CommandEnum::TX,
            Command::CommandEnum::UP,
            Command::CommandEnum::VR};
        break;
    case Radios::TS811E:
        availableCommands = {
            Command::CommandEnum::AI,
            Command::CommandEnum::DI,
            Command::CommandEnum::DN,
            Command::CommandEnum::DS,
            Command::CommandEnum::FA,
            Command::CommandEnum::FB,
            Command::CommandEnum::FN,
            Command::CommandEnum::ID,
            Command::CommandEnum::IF,
            Command::CommandEnum::LK,
            Command::CommandEnum::MC,
            Command::CommandEnum::MD,
            Command::CommandEnum::MR,
            Command::CommandEnum::MW,
            Command::CommandEnum::OS,
            Command::CommandEnum::RC,
            Command::CommandEnum::RD,
            Command::CommandEnum::RT,
            Command::CommandEnum::RU,
            Command::CommandEnum::RX,
            Command::CommandEnum::SC,
            Command::CommandEnum::SP,
            Command::CommandEnum::ST,
            Command::CommandEnum::TO,
            Command::CommandEnum::TX,
            Command::CommandEnum::UP,
            Command::CommandEnum::VR};
        break;
    case Radios::TS940S:
        availableCommands = {
            Command::CommandEnum::AI,
            Command::CommandEnum::AT,
            Command::CommandEnum::DN,
            Command::CommandEnum::FA,
            Command::CommandEnum::FB,
            Command::CommandEnum::FN,
            Command::CommandEnum::HD,
            Command::CommandEnum::ID,
            Command::CommandEnum::IF,
            Command::CommandEnum::LK,
            Command::CommandEnum::LO,
            Command::CommandEnum::MC,
            Command::CommandEnum::MD,
            Command::CommandEnum::MR,
            Command::CommandEnum::MS,
            Command::CommandEnum::MW,
            Command::CommandEnum::RC,
            Command::CommandEnum::RD,
            Command::CommandEnum::RT,
            Command::CommandEnum::RU,
            Command::CommandEnum::RX,
            Command::CommandEnum::SC,
            Command::CommandEnum::SH,
            Command::CommandEnum::SL,
            Command::CommandEnum::SP,
            Command::CommandEnum::UP,
            Command::CommandEnum::VB,
            Command::CommandEnum::VR,
            Command::CommandEnum::XT,
        };
        break;
    default:
        availableCommands = {};
    }
}

std::vector<Command::CommandEnum> Commandset::getAvailableCommands()
{
    return availableCommands;
}

void Commandset::printAvailableCommands()
{
    printf("Your available commands are: ");
    for (size_t i = 0; i < availableCommands.size(); ++i)
    {
        std::string value = Command::commandToString(availableCommands[i]);
        printf("%s ", value.c_str());
    }
    printf("\n");
}

bool Commandset::verifyCommand(std::string command)
{
    bool result = false;
    std::string upperCommand = Helpers::toUpper(command);
    Command::CommandEnum commandValue = Command::stringToCommand(upperCommand);
    if (commandValue != Command::CommandEnum::ZZ)
    {
        result = true;
    }
    return result;
}