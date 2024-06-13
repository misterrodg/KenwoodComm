#include "model_number.h"
#include <regex>

ModelNumber::ModelNumber() : modelNumber(Radios::UNRECOGNIZED) {}

Radios ModelNumber::parseUnit(const std::string &modelStr)
{
    std::string lowerStr = Helpers::toLower(modelStr);
    if (lowerStr == "ts140s")
        return Radios::TS140S;
    if (lowerStr == "ts680s")
        return Radios::TS680S;
    if (lowerStr == "ts711a")
        return Radios::TS711A;
    if (lowerStr == "ts711e")
        return Radios::TS711E;
    if (lowerStr == "ts790a")
        return Radios::TS790A;
    if (lowerStr == "ts790e")
        return Radios::TS790E;
    if (lowerStr == "ts811a")
        return Radios::TS811A;
    if (lowerStr == "ts811B")
        return Radios::TS811B;
    if (lowerStr == "ts811e")
        return Radios::TS811E;
    if (lowerStr == "ts940s")
        return Radios::TS940S;
    return Radios::UNRECOGNIZED;
}

bool ModelNumber::setModelNumber(const std::string &input)
{
    bool result = false;

    std::regex regex(R"(TS\d{3}[ABES])", std::regex_constants::icase);
    std::smatch match;

    if (std::regex_match(input, regex))
    {
        modelNumber = parseUnit(input);
        if (modelNumber != Radios::UNRECOGNIZED)
        {
            result = true;
        }
    }
    else
    {
        printf("Unrecognized model number.\n");
    }

    return result;
}

Radios ModelNumber::getModelNumber()
{
    return modelNumber;
}

std::string ModelNumber::getModelNumberString()
{
    switch (modelNumber)
    {
    case Radios::TS140S:
        return "TS140S";
    case Radios::TS680S:
        return "TS680S";
    case Radios::TS711A:
        return "TS711A";
    case Radios::TS711E:
        return "TS711E";
    case Radios::TS790A:
        return "TS790A";
    case Radios::TS790E:
        return "TS790E";
    case Radios::TS811A:
        return "TS811A";
    case Radios::TS811B:
        return "TS811B";
    case Radios::TS811E:
        return "TS811E";
    case Radios::TS940S:
        return "TS940S";
    default:
        return "UNRECOGNIZED";
    }
}

std::string ModelNumber::getGeneric()
{
    switch (modelNumber)
    {
    case Radios::TS140S:
        return "140";
    case Radios::TS680S:
        return "680";
    case Radios::TS711A:
        return "711";
    case Radios::TS711E:
        return "711";
    case Radios::TS790A:
        return "790";
    case Radios::TS790E:
        return "790";
    case Radios::TS811A:
        return "811";
    case Radios::TS811B:
        return "811";
    case Radios::TS811E:
        return "811";
    case Radios::TS940S:
        return "940";
    default:
        return "UNRECOGNIZED";
    }
}

std::string ModelNumber::getAll()
{
    return "TS140S / TS680S / TS711A / TS711E / TS790A / TS790E / TS811A / TS811B / TS811E / TS940S";
}