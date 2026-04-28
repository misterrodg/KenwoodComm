#ifndef MEMORY_CHANNEL_H
#define MEMORY_CHANNEL_H

#include "core/result.h"

#include <map>
#include <string>

// Kenwood Parameter #7: Memory Channel (with 2 digits, e.g. 02 for CH2)

class MemoryChannel {
public:
    enum class MemoryChannelEnum {
        MC00 = 0,
        MC01 = 1,
        MC02 = 2,
        MC03 = 3,
        MC04 = 4,
        MC05 = 5,
        MC06 = 6,
        MC07 = 7,
        MC08 = 8,
        MC09 = 9,
        MC10 = 10,
        MC11 = 11,
        MC12 = 12,
        MC13 = 13,
        MC14 = 14,
        MC15 = 15,
        MC16 = 16,
        MC17 = 17,
        MC18 = 18,
        MC19 = 19,
        MC20 = 20,
        MC21 = 21,
        MC22 = 22,
        MC23 = 23,
        MC24 = 24,
        MC25 = 25,
        MC26 = 26,
        MC27 = 27,
        MC28 = 28,
        MC29 = 29,
        MC30 = 30,
        MC31 = 31,
        MC32 = 32,
        MC33 = 33,
        MC34 = 34,
        MC35 = 35,
        MC36 = 36,
        MC37 = 37,
        MC38 = 38,
        MC39 = 39,
        MC40 = 40,
        MC41 = 41,
        MC42 = 42,
        MC43 = 43,
        MC44 = 44,
        MC45 = 45,
        MC46 = 46,
        MC47 = 47,
        MC48 = 48,
        MC49 = 49,
        MC50 = 50,
        MC51 = 51,
        MC52 = 52,
        MC53 = 53,
        MC54 = 54,
        MC55 = 55,
        MC56 = 56,
        MC57 = 57,
        MC58 = 58,
        MC59 = 59,
        MC60 = 60,
        MC61 = 61,
        MC62 = 62,
        MC63 = 63,
        MC64 = 64,
        MC65 = 65,
        MC66 = 66,
        MC67 = 67,
        MC68 = 68,
        MC69 = 69,
        MC70 = 70,
        MC71 = 71,
        MC72 = 72,
        MC73 = 73,
        MC74 = 74,
        MC75 = 75,
        MC76 = 76,
        MC77 = 77,
        MC78 = 78,
        MC79 = 79,
        MC80 = 80,
        MC81 = 81,
        MC82 = 82,
        MC83 = 83,
        MC84 = 84,
        MC85 = 85,
        MC86 = 86,
        MC87 = 87,
        MC88 = 88,
        MC89 = 89,
        MC90 = 90,
        MC91 = 91,
        MC92 = 92,
        MC93 = 93,
        MC94 = 94,
        MC95 = 95,
        MC96 = 96,
        MC97 = 97,
        MC98 = 98,
        MC99 = 99,
        UNKNOWN = -1
    };

    static MemoryChannelEnum
    StringToChannelEnum(const std::string& memoryChannel);
    static std::string
    ChannelEnumToIntString(const MemoryChannelEnum& memoryChannel);
    static std::string
    ChannelEnumToString(const MemoryChannelEnum& memoryChannel);
    static std::string
    ChannelEnumToFriendlyString(const MemoryChannelEnum& memoryChannel);
    static constexpr int MAX_MEMORY_CHANNEL_LENGTH = 2;
};

#endif