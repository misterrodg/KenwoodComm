#include "commandset.h"

Commandset::Commandset(Radios radioType)
{
    switch (radioType)
    {
    case Radios::TS50S:
        availableCommands = {
            CommandPrefix::CommandPrefixEnum::FA,
            CommandPrefix::CommandPrefixEnum::FB,
            CommandPrefix::CommandPrefixEnum::FN,
            CommandPrefix::CommandPrefixEnum::ID,
            CommandPrefix::CommandPrefixEnum::IF,
            CommandPrefix::CommandPrefixEnum::MD,
            CommandPrefix::CommandPrefixEnum::RX,
            CommandPrefix::CommandPrefixEnum::SP,
            CommandPrefix::CommandPrefixEnum::TX};
        break;
    case Radios::TS60S:
        availableCommands = {
            CommandPrefix::CommandPrefixEnum::FA,
            CommandPrefix::CommandPrefixEnum::FB,
            CommandPrefix::CommandPrefixEnum::FN,
            CommandPrefix::CommandPrefixEnum::ID,
            CommandPrefix::CommandPrefixEnum::IF,
            CommandPrefix::CommandPrefixEnum::MD,
            CommandPrefix::CommandPrefixEnum::RX,
            CommandPrefix::CommandPrefixEnum::SP,
            CommandPrefix::CommandPrefixEnum::TX};
        break;
    case Radios::TS140S:
        availableCommands = {
            CommandPrefix::CommandPrefixEnum::AI,
            CommandPrefix::CommandPrefixEnum::DN,
            CommandPrefix::CommandPrefixEnum::FA,
            CommandPrefix::CommandPrefixEnum::FB,
            CommandPrefix::CommandPrefixEnum::FN,
            CommandPrefix::CommandPrefixEnum::ID,
            CommandPrefix::CommandPrefixEnum::IF,
            CommandPrefix::CommandPrefixEnum::LK,
            CommandPrefix::CommandPrefixEnum::MC,
            CommandPrefix::CommandPrefixEnum::MD,
            CommandPrefix::CommandPrefixEnum::MR,
            CommandPrefix::CommandPrefixEnum::MW,
            CommandPrefix::CommandPrefixEnum::RC,
            CommandPrefix::CommandPrefixEnum::RD,
            CommandPrefix::CommandPrefixEnum::RT,
            CommandPrefix::CommandPrefixEnum::RU,
            CommandPrefix::CommandPrefixEnum::RX,
            CommandPrefix::CommandPrefixEnum::SC,
            CommandPrefix::CommandPrefixEnum::SP,
            CommandPrefix::CommandPrefixEnum::TX,
            CommandPrefix::CommandPrefixEnum::UP};
        break;
    case Radios::TS680S:
        availableCommands = {
            CommandPrefix::CommandPrefixEnum::AI,
            CommandPrefix::CommandPrefixEnum::DN,
            CommandPrefix::CommandPrefixEnum::FA,
            CommandPrefix::CommandPrefixEnum::FB,
            CommandPrefix::CommandPrefixEnum::FN,
            CommandPrefix::CommandPrefixEnum::ID,
            CommandPrefix::CommandPrefixEnum::IF,
            CommandPrefix::CommandPrefixEnum::LK,
            CommandPrefix::CommandPrefixEnum::MC,
            CommandPrefix::CommandPrefixEnum::MD,
            CommandPrefix::CommandPrefixEnum::MR,
            CommandPrefix::CommandPrefixEnum::MW,
            CommandPrefix::CommandPrefixEnum::RC,
            CommandPrefix::CommandPrefixEnum::RD,
            CommandPrefix::CommandPrefixEnum::RT,
            CommandPrefix::CommandPrefixEnum::RU,
            CommandPrefix::CommandPrefixEnum::RX,
            CommandPrefix::CommandPrefixEnum::SC,
            CommandPrefix::CommandPrefixEnum::SP,
            CommandPrefix::CommandPrefixEnum::TX,
            CommandPrefix::CommandPrefixEnum::UP};
        break;
    case Radios::TS711A:
        availableCommands = {
            CommandPrefix::CommandPrefixEnum::AI,
            CommandPrefix::CommandPrefixEnum::DI,
            CommandPrefix::CommandPrefixEnum::DN,
            CommandPrefix::CommandPrefixEnum::DS,
            CommandPrefix::CommandPrefixEnum::FA,
            CommandPrefix::CommandPrefixEnum::FB,
            CommandPrefix::CommandPrefixEnum::FN,
            CommandPrefix::CommandPrefixEnum::ID,
            CommandPrefix::CommandPrefixEnum::IF,
            CommandPrefix::CommandPrefixEnum::LK,
            CommandPrefix::CommandPrefixEnum::MC,
            CommandPrefix::CommandPrefixEnum::MD,
            CommandPrefix::CommandPrefixEnum::MR,
            CommandPrefix::CommandPrefixEnum::MW,
            CommandPrefix::CommandPrefixEnum::OS,
            CommandPrefix::CommandPrefixEnum::RC,
            CommandPrefix::CommandPrefixEnum::RD,
            CommandPrefix::CommandPrefixEnum::RT,
            CommandPrefix::CommandPrefixEnum::RU,
            CommandPrefix::CommandPrefixEnum::RX,
            CommandPrefix::CommandPrefixEnum::SC,
            CommandPrefix::CommandPrefixEnum::SP,
            CommandPrefix::CommandPrefixEnum::ST,
            CommandPrefix::CommandPrefixEnum::TN,
            CommandPrefix::CommandPrefixEnum::TO,
            CommandPrefix::CommandPrefixEnum::TX,
            CommandPrefix::CommandPrefixEnum::UP,
            CommandPrefix::CommandPrefixEnum::VR};
        break;
    case Radios::TS711E:
        availableCommands = {
            CommandPrefix::CommandPrefixEnum::AI,
            CommandPrefix::CommandPrefixEnum::DI,
            CommandPrefix::CommandPrefixEnum::DN,
            CommandPrefix::CommandPrefixEnum::DS,
            CommandPrefix::CommandPrefixEnum::FA,
            CommandPrefix::CommandPrefixEnum::FB,
            CommandPrefix::CommandPrefixEnum::FN,
            CommandPrefix::CommandPrefixEnum::ID,
            CommandPrefix::CommandPrefixEnum::IF,
            CommandPrefix::CommandPrefixEnum::LK,
            CommandPrefix::CommandPrefixEnum::MC,
            CommandPrefix::CommandPrefixEnum::MD,
            CommandPrefix::CommandPrefixEnum::MR,
            CommandPrefix::CommandPrefixEnum::MW,
            CommandPrefix::CommandPrefixEnum::OS,
            CommandPrefix::CommandPrefixEnum::RC,
            CommandPrefix::CommandPrefixEnum::RD,
            CommandPrefix::CommandPrefixEnum::RT,
            CommandPrefix::CommandPrefixEnum::RU,
            CommandPrefix::CommandPrefixEnum::RX,
            CommandPrefix::CommandPrefixEnum::SC,
            CommandPrefix::CommandPrefixEnum::SP,
            CommandPrefix::CommandPrefixEnum::ST,
            CommandPrefix::CommandPrefixEnum::TO,
            CommandPrefix::CommandPrefixEnum::TX,
            CommandPrefix::CommandPrefixEnum::UP,
            CommandPrefix::CommandPrefixEnum::VR};
        break;
    case Radios::TS790A:
        availableCommands = {
            CommandPrefix::CommandPrefixEnum::AI,
            CommandPrefix::CommandPrefixEnum::BY,
            CommandPrefix::CommandPrefixEnum::CN,
            CommandPrefix::CommandPrefixEnum::CT,
            CommandPrefix::CommandPrefixEnum::DC,
            CommandPrefix::CommandPrefixEnum::DN,
            CommandPrefix::CommandPrefixEnum::FA,
            CommandPrefix::CommandPrefixEnum::FB,
            CommandPrefix::CommandPrefixEnum::FN,
            CommandPrefix::CommandPrefixEnum::ID,
            CommandPrefix::CommandPrefixEnum::IF,
            CommandPrefix::CommandPrefixEnum::LK,
            CommandPrefix::CommandPrefixEnum::LT,
            CommandPrefix::CommandPrefixEnum::MC,
            CommandPrefix::CommandPrefixEnum::MD,
            CommandPrefix::CommandPrefixEnum::MR,
            CommandPrefix::CommandPrefixEnum::MT,
            CommandPrefix::CommandPrefixEnum::MW,
            CommandPrefix::CommandPrefixEnum::OS,
            CommandPrefix::CommandPrefixEnum::RC,
            CommandPrefix::CommandPrefixEnum::RD,
            CommandPrefix::CommandPrefixEnum::RT,
            CommandPrefix::CommandPrefixEnum::RU,
            CommandPrefix::CommandPrefixEnum::RX,
            CommandPrefix::CommandPrefixEnum::SC,
            CommandPrefix::CommandPrefixEnum::SM,
            CommandPrefix::CommandPrefixEnum::SP,
            CommandPrefix::CommandPrefixEnum::ST,
            CommandPrefix::CommandPrefixEnum::TN,
            CommandPrefix::CommandPrefixEnum::TO,
            CommandPrefix::CommandPrefixEnum::TX,
            CommandPrefix::CommandPrefixEnum::UP,
            CommandPrefix::CommandPrefixEnum::VR};
        break;
    case Radios::TS790E:
        availableCommands = {
            CommandPrefix::CommandPrefixEnum::AI,
            CommandPrefix::CommandPrefixEnum::BY,
            CommandPrefix::CommandPrefixEnum::CN,
            CommandPrefix::CommandPrefixEnum::CT,
            CommandPrefix::CommandPrefixEnum::DC,
            CommandPrefix::CommandPrefixEnum::DN,
            CommandPrefix::CommandPrefixEnum::FA,
            CommandPrefix::CommandPrefixEnum::FB,
            CommandPrefix::CommandPrefixEnum::FN,
            CommandPrefix::CommandPrefixEnum::ID,
            CommandPrefix::CommandPrefixEnum::IF,
            CommandPrefix::CommandPrefixEnum::LK,
            CommandPrefix::CommandPrefixEnum::LT,
            CommandPrefix::CommandPrefixEnum::MC,
            CommandPrefix::CommandPrefixEnum::MD,
            CommandPrefix::CommandPrefixEnum::MR,
            CommandPrefix::CommandPrefixEnum::MT,
            CommandPrefix::CommandPrefixEnum::MW,
            CommandPrefix::CommandPrefixEnum::OS,
            CommandPrefix::CommandPrefixEnum::RC,
            CommandPrefix::CommandPrefixEnum::RD,
            CommandPrefix::CommandPrefixEnum::RT,
            CommandPrefix::CommandPrefixEnum::RU,
            CommandPrefix::CommandPrefixEnum::RX,
            CommandPrefix::CommandPrefixEnum::SC,
            CommandPrefix::CommandPrefixEnum::SM,
            CommandPrefix::CommandPrefixEnum::SP,
            CommandPrefix::CommandPrefixEnum::ST,
            CommandPrefix::CommandPrefixEnum::TN,
            CommandPrefix::CommandPrefixEnum::TO,
            CommandPrefix::CommandPrefixEnum::TX,
            CommandPrefix::CommandPrefixEnum::UP,
            CommandPrefix::CommandPrefixEnum::VR};
        break;
    case Radios::TS811A:
        availableCommands = {
            CommandPrefix::CommandPrefixEnum::AI,
            CommandPrefix::CommandPrefixEnum::DI,
            CommandPrefix::CommandPrefixEnum::DN,
            CommandPrefix::CommandPrefixEnum::DS,
            CommandPrefix::CommandPrefixEnum::FA,
            CommandPrefix::CommandPrefixEnum::FB,
            CommandPrefix::CommandPrefixEnum::FN,
            CommandPrefix::CommandPrefixEnum::ID,
            CommandPrefix::CommandPrefixEnum::IF,
            CommandPrefix::CommandPrefixEnum::LK,
            CommandPrefix::CommandPrefixEnum::MC,
            CommandPrefix::CommandPrefixEnum::MD,
            CommandPrefix::CommandPrefixEnum::MR,
            CommandPrefix::CommandPrefixEnum::MW,
            CommandPrefix::CommandPrefixEnum::OS,
            CommandPrefix::CommandPrefixEnum::RC,
            CommandPrefix::CommandPrefixEnum::RD,
            CommandPrefix::CommandPrefixEnum::RT,
            CommandPrefix::CommandPrefixEnum::RU,
            CommandPrefix::CommandPrefixEnum::RX,
            CommandPrefix::CommandPrefixEnum::SC,
            CommandPrefix::CommandPrefixEnum::SP,
            CommandPrefix::CommandPrefixEnum::ST,
            CommandPrefix::CommandPrefixEnum::TN,
            CommandPrefix::CommandPrefixEnum::TO,
            CommandPrefix::CommandPrefixEnum::TX,
            CommandPrefix::CommandPrefixEnum::UP,
            CommandPrefix::CommandPrefixEnum::VR};
        break;
    case Radios::TS811B:
        availableCommands = {
            CommandPrefix::CommandPrefixEnum::AI,
            CommandPrefix::CommandPrefixEnum::DI,
            CommandPrefix::CommandPrefixEnum::DN,
            CommandPrefix::CommandPrefixEnum::DS,
            CommandPrefix::CommandPrefixEnum::FA,
            CommandPrefix::CommandPrefixEnum::FB,
            CommandPrefix::CommandPrefixEnum::FN,
            CommandPrefix::CommandPrefixEnum::ID,
            CommandPrefix::CommandPrefixEnum::IF,
            CommandPrefix::CommandPrefixEnum::LK,
            CommandPrefix::CommandPrefixEnum::MC,
            CommandPrefix::CommandPrefixEnum::MD,
            CommandPrefix::CommandPrefixEnum::MR,
            CommandPrefix::CommandPrefixEnum::MW,
            CommandPrefix::CommandPrefixEnum::OS,
            CommandPrefix::CommandPrefixEnum::RC,
            CommandPrefix::CommandPrefixEnum::RD,
            CommandPrefix::CommandPrefixEnum::RT,
            CommandPrefix::CommandPrefixEnum::RU,
            CommandPrefix::CommandPrefixEnum::RX,
            CommandPrefix::CommandPrefixEnum::SC,
            CommandPrefix::CommandPrefixEnum::SP,
            CommandPrefix::CommandPrefixEnum::ST,
            CommandPrefix::CommandPrefixEnum::TN,
            CommandPrefix::CommandPrefixEnum::TO,
            CommandPrefix::CommandPrefixEnum::TX,
            CommandPrefix::CommandPrefixEnum::UP,
            CommandPrefix::CommandPrefixEnum::VR};
        break;
    case Radios::TS811E:
        availableCommands = {
            CommandPrefix::CommandPrefixEnum::AI,
            CommandPrefix::CommandPrefixEnum::DI,
            CommandPrefix::CommandPrefixEnum::DN,
            CommandPrefix::CommandPrefixEnum::DS,
            CommandPrefix::CommandPrefixEnum::FA,
            CommandPrefix::CommandPrefixEnum::FB,
            CommandPrefix::CommandPrefixEnum::FN,
            CommandPrefix::CommandPrefixEnum::ID,
            CommandPrefix::CommandPrefixEnum::IF,
            CommandPrefix::CommandPrefixEnum::LK,
            CommandPrefix::CommandPrefixEnum::MC,
            CommandPrefix::CommandPrefixEnum::MD,
            CommandPrefix::CommandPrefixEnum::MR,
            CommandPrefix::CommandPrefixEnum::MW,
            CommandPrefix::CommandPrefixEnum::OS,
            CommandPrefix::CommandPrefixEnum::RC,
            CommandPrefix::CommandPrefixEnum::RD,
            CommandPrefix::CommandPrefixEnum::RT,
            CommandPrefix::CommandPrefixEnum::RU,
            CommandPrefix::CommandPrefixEnum::RX,
            CommandPrefix::CommandPrefixEnum::SC,
            CommandPrefix::CommandPrefixEnum::SP,
            CommandPrefix::CommandPrefixEnum::ST,
            CommandPrefix::CommandPrefixEnum::TO,
            CommandPrefix::CommandPrefixEnum::TX,
            CommandPrefix::CommandPrefixEnum::UP,
            CommandPrefix::CommandPrefixEnum::VR};
        break;
    case Radios::TS940S:
        availableCommands = {
            CommandPrefix::CommandPrefixEnum::AI,
            CommandPrefix::CommandPrefixEnum::AT,
            CommandPrefix::CommandPrefixEnum::DN,
            CommandPrefix::CommandPrefixEnum::FA,
            CommandPrefix::CommandPrefixEnum::FB,
            CommandPrefix::CommandPrefixEnum::FN,
            CommandPrefix::CommandPrefixEnum::HD,
            CommandPrefix::CommandPrefixEnum::ID,
            CommandPrefix::CommandPrefixEnum::IF,
            CommandPrefix::CommandPrefixEnum::LK,
            CommandPrefix::CommandPrefixEnum::LO,
            CommandPrefix::CommandPrefixEnum::MC,
            CommandPrefix::CommandPrefixEnum::MD,
            CommandPrefix::CommandPrefixEnum::MR,
            CommandPrefix::CommandPrefixEnum::MS,
            CommandPrefix::CommandPrefixEnum::MW,
            CommandPrefix::CommandPrefixEnum::RC,
            CommandPrefix::CommandPrefixEnum::RD,
            CommandPrefix::CommandPrefixEnum::RT,
            CommandPrefix::CommandPrefixEnum::RU,
            CommandPrefix::CommandPrefixEnum::RX,
            CommandPrefix::CommandPrefixEnum::SC,
            CommandPrefix::CommandPrefixEnum::SH,
            CommandPrefix::CommandPrefixEnum::SL,
            CommandPrefix::CommandPrefixEnum::SP,
            CommandPrefix::CommandPrefixEnum::UP,
            CommandPrefix::CommandPrefixEnum::VB,
            CommandPrefix::CommandPrefixEnum::VR,
            CommandPrefix::CommandPrefixEnum::XT,
        };
        break;
    default:
        availableCommands = {};
    }
}

std::vector<CommandPrefix::CommandPrefixEnum> Commandset::getAvailableCommands()
{
    return availableCommands;
}

void Commandset::printAvailableCommands(bool expand)
{
    printf("Your available commands are: ");
    if (expand)
    {
        printf("\n");
    }
    for (size_t i = 0; i < availableCommands.size(); ++i)
    {
        std::string value = CommandPrefix::CommandToString(availableCommands[i]);
        if (expand)
        {
            std::string expandedValue = CommandPrefix::CommandToStringExpanded(availableCommands[i]);
            printf("%s: %s\n", value.c_str(), expandedValue.c_str());
        }
        else
        {
            printf("%s ", value.c_str());
        }
    }
    printf("\n");
}

bool Commandset::verifyCommand(std::string command)
{
    bool result = false;
    std::string upperCommand = Helpers::toUpper(command);
    CommandPrefix::CommandPrefixEnum commandValue = CommandPrefix::StringToCommandPrefix(upperCommand);
    if (commandValue != CommandPrefix::CommandPrefixEnum::ZZ)
    {
        result = true;
    }
    return result;
}