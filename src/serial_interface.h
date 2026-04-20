#ifndef SERIAL_INTERFACE_H
#define SERIAL_INTERFACE_H

#include <string>

class ISerialPort {
public:
    virtual ~ISerialPort() = default;
    virtual void Open() = 0;
    virtual void Close() = 0;
    virtual void Write(const std::string& command) = 0;
    virtual std::string Read() = 0;
    virtual bool GetEstablished() = 0;
};

#endif
