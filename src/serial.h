#ifndef SERIAL_H
#define SERIAL_H

// C library headers
#include <stdio.h>
#include <cstdio>
#include <signal.h>
#include <string.h>
#include <termios.h>
#include <iostream>

// Linux headers
#include <fcntl.h>   // Contains file controls like O_RDWR
#include <errno.h>   // Error integer and strerror() function
#include <termios.h> // Contains POSIX terminal control definitions
#include <unistd.h>  // write(), read(), close(), usleep()
#include <iomanip>

#include "command.h"
#include "response.h"

class Serial
{
public:
    Serial(const std::string &portOverride = "");
    void Open();
    void Close();
    void Write(const std::string &command);
    std::string Read();
    bool GetEstablished();

private:
    bool established = false;
    std::string serialPort;
    int fdPort;
    const speed_t BAUD = B4800;
    const std::string DEFAULT_PORT = "/dev/ttyUSB0";
};

#endif