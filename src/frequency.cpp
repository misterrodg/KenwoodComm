#include "frequency.h"
#include "frequency_unit.h"
#include <regex>
#include <stdexcept>
#include <algorithm>
#include <cctype>

Frequency::Frequency() : frequencyInHz(0) {}

void Frequency::setFrequency(const std::string &input)
{
    std::regex regex(R"((\d+(\.\d+)?)([a-zA-Z]+))");
    std::smatch match;

    if (std::regex_match(input, match, regex))
    {
        double value = std::stod(match[1].str());
        std::string unit = match[3].str();

        FrequencyUnit::Unit frequencyUnit = FrequencyUnit::parseUnit(unit);
        frequencyInHz = FrequencyUnit::toHz(value, frequencyUnit);
    }
    else
    {
        throw std::invalid_argument("Invalid frequency format");
    }
}

uint64_t Frequency::getFrequencyInHz() const
{
    return frequencyInHz;
}

std::string Frequency::getFrequencyString()
{
    char formattedFrequency[12];
    std::sprintf(formattedFrequency, "%011lu", frequencyInHz);

    return formattedFrequency;
}