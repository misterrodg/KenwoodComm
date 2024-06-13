#ifndef LOCK_H
#define LOCK_H

#include <map>
#include <string>

class Lock
{
public:
    enum class LockEnum
    {
        UNLOCKED,
        LOCKED,
        UNKNOWN
    };
    static LockEnum StringToLock(const std::string &lockString);
    static std::string LockToIntString(const LockEnum &lockEnum);
    static std::string LockToString(const LockEnum &lockEnum);
    static const int MAX_LOCK_LENGTH = 8;
};
#endif