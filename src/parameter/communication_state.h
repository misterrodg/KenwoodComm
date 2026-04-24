#ifndef COMMUNICATION_STATE_H
#define COMMUNICATION_STATE_H

#include <map>
#include <string>

// Kenwood Parameter #11: TX/RX - Communication State (RECEIVE/TRANSMIT)

class CommunicationState {
public:
    enum class CommunicationStateEnum {
        RECEIVE = 0,
        TRANSMIT = 1,
        UNKNOWN = -1
    };
    static CommunicationStateEnum StringToState(const std::string& stateString);
    static std::string
    StateToIntString(const CommunicationStateEnum& stateEnum);
    static std::string StateToString(const CommunicationStateEnum& stateEnum);
    static constexpr int MAX_STATE_LENGTH = 8;
};

#endif