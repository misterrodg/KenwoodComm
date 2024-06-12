#ifndef COMMAND_PREFIX_H
#define COMMAND_PREFIX_H

#include <map>
#include <string>

class CommandPrefix
{
public:
    enum class CommandPrefixEnum
    {
        AI, // Auto Information
        AT, // Antenna Tuner
        BY, // Busy
        CN, // CTCSS Number
        CT, // CTCSS
        DC, // Destination Code
        DI, // DCS ID
        DN, // Down
        DS, // DCS
        FA, // Frequency VFO A
        FB, // Frequency VFO B
        FN, // Function
        HD, // Scan Hold
        ID, // ID
        IF, // Information
        LK, // Lock
        LO, // Local
        LT, // Auto Lock Tone
        MC, // Memory Channel
        MD, // Mode
        MR, // Memory Read
        MS, // Memory Scan
        MT, // Mute
        MW, // Memory Write
        OS, // Offset
        RC, // RIT Clear
        RD, // RIT Down
        RU, // RIT Up
        RT, // RIT
        RX, // RX
        SC, // Scan
        SH, // Slope Tune High
        SL, // Slope Tune Low
        SM, // S-Meter (Sub)
        SP, // Split
        ST, // Step
        TN, // Tone Number
        TO, // Tone
        TX, // TX
        UP, // Up
        VB, // VBT
        VR, // Voice Recall
        XT, // XIT
        ZZ  // NOT A COMMAND
    };
    static CommandPrefixEnum StringToCommandPrefix(const std::string &commandString);
    static std::string CommandToString(const CommandPrefixEnum &command);
    static std::string CommandToStringExpanded(const CommandPrefixEnum &command);
    static const int COMMAND_LENGTH;
};

#endif
