#ifndef SERIAL_H
#define SERIAL_H

#include "serial_interface.h"
#include <string>
#include <termios.h>

class Serial : public ISerialPort {
public:
    Serial(const std::string &portOverride = "");
    void Open() override;
    void Close() override;
    void Write(const std::string &command) override;
    std::string Read() override;
    bool GetEstablished() override;

private:
    bool established = false;
    std::string serialPort;
    int fdPort;
    const speed_t BAUD = B4800;
    const std::string DEFAULT_PORT = "/dev/ttyUSB0";
};

#endif