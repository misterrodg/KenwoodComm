#include "defaults.h"
#include "session.h"

#include <iostream>
#include <string>

Defaults initialize()
{
    std::string filepath = "./DEFAULTS.txt";
    Defaults defaults(filepath);

    std::string callSign = defaults.getCallSign();
    std::string modelNumber = defaults.getModelNumberString();

    if (!callSign.empty())
    {
        std::cout << "Hello, " << callSign << "!" << std::endl;
    }
    else
    {
        bool properCallsign = false;
        while (!properCallsign)
        {
            std::cout << "What is your callsign?" << std::endl;
            std::getline(std::cin, callSign);
            properCallsign = defaults.setCallSign(callSign);
        }
        std::cout << "Hello, " << callSign << "!" << std::endl;
    }

    if (!modelNumber.empty() && modelNumber != "UNRECOGNIZED")
    {
        std::cout << "Setting up for a " << modelNumber << std::endl;
    }
    else
    {
        bool properModelNumber = false;
        while (!properModelNumber)
        {
            std::cout << "What is the model number of your radio?" << std::endl;
            std::getline(std::cin, modelNumber);
            properModelNumber = defaults.setModelNumber(modelNumber);
        }
    }

    defaults.save();

    return defaults;
}

int main()
{
    Defaults defaults = initialize();
    Session session(defaults.getModelNumber());

    std::string command = "";

    while (session.sessionOpen)
    {
        std::cout << ":: ";
        std::getline(std::cin, command);
        session.CheckCommand(command);
    }

    return 0;
}
