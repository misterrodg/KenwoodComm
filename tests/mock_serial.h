#pragma once

#include "serial_interface.h"
#include <string>
#include <vector>

// MockSerial captures Write() calls and returns a canned Read() response.
// GetEstablished() returns true by default so Session::write() forwards calls.
class MockSerial : public ISerialPort {
public:
    std::vector<std::string> written;
    std::string nextRead;

    void Open() override {
        established_ = true;
    }
    void Close() override {
        established_ = false;
    }
    void Write(const std::string& command) override {
        written.push_back(command);
    }
    std::string Read() override {
        return nextRead;
    }
    bool GetEstablished() override {
        return established_;
    }

    // Convenience helpers
    void reset() {
        written.clear();
        nextRead.clear();
    }
    bool receivedCommand(const std::string& cmd) const {
        for (const auto& w : written)
            if (w == cmd)
                return true;
        return false;
    }

private:
    bool established_ = true;
};
