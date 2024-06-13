#include "communication_state.h"

CommunicationState::CommunicationStateEnum CommunicationState::StringToState(const std::string &stateString)
{
    static const std::map<std::string, CommunicationState::CommunicationStateEnum> enumMap = {
        {"RECEIVE", CommunicationState::CommunicationStateEnum::RECEIVE},
        {"RX", CommunicationState::CommunicationStateEnum::RECEIVE},
        {"0", CommunicationState::CommunicationStateEnum::RECEIVE},
        {"TRANSMIT", CommunicationState::CommunicationStateEnum::TRANSMIT},
        {"TX", CommunicationState::CommunicationStateEnum::TRANSMIT},
        {"1", CommunicationState::CommunicationStateEnum::TRANSMIT}};

    auto it = enumMap.find(stateString);
    if (it != enumMap.end())
    {
        return it->second;
    }
    printf("Unrecognized option. Options are: RECEIVE/RX, or TRANSMIT/TX.\n");
    return CommunicationState::CommunicationStateEnum::UNKNOWN;
}

std::string CommunicationState::StateToIntString(const CommunicationStateEnum &stateEnum)
{
    static const std::map<CommunicationState::CommunicationStateEnum, std::string> enumMap = {
        {CommunicationState::CommunicationStateEnum::RECEIVE, "0"},
        {CommunicationState::CommunicationStateEnum::TRANSMIT, "1"}};

    auto it = enumMap.find(stateEnum);
    if (it != enumMap.end())
    {
        return it->second;
    }
    return "UNKNOWN";
}

std::string CommunicationState::StateToString(const CommunicationStateEnum &stateEnum)
{
    static const std::map<CommunicationState::CommunicationStateEnum, std::string> enumMap = {
        {CommunicationState::CommunicationStateEnum::RECEIVE, "RECEIVE"},
        {CommunicationState::CommunicationStateEnum::TRANSMIT, "TRANSMIT"}};

    auto it = enumMap.find(stateEnum);
    if (it != enumMap.end())
    {
        return it->second;
    }
    return "UNKNOWN";
}