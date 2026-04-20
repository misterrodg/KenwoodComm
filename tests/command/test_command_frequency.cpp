#include "test_framework.h"
#include "command/fa.h"

TEST(CommandFrequency, SetFrequency_Valid_ReturnsOK) {
    FA fa;
    ASSERT_TRUE(fa.SetFrequency("14.1 MHz").OK());
}

TEST(CommandFrequency, SetFrequency_Invalid_ReturnsError) {
    FA fa;
    ASSERT_FALSE(fa.SetFrequency("notafrequency").OK());
}

TEST(CommandFrequency, SetFrequency_Empty_ReturnsError) {
    FA fa;
    ASSERT_FALSE(fa.SetFrequency("").OK());
}

TEST(CommandFrequency, ToCommand_Write_14MHz) {
    FA fa;
    fa.SetFrequency("14.1 MHz");
    ASSERT_STREQ(fa.ToCommand(), "FA00014100000;");
}

TEST(CommandFrequency, ToCommand_Write_7MHz) {
    FA fa;
    fa.SetFrequency("7 MHz");
    ASSERT_STREQ(fa.ToCommand(), "FA00007000000;");
}

TEST(CommandFrequency, ToCommand_Write_144MHz) {
    FA fa;
    fa.SetFrequency("144.200 MHz");
    ASSERT_STREQ(fa.ToCommand(), "FA00144200000;");
}

TEST(CommandFrequency, ToCommand_ReadStatus) {
    FA fa;
    ASSERT_STREQ(fa.ToCommand(true), "FA;");
}

TEST(CommandFrequency, ConstructorWithParameter) {
    FA fa("14.1 MHz");
    ASSERT_STREQ(fa.ToCommand(), "FA00014100000;");
}
