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
        std::cout << "Setting up for a " << modelNumber << "." << std::endl;
    }
    else
    {
        bool properModelNumber = false;
        while (!properModelNumber)
        {
            std::cout << "What is the model number of your radio?" << std::endl;
            std::cout << defaults.getModelNumber().getAll() << std::endl;
            std::getline(std::cin, modelNumber);
            properModelNumber = defaults.setModelNumber(modelNumber);
        }
    }

    defaults.save();

    return defaults;
}

int main(int argc, char **argv)
{
    bool localMode = false;
    bool safeMode = false;
    if (argc > 1)
    {
        for (int i = 1; i < argc; ++i)
        {
            if (strcmp(argv[i], "local") == 0)
            {
                localMode = true;
            }
            else if (strcmp(argv[i], "safe") == 0)
            {
                safeMode = true;
            }
        }
    }
    Defaults defaults = initialize();
    Session session(safeMode, localMode, defaults.getModelNumber());

    std::string command = "";

    while (session.sessionOpen)
    {
        if (session.safeMode)
        {
            std::cout << "SAFE ";
        }
        std::cout << ":: ";
        std::getline(std::cin, command);
        session.CheckCommand(command);
    }

    return 0;
}
