#ifndef PASSBAND_H
#define PASSBAND_H

#include <string>
#include <cstdint>

class Passband
{
public:
    Passband();
    void setPassband(const std::string &input);
    unsigned short int getPassband() const;
    std::string getPassbandString();

private:
    unsigned short int passband;
};

#endif