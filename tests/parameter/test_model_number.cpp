#include "parameter/model_number.h"
#include "test_framework.h"

TEST(ModelNumber, AcceptsTS50S) {
    ModelNumber mn;
    ASSERT_TRUE(mn.setModelNumber("TS50S").OK());
    ASSERT_EQ(mn.getModelNumber(), Radios::TS50S);
}

TEST(ModelNumber, AcceptsTS60S) {
    ModelNumber mn;
    ASSERT_TRUE(mn.setModelNumber("TS60S").OK());
    ASSERT_EQ(mn.getModelNumber(), Radios::TS60S);
}

TEST(ModelNumber, AcceptsLowercaseInput) {
    ModelNumber mn;
    ASSERT_TRUE(mn.setModelNumber("ts140s").OK());
    ASSERT_EQ(mn.getModelNumber(), Radios::TS140S);
}

TEST(ModelNumber, AcceptsTS811B) {
    ModelNumber mn;
    ASSERT_TRUE(mn.setModelNumber("TS811B").OK());
    ASSERT_EQ(mn.getModelNumber(), Radios::TS811B);
}

TEST(ModelNumber, RejectsInvalidModel) {
    ModelNumber mn;
    ASSERT_FALSE(mn.setModelNumber("TS999Z").OK());
    ASSERT_EQ(mn.getModelNumber(), Radios::UNRECOGNIZED);
}
