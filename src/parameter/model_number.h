#ifndef MODEL_NUMBER_H
#define MODEL_NUMBER_H

#include <string>

// Kenwood Parameter #16: Model Number (e.g. 001 for TS-711, etc.)

class ModelNumber {
public:
    enum class ModelNumberEnum {
        TS711 = 1,
        TS811 = 2,
        TS940 = 3,
        TS140_680 = 6,
        UNRECOGNIZED = -1
    };

    static ModelNumberEnum StringToModelNumber(const std::string& modelNumber);
    static std::string
    ModelNumberToIntString(const ModelNumberEnum& modelNumber);
    static std::string ModelNumberToString(const ModelNumberEnum& modelNumber);
    static std::string
    ModelNumberToFriendlyString(const ModelNumberEnum& modelNumber);
    static constexpr int MAX_MODEL_NUMBER_LENGTH = 3;
};

#endif
