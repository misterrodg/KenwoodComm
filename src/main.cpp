#include "config/config_manager.h"
#include "parameter/call_sign.h"
#include "parameter/model_number.h"
#include "session.h"

#include <iostream>
#include <string>

ConfigManager initialize(const std::string& requestedProfile) {
    std::string filepath = "./kenwoodcomm.ini";
    ConfigManager config;
    config.load(filepath);

    std::string callSign = config.getFromSection("DEFAULT", "CALLSIGN");
    std::string profileName = requestedProfile;
    if (profileName.empty()) {
        profileName = config.getFromSection("DEFAULT", "PROFILE");
    }

    std::string modelNumber = "";
    if (!profileName.empty()) {
        modelNumber = config.getFromSection(profileName, "MODEL_NUMBER");
    }

    if (!callSign.empty()) {
        std::cout << "Hello, " << callSign << "!" << std::endl;
    } else {
        bool properCallsign = false;
        while (!properCallsign) {
            std::cout << "What is your callsign?" << std::endl;
            std::getline(std::cin, callSign);
            // Validate callsign using CallSign parameter class
            CallSign cs;
            if (cs.setCallSign(callSign)) {
                config.setInSection("DEFAULT", "CALLSIGN",
                                    cs.getCallSignString());
                callSign = cs.getCallSignString();
                properCallsign = true;
            }
        }
        std::cout << "Hello, " << callSign << "!" << std::endl;
    }

    if (!modelNumber.empty() && modelNumber != "UNRECOGNIZED") {
        profileName = modelNumber;
        std::cout << "Setting up for a " << modelNumber << "." << std::endl;
    } else {
        bool properModelNumber = false;
        while (!properModelNumber) {
            std::cout << "What is the model number of your radio?" << std::endl;
            ModelNumber mn;
            std::cout << mn.getAll() << std::endl;
            std::getline(std::cin, modelNumber);
            if (mn.setModelNumber(modelNumber)) {
                modelNumber = mn.getModelNumberString();
                profileName = modelNumber;
                properModelNumber = true;
            }
        }
    }

    std::string serialPort = config.getFromSection(profileName, "SERIAL_PORT");
    if (serialPort.empty()) {
        while (serialPort.empty()) {
            std::cout << "What is the serial port for your radio?" << std::endl;
            std::getline(std::cin, serialPort);
            if (serialPort.empty()) {
                std::cout << "Serial port cannot be blank." << std::endl;
            }
        }
    }

    config.setInSection("DEFAULT", "PROFILE", profileName);
    config.setInSection(profileName, "MODEL_NUMBER", modelNumber);
    config.setInSection(profileName, "SERIAL_PORT", serialPort);
    config.setProfile(profileName);

    config.save();

    return config;
}

int main(int argc, char** argv) {
    bool localMode = false;
    bool safeMode = false;
    std::string requestedProfile = "";
    if (argc > 1) {
        for (int i = 1; i < argc; ++i) {
            std::string arg = argv[i];
            if (arg == "local") {
                localMode = true;
            } else if (arg == "safe") {
                safeMode = true;
            } else if (arg.rfind("profile=", 0) == 0 && arg.size() > 8) {
                requestedProfile = arg.substr(8);
            }
        }
    }
    ConfigManager config = initialize(requestedProfile);

    // Get model number from config and create ModelNumber object
    std::string modelNumberStr =
        config.getFromSection(config.getCurrentProfile(), "MODEL_NUMBER");
    if (modelNumberStr.empty()) {
        modelNumberStr = config.getFromSection("DEFAULT", "MODEL_NUMBER");
    }
    ModelNumber modelNumber;
    modelNumber.setModelNumber(modelNumberStr);

    Session session(safeMode, localMode, modelNumber);

    std::string command = "";

    while (session.sessionOpen) {
        if (session.safeMode) {
            std::cout << "SAFE ";
        }
        std::cout << ":: ";
        std::getline(std::cin, command);
        session.CheckCommand(command);
    }

    return 0;
}
