#include "parameter/model_number.h"
#include "test_framework.h"

TEST(ModelNumber, AcceptsTS711ByCode) {
    ASSERT_EQ(ModelNumber::StringToModelNumber("001"),
              ModelNumber::ModelNumberEnum::TS711);
}

TEST(ModelNumber, AcceptsTS811ByNumber) {
    ASSERT_EQ(ModelNumber::StringToModelNumber("2"),
              ModelNumber::ModelNumberEnum::TS811);
}

TEST(ModelNumber, AcceptsTS940ByName) {
    ASSERT_EQ(ModelNumber::StringToModelNumber("TS940"),
              ModelNumber::ModelNumberEnum::TS940);
}

TEST(ModelNumber, IntStringUsesThreeDigits) {
    ASSERT_EQ(ModelNumber::ModelNumberToIntString(
                  ModelNumber::ModelNumberEnum::TS140_680),
              "006");
}

TEST(ModelNumber, RejectsInvalidModel) {
    ASSERT_EQ(ModelNumber::StringToModelNumber("TS999"),
              ModelNumber::ModelNumberEnum::UNRECOGNIZED);
}
