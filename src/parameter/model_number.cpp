#include "model_number.h"

#include <map>

ModelNumber::ModelNumberEnum
ModelNumber::StringToModelNumber(const std::string& modelNumber) {
    static const std::map<std::string, ModelNumber::ModelNumberEnum> enumMap = {
        {"TS711", ModelNumber::ModelNumberEnum::TS711},
        {"1", ModelNumber::ModelNumberEnum::TS711},
        {"001", ModelNumber::ModelNumberEnum::TS711},
        {"TS811", ModelNumber::ModelNumberEnum::TS811},
        {"2", ModelNumber::ModelNumberEnum::TS811},
        {"002", ModelNumber::ModelNumberEnum::TS811},
        {"TS940", ModelNumber::ModelNumberEnum::TS940},
        {"3", ModelNumber::ModelNumberEnum::TS940},
        {"003", ModelNumber::ModelNumberEnum::TS940},
        {"TS140/680", ModelNumber::ModelNumberEnum::TS140_680},
        {"6", ModelNumber::ModelNumberEnum::TS140_680},
        {"006", ModelNumber::ModelNumberEnum::TS140_680},
    };

    auto it = enumMap.find(modelNumber);
    if (it != enumMap.end()) {
        return it->second;
    }

    return ModelNumber::ModelNumberEnum::UNRECOGNIZED;
}

std::string
ModelNumber::ModelNumberToIntString(const ModelNumberEnum& modelNumber) {
    switch (modelNumber) {
    case ModelNumber::ModelNumberEnum::TS711:
        return "001";
    case ModelNumber::ModelNumberEnum::TS811:
        return "002";
    case ModelNumber::ModelNumberEnum::TS940:
        return "003";
    case ModelNumber::ModelNumberEnum::TS140_680:
        return "006";
    default:
        return "UNKNOWN";
    }
}

std::string
ModelNumber::ModelNumberToString(const ModelNumberEnum& modelNumber) {
    switch (modelNumber) {
    case ModelNumber::ModelNumberEnum::TS711:
        return "TS711";
    case ModelNumber::ModelNumberEnum::TS811:
        return "TS811";
    case ModelNumber::ModelNumberEnum::TS940:
        return "TS940";
    case ModelNumber::ModelNumberEnum::TS140_680:
        return "TS140/680";
    default:
        return "UNKNOWN";
    }
}

std::string
ModelNumber::ModelNumberToFriendlyString(const ModelNumberEnum& modelNumber) {
    return ModelNumberToString(modelNumber);
}
