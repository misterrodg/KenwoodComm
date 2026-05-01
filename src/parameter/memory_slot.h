#ifndef MEMORY_SLOT_H
#define MEMORY_SLOT_H

#include "parameter/frequency.h"
#include "parameter/memory_channel_split.h"
#include "parameter/memory_lockout.h"
#include "parameter/mode.h"
#include "parameter/offset.h"
#include "parameter/switch.h"
#include "parameter/tone_frequency.h"

// One stored memory channel entry for the mock radio.
// All fields default to UNKNOWN/unset; hasFrequency tracks whether a
// frequency was actually written (since Frequency has no sentinel value).
// occupied distinguishes "never written" from "written with blank fields".
struct MemorySlot {
    bool occupied = false;

    // P1 - Split Specification
    MemoryChannelSplit::MemoryChannelSplitEnum split =
        MemoryChannelSplit::MemoryChannelSplitEnum::UNKNOWN;

    // P2 Memory Bank

    // P3 Memory Channel

    // P4 — Frequency
    bool hasFrequency = false;
    Frequency frequency;

    // P5 — Mode
    Mode::ModeEnum mode = Mode::ModeEnum::UNKNOWN;

    // P6 — Memory Lockout
    MemoryLockout::MemoryLockoutEnum lockout =
        MemoryLockout::MemoryLockoutEnum::UNKNOWN;

    // P7 — Tone Status
    Switch::SwitchEnum toneStatus = Switch::SwitchEnum::UNKNOWN;

    // P8 — Tone Frequency
    ToneFrequency::ToneFrequencyEnum toneFrequency =
        ToneFrequency::ToneFrequencyEnum::UNKNOWN;

    // P9 — Offset
    Offset::OffsetEnum offset = Offset::OffsetEnum::UNKNOWN;
};

#endif // MEMORY_SLOT_H
