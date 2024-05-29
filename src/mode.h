#ifndef MODE_H
#define MODE_H

enum class Mode
{
    LSB = 1,
    USB,
    CW,
    FM,
    AM,  // TS140S/680S/940S only
    FSK, // TS940 only
    CWN  // TS140S/680S only
};

#endif