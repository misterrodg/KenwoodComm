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
        MC, // Memory Channel
        MD, // Mode
        MR, // Memory Read
        MS, // Memory Scan
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
