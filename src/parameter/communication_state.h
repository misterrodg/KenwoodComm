#ifndef COMMUNICATION_STATE_H
#define COMMUNICATION_STATE_H

#include <map>
#include <string>

class CommunicationState
{
public:
    enum class CommunicationStateEnum
    {
        RECEIVE,
        TRANSMIT,
        UNKNOWN
    };
    static CommunicationStateEnum StringToState(const std::string &stateString);
    static std::string StateToIntString(const CommunicationStateEnum &stateEnum);
    static std::string StateToString(const CommunicationStateEnum &stateEnum);
    static const int MAX_STATE_LENGTH = 8;
};

#endif