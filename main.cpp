#include "src/defaults.h"

#include <iostream>
#include <string>

void initialize()
{
    std::string filepath = "./DEFAULTS.txt";
    Defaults defaults(filepath);

    std::string callSign = defaults.getCallSign();
    std::string modelNumber = defaults.getModelNumber();

    if (!callSign.empty())
    {
        std::cout << "Hello, " << callSign << "!" << std::endl;
    }
    else
    {
        std::cout << "Hello. What is your callsign?" << std::endl;
        std::getline(std::cin, callSign);
        std::cout << "Hello, " << callSign << "!" << std::endl;
        defaults.setCallSign(callSign);
    }

    if (!modelNumber.empty() && modelNumber != "UNRECOGNIZED")
    {
        std::cout << "Setting up for a " << modelNumber << std::endl;
    }
    else
    {
        std::cout << "What is the model number of your radio?" << std::endl;
        std::getline(std::cin, modelNumber);
        defaults.setModelNumber(modelNumber);
    }

    defaults.save();
}

int main()
{
    initialize();

    return 0;
}
