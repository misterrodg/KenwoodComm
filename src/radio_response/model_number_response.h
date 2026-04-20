#ifndef MODEL_NUMBER_RESPONSE_H
#define MODEL_NUMBER_RESPONSE_H

enum class ModelNumberResponse
// This quirk defined on page 24 of the IF-10A/B/C Manual
{
    TS711 = 1,
    TS811 = 2,
    TS940 = 3,
    TS140TS680 = 6,
    TS790 = 7,
};

#endif