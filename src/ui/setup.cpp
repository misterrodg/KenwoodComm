#include "setup.h"

#include "core/error_reporter.h"
#include "parameter/call_sign.h"

#include <iostream>
#include <string>

namespace ui {

ConfigManager RunSetup(const std::string& requestedProfile) {
    std::string filepath = "./kenwoodcomm.ini";
    ConfigManager config;
    config.load(filepath);

    std::string callSign = config.getFromSection("DEFAULT", "CALLSIGN");
    std::string profileName = requestedProfile;
    if (profileName.empty()) {
        profileName = config.getFromSection("DEFAULT", "PROFILE");
    }

    std::string modelNumber;
    if (!profileName.empty()) {
        modelNumber = config.getFromSection(profileName, "MODEL_NUMBER");
    }

    // ---- callsign ----
    if (!callSign.empty()) {
        std::cout << "Hello, " << callSign << "!" << std::endl;
    } else {
        bool valid = false;
        while (!valid) {
            std::cout << "What is your callsign?" << std::endl;
            std::getline(std::cin, callSign);
            CallSign cs;
            core::Result<void> result = cs.setCallSign(callSign);
            if (result.OK()) {
                config.setInSection("DEFAULT", "CALLSIGN",
                                    cs.getCallSignString());
                callSign = cs.getCallSignString();
                valid = true;
            } else {
                printError(result.error());
            }
        }
        std::cout << "Hello, " << callSign << "!" << std::endl;
    }

    // ---- model number ----
    if (!modelNumber.empty() && modelNumber != "UNRECOGNIZED") {
        profileName = modelNumber;
        std::cout << "Setting up for a " << modelNumber << "." << std::endl;
    } else {
        bool valid = false;
        while (!valid) {
            std::cout << "What is the model number of your radio?" << std::endl;
            std::cout << Radio::allSupported() << std::endl;
            std::getline(std::cin, modelNumber);
            core::Result<Radios> result = Radio::parse(modelNumber);
            if (result.OK()) {
                modelNumber = Radio::toString(result.value());
                profileName = modelNumber;
                valid = true;
            } else {
                printError(result.error());
            }
        }
    }

    // ---- serial port ----
    std::string serialPort = config.getFromSection(profileName, "SERIAL_PORT");
    while (serialPort.empty()) {
        std::cout << "What is the serial port for your radio?" << std::endl;
        std::getline(std::cin, serialPort);
        if (serialPort.empty()) {
            std::cout << "Serial port cannot be blank." << std::endl;
        }
    }

    config.setInSection("DEFAULT", "PROFILE", profileName);
    config.setInSection(profileName, "MODEL_NUMBER", modelNumber);
    config.setInSection(profileName, "SERIAL_PORT", serialPort);
    config.setProfile(profileName);
    config.save();

    return config;
}

Radios ResolveRadioModel(const ConfigManager& config) {
    std::string modelNumberStr =
        config.getFromSection(config.getCurrentProfile(), "MODEL_NUMBER");
    if (modelNumberStr.empty()) {
        modelNumberStr = config.getFromSection("DEFAULT", "MODEL_NUMBER");
    }

    core::Result<Radios> result = Radio::parse(modelNumberStr);
    if (!result.OK()) {
        printError(result.error());
        return Radios::UNRECOGNIZED;
    }

    return result.value();
}

} // namespace ui
