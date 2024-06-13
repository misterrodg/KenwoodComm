#include "lock.h"

Lock::LockEnum Lock::StringToLock(const std::string &lockString)
{
    static const std::map<std::string, Lock::LockEnum> enumMap = {
        {"UNLOCKED", Lock::LockEnum::UNLOCKED},
        {"0", Lock::LockEnum::UNLOCKED},
        {"LOCKED", Lock::LockEnum::LOCKED},
        {"1", Lock::LockEnum::LOCKED}};

    auto it = enumMap.find(lockString);
    if (it != enumMap.end())
    {
        return it->second;
    }
    printf("Unrecognized option. Options are: UNLOCKED, or LOCKED.\n");
    return Lock::LockEnum::UNKNOWN;
}

std::string Lock::LockToIntString(const LockEnum &lockEnum)
{
    static const std::map<Lock::LockEnum, std::string> enumMap = {
        {Lock::LockEnum::UNLOCKED, "0"},
        {Lock::LockEnum::LOCKED, "1"}};

    auto it = enumMap.find(lockEnum);
    if (it != enumMap.end())
    {
        return it->second;
    }
    return "UNKNOWN";
}

std::string Lock::LockToString(const LockEnum &lockEnum)
{
    static const std::map<Lock::LockEnum, std::string> enumMap = {
        {Lock::LockEnum::UNLOCKED, "UNLOCKED"},
        {Lock::LockEnum::LOCKED, "LOCKED"}};

    auto it = enumMap.find(lockEnum);
    if (it != enumMap.end())
    {
        return it->second;
    }
    return "UNKNOWN";
}