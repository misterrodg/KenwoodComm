#include "defaults.h"

Defaults::Defaults(const std::string filePath) : filePath(filePath), callSign()
{
    readDefaults();
}

void Defaults::readDefaults()
{
    std::ifstream file(filePath);
    std::string line;

    std::string default_file_callsign = "";
    std::string default_file_model_number = "";

    if (file.is_open())
    {
        while (getline(file, line))
        {
            size_t pos = line.find(CALLSIGN_KEY);
            if (pos != std::string::npos)
            {
                default_file_callsign = line.substr(pos + CALLSIGN_KEY.length());
            }

            pos = line.find(MODEL_NUMBER_KEY);
            if (pos != std::string::npos)
            {
                default_file_model_number = line.substr(pos + MODEL_NUMBER_KEY.length());
            }
        }
    }

    if (default_file_callsign != "")
    {
        callSign.setCallSign(default_file_callsign);
    }
    else
    {
        printf("No callsign found.\n");
    }

    if (default_file_model_number != "")
    {
        modelNumber.setModelNumber(default_file_model_number);
    }
    else
    {
        printf("No model number found.\n");
    }
}

std::string Defaults::getCallSign()
{
    return callSign.getCallSignString();
}

bool Defaults::setCallSign(const std::string newCallSign)
{
    defaultsChanged = true;
    return callSign.setCallSign(newCallSign);
}

std::string Defaults::getModelNumber()
{
    return modelNumber.getModelNumber();
}

bool Defaults::setModelNumber(const std::string newModelNumber)
{
    defaultsChanged = true;
    return modelNumber.setModelNumber(newModelNumber);
}

void Defaults::save()
{
    if (defaultsChanged)
    {
        std::ofstream outputFile(filePath);

        if (!outputFile.is_open())
        {
            std::cerr << "Error opening the file." << std::endl;
        }

        outputFile << CALLSIGN_KEY << callSign.getCallSignString() << "\n";
        outputFile << MODEL_NUMBER_KEY << modelNumber.getModelNumber() << "\n";

        outputFile.close();

        std::cout << "Defaults saved successfully." << std::endl;
    }
}
